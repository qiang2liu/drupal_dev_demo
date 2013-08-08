<?php
/**
 * Implements theme_preprocess_node();
 */
function newfteui_preprocess_node(&$vars) {
  $node = $vars['node'];
  if($node->type == 'edgemakers_set') {
    require_once drupal_get_path('module', 'edgemakers_set').'/edgemakers_set.pages.inc';
    $terms = _edgemakers_set_get_terms();
    $types = field_get_items('node', $node, 'field_set_type');
    $type = $types && count($types) > 0 ? $terms[$types[0]['tid']] : '';

    if($type == 'Inspiration' || $type == 'Showcase' || $type == 'Video')
      $type = 'video';
    else if($type == 'Video with Comments')
      $type = 'videocomments';
    else if($type == 'Video with Q&A')
      $type = 'videoqa';
    else if($type == 'Survey & Assessment')
      $type = 'survey';
    if($type == 'Image' || $type == 'Text' || $type == 'video' || $type == 'Idea' || $type == 'videocomments' || $type == 'videoqa' || $type == 'survey' || $type == 'Document') {
      $vars['display_submitted'] = false;
      $vars['theme_hook_suggestions'][] = 'node__edgemakers_set__'.strtolower($type);
    }
  }
}
/*
 * Implments hook_preprocess_html().
 */
function newfteui_preprocess_html() {
  drupal_add_library('system', 'drupal.ajax');
  drupal_add_library('system', 'jquery.form');
  drupal_add_library('system', 'drupal.form');
}
/**
 * Implements theme_preprocess_comment_wrapper();
 */
function newfteui_preprocess_comment_wrapper(&$vars) {
  $vars['comments_title'] = t('Comments:');
  $node = $vars['node'];
  if($node->type == 'edgemakers_set') {
    require_once drupal_get_path('module', 'edgemakers_set').'/edgemakers_set.pages.inc';
    $terms = _edgemakers_set_get_terms();
    $types = field_get_items('node', $node, 'field_set_type');
    $type = $types && count($types) > 0 ? $terms[$types[0]['tid']] : '';
    global $user;
    if($type == 'Video with Comments') {
      $vars['comments_title'] = '';
      $oldComments = $vars['content']['comments'];
      /*if(isset($oldComments['#sorted'])) {
        $sorted = $oldComments['#sorted'];
        unset($oldComments['#sorted']);
      }
      if(isset($oldComments['pager'])) {
        $pager = $oldComments['pager'];
        unset($oldComments['pager']);
      }
      $oldComments = array_reverse($oldComments, true);
      if(isset($oldComments['#sorted'])) {
        $oldComments = array_merge(array('#sorted'=>$sorted), $oldComments);
      }
      if(isset($oldComments['pager'])) {
        $vars['content']['comments'] = array_merge($oldComments, array('pager'=>$pager));
      }*/
    } else if($type == 'Video with Q&A') {
      $vars['comments_title'] = t('Answer:');
      $comments = array();
      if($user->uid != 0) {
        foreach($vars['content']['comments'] as $cid=>$comment) {
          if($user->uid == $comment['#comment']->uid) {
            $comments[$cid] = $comment;
            $vars['content']['comment_form'] = false;
            break;
          }
        }
      }
      $vars['content']['comments'] = $comments;
    }
  }
}
/**
 * Implements theme_preprocess_comment();
 */
function newfteui_preprocess_comment(&$vars) {
  $vars['submitted'] = false;
  $vars['title'] = '';
}

/**
 * Implements theme_breadcrumb();
 */
function newfteui_breadcrumb($variables) {

  //drupal_set_message("edgemakers_stage_breadcrumb include home link");

  $breadcrumb = $variables['breadcrumb'];
  $crumb_arrow = '<span class="crumbs-arrow"> &raquo </span>';
  if (!empty($breadcrumb)) {

    $show_home = theme_get_setting('show_home');

    if (isset($breadcrumb[0])) {
      //drupal_set_message('reset home now.<pre>' . print_r($breadcrumb, TRUE) . '</pre>');
      //drupal_set_message('show home:<pre>' . print_r($show_home, TRUE) . '</pre>');
      $breadcrumb[0] = l(t('Home'), 'home');
    }

    $arr_crumbs = array();
    array_push($arr_crumbs, '<span class="crumbs">' . implode($crumb_arrow, $breadcrumb) . '</span>');

    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $array_size = count($arr_crumbs);
    for ($i=0; $i < $array_size; $i++) {
      if ( $i == $array_size - 1 ) {
      // Menu link title may override the content title
        (menu_get_active_title()) ? $current_crumb = menu_get_active_title() : $current_crumb = drupal_get_title();
      // If current page is 'Edit Page'
      if (substr(drupal_get_title(), 0, 18) == '<em>Edit Page</em>') {
          $current_crumb = 'Edit';
        }

        $output .= $arr_crumbs[$i] . '<span class="crumbs-current">' . $crumb_arrow . $current_crumb . '</span>';
        break;
      }
      $output .= $arr_crumbs[$i];
    }

    return '<div class="breadcrumb">' . $output . '</div>';
  }
}

function newfteui_preprocess_rate_template_like(&$variables) {
  extract($variables);

  $variables['like_button'] = theme('rate_button', array('text' => $results['count'], 'href' => url('edgemakers/set/ajaxlike/'.$content_id), 'class' => 'rate-like-btn use-ajax rate-button-cid-'.$content_id));
}

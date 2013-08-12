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
      $vars['content']['comments']['pager']['#tags'] = array('<<','<','','>','>>');
      $vars['content']['comments']['pager']['#item_attributes'] = array('class' => 'use-ajax');
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
function newfteui_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $item_attributes = isset($variables['item_attributes']) ? $variables['item_attributes'] : array();
  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters, 'attributes' => $item_attributes));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters, 'attributes' => $item_attributes));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters, 'attributes' => $item_attributes));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters, 'attributes' => $item_attributes));

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters, 'attributes' => $item_attributes)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('pager-current'),
            'data' => $i,
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array('pager-item'),
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters, 'attributes' => $item_attributes)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => '…',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pager')),
    ));
  }
}
function newfteui_pager_first($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  global $pager_page_array;
  $output = '';

  // If we are anywhere but the first page
  if ($pager_page_array[$element] > 0) {
    $output = theme('pager_link', array('text' => $text, 'page_new' => pager_load_array(0, $element, $pager_page_array), 'element' => $element, 'parameters' => $parameters, 'attributes' => $attributes));
  }

  return $output;
}

/**
 * Returns HTML for the "previous page" link in a query pager.
 *
 * @param $variables
 *   An associative array containing:
 *   - text: The name (or image) of the link.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - interval: The number of pages to move backward when the link is clicked.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager links.
 *
 * @ingroup themeable
 */
function newfteui_pager_previous($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  global $pager_page_array;
  $output = '';

  // If we are anywhere but the first page
  if ($pager_page_array[$element] > 0) {
    $page_new = pager_load_array($pager_page_array[$element] - $interval, $element, $pager_page_array);

    // If the previous page is the first page, mark the link as such.
    if ($page_new[$element] == 0) {
      $output = theme('pager_first', array('text' => $text, 'element' => $element, 'parameters' => $parameters, 'attributes' => $attributes));
    }
    // The previous page is not the first page.
    else {
      $output = theme('pager_link', array('text' => $text, 'page_new' => $page_new, 'element' => $element, 'parameters' => $parameters, 'attributes' => $attributes));
    }
  }

  return $output;
}

/**
 * Returns HTML for the "next page" link in a query pager.
 *
 * @param $variables
 *   An associative array containing:
 *   - text: The name (or image) of the link.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - interval: The number of pages to move forward when the link is clicked.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager links.
 *
 * @ingroup themeable
 */
function newfteui_pager_next($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $interval = $variables['interval'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  global $pager_page_array, $pager_total;
  $output = '';

  // If we are anywhere but the last page
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $page_new = pager_load_array($pager_page_array[$element] + $interval, $element, $pager_page_array);
    // If the next page is the last page, mark the link as such.
    if ($page_new[$element] == ($pager_total[$element] - 1)) {
      $output = theme('pager_last', array('text' => $text, 'element' => $element, 'parameters' => $parameters, 'attributes' => $attributes));
    }
    // The next page is not the last page.
    else {
      $output = theme('pager_link', array('text' => $text, 'page_new' => $page_new, 'element' => $element, 'parameters' => $parameters, 'attributes' => $attributes));
    }
  }

  return $output;
}

/**
 * Returns HTML for the "last page" link in query pager.
 *
 * @param $variables
 *   An associative array containing:
 *   - text: The name (or image) of the link.
 *   - element: An optional integer to distinguish between multiple pagers on
 *     one page.
 *   - parameters: An associative array of query string parameters to append to
 *     the pager links.
 *
 * @ingroup themeable
 */
function newfteui_pager_last($variables) {
  $text = $variables['text'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];
  global $pager_page_array, $pager_total;
  $output = '';

  // If we are anywhere but the last page
  if ($pager_page_array[$element] < ($pager_total[$element] - 1)) {
    $output = theme('pager_link', array('text' => $text, 'page_new' => pager_load_array($pager_total[$element] - 1, $element, $pager_page_array), 'element' => $element, 'parameters' => $parameters, 'attributes' => $attributes));
  }

  return $output;
}
function newfteui_pager_link($variables) {
  $text = $variables['text'];
  $page_new = $variables['page_new'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $attributes = $variables['attributes'];

  $page = isset($_GET['page']) ? $_GET['page'] : '';
  $new_page = implode(',', pager_load_array($page_new[$element], $element, explode(',', $page)));
  $parameters['page'] = $new_page;

  $query = array();
  if (count($parameters)) {
    $query = drupal_get_query_parameters($parameters, array());
  }
  if ($query_pager = pager_get_query_parameters()) {
    $query = array_merge($query, $query_pager);
  }

  // Set each pager link title
  if (!isset($attributes['title'])) {
    static $titles = NULL;
    if (!isset($titles)) {
      $titles = array(
        t('« first') => t('Go to first page'),
        t('‹ previous') => t('Go to previous page'),
        t('next ›') => t('Go to next page'),
        t('last »') => t('Go to last page'),
      );
    }
    if (isset($titles[$text])) {
      $attributes['title'] = $titles[$text];
    }
    elseif (is_numeric($text)) {
      $attributes['title'] = t('Go to page @number', array('@number' => $text));
    }
  }

  // @todo l() cannot be used here, since it adds an 'active' class based on the
  //   path only (which is always the current path for pager links). Apparently,
  //   none of the pager links is active at any time - but it should still be
  //   possible to use l() here.
  // @see http://drupal.org/node/1410574
  $attributes['href'] = url($_GET['q'], array('query' => $query));
  return '<a' . drupal_attributes($attributes) . '>' . check_plain($text) . '</a>';
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

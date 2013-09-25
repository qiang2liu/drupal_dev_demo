<?php
/**
 * functions for edgemakers_set_form_alter
 *
 */
function _edgemakers_set_load_my_javascript($element){
  drupal_add_js(drupal_get_path('module', 'edgemakers_set').'/js/set.js');
  return($element);
}
function edgemakers_set_node_submit_redirect_handler($form, &$form_state) {
  unset($_REQUEST['destination']);
  unset($form['#redirect']);
  //$node = $form_state['node'];
  //if (!isset($node->nid)) {
    $form_state['redirect'] = 'admin/edgemakers/set';
  //}
}
/**
 * page callbacks
 *
 */
//render the edgemakers admin page, with links listed
function edgemakers_set_admin_page() {
  $item = menu_get_item();
  if ($content = system_admin_menu_block($item)) {
    $output = theme('admin_block_content', array('content' => $content));
  }
  else {
    $output = t('You do not have any administrative items.');
  }
  return $output;
}
//render the create set page
function edgemakers_set_admin_create_page() {
  module_load_include('inc', 'node', 'node.pages');
  $form = node_add('edgemakers_set');
  $output = drupal_render($form);
  return $output;
}
//delete set, and update setes list
function edgemakers_set_admin_delete_action($nid, $ajax) {
  module_load_include('inc', 'node', 'node.pages');
  node_delete($nid);

  if ($ajax) {
    _edgemakers_set_admin_list_update();
  }
  else {
    $set = node_load($nid);
    drupal_set_message(t('Set [@set_title] deleted.', array('@set_title' => $set->title)));
    drupal_goto('admin/edgemakers/set');
  }
}
//update setes list
function _edgemakers_set_admin_list_update() {
  $output = _edgemakers_set_admin_list_html();
  $commands = array();
  $commands[] = ajax_command_replace('#setesListDiv', '<div id="setesListDiv">' . $output . '</div>');
  $page = array('#type' => 'ajax', '#commands' => $commands);
  ajax_deliver($page);
}
function _edgemakers_set_admin_list_html() {
  return drupal_render(drupal_get_form('edgemakers_set_admin_list_form'));
}
//generate the list setes form for drupal_get_form
function edgemakers_set_admin_list_form() {
  drupal_add_js(drupal_get_path('module', 'edgemakers_stage') . '/js/edgemakers_stage_admin.js');
  drupal_add_library('system', 'drupal.ajax');
  ctools_include('modal');
  ctools_modal_add_js();
  $type = "edgemakers_set";
  $nodes = node_load_multiple(array(), array('type' => $type));
  $header = array(
    'title' => array('data' => t('Set Title')),
    'type' => array('data' => t('Set Type')),
    'url' => array('data' => t('Set URL')),
    'operations' => t('Operations'),
  );
  $terms = _edgemakers_set_get_terms();
  $destination = drupal_get_destination();
  $options = array();
  foreach ($nodes as $node) {
    $operations = array(
      'delete' => array(
        'title' => t('delete'),
        'href' => 'admin/edgemakers/set/ajaxdelete/' . $node->nid . '/nojs/',
        'attributes' => array(
          'class' => array('use-ajax', 'set-delete-link'),
          'nid' => $node->nid,
        ),
      ),
      'edit' => array(
        'title' => t('edit'),
				'href' => 'modal/node/' . $node->nid . '/edit/nojs/1',
        'attributes' => array('class' => array('ctools-use-modal')),
      ),
    );
    $types = field_get_items('node', $node, 'field_set_type');
    $type = $types && count($types) > 0 ? $terms[$types[0]['tid']] : '';
    if($type == 'Video with Q&A') {
      $operations['answers'] = array(
        'title' => t('Answers'),
        'href' => 'admin/edgemakers/set/answers/' . $node->nid,
        'query' => $destination,
      );
    } else if($type == 'Survey & Assessment') {
      $surveys = field_get_items('node', $node, 'field_set_survey');
      $survey = $surveys && count($surveys) > 0 ? $surveys[0]['target_id'] : '';
      if($survey) {
        $operations['submissions'] = array(
          'title' => t('Submissions'),
          'href' => 'admin/edgemakers/set/submissions/' . $survey,
          'query' => $destination,
        );
      }
    }
    $urls = field_get_items('node', $node, 'field_set_url');
    $url = $urls && count($urls) > 0 ? $urls[0]['url'] : '';
    $options[$node->nid] = array(
      'title' => check_plain($node->title),
      'type' => $type,
      'url' => $url,
      'operations' => array(
        'data' => array(
          '#theme' => 'links__node_operations',
          '#links' => $operations,
          '#attributes' => array('class' => array('links', 'inline')),
        ),
      ),
    );
  }
  $form['nodes'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $options,
    '#empty' => t('No content available.'),
  );
  $form['pager'] = array('#markup' => theme('pager'));
  $form['#prefix'] = '<div id="setesListDiv">';
  $form['#suffix'] = '</div>';
  return $form;
}
function edgemakers_set_answers_page($nid) {
  return drupal_get_form(edgemakers_set_answers_form, $nid);
}
function edgemakers_set_answers_form($form, &$form_state, $nid) {
  $header = array(
    'subject' => array('data' => t('Subject'), 'field' => 'subject'),
    'author' => array('data' => t('Author'), 'field' => 'name'),
    'changed' => array('data' => t('Updated'), 'field' => 'c.changed', 'sort' => 'desc'),
    'operations' => array('data' => t('Operations')),
  );

  $query = db_select('comment', 'c')->extend('PagerDefault')->extend('TableSort');
  $query->addTag('node_access');
  $result = $query
    ->fields('c', array('cid', 'subject', 'name', 'changed'))
    ->condition('c.nid', $nid)
    ->limit(50)
    ->orderByHeader($header)
    ->execute();

  $cids = array();

  foreach ($result as $row) {
    $cids[] = $row->cid;
  }
  $comments = comment_load_multiple($cids);
  // Build a table listing the appropriate comments.
  $options = array();
  $destination = drupal_get_destination();

  foreach ($comments as $comment) {
    $comment_body = field_get_items('comment', $comment, 'comment_body');
    $options[$comment->cid] = array(
      'subject' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $comment->subject,
          '#href' => 'comment/' . $comment->cid,
          '#options' => array('attributes' => array('title' => truncate_utf8($comment_body[0]['value'], 128)), 'fragment' => 'comment-' . $comment->cid),
        ),
      ),
      'author' => theme('username', array('account' => $comment)),
      'changed' => format_date($comment->changed, 'short'),
      'operations' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => t('edit'),
          '#href' => 'comment/' . $comment->cid . '/edit',
          '#options' => array('query' => $destination),
        ),
      ),
    );
  }

  $form['backlink'] = array('#markup' => l(t('Go Back'), $_GET['destination']));
  $form['comments'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $options,
    '#empty' => t('No comments available.'),
  );

  $form['pager'] = array('#theme' => 'pager');

  return $form;
}
function edgemakers_set_like($cid) {
  $content_type = 'comment';
  $content_id = (int) $cid;
  $widget_id = (int) $_GET['widget_id'];
  $widget_mode = RATE_COMPACT;

  $widgets = variable_get(RATE_VAR_WIDGETS, array());
  $widget_id = '';
  foreach($widgets as $widget_id => $widget) {
    if($widget->name == 'like') {
      foreach ($widget->options as $option) {
        rate_save_vote($widget, $content_type, $content_id, $widget->options[0], TRUE);
      }
      break;
    }
  }
  $results = rate_get_results($content_type, $cid, $widget_id);
  // Process options.

  $selector = '.rate-button-cid-'.$cid;
  $output = $results['count'];
  $commands = array();
  $commands[] = ajax_command_html($selector , $output);
  $page = array('#type' => 'ajax', '#commands' => $commands);
  ajax_deliver($page);
}
function _edgemakers_set_get_terms() {
  $terms = array();
  $vocabulary = taxonomy_vocabulary_machine_name_load('set_types');
  $oterms = taxonomy_get_tree($vocabulary->vid);
  foreach($oterms as $term) {
    $terms[$term->tid] = $term->name;
  }
  return $terms;
}
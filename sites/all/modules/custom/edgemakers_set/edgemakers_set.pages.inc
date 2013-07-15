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
function edgemakers_set_admin_delete_action($nid) {
  module_load_include('inc', 'node', 'node.pages');
  node_delete($nid);
  _edgemakers_set_admin_list_update();
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
  $options = array();
  foreach ($nodes as $node) {
    $langcode = entity_language('node', $node);
    $l_options = $langcode != LANGUAGE_NONE && isset($languages[$langcode]) ? array('language' => $languages[$langcode]) : array();
    $operations = array(
      'delete' => array(
        'title' => t('delete'),
        'href' => 'admin/edgemakers/set/ajaxdelete/' . $node->nid . '/nojs/',
        'attributes' => array('class' => array('use-ajax')),
      ),
      'edit' => array(
        'title' => t('edit'),
				'href' => 'modal/node/' . $node->nid . '/edit/nojs/1',
        'attributes' => array('class' => array('ctools-use-modal')),
      ),
    );
    $types = field_get_items('node', $node, 'field_set_type');
    $type = $types && count($types) > 0 ? $terms[$types[0]['tid']] : '';
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
function _edgemakers_set_get_terms() {
  $terms = array();
  $vid = variable_get('set_vid');
  $oterms = taxonomy_get_tree($vid);
  foreach($oterms as $term) {
    $terms[$term->tid] = $term->name;
  }
  return $terms;
}
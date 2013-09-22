<?php
/**
 * @file
 * Stage manage pages.
 */

/**
 * Create new Stage page.
 * @return string
 *   - HTML code.
 */
function edgemakers_stage_create_page() {
  module_load_include('inc', 'node', 'node.pages');
  $form = node_add('stage');
  unset($form['box_index_data']);
  return drupal_render($form);
}

/**
 * Edgemakers stage edit.
 *
 * @return string
 *   - HTML code.
 */
function edgemakers_stage_edit($nid = '') {
  if ($nid) {
    module_load_include('inc', 'node', 'node.pages');
    $node = node_load($nid);
    $form = drupal_get_form('node_form', $node);
    $output = drupal_render($form);
    return $output;
  }
  else {
    drupal_goto('admin/edgemakers/stage/create');
  }

}

<?php
/**
 * @file data api of stage.
 */

/**
 * Export the stage json data.
 */
function edgemakers_stage_api_list_json() {
  $type = variable_get('edgemakers_stage_content_type', 'stage');
  $nodes = node_load_multiple(array(), array('type' => $type));
  foreach($nodes AS $node) {
    $set_html = edgemakers_stage_api_set_list_html($node->nid);
    $node->defualt_image = theme('image', array('path'=>drupal_get_path('module', 'edgemakers_stage') . '/images/stageDefault.png'));
  	$json[] = $node;
  }
  drupal_json_output($json);
}

/**
 * Ajax link callback;
 * @param unknown_type $page_callback_result
 */
function edgemakers_stage_ajax_callback($page_callback_result) {
  // Only render content
  print $page_callback_result;
  // Perform end-of-request tasks.
  drupal_page_footer();
}

/**
 * Return set list data by stage id.
 *
 * @param int $stage_id
 */
function edgemakers_stage_api_set_list_html($stage_id) {

  $html = '';

  if ($stage_id) {
    $stage = node_load($stage_id);

    if (isset($stage->box_index_data[LANGUAGE_NONE])) {

      $stage_index = unserialize($stage->box_index_data[LANGUAGE_NONE][0]['value']);
      //dpm($stage_index);

      foreach ($stage_index AS $set) {
        if($set['set_id']) {
          $node = node_load($set['set_id']);

          // Get box type by tid.
          if (isset($node->field_set_type[LANGUAGE_NONE])) {
            $node->term = taxonomy_term_load($node->field_set_type[LANGUAGE_NONE][0]['tid']);
          }

          //if (function_exists(theme_set_item)) {
            $item = theme('set_item', array('item'=>$node));
            //$item = theme_set_item_list($node->term, $node);
          //}
          //else {
          //  $item = l($node->title, 'node/' . $node->nid);
          //}
          $sets['items'][] = $item;
        }
      }

      $sets['title'] = 'Set list.';
      $sets['type'] = 'ul';
      $sets['attributes'] = array();

      $set_list = theme_item_list($sets);

      $html .= $set_list;

    }

  }

  return $html;

}
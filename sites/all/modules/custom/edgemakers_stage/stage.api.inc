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
  	$json[] = $node;
  }
  drupal_json_output($json);
}

/**
 *
 * @param int $stage_id
 */
function edgemakers_stage_api_set_list_json($stage_id) {

  if ($stage_id) {
    $stage = node_load($stage_id);
    foreach ($stage AS $set) {

    }
  }

}
<?php
/**
 * @file data api of stage.
 */

function edgemakers_stage_api_list_json() {
  $type = variable_get('edgemakers_stage_content_type', 'stage');
  $nodes = node_load_multiple(array(), array('type' => $type));
  drupal_json_output($nodes);
}
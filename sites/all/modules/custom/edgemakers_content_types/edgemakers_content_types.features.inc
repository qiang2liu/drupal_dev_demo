<?php
/**
 * @file
 * edgemakers_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function edgemakers_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function edgemakers_content_types_node_info() {
  $items = array(
    'edgemakers_topic' => array(
      'name' => t('Topic'),
      'base' => 'node_content',
      'description' => t('Topic is a very basic and core content type in EdgeMakers. Topics are normally linked to <em>Wicked problem</em> and <em>Carousel</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

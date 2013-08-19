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
    'carousel_item' => array(
      'name' => t('Carousel Item'),
      'base' => 'node_content',
      'description' => t('Carousel Item Node type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'edgemakers_set' => array(
      'name' => t('Set'),
      'base' => 'node_content',
      'description' => t('Node type used for setes.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'edgemakers_topic' => array(
      'name' => t('Topic'),
      'base' => 'node_content',
      'description' => t('Topic is a very basic and core content type in EdgeMakers. Topics are normally linked to <em>Wicked problem</em> and <em>Carousel</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'media_for_upload' => array(
      'name' => t('media for upload'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'murals' => array(
      'name' => t('murals'),
      'base' => 'node_content',
      'description' => t('infos of mural  in the mural site'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'site_bg_image' => array(
      'name' => t('Site BG Image'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'stage' => array(
      'name' => t('Stage'),
      'base' => 'node_content',
      'description' => t('Node type used for making stage.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'base' => 'node_content',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

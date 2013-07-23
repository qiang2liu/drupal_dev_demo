<?php

/**
 * @file
 * FTE box layout admin module configuration on admin.
 */

/**
 * Form builder function for module settings.
 */
function marker_clusterer_demo_settings() {

  $types = node_type_get_types();
  $content_type_options = array();
  $terms_optins = array();

  $vocabularies = taxonomy_get_vocabularies();

  foreach ($vocabularies AS $voca) {
    $voca_optins[$voca->vid] = $voca->name;
  }

  foreach ($vocabularies as $vocabula) {

    $terms_tree[$vocabula->vid] = taxonomy_get_tree($vocabula->vid);
    foreach ($terms_tree[$vocabula->vid] as $ter) {

      $perfix = '';

      for ($i = 0; $i < $ter->depth; $i++) {
        $perfix .= '-';
      }

      $terms_optins[$ter->tid] = $perfix . $ter->name;
    }

  }

  $content_type_options[""] = 'All';

  foreach ($types as $type) {
    $content_type_options[$type->type] = $type->name;
  }

  $form['Content_Type']['marker_clusterer_demo_settings_content_type'] = array(
    '#type' => 'select',
    '#title' => t('Content type for boxs layout.'),
    '#default_value' => variable_get('marker_clusterer_demo_settings_content_type', 'stage'),
    '#description' => t('Set the content type to stage.'),
    '#options' => $content_type_options,
  );

  return system_settings_form($form);

}

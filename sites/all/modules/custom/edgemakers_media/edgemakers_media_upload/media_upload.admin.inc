<?php
/**
 * Form builder function for module settings.
 *
 * @return array
 *   - System settings form elements.
 */
function edgemakers_media_upload_settings() {

  $types = node_type_get_types();
  $content_type_options = array();
  $terms_optins = array();

  $vocabularies = taxonomy_get_vocabularies();

  foreach ($vocabularies as $voca) {
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

  foreach ($types as $type) {
    $content_type_options[$type->type] = $type->name;
  }

  $form['Content_Type']['edgemakers_media_content_type'] = array(
    '#type' => 'select',
    '#title' => t('Content type for media.'),
    '#default_value' => variable_get('edgemakers_media_content_type', 'media_for_upload'),
    '#description' => t('Set the content type to media.'),
    '#options' => $content_type_options,
  );

  return system_settings_form($form);

}
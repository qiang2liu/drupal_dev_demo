<?php
function edgemakers_community_settings() {

  $types = node_type_get_types();
  $content_type_options = array();
  foreach ($types as $type) {
    $content_type_options[$type->type] = $type->name;
  }

  $form['types']['edgemakers_community_content_type'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types that will display for Community Page'),
    '#default_value' => variable_get('edgemakers_community_content_type', array()),
    '#description' => t('Set content types for community page.'),
    '#options' => $content_type_options,
  );

  $form['types']['edgemakers_community_comment_type'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Comment Types that will display for Community Page.'),
    '#default_value' => variable_get('edgemakers_community_comment_type', array()),
    '#description' => t('Set comment types for community page.'),
    '#options' => $content_type_options,
  );
  
  $form['num']['edgemakers_community_activity_num'] = array(
    '#type' => 'select',
    '#title' => t('Activity Num that will display for Community Page.'),
    '#default_value' => variable_get('edgemakers_community_activity_num', 5),
    '#description' => t('Set Activity Num for community page.'),
    '#options' => range(0, 50),
  );

  return system_settings_form($form);
}
<?php
/**
 * Override or insert variables into the node template.
 */
function newfteui_preprocess_node(&$vars) {
  $node = $vars['node'];
  if($node->type == 'edgemakers_set') {
    require_once drupal_get_path('module', 'edgemakers_set').'/edgemakers_set.pages.inc';
    $terms = _edgemakers_set_get_terms();
    $types = field_get_items('node', $node, 'field_set_type');
    $type = $types && count($types) > 0 ? $terms[$types[0]['tid']] : '';

    if($type == 'Inspiration' || $type == 'Showcase')
      $type = 'video';
    if($type == 'Image' || $type == 'Text' || $type == 'video' || $type == 'Idea') {
      $vars['display_submitted'] = false;
      $vars['theme_hook_suggestions'][] = 'node__edgemakers_set__'.strtolower($type);
    }
  }
}

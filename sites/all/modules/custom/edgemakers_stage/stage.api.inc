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

          $item = theme_set_item_list($node->term, $node, $stage_id);

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

/**
 * Theme of each category set.
 *
 * @param array $type
 * @param array $item
 */
function theme_set_item_list($type, $item = array(), $stage_id = '') {

  $output = '';

  if (isset($item->nid)) {
    $edit_url = l('Edit',
      'modal/node/' . $item->nid . '/edit/nojs/1',
      array(
        'query' => array(
          'destination' => $_GET["q"],
        ),
        'attributes' => array(
          'class' => array('ctools-use-modal'),
        ),
      )
    );

    switch (strtolower($type->name)) {
      case 'learn module':
        if (isset($item->field_set_image[LANGUAGE_NONE])) {
          $ary_image = array(
            'path' => $item->field_set_image[LANGUAGE_NONE][0]['uri'],
            'attributes' => array(),
          );

          $set_image = theme_image($ary_image);

        }
        $output .= '<li>' . $set_image . l($item->title . '(' . $type->name . ')', 'node/' . $item->nid . '') . '</li>';
        break;
      case '':
        $output .= '<li>' . l($item->title . '(' . $type->name . ')', 'node/' . $item->nid . '') . '</li>';
        break;
      default:
        $output .= '<li>' . l($item->title . '(' . $type->name . ')', 'node/' . $item->nid . '') . '</li>';
        break;
    }
  }

  return $output;

}
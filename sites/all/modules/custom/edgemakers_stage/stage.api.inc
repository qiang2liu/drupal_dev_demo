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

      if ($stage_index) {
        //dpm($stage_index);
        aasort($stage_index, 'location_index');

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
            //$item = l($node->title, 'stage/set/view/' . $node->nid);
            //}
            $sets['items'][] = $item;
          }
        }

        if (count($sets['items'] > 0)) {



          $sets['title'] = '';
          $sets['type'] = 'ul';
          $sets['attributes'] = array();

          $set_list = theme_item_list($sets);

        }
        else {
          drupal_set_message("Set is empty.");
          $set_list = t('Set is empty in stage.');
        }

      }


      $html .= $set_list;

    }

  }

  return $html;

}

function edgemakers_stage_api_set_view_html($set_id = '') {
  if ($set_id) {
    $node = node_load($set_id);


    if($type == 'Image' || $type == 'Text' || $type == 'video') {

    }
  // Get box type by tid.
  if (isset($node->field_set_type[LANGUAGE_NONE])) {
    $node->term = taxonomy_term_load($node->field_set_type[LANGUAGE_NONE][0]['tid']);
  }

  if($node->term->name == 'Inspiration' || $node->term->name == 'Showcase') {
    $type = 'video';
  }
  else {
    $type = $node->term->name;
  }

  switch (strtolower($type)) {
    case 'video with q&a':
      $img = array(
        'path' => drupal_get_path('module', 'edgemakers_stage') . '/images/Video w-QandA Set.png',
      );
      $html = '<div id="buildingSet">' . theme('image', $img) . '</div>';

      return $html;
      break;
    case 'video with comments':
      $img = array(
        'path' => drupal_get_path('module', 'edgemakers_stage') . '/images/Video w-Comments Set.png',
      );
      $html = '<div id="buildingSet">' . theme('image', $img) . '</div>';

      return $html;
      break;
    case 'survey & assessment':
      $html = '<div id="buildingSet"><h3>This is a survey & assessment set, will be developped later</h3></div>';
      return $html;
      break;
    case 'topic page':

      $html = '<div id="buildingSet"><h3>This is a topic set, will be developped later</h3></div>';

      return $html;
      break;
    case 'idea':
      $img = array(
        'path' => drupal_get_path('module', 'edgemakers_stage') . '/images/Mural.ly-work-area.png',
      );
      $html = '<div id="buildingSet">' . theme('image', $img) . '</div>';

      return $html;
      break;
    default:
      return drupal_render(node_view($node, 'full'));
  }

    return drupal_render(node_view($node, 'full'));
    //print drupal_render(node_view($node, 'full'));
  }
}

/**
 * Sort array by value key.
 *
 * @link http://stackoverflow.com/questions/2699086/sort-multidimensional-array-by-value-2
 *
 * @param array $array
 * @param array $key
 */
function aasort (&$array, $key) {
  $sorter=array();
  $ret=array();
  reset($array);
  foreach ($array as $ii => $va) {
    $sorter[$ii]=$va[$key];
  }
  asort($sorter);
  foreach ($sorter as $ii => $va) {
    $ret[$ii]=$array[$ii];
  }
  $array=$ret;
}

//aasort($your_array,"order");
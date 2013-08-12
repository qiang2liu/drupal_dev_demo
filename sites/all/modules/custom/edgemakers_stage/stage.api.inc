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
    $html .= '<div id="stage-title" style="display: none;"><h2>' . $stage->title . '</h2></div>';

    if (isset($stage->box_index_data[LANGUAGE_NONE])) {

      $stage_index = unserialize($stage->box_index_data[LANGUAGE_NONE][0]['value']);

      if ($stage_index) {
        //dpm($stage_index);
        aasort($stage_index, 'location_index');

        foreach ($stage_index AS $set) {
          if($set['set_id']) {
            $node = node_load($set['set_id']);

            if ($node->nid) {
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
        }

        if (count($sets['items'] > 0)) {

          $sets['title'] = '';
          $sets['type'] = 'ul';
          $sets['attributes'] = array();

          $set_list = theme_item_list($sets);

        }
        else {
          //drupal_set_message("Set is empty.");
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
    // Get box type by tid.
    if (isset($node->field_set_type[LANGUAGE_NONE])) {
      $node->term = taxonomy_term_load($node->field_set_type[LANGUAGE_NONE][0]['tid']);
    }
    $term = $node->term->name;
    if($term == 'Inspiration' || $term == 'Showcase' || $term == 'Video') {
      $type = 'video';
    } else {
      $type = $term;
    }
    switch (strtolower($type)) {
      case 'survey & assessment':
        return drupal_render(node_view($node, 'full'));
      case 'topic page':
        $html = '<div id="buildingSet"><h3>This is a topic set, will be developed later</h3></div>';
        return $html;
        break;
      case 'idea':
        $img = array(
          'path' => drupal_get_path('module', 'edgemakers_stage') . '/images/Mural.ly-work-area.png',
        );
        $html = '<div id="buildingSet">' . theme('image', $img) . '</div>';
        return $html;
        break;
      case 'image':
      case 'text':
      case 'video':
      case 'document':
        return drupal_render(node_view($node, 'full'));
      case 'video with comments':
      case 'video with q&a':
        $comments = comment_node_page_additions($node);
        if(isset($_GET['page'])) {
          unset($comments['comment_form']);
          $output = drupal_render($comments);
          $output .= '<script>Drupal.attachBehaviors();</script>';
          $commands = array();
          $commands[] = ajax_command_html('#comments-list' , $output);
          $page = array('#type' => 'ajax', '#commands' => $commands);
          ajax_deliver($page);
          return;
        } else {
          $node_view = node_view($node);
          $node_view['comments'] = $comments;
          return drupal_render($node_view);
        }
      default:
        $html = '<div id="buildingSet"><h3>This is a ' . $term . ' set, will be developed later</h3></div>';
        return $html;
    }
    return drupal_render(node_view($node, 'full'));
  }
}

function _get_youtube_video_data($node) {

  $urls = field_get_items('node', $node, 'field_set_url');
  $url = $urls && count($urls) > 0 ? $urls[0]['url'] : '';
  $ytid = _youtube_parser($url);

  if ($ytid) {
    drupal_set_message("_get_youtube_video_info " . $ytid);
    $youtube_info = _get_youtube_video_info($ytid);
    return $youtube_info;
  }

  return false;

}

function _youtube_parser($url) {
	preg_match("#(?<=v=)[a-zA-Z0-9-]+(?=&)|(?<=v\/)[^&\n]+|(?<=v=)[^&\n]+|(?<=youtu.be/)[^&\n]+#", $url, $matches);
	if(is_array($matches) && count($matches) > 0)
		return $matches[0];
	return false;
}

function _get_youtube_video_info($id) {

  $path = 'http://gdata.youtube.com/feeds/api/videos/' . $id;

  $query = array(
    'v' => '2',
    'alt' => 'jsonc',
  );

  $url = url($path, array('query' => $query));
  $result = drupal_http_request($url);
  $data = json_decode($result->data);

  drupal_set_message($url . 'Youtube data is:<pre>' . print_r($data, TRUE) . '</pre>');

  return $data;
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
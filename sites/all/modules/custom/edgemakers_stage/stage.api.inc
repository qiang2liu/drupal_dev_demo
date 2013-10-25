<?php
/**
 * @file
 * Data api of stage.
 */

/**
 * Export the stage json data.
 */
function edgemakers_stage_api_list_json() {
  $type = variable_get('edgemakers_stage_content_type', 'stage');
  $nodes = node_load_multiple(array(), array('type' => $type));

  foreach ($nodes as $node) {
    $node->defualt_image = theme('image',
      array(
        'path' => drupal_get_path('module', 'edgemakers_stage') . '/images/stageDefault.png',
      )
    );
    $json[] = $node;
  }

  drupal_json_output($json);

}

/**
 * Ajax link callback.
 *
 * @param array $page_callback_result
 *   - Drupal output elements.
 */
function edgemakers_stage_ajax_callback($page_callback_result) {
  // Only render content.
  print $page_callback_result;
  // Perform end-of-request tasks.
  drupal_page_footer();
}

/**
 * Return set list data by stage id.
 *
 * @param int $stage_id
 *   - Stage id.
 */
function edgemakers_stage_api_set_list_html($stage_id) {

  $html = '';

  if ($stage_id) {
    $stage = node_load($stage_id);
    $html .= '<div id="stage-title" style="display: none;"><h2>' . $stage->title . '</h2></div>';
    if (user_access('view teacher notes')&& isset($stage->field_teacher_notes[LANGUAGE_NONE])) {
      $notes = $stage->field_teacher_notes[LANGUAGE_NONE];
      $note = ($notes && count($notes > 0))?$notes[0]['value'] : '';
    }
    else {
      $note = '';
    }
    $html .= '<div id="stage-notes" style="display: none;">' . $note . '</div>';

    if (isset($stage->box_index_data[LANGUAGE_NONE])) {

      $stage_index = unserialize($stage->box_index_data[LANGUAGE_NONE][0]['value']);

      // Remove lost data.
      $sets = array();
      foreach ($stage_index as $key => $set_index) {
        $set = node_load($set_index['set_id']);
        if (!$set) {
          unset($stage_index[$key]);
        }
        else {
          $sets[$set_index['set_id']] = $set;
        }
      }

      if ($stage_index) {

        aasort($stage_index, 'location_index');

        $count = count($stage_index);

        $i = 0;

        foreach ($stage_index as $key => $set) {

          if ($set['set_id']) {

            $node = $sets[$set['set_id']];

            if ($node->nid) {

              // Get prev/next.
              if (($key - 1) < 0) {
                $prev = $stage_index[$count - 1];
              }
              else {
                $prev = $stage_index[$key - 1];
              }

              if (($key + 1) > ($count - 1)) {
                $next = $stage_index[0];
              }
              else {
                $next = $stage_index[$key + 1];
              }

              // Get box type by tid.
              if (isset($node->field_set_type[LANGUAGE_NONE])) {
                $node->term = taxonomy_term_load($node->field_set_type[LANGUAGE_NONE][0]['tid']);
              }

              $item = theme('set_item', array('item' => $node));

              $sets['items'][$i]['data'] = $item;
              $sets['items'][$i]['prev'] = $prev['set_id'];
              $sets['items'][$i]['next'] = $next['set_id'];
              $sets['items'][$i]['current'] = $set['set_id'];

              $prev_node = node_load($prev['set_id']);
              $type = 'prev_normal';
              if (isset($prev_node->field_set_type[LANGUAGE_NONE])) {
                $term = taxonomy_term_load($prev_node->field_set_type[LANGUAGE_NONE][0]['tid']);
                if($term) $type = strtolower(str_replace(array(' ', '&'), array('_', ''), $term->name).'');
              }
              $sets['items'][$i]['prevtype'] = $type;

              $next_node = node_load($next['set_id']);
              $type = 'next_normal';
              if (isset($next_node->field_set_type[LANGUAGE_NONE])) {
                $term = taxonomy_term_load($next_node->field_set_type[LANGUAGE_NONE][0]['tid']);
                if($term) $type = strtolower(str_replace(array(' ', '&'), array('_', ''), $term->name).'');
              }
              $sets['items'][$i]['nexttype'] = $type;

              $i++;

            }
          }
        }

        if (count($sets['items'] > 0)) {

          $sets['title'] = '';
          $sets['type'] = 'ul';
          $sets['attributes'] = array();

          $set_list = theme('item_list', $sets);

        }
        else {
          $set_list = t('Set is empty in stage.');
        }

      }

      $html .= $set_list;

    }

  }

  return $html;

}

/**
 * Stage list html.
 *
 * @param int $set_id
 *   - Set id.
 *
 * @return string
 *   - HTML code.
 */
function edgemakers_stage_api_set_view_html($set_id = '') {

  if ($set_id) {

    $node = node_load($set_id);
    // Get box type by tid.
    if (isset($node->field_set_type[LANGUAGE_NONE])) {
      $node->term = taxonomy_term_load($node->field_set_type[LANGUAGE_NONE][0]['tid']);
    }
    $term = $node->term->name;

    if (user_access('view teacher notes')) {
      $notes = $node->field_teacher_notes[LANGUAGE_NONE];
      $note = ($notes && count($notes > 0)) ? $notes[0]['value'] : '';
    }
    else {
      $note = '';
    }
    $note = '<div id="set-notes" style="display: none;">' . $note . '</div>';
    if ($term == 'Inspiration' || $term == 'Showcase' || $term == 'Video') {
      $type = 'video';
    }
    else {
      $type = $term;
    }
    switch (strtolower($type)) {
      case 'mural':
        $img = array(
          'path' => drupal_get_path('module', 'edgemakers_stage') . '/images/Mural.ly-work-area.png',
        );
        $html = '<div id="buildingSet">' . theme('image', $img) . '</div>' . $note;
        return $html;

      case 'survey & assessment':
      case 'topic page':
      case 'slideshow':
      case 'image':
      case 'text':
      case 'video':
      case 'document':
        return drupal_render(node_view($node, 'full')) . $note;

      case 'video with comments':
      case 'video with q&a':
        $comments = comment_node_page_additions($node);
        if (isset($_GET['page'])) {
          unset($comments['comment_form']);
          $output = drupal_render($comments);
          $output .= '<script>Drupal.attachBehaviors();</script>';
          $commands = array();
          $commands[] = ajax_command_html('#comments-list', $output);
          $page = array('#type' => 'ajax', '#commands' => $commands);
          ajax_deliver($page);
          return;
        }
        else {
          $node_view = node_view($node);
          $node_view['comments'] = $comments;
          return drupal_render($node_view) . $note;
        }
        break;

      default:
        $html = '<div id="buildingSet"><h3>This is a ' . $term . ' set, will be developed later</h3></div>' . $note;
        return $html;

    }

    return drupal_render(node_view($node, 'full')) . $note;

  }
}

/**
 * Get youtube data by node.
 *
 * @param array $node
 *   - Node data.
 *
 * @return string
 *   - Youtube data.
 */
function _get_youtube_video_data($node) {

  $urls = field_get_items('node', $node, 'field_set_url');
  $url = $urls && count($urls) > 0 ? $urls[0]['url'] : '';
  $ytid = _youtube_parser($url);

  if ($ytid) {
    $youtube_info = _get_youtube_video_info($ytid);
    return $youtube_info;
  }

  return '';

}

/**
 * Parse youtube url.
 *
 * @param string $url
 *   - Youtube url.
 *
 * @return string
 *   - Parse data.
 */
function _youtube_parser($url) {
  preg_match("#(?<=v=)[a-zA-Z0-9-]+(?=&)|(?<=v\/)[^&\n]+|(?<=v=)[^&\n]+|(?<=youtu.be/)[^&\n]+#", $url, $matches);
  if (is_array($matches) && count($matches) > 0) {
    return $matches[0];
  }
  return '';
}

/**
 * Get yotuube video info by video id.
 *
 * @param string $id
 *   - Yotubue video id.
 *
 * @return mixed
 *   - Youtube data.
 */
function _get_youtube_video_info($id) {

  $path = 'http://gdata.youtube.com/feeds/api/videos/' . $id;

  $query = array(
    'v' => '2',
    'alt' => 'jsonc',
  );

  $url = url($path, array('query' => $query));
  $result = drupal_http_request($url);
  $data = json_decode($result->data);

  return $data;
}

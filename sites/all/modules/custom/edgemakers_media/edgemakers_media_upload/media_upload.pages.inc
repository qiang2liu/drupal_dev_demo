<?php

/**
 * Return media list on gallry pane.
 *
 * @param string $type
 *   - Search keyword.
 *
 * @param int $page
 *   - Current page.
 *
 * @param string $keyword
 *   - Search keyword.
 *
 * @return string
 *   - HTML code.
 */
function edgemakers_media_list_on_gallery($type = '', $page = 0, $keyword = '') {

  global $user;
  $limit = 4;

  // Get all data.
  if (strtolower($type) == 'media') {
    $limit = 12;
  }

  $start = $page * $limit;

  // Default sort by.
  $orderby[0]['name'] = 'nid';
  $orderby[0]['direction'] = 'DESC';


  if ($keyword) {
    $media_list = _edgemakers_media_upload_search_execute_result($type, $keyword, $page, $limit, array(), $orderby);
  }
  else {
    $media_list = edgemakers_media_list('', $type, $start, $limit, array(), $orderby);
  }

  if (count($media_list) == 0) {
//     return t('There is no !type available', array('!type' => $type));
    return '';
  }

  arsort($media_list);

  $html = '<div class="media item-studio">';

  $i = 1;
  foreach ($media_list as $node) {
    $class = '';
    if ($i == 1) {
      $class = 'first';
    }

    if ($i == count($media_list)) {
      $class = 'last';
    }

    $video_class = '';

    $node_thumb = _get_media_thumb($node);

    $html .= '<li class="' . $class . '">';

    // Cover.
    $node_user = user_load($node->uid);
    $node_field_first_name = field_get_items('user', $node_user, 'field_firstname');
    $node_first_name = $node_field_first_name && count($node_field_first_name) > 0 ? $node_field_first_name[0]['value'] : '';
    $node_field_last_name = field_get_items('user', $node_user, 'field_lastname');
    $node_last_name = $node_field_last_name && count($node_field_last_name) > 0 ? $node_field_last_name[0]['value'] : '';
    $node_username = $node_first_name . ' ' . $node_last_name;

    // Media type.
    $media_type_field = field_get_items('node', $node, 'field_media_type');
    $media_type_tid = $media_type_field && count($media_type_field) > 0 ? $media_type_field[0]['tid'] : '';
    $media_type_term = taxonomy_term_load($media_type_tid);
    $media_type_name = $media_type_term->name;
    if (!$media_type_name) {
      $media_type_name = 'Media';
    }

    $html .= '<div class="set-cover">';
    $html .= '<h5>' . $node->title . '</h5>
                <p class="inspiration">' . $node_username . '</p>
                <p class="' . strtolower($media_type_name) . '">' . $media_type_name . '</p>
              </div>';


    if (
      (strpos($node_thumb, 'img.youtube.com') !== false) OR
      (strpos($node_thumb, 'iconAudioDefault') !== false) OR
      (strpos($node_thumb, 'iconDocsDefault') !== false )
    ) {
      $video_class = ' video ';
      $media_thumb = theme('image', array('path' => $node_thumb));
    }
    else {
      // edgemakers_studio_gallery_list should "Scale and crop 156x106"
      // $media_thumb = theme('image_style', array('path' => $node_thumb, 'style_name' => 'edgemakers_studio_gallery_list'));
      $media_thumb = theme('image', array('path' => $node_thumb));
    }

    $html .= '<span class="mediathumb ' . $video_class . $node->title . ' ">';
    $html .=  $media_thumb;
    $html .= '</span>';

    $edit_url = l(t('<span></span>'), 'node/' . $node->nid,
      array(
        'html' => TRUE,
        'attributes' => array(
          'nid' => $node->nid,
          'class' => array('studio-media-list-item-link'),
          'title' => $node->title,
        ),
      )
    );

    $html .= $edit_url;

    $html .= '</li>';

    $i++;

  }

  $html .= '</div>';

  return $html;

}

/**
 * Return media list on studio pane.
 *
 * @param int $pager
 *   - Current page.
 *
 * @return string
 *   - HTML code.
 */
function edgemakers_media_list_on_studio($pager = 0) {

  global $user;
  $limit = 8;
  $start = $pager * $limit;
  $video_class = '';

  $html = '';

  if ($user->uid !== 0) {

    $orderby[0]['name'] = 'nid';
    $orderby[0]['direction'] = 'DESC';

    $my_media_nodes = edgemakers_media_list($user->uid, '', $start, $limit, array(), $orderby);

    if (count($my_media_nodes) == 0) {
//       return t('There is no media available for you.');
      return '';
    }
    else {
      $html .= '<div class="media item-studio">';
    }

    arsort($my_media_nodes);
    $i = 1;

    foreach ($my_media_nodes as $node) {
      $class = '';
      if ($i == 1) {
        $class = 'first';
      }

      if ($i == count($my_media_nodes)) {
        $class = 'last';
      }

      $node_thumb = _get_media_thumb($node);

      $html .= '<li class="' . $class . '">';

      // Cover.
      $node_user = user_load($node->uid);
      $node_field_first_name = field_get_items('user', $node_user, 'field_firstname');
      $node_first_name = $node_field_first_name && count($node_field_first_name) > 0 ? $node_field_first_name[0]['value'] : '';
      $node_field_last_name = field_get_items('user', $node_user, 'field_lastname');
      $node_last_name = $node_field_last_name && count($node_field_last_name) > 0 ? $node_field_last_name[0]['value'] : '';
      $node_username = $node_first_name . ' ' . $node_last_name;

      // Media type.
      $media_type_field = field_get_items('node', $node, 'field_media_type');
      $media_type_tid = $media_type_field && count($media_type_field) > 0 ? $media_type_field[0]['tid'] : '';
      $media_type_term = taxonomy_term_load($media_type_tid);
      $media_type_name = isset($media_type_term->name)?$media_type_term->name : '';
      if (!$media_type_name) {
        $media_type_name = 'Media';
      }

      $html .= '<div class="set-cover">
                  <h5>' . $node->title . '</h5>
                  <p class="inspiration">' . $node_username . '</p>
                  <p class="' . strtolower($media_type_name) . '">' . $media_type_name . '</p>
                </div>';

      if (
        (strpos($node_thumb, 'img.youtube.com') !== false) OR
        (strpos($node_thumb, 'iconAudioDefault') !== false) OR
        (strpos($node_thumb, 'iconDocsDefault') !== false )
      ) {
        $video_class = ' video ';
        $media_thumb = theme('image', array('path' => $node_thumb));
      }
      else {
        // edgemakers_studio_gallery_list should "Scale and crop 156x106"
        // $media_thumb = theme('image_style', array('path' => $node_thumb, 'style_name' => 'edgemakers_studio_gallery_list'));
        $media_thumb = theme('image', array('path' => $node_thumb));
      }

      $html .= '<span class="mediathumb '. $video_class . $node->title . ' ">'
                . $media_thumb .
              '</span>';

      $view_url = l(t('<span class =""></span>'), 'node/' . $node->nid,
        array(
          'html' => TRUE,
          'attributes' => array(
            'nid' => $node->nid,
            'class' => array('studio-media-list-item-link'),
            'title' => $node->title,
            'position' => 'studio',
          ),
        )
      );

      $html .= $view_url;

      $html .= '</li>';

      $i++;
    }

    $html .= '</div>';

  }

  return $html;
}

/**
 * Show media list on toolbar.
 *
 * @param int $limit
 *   - Limit in list.
 *
 * @return string
 *   - HTML code.
 */
function edgemakers_my_media_list_on_toolbar($limit = 5) {

  global $user;

  $my_media_nodes = array();
  $html = '<div class="toolbar-item media">';

  if ($user->uid !== 0) {
    $my_media_nodes = edgemakers_media_list($user->uid, '', 0, $limit);
    arsort($my_media_nodes);
    $i = 0;

    foreach ($my_media_nodes as $node) {
      if ($i < $limit) {

        $media_item['items'][$i]['data'] = l($node->title,
          'node/' . $node->nid,
          array(
            'attributes' => array(
              'id' => 'media-node-' . $node->nid,
            ),
          )
        );

        $media_item['items'][$i]['class'][] = 'edgemakers-media-item';

        $i++;
      }
    }
    if (count($my_media_nodes) > 0) {

      $html .= '<h4 class="has-child">Media<em></em></h4>';

      $media_item['title'] = '';
      $media_item['type'] = 'ul';
      $media_item['attributes'] = array('id' => 'media-list', 'class' => 'media-video');

      $media_html = theme('item_list', $media_item);
      $html .= $media_html;
    }


  }

  if (count($my_media_nodes) <= 0) {
    $html .= '<h4 class="has-child">Media</h4>';
  }

  $html .= '</div>';

  return $html;

}

/**
 * Return media list data by uid.
 *
 * @param int $limit
 *   - Limit in list.
 *
 * @return string
 *   - HTML code.
 */
function edgemakers_media_list_on_toolbar($limit = 5) {

  global $user;
  $nodes = array();

  $content_type = variable_get('edgemakers_media_content_type', 'media_for_upload');

  $html = '<div class="toolbar-item media">';

  if ($user->uid !== 0) {

    $media_items = array('items' => array());
    $nodes = edgemakers_media_get_my_media($user->uid, $content_type);
    foreach ($nodes as $node) {
      $media_items['items'][] = array(
        'data' => l($node->title,
          'node/' . $node->nid,
          array(
            'html' => TRUE,
            'attributes' => array(
              'id' => 'media-node-' . $node->nid,
              'title' => $node->title,
            ),
          )
        ),
        'class' => array('edgemakers-media-item'),
      );
    }

    if (count($nodes) > 0) {

      $html .= '<h4 class="has-child">Media<em></em></h4>';

      $media_items['title'] = '';
      $media_items['type'] = 'ul';
      $media_items['attributes'] = array('id' => 'media-list', 'class' => 'media-video');

      $media_html = theme('item_list', $media_items);
      $html .= $media_html;
    }
    else {
      $html .= '<h4 class="has-child">Media</h4>';
    }

  }
  else {
    $html .= '<h4 class="has-child">Media</h4>';
  }

  $html .= '</div>';

  return $html;

}

/**
 * Media view html function.
 *
 * @param int $nid
 *   - Node id;
 *
 * @return Ambigous
 *   - <The, void, string, A, boolean>|string.
 */
function edgemakers_media_view_html($nid, $position) {
  if ($nid) {
    $node = node_load($nid);
    $node->from_position = $position;
    return drupal_render(node_view($node, 'full'));
  }
  return 'Media page building.';
}

/**
 * Get my media in studio.
 *
 * @param int $uid
 *   - Account uid.
 *
 * @param string $content_type
 *   - Media type name.
 *
 * @param int $limit
 *   - Limit in list.
 *
 * @return Ambigous
 *   - <multitype:, An>
 */
function edgemakers_media_get_my_media($uid, $content_type, $limit = 5) {
  $query = db_select('node', 'n');

  $nodes = array();
  $nids = $query->condition('n.type', $content_type)->condition('n.status', NODE_PUBLISHED)->condition('n.uid', $uid)->fields('n', array('nid'))->orderBy('n.changed', 'DESC')->addTag('node_access')->range(0, $limit)->execute()->fetchCol();

  if ($nids) {
    $nodes = node_load_multiple($nids);
  }

  return $nodes;

}

/**
 * Ajax link callback.
 *
 * @param array $page_callback_result
 *   - Ajax return elements.
 *
 * @return string
 *   - Ajax output string, maybe json format.
 */
function edgemakers_media_ajax_callback($page_callback_result) {
  // Only render content.
  print $page_callback_result;
  // Perform end-of-request tasks.
  drupal_page_footer();
}

/**
 * Custome search by search module, but not hook_search_execute().
 *
 * @param string $type
 *   - Media type name.
 *
 * @param string $keys
 *   - Search keyword.
 *
 * @param int $page
 *   - Current page.
 *
 * @param int $pager
 *   - Limit in page.
 *
 * @return array
 *   - Search node data.
 */
function _edgemakers_media_upload_search_execute_result($type = '', $keys = '', $page = 0, $pager = 5, $conditions = array(), $orderby = array()) {

  $start = $page * $pager;
  $keys = trim($keys);

  if ($keys) {

    $query = db_select('search_index', 'i')
      ->condition('i.type', 'node');

    // Full text search, copy from search.extender.inc.
    $query->innerJoin('search_dataset', 'd', 'i.sid = d.sid  AND i.type = d.type');

    // Full text search by drupal default search.
//     $query->condition('d.data', '%' . strtolower($keys) . '%', 'LIKE');

    // Keys is multi and split by "space".
//     $keys_array = explode(' ', $keys);
//     $orkeys = db_or();
//     foreach ($keys_array as $key) {
//       $orkeys->condition('i.word', '%' . strtolower($key) . '%', 'LIKE');
//     }
//     $query->condition($orkeys);

    // Unique sid.
    $query->AddExpression('distinct i.sid', 'sid_node');

    $query->range($start, $pager);

    $query->join('node', 'n', 'n.nid = i.sid');
    $query->condition('n.type', 'media_for_upload');
    $query->condition('n.status', 1);

    if ($conditions) {
      foreach ($conditions AS $c) {
        foreach ($c AS $v) {
          $query->condition($v['field'], $v['value'], $v['operator']);
        }
//
      }
    }

    if ($orderby) {
      foreach ($orderby AS $o) {
        $query->orderBy($o['name'], $o['direction']);
      }
    }

    // Search by media type.
    if ($type && strtolower($type) !== 'media') {
      $media_type_tid = _get_media_tid($type);
      $query->innerJoin('field_data_field_media_type', 'media_type', 'n.nid = media_type.entity_id');
      $query->condition('media_type.field_media_type_tid', $media_type_tid);
    }

    // Just return "share to gallery" media.
    $query->innerJoin('field_data_field_share_to_gallery', 'field_share', 'n.nid = field_share.entity_id');
    $query->condition('field_share.field_share_to_gallery_value', '1');

    // The numeric score of the word, higher being more important.
    $query->orderBy('i.score', 'ASC');

    $query->orderBy('n.title', 'ASC');
    $query->orderBy('i.sid', 'DESC');
    $query->orderBy('n.nid', 'DESC');

    // Join  field_tags table and term table.
    $query->leftJoin('field_data_field_tags', 'field_tags', 'n.nid = field_tags.entity_id');
    $query->leftJoin('taxonomy_term_data', 'term', 'field_tags.field_tags_tid = term.tid');
    // Order by tags by term ASC.
    $query->orderBy('term.name', 'ASC');

    // Key search by normal SQL.
    $orkeys = db_or();
    $orkeys->condition('n.title', '%' . strtolower($keys) . '%', 'LIKE');
    $orkeys->condition('term.name', '%' . strtolower($keys) . '%', 'LIKE');

    $query->condition($orkeys);

    $find = $query->execute();

//     print('find<pre>'.print_r($find,TRUE).'</pre>');

    $results = array();

    foreach ($find as $item) {
      // Render the node.
      $node = node_load($item->sid_node);
      $results[] = $node;
    }

    return $results;

  }

  return '';

}

/**
 * page callback
*/
function edgemakers_media_show_nav($type = 'my', $nid = '', $nav = 'prev', $keywords = '') {

  global $user;
  $json = '';

  $nodes = array();
  $limit = 1;
  $start = 0;

  switch ($nav) {
    case 'prev':
      $operator = '>';
      // Sort by Alphabetical on Date[nid].
      $orderby[0]['name'] = 'nid';
      $orderby[0]['direction'] = 'ASC';
      break;

    case 'next':
      $operator = '<';
      // Sort by Alphabetical on Date[nid].
      $orderby[0]['name'] = 'nid';
      $orderby[0]['direction'] = 'DESC';
      break;

    default:
      $operator = '=';
      break;
  }

  $conditions['property'][] = array(
    'field' => 'nid',
    'column' => 'nid',
    'value' => $nid,
    'operator' => $operator,
  );

//   print($user->uid . ' => <pre>'.print_r($conditions,TRUE).'</pre>');
  switch ($type) {
    case 'studio':
      $nodes = edgemakers_media_list($user->uid, '', $start, $limit, $conditions, $orderby);
      break;

    case 'gallery':
      if ($keywords) {
        $nodes = _edgemakers_media_upload_search_execute_result('media', $keywords, $page, $limit, $conditions, $orderby);
      }
      else {
        $nodes = edgemakers_media_list('', 'media', $start, $limit, $conditions, $orderby);
      }
//       $nodes = edgemakers_media_list(0, '', $start, $limit, $conditions);
      break;
  }

  foreach ($nodes as $node) {
    $json[] = $node;
  }

  drupal_json_output($json);
}


/**
 * Get media term tid by type name.
 *
 * @param string $type
 *   - Media type name.
 *
 * @return string
 *   - Term tid.
 */
function _get_media_tid($type) {
  $media_type_tid = '';

  $field_name = 'field_media_type';
  $info = field_info_field($field_name);
  $vocab_keys = array();
  foreach ($info['settings']['allowed_values'] as $item) {
    $vocab_keys[] = $item['vocabulary'];
    $vocab_machine_name = $item['vocabulary'];
  }

  switch ($type) {
    case 'video':
      $terms = taxonomy_get_term_by_name('Video', $vocab_machine_name);
      break;

    case 'image':
      $terms = taxonomy_get_term_by_name('Image', $vocab_machine_name);
      break;

    case 'audio':
      $terms = taxonomy_get_term_by_name('Audio', $vocab_machine_name);
      break;

    case 'docs':
      $terms = taxonomy_get_term_by_name('Docs', $vocab_machine_name);
      break;

  }

  foreach ($terms as $term) {
    $media_type_tid = $term->tid;
  }

  return $media_type_tid;

}

/**
 * Get media list function as same get node_load_multiple.
 *
 * @param string $uid
 *   - Account uid.
 *
 * @param string $media_type
 *   - Media type.
 *
 * @param int $start
 *   - List start.
 *
 * @param int $limit
 *   - List limit.
 *
 * @return Ambigous
 *   - <multitype:, An>
 */
function edgemakers_media_list($uid = '', $media_type = '', $start = 0, $limit = 5, $conditions = array(), $sortby = array()) {

  $content_type = variable_get('edgemakers_media_content_type', 'media_for_upload');
  $media_nodes = array();

  // $query = new EntityFieldQuery();

  if ($conditions) {

    $query = new EntityFieldQuery();

    foreach ($conditions AS $con_key => $con_arry) {
      $query_condition_field = $con_key . 'Condition';
      if ($con_key == 'field') {
        foreach ($con_arry AS $con) {
          $query->fieldCondition($con['field'], $con['column'], $con['value'], $con['operator']);
        }
      } else {
        foreach ($con_arry AS $con) {
          $query->{$query_condition_field}($con['column'], $con['value'], $con['operator']);
        }
      }
    }
  } else {
    $query = new EntityFieldQuery();
  }

  $query->entityCondition('entity_type', 'node')
    ->addTag('efq_debug')
    ->propertyCondition('status', 1)
    ->propertyCondition('type', array($content_type))
    ->range($start, $limit);

  if ($uid) {
    $query->propertyCondition('uid', $uid);
  }

  if ($media_type) {

    // Query media type.
    if ($media_type !== 'media') {
      $media_type_tid = _get_media_tid($media_type);
      $query->fieldCondition('field_media_type', 'tid', $media_type_tid);
    }

    // Query condition is share to gallery.
    $query->fieldCondition('field_share_to_gallery', 'value', '1');
  }

  foreach ($sortby AS $sort) {
    $query->propertyOrderBy($sort['name'], ($sort['direction']) ? $sort['direction'] : 'DESC');
  }

  $result = $query->execute();

  if (!empty($result['node'])) {
    $media_nodes = node_load_multiple(array_keys($result['node']), '', TRUE);
  }

  return $media_nodes;

}

/**
 * Get the media thumb by node.
 *
 * @param array $node
 *   - Node data.
 *
 * @return string
 *   - HTML code.
 */
function _get_media_thumb($node) {

  $thumb_url = '';

  $field_media_url = field_get_items('node', $node, 'field_media_url');
  $media_url = $field_media_url && count($field_media_url) > 0 ? $field_media_url[0]['value'] : '';

  module_load_include('inc', 'edgemakers_stage', 'stage.api');
  $youtube_id = _youtube_parser($media_url);

  if ($youtube_id) {
    $thumb_url = 'http://img.youtube.com/vi/' . $youtube_id . '/0.jpg';
  }
  else {

    $media_type_field = field_get_items('node', $node, 'field_media_type');
    $media_type_tid = $media_type_field && count($media_type_field) > 0 ? $media_type_field[0]['tid'] : '';
    $media_type_term = taxonomy_term_load($media_type_tid);
    $media_type_name = isset($media_type_term->name)?$media_type_term->name : '';

    switch (strtolower($media_type_name)) {
      case 'image':
        if (isset($node->field_media_upload[LANGUAGE_NONE])) {
          $thumb_url = $node->field_media_upload[LANGUAGE_NONE][0]['uri'];
        }
        else {
          $thumb_url = drupal_get_path('module', 'edgemakers_media_upload') . '/images/iconImageDefault.png';
        }
        break;

      case 'audio':
        $thumb_url = drupal_get_path('module', 'edgemakers_media_upload') . '/images/iconAudioDefault.png';
        break;

      case 'docs':
        $thumb_url = drupal_get_path('module', 'edgemakers_media_upload') . '/images/iconDocsDefault.png';
        break;

      default:
        $thumb_url = $media_url;
        break;

    }

  }

  return $thumb_url;
}

/* gets the data from a URL */
function _get_data_curl($url) {
	$ch = curl_init();
	$timeout = 5;
	curl_setopt($ch, CURLOPT_URL, $url);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, $timeout);
	$data = curl_exec($ch);
	curl_close($ch);
	return $data;
}

/**
 * Create temp file from url.
 *
 * @param array $file
 *   - File info.
 *
 * @return string
 *   - Tmpe file name.
 */
function _create_tmp_download_file($file) {
  $tmp_dir = file_directory_temp();

  $tmp_file = pathinfo($file->filename);
  $tmp_file_name = $tmp_file['filename'] . round(microtime(true)*1000) . '.' . $tmp_file['extension'];
  $tmp_full_file_name = $tmp_dir . '/' . $tmp_file_name;

  // Get file content from url;
  $file_url = file_create_url($file->uri);
  $content =  _get_data_curl($file_url);
  watchdog('Debug', 'Get content from url: ' . $file_url . '<pre>' . print_r($file_url, TRUE) . '</pre>');

// print($tmp_file_name);
  $fh = fopen($tmp_full_file_name, 'w') or die("can't open file");
  fwrite($fh, $content);
  fclose($fh);

  return $tmp_file_name;

}

/**
 * Download file by fid.
 *
 * @param int $fid
 *   - File id.
 */
function edgemakers_media_upload_download($fid = '') {

  if ($fid) {

    $file = file_load($fid);
    $download_file = file_directory_temp() .'/'. _create_tmp_download_file($file);

//     $file_url = file_create_url($file->uri);
    watchdog('Debug', 'file info: ' . $download_file . '<pre>' . print_r($file, TRUE) . '</pre>');

    if (file_exists($download_file)) {
      header('Content-Description: File Transfer');
      header('Content-Type: application/octet-stream');
      header('Content-Disposition: attachment; filename='.basename($file->filename));
      header('Content-Transfer-Encoding: binary');
      header('Expires: 0');
      header('Cache-Control: must-revalidate');
      header('Pragma: public');
      header('Content-Length: ' . filesize($download_file));
      ob_clean();
      flush();
      readfile($download_file);
      exit;
    }

    exit;

    $tmp_file = pathinfo($file->filename);

    switch($tmp_file['extension']){
      case 'xls':
        $mimeType = 'application/vnd.ms-excel';
        break;

      case 'xlsx':
        $mimeType = 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet';
        break;

      default:
        $mimeType = $file->filemime;
        break;

    }
//  echo $mimeType;
    header('Content-Description: File Transfer');
    header('Content-Type: ' . $mimeType);
    header('Content-Disposition: attachment; filename='.basename($download_file));
    header('Content-Transfer-Encoding: binary');
    header('Expires: 0');
    header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
    header('Pragma: public');
    header('Content-Length: ' . $file->filesize);
    ob_clean();
    flush();
    readfile(file_directory_temp() . $download_file);
    exit;


    header("Pragma: public");
    header("Expires: 0");
    header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
    header("Content-Type: application/force-download");
    header("Content-Type: application/octet-stream");
    header("Content-Type: application/download");
    header("Content-Type: $file->filemime");
    header("Content-Disposition: attachment;filename=".basename($download_file));
    header("Content-Transfer-Encoding: binary ");
    header("Content-Length: " . $file->filesize);
//     ob_clean();
//     flush();
//     readfile($download_file);

    exit;
  }

  exit;
}
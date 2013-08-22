<?php

/**
 *
 * @param int $uid
 *   user id
 * @param string $musername
 *   mural username
 * @param string $mroomid
 *   mural user room id
 *
 * @return html string
 *   the user's own mural lists
 */
function get_myideas_shareideas($uid, $musername, $mroomid) {

dpm($uid . $musername . $mroomid);
  $myideas_list = array();
  $shareideas_list = array();
  $the_muralid_array = array();
  // call mural api to get list
  $mural_api = new Muralapi;
  $result = $mural_api->get_all_murals($musername);
dpm($result);
  if (is_object($result) && isset($result->data)) {
    $data = drupal_json_decode($result->data);
    if (is_array($data)) {
      foreach ($data as $k => $mobj) {
        $the_pos = strpos($mobj['id'], '.');
        if ($the_pos === false) {
          $the_pos = 0;
        } else {
          $the_pos += 1;
        }
        $the_muralid = substr($mobj['id'], $the_pos);
        $the_muralid_array[] = $the_muralid;
        if (!empty($mobj['members'][$musername])) {
          if ($mobj['members'][$musername]['role'] == 'owner') {
            $myideas_list[$the_muralid] = array('muralid' => $the_muralid,
              'thumburl' => $mobj['thumbUrl'],
            );
          } else {
            $shareideas_list[$the_muralid] = array('muralid' => $the_muralid,
              'thumburl' => $mobj['thumbUrl'],
            );
          }
        }
      }
    }
  }


  if (!empty($myideas_list) || !empty($shareideas_list)) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'murals')
            ->fieldCondition('field_muralid', 'value', $the_muralid_array, 'IN');
    $results = $query->execute();

    if (is_array($results['node']) && !empty($results['node'])) {
      $the_nids = array_keys($results['node']);
      $nodes = node_load_multiple($the_nids);
      if (is_array($nodes)) {
        foreach ($nodes as $knid => $vnode) {
          $node_muralfield = field_get_items('node', $vnode, 'field_muralid');
          $node_muralid = $node_muralfield[0]['value'];
          if (isset($myideas_list[$node_muralid])) {
            $myideas_list[$node_muralid]['nid'] = $knid;
          } else {
            if (isset($shareideas_list[$node_muralid])) {
              $shareideas_list[$node_muralid]['nid'] = $knid;
            }
          }
        }
      }
    }
  }

  if (!empty($myideas_list)) {
    ctools_include('modal');
    ctools_include('ajax');
    ctools_modal_add_js();
  }
  $content = theme('studio_ideas_list', array('myideas' => $myideas_list, 'myshareideas' => $shareideas_list));
  return $content;
}

/**
 * get the thumburl info of the every mural by mural api , put it to the node array $murals
 * @param array $murals
 *
 */
function get_murals_detail(&$murals) {
  $the_mid_array = array();
  foreach ($murals as $k => $v) {
    $the_field_obj = field_get_items('node', $v, 'field_muralid');
    //  $the_mid_array
  }
}

// function muralshow_share($nid) {
function muralshow_share($owerid = '', $mid = '') {

  global $user;

  // Get node info by mid and owerid

  $nodeQuery = new EntityFieldQuery;
// $result = $query
//   ->entityCondition('entity_type', 'node')
//   ->propertyCondition('type', $node_type)
//   ->propertyCondition('title', $title)
//   ->execute();

// // $result['node'] contains a list of nids where the title matches
// if (!empty($result['node']) {
//   // You could use node_load_multiple() instead of entity_load() for nodes
//   $nodes = entity_load('node', $result['node']);
// }

  $entities = $nodeQuery->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'murals')
  ->fieldCondition('field_muralid','value', $mid, '=')
//   ->fieldCondition('field_muraluser','value', $owerid, '=')
  ->execute();

//   print('<pre>' . print_r($entities, TRUE) . '</pre>');
//   print("owerid = $owerid, mural id: $mid");


  if (!empty($entities['node'])) {
    foreach ($entities['node'] AS $node_en) {
      $the_node = node_load($node_en->nid);
    }
//     $the_node = entity_load('node', $entities['node']);
    dpm($the_node);
  }


  $username = $owerid;
  $muralid = $mid;

//   $the_node = node_load($nid);
//   $muralid_obj = field_get_items('node', $the_node, 'field_muralid');
//   $muralowner_obj = field_get_items('node', $the_node, 'field_muraluser');
//   $mid = 0;
//   $node_uid = 0;

//   if (isset($the_node->uid)) {
//     $node_uid = $the_node->uid;
//   }

//   if (!empty($muralid_obj[0]['value'])) {
//     $the_muralid = $muralid_obj[0]['value'];
//     $mid = $the_muralid;
//   }
//   if (!empty($muralowner_obj[0]['value'])) {
//     $the_muralowner = $muralowner_obj[0]['value'];
//   }
//   if (!empty($the_muralid) && !empty($the_muralowner)) {

    $account = user_load($user->uid);
    if (!empty($account->field_muralusername)) {
      $fieldinfo = field_get_items('user', $account, 'field_muralusername');
      if ($fieldinfo) {
        $muraluser_invite = $fieldinfo[0]['value'];
      }
    }


    if ($user->uid > 0 && !empty($muraluser_invite)) {

      $mural_api = new Muralapi;

      $property_name = "shared";
      $property_value = (bool) 1;
      $result_share = $mural_api->update_mural_properties($username, $muralid, $property_name, $property_value);
      $data = $result_share->data;

      $result_invite = $mural_api->invite_user_mural($owerid, $mid, array($muraluser_invite));
      dpm($result_invite);

//       $property_name = "shared";
//       $property_value = (bool) 1;
//       $result = $mural_api->update_mural_properties($username, $muralid, $property_name, $property_value);
//       $data = $result->data;

//       dpm($result);

//       $result = $mural_api->invite_user_mural($the_muralowner, $the_muralid, array($muraluser_invite));
    }
//   }

//   return muralshow($nid, $mid, $node_uid);

  dpm($the_node);

  return muralshow($the_node->nid, $mid, $the_node->uid);

}


function muralshow($nid, $mid = 0, $uid = 0) {

  global $user;
  $the_node_uid = 0;
  if ($uid > 0) {
    $the_node_uid = $uid;
  }
  if ($mid == 0) {
    $the_node = node_load($nid);
    $muralid_array = field_get_items('node', $the_node, 'field_muralid');
    $mid = $muralid_array[0]['value'];
    $the_node_uid = $the_node->uid;
  }
  else {
    $the_node = node_load($nid);
  }

  $mural_id_arr = explode('.' , $mid);

  if ($mural_id_arr[0] == 'edgemakers') {
    $mid = $mural_id_arr[1];
  }

  dpm($nid);

  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();

  $img_gear = '<img title="set" alt="set" src="' . $GLOBALS['base_path'] . path_to_theme() . '/images/mock-gear.png"/>';
  $img_settings = array(
  	'path' => drupal_get_path('theme', 'newfteui') . '/images/iconMuralSettings.png',
  );
  $img_gear = theme('image', $img_settings);
  if ($user->uid == $the_node_uid) {
    $edit_url = l($img_gear, 'modal/node/' . $nid . '/edit/nojs/0', array(
      'query' => array(
        'destination' => $GLOBALS['base_path'] . 'mural/' . $nid,
      ),
      'html' => true,
      'attributes' => array(
        'class' => array('ctools-use-modal'),
      ),
            )
    );
  } else {
    $edit_url = '';
  }

dpm($the_node);

  return theme("muralypage", array('data' => array('m_id' => $mid,
              'seturl' => $edit_url,
  		'node' => $the_node,
                  )));
}

function muralcreate($template_id = 0, $nid = 0, $owner_id = '') {
  global $user;

  //drupal_set_message('Template id: ' . $template_id);
  //drupal_set_message('Node id: ' . $nid);
  $title = 'Untitled';

  $ret = "mural create page";
  if ($template_id != 0) {
    $ret = " duplicate mural,  the  id ==" . $template_id;
  }

  // return $ret;
  $account = user_load($user->uid);

  $mural_api = new Muralapi;
  $muralusername = '';
  $muralroomid = '';
  if (empty($account->field_muralusername)) {
    // this account hasn't mapped to a  mural account,call mural api to do it
    fteuser_set_mural_user($mural_api, $account);
    $account = user_load($user->uid);
    $fieldinfo = field_get_items('user', $account, 'field_muralusername');
    if ($fieldinfo) {
      $muralusername = $fieldinfo[0]['value'];
    }
  } else {
    $fieldinfo = field_get_items('user', $account, 'field_muralusername');

    if ($fieldinfo) {
      $muralusername = $fieldinfo[0]['value'];
    }
  }
  if (!empty($muralusername)) {
    if (empty($account->field_muralroomid)) {
      //create mural room for the muraluser
      $title = 'mymuralroom';
      $muralroomid = muralapi_create_room($mural_api, $muralusername, $title, $account);
    } else {
      $fieldinfo = field_get_items('user', $account, 'field_muralroomid');

      if ($fieldinfo) {
        $muralroomid = $fieldinfo[0]['value'];
      }
    }
  }
  if ($muralusername == '' || $muralroomid == '') {
//     drupal_set_message(t('can\'t get link to the mural account!'), 'error');

    return '';
  }

  if ($template_id == 0) {
    //create new mural
    $the_mural = create_mural($mural_api, $muralusername, $muralroomid);
//     dd($the_m_id, 'create mural');

    // Create_mural return mural data now.
//     if ($the_m_id == '') {
    if (!$the_mural) {
//       drupal_set_message(t('can\'t create mural!'), 'error');
      return '';
    }
  } else {

    if ($owner_id) {
      $mural_api = new Muralapi;
      $mural_info = $mural_api->retrieve_a_mural($owner_id, $template_id);

      $data = $mural_info->data;
      $r = drupal_json_decode($data);
//       dpm($data);
//       dpm('<pre>' . print_r($r, TRUE) . '</pre>');

      $title = 'Copy of ' . $r['title'];
    }

  	if ($nid) {
  		$node = node_load($nid);
  		// duplicate the mural
      $title = isset($node->title)?'Copy of ' . $node->title:'my mural';
  	}

    $the_mural = create_mural($mural_api, $muralusername, $muralroomid, $title, $template_id);
    // Create_mural return mural data now.
//     if ($the_m_id == '') {
    if (!$the_mural) {
//       drupal_set_message(t('can\'t create mural!'), 'error');
      return '';
    }
  }

  $newNode = (object) NULL;
  $newNode->type = 'murals';
  $newNode->title = $title;
  $newNode->created = strtotime("now");
  $newNode->changed = strtotime("now");
  $newNode->status = 1;
  $newNode->comment = 0;
  $newNode->promote = 0;
  $newNode->moderate = 0;
  $newNode->sticky = 0;
  $newNode->language = 'und';
  $newNode->field_muralid['und'][0]['value'] = $the_mural['id'];
  $newNode->field_muraluser['und'][0]['value'] = $muralusername;

  $newNode->field_mural_thumburl['und'][0]['value'] = $the_mural['thumbUrl'];
  $mural_memebers = array_keys($the_mural['members']);
  $newNode->field_mural_members['und'][0]['value'] = serialize($mural_memebers);

  node_object_prepare($newNode);
  node_save($newNode);
  $the_nid = $newNode->nid;

  return $newNode;

  //drupal_goto('mural/' . $the_nid);
}

function create_mural($mural_api, $muser, $mroomid, $title = 'my mural', $duplicate_id = '') {
  $params = array('title' => $title, 'room' => $mroomid);
  if ($duplicate_id != '') {
    $mural_api_result = $mural_api->duplicate_mural($muser, $duplicate_id, $params);
//     dd($mural_api_result, 'mural api results of duplicate_mural');
  } else {
    $mural_api_result = $mural_api->create_mural($muser, $params);
//     dd($mural_api_result, 'mural api results of create_mural');
  }
  if (is_object($mural_api_result) && isset($mural_api_result->data)) {
    $muralapi_response_obj = drupal_json_decode($mural_api_result->data);

//     dd($muralapi_response_obj, 'mural api results of $mural_api_result json data.');

    if (!empty($muralapi_response_obj['id'])) {
      $str_p = preg_match("/[0-9]+$/", $muralapi_response_obj['id'], $matches);
      $new_mural_id = '';
      if ($str_p) {
        $new_mural_id = $matches[0];
      }
      dpm($muralapi_response_obj);
      // Return whole data from mural.
      return $muralapi_response_obj;
//       return $new_mural_id;
    }
  }
  return '';
}

function _mural_usersearch_autocomplete($string = '') {
  $ret = array();
  $query = db_select('users', 'u');
  $query->leftJoin('field_data_field_muralusername', 'f', '(u.uid = f.entity_id and f.bundle = :p)', array(':p' => 'user'));
  $query->fields('u', array('uid', 'name'))
          ->isNotNull(field_muralusername_value)
          ->condition('u.name', '%' . db_like($string) . '%', 'LIKE');
  $result = $query->execute();
  foreach ($result as $row) {
    $ret[$row->name] = check_plain($row->name);
  }
  drupal_json_output($ret);
}

/**
 * Move muralcreate page here.
 *
 * @param int $template_id
 */
function themuraly_mural_page($template_id = 0, $nid = 0, $owner_id = '') {

	$node = muralcreate($template_id, $nid, $owner_id);
	if ($node->nid) {
		drupal_goto('mural/' . $node->nid);
	}
	else {
// 	  drupal_set_message(t('Can\'t create mural on create page.'));
// 	  echo '<span class="close-mural-dialog" onclick=\'window.parent.closeFromIframe();\'> X </span>';
	}

}

/**
 * Create mural AJAX.
 */
function themuraly_mural_create_ajax() {
	$node = muralcreate($template_id);
	print(drupal_json_output($node));
	exit;
}

function mural_delete($nid = 0) {

	$html = '';

	global $user;

	if ($nid) {

		$node = node_load($nid);

		$field_muraluser = field_get_items('node', $node, 'field_muraluser');

		if ($field_muraluser) {
			$muralusername = $field_muraluser[0]['value'];
		}

		$field_muralid = field_get_items('node', $node, 'field_muralid');

		if ($field_muralid) {
			$muralid = $field_muralid[0]['value'];
		}

		$mural_api = new Muralapi;

		$delete_status = $mural_api->delete_mural($muralusername, $muralid);

		if ($delete_status->data == 'OK') {
// 			drupal_set_message('Mural ' . $node->title . ' have deleted.');
			//drupal_set_message('<pre>' . print_r($delete_status, TRUE) . '</pre>');
			$html .= 'Mural ' . $node->title . ' have deleted.';
		}
		else {
// 			drupal_set_message(t('Delete fail'), 'error');
			$html .= 'Mural ' . $node->title . ' fail.';
		}


	}
	else {
// 		drupal_set_message(t('Delete fail'), 'error');
		$html .= 'Mural ' . $node->title . ' fail.';
	}

	$html .= 'Close it after 5 seconds';

	drupal_add_js('setInterval(window.parent.closeFromIframe(), 5000);', array('type'=>'inline'));

	return $html;
}
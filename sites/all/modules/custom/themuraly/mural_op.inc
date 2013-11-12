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

// dpm($uid . $musername . $mroomid);
  $myideas_list = array();
  $shareideas_list = array();
  $the_muralid_array = array();
  // call mural api to get list
  $mural_api = new Muralapi;
  $result = $mural_api->get_all_murals($musername);
// dpm($result);
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

//   dpm($shareideas_list);


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

          $img_settings = array(
            'path' => drupal_get_path('theme', 'newfteui') . '/images/iconMuralSettings.png',
          );
          $img_gear = theme('image', $img_settings);

          $img_gear = '<img title="set" alt="set" src="' . $GLOBALS['base_path'] . path_to_theme() . '/images/mock-gear.png"/>';

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

          $shareideas_list[$node_muralid]['set_url'] = $edit_url;
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

  $entities = $nodeQuery->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'murals')
          ->fieldCondition('field_muralid', 'value', $mid, '=')
//   ->fieldCondition('field_muraluser','value', $owerid, '=')
          ->execute();

  if (!empty($entities['node'])) {
    foreach ($entities['node'] AS $node_en) {
      $the_node = node_load($node_en->nid);
    }
//     dpm($the_node);
  }

  $username = $owerid;
  $muralid = $mid;

  $account = user_load($user->uid);
  if (!empty($account->field_muralusername)) {
    $fieldinfo = field_get_items('user', $account, 'field_muralusername');
    if ($fieldinfo) {
      $muraluser_invite = $fieldinfo[0]['value'];
    }

    //Add share nid into user profile.
    if ($the_node->uid <> $user->uid) {
      $field_mural_share_with_me = field_get_items('user', $account, 'field_mural_share_with_me');
      if ($field_mural_share_with_me) {
        $mural_share_with_me = $field_mural_share_with_me[0]['value'];
      }
      if (empty($mural_share_with_me)) {
        $share_with_me = array();
      } else {
        $share_with_me = explode(',', $mural_share_with_me);
      }
      $share_with_me[] = $the_node->nid;
      //       dpm($share_with_me);
      $mural_share_with_me_val = implode(',', array_unique($share_with_me));
      //       dpm($mural_share_with_me_val);
      // edit field-data
      $new_account->uid = $account->uid;
      $new_account->field_mural_share_with_me['und'][0]['value'] = $mural_share_with_me_val;
      // save existing user
      unset($new_account->pass);
      $new_account = user_save((object) array('uid' => $new_account->uid), (array) $new_account);
//         dpm($new_account);
    }
    // End add share nid into user profile
  }


  if ($user->uid > 0 && !empty($muraluser_invite)) {

    $mural_api = new Muralapi;

    //Ensure share mural is share property is TRUE.
    $property_name = "shared";
    $property_value = (bool) 1;
    $result_share = $mural_api->update_mural_properties($username, $muralid, $property_name, $property_value);
    $data = $result_share->data;

    $result_invite = $mural_api->invite_user_mural($owerid, $mid, array($muraluser_invite));
//       dpm($result_invite);
  }

//   dpm($the_node);

  return muralshow($the_node->nid, $mid, $the_node->uid);
}

function muralshow($nid, $mid = 0, $uid = 0) {

  global $user;

  // for issue fte-419: Need to create mural user/room automatically if not yet when show a mural in iframe
  $the_account = user_load($user->uid);
  $the_res = get_muralusername_muralroom($the_account);
  $error_msg = '';
  if ($the_res['muralusername'] == '') {
    $error_msg .= t('Failed to load this mural because mural user can\'t be created,');
  }
  if ($the_res['muralroomid'] == '') {
    $error_msg .= t('Failed to load this mural because mural room can\'t be created,');
  }
  if ($error_msg != '') {
    $error_msg .= t('please try it later.');
    return $error_msg;
  }
//   watchdog('Invite Share' , 'User info in muralshow(): <pre>' . print_r($user, TRUE) . '</pre>');
  $the_node_uid = 0;
  if ($uid > 0) {
    $the_node_uid = $uid;
  }
  if ($mid == 0) {
    $the_node = node_load($nid);
    $muralid_array = field_get_items('node', $the_node, 'field_muralid');
    $mid = $muralid_array[0]['value'];
    $the_node_uid = $the_node->uid;
  } else {
    $the_node = node_load($nid);
  }

  $str_p = preg_match("/[0-9]+$/", $mid, $matches);
  $new_mural_id = '';
  if ($str_p) {
    $mid = $matches[0];
  }

  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();

  $img_gear = '<img title="set" alt="set" src="' . $GLOBALS['base_path'] . path_to_theme() . '/images/mock-gear.png"/>';
  $img_settings = array(
    'path' => drupal_get_path('theme', 'newfteui') . '/images/iconMuralSettings.png',
  );
  $img_gear = theme('image', $img_settings);
//   dpm($the_node_uid);
  if ($user->uid == $the_node_uid) {
//     dpm($nid);
    $edit_url = l($img_gear, 'modal/node/' . $nid . '/edit/nojs/0', array(
      'query' => array(
        'destination' => $GLOBALS['base_path'] . 'mural/' . $nid,
      ),
      'html' => true,
      'attributes' => array(
        'class' => array(
          'ctools-use-modal',
          'ctools-modal-modal-popup-small',
        ),
        'title' => t('Settings'),
      ),
            )
    );
  } else {
    $edit_url = '';
  }

// dpm($the_node);

  return theme("muralypage", array('data' => array('m_id' => $mid,
              'seturl' => $edit_url,
              'node' => $the_node,
                  )));
}

/**
 *
 * get/create the muralusername and muralroomid
 *
 * @param object $account
 * @return array
 */
function get_muralusername_muralroom($account) {
  $ret = array();
  $mural_api = new Muralapi;
  $muralusername = '';
  $muralroomid = '';
  $i = 1;
  while ($muralusername == '' && $i <= 3) {
    if (empty($account->field_muralusername)) {
      // this account hasn't mapped to a  mural account,call mural api to do it
      fteuser_set_mural_user($mural_api, $account);
      $account = user_load($account->uid);
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
    $i++;
  }

  if (!empty($muralusername)) {


    $i = 1;
    while ($muralroomid == '' && $i <= 3) {
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
      $i++;
    }
  }
  if ($muralusername == '' || $muralroomid == '') {
    watchdog("Muraly", '$muralusername and $muralroomid empty' . print_r($muralroomid, TRUE) . '</pre>');
    // drupal_set_message(t('can\'t get link to the mural account!'), 'error');
  }
  $ret['muralusername'] = $muralusername;
  $ret['muralroomid'] = $muralroomid;

  return $ret;
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

  $the_res = get_muralusername_muralroom($account);
  $error_msg = '';
  if ($the_res['muralusername'] == '') {
    $error_msg .= t('Failed to create mural because mural user can\'t be created,');
  }
  if ($the_res['muralroomid'] == '') {
    $error_msg .= t('Failed to create mural because mural room can\'t be created,');
  }
  if ($error_msg != '') {
    $error_msg .= t('please try it later.');
    return $error_msg;
  } else {
    $muralusername = $the_res['muralusername'];
    $muralroomid = $the_res['muralroomid'];
  }
  if ($template_id == 0) {
//     watchdog("Topic Debug", '$template_id info: ' . print_r($template_id, TRUE) . '</pre>');
    //create new mural
    $the_mural = create_mural($mural_api, $muralusername, $muralroomid);

    watchdog("Muraly", 'Create mural id from api: ' . print_r($the_mural, TRUE) . '</pre>');
//     dd($the_m_id, 'create mural');
    // Create_mural return mural data now.
//     if ($the_m_id == '') {
    if (!$the_mural) {
//       drupal_set_message(t('can\'t create mural!'), 'error');
      return '';
    }
  } else {

//     watchdog("Topic Debug", '$owner_id info' . print_r($owner_id, TRUE) . '</pre>');
    if ($owner_id) {
      $mural_api = new Muralapi;
      $mural_info = $mural_api->retrieve_a_mural($owner_id, $template_id);
      $data = $mural_info->data;
      $r = drupal_json_decode($data);
//       dpm($data);
//       watchdog("Topic Debug", 'mural info' . $r);
//       dpm('<pre>' . print_r($r, TRUE) . '</pre>');

      $title = 'Copy of ' . $r['title'];
    }

//     watchdog("Topic Debug", '$nid info' . print_r($nid, TRUE) . '</pre>');
    if ($nid) {
      $node = node_load($nid);
      // duplicate the mural
      $title = isset($node->title) ? 'Copy of ' . $node->title : 'my mural';
    }

    $the_mural = create_mural($mural_api, $muralusername, $muralroomid, $title, $template_id);

//     watchdog("Topic Debug", '$the_mural info' . print_r($the_mural, TRUE) . '</pre>');
    // Create_mural return mural data now.
//     if ($the_m_id == '') {
    if (!$the_mural) {
//       drupal_set_message(t('can\'t create mural!'), 'error');
      return '';
    }
  }

//   watchdog("Topic Debug", '$the_mural after create info' . print_r($the_mural, TRUE) . '</pre>');

  $str_p = preg_match("/[0-9]+$/", $the_mural['id'], $matches);
  $new_mural_id = '';
  if ($str_p) {
    $new_mural_id = $matches[0];
  }

  watchdog("Muraly", 'Get mural from api: ' . print_r($the_mural, TRUE) . '</pre>');

  if ($new_mural_id) {
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
    $newNode->field_muralid['und'][0]['value'] = $new_mural_id;
    $newNode->field_muraluser['und'][0]['value'] = $muralusername;

    $newNode->field_mural_thumburl['und'][0]['value'] = $the_mural['thumbUrl'];
    $mural_memebers = array_keys($the_mural['members']);
    $newNode->field_mural_members['und'][0]['value'] = serialize($mural_memebers);

    // Set privacy default value.
    $newNode->field_muralshared['und'][0]['value'] = -1;

    // Set share to gallery default value.
    $newNode->field_share_to_gallery['und'][0]['value'] = -1;

    node_object_prepare($newNode);
    node_save($newNode);
    $the_nid = $newNode->nid;

    watchdog('Muraly', 'New node<pre>' . print_r($newNode, TRUE) . '</pre>');

    return $newNode;
  } else {
    return t('Create mural fail');
  }

  //drupal_goto('mural/' . $the_nid);
}

function create_mural($mural_api, $muser, $mroomid, $title = 'my mural', $duplicate_id = '') {
  $params = array('title' => $title, 'room' => $mroomid);
  if ($duplicate_id != '') {
    $mural_api_result = $mural_api->duplicate_mural($muser, $duplicate_id, $params);
    watchdog('Muraly', 'mural api info:' . '<pre' . print_r($mural_api_result, TRUE) . '</pre>');
//     dd($mural_api_result, 'mural api results of duplicate_mural');
  } else {
    $mural_api_result = $mural_api->create_mural($muser, $params);
    watchdog('Muraly', 'mural api info:' . print_r($mural_api_result, TRUE));
//     dd($mural_api_result, 'mural api results of create_mural');
  }
  if (is_object($mural_api_result) && isset($mural_api_result->data)) {
    $muralapi_response_obj = drupal_json_decode($mural_api_result->data);
//     watchdog('Topic Debug', 'mural api decode json info:' . print_r($muralapi_response_objm, TRUE));
//     dd($muralapi_response_obj, 'mural api results of $mural_api_result json data.');

    if (!empty($muralapi_response_obj['id'])) {
      $str_p = preg_match("/[0-9]+$/", $muralapi_response_obj['id'], $matches);
      $new_mural_id = '';
      if ($str_p) {
        $new_mural_id = $matches[0];
      }
//       dpm($muralapi_response_obj);
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

function _mural_email_search_autocomplete($string = '') {
  $ret = array();
  $query = db_select('users', 'u');

  $or = db_or();
  $or->condition('u.name', '%' . db_like($string) . '%', 'LIKE');
  $or->condition('u.mail', '%' . db_like($string) . '%', 'LIKE');
  $query->condition($or);

  $query->leftJoin('field_data_field_muralusername', 'f', '(u.uid = f.entity_id and f.bundle = :p)', array(':p' => 'user'));
  $query->fields('u', array('mail', 'name'))
          ->isNotNull(field_muralusername_value);
//           ->condition('u.mail', '%' . db_like($string) . '%', 'LIKE')
//           ->condition('u.mail', '%' . db_like($string) . '%', 'LIKE');
  $query->condition($or);
  $result = $query->execute();
  foreach ($result as $row) {
    $ret[$row->mail] = check_plain($row->name);
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
  } else {
    watchdog('Muraly', 'Create mural fail.');
// 	  drupal_set_message(t('Can\'t create mural on create page.'));
    if (is_string($node) && $node != '') {
      return $node;
    }
    return t('Can\'t create mural');
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
      $html .= 'Mural ' . $node->title . ' have deleted.';
      $node_delete = node_delete($nid);
      watchdog('Mural node delete', $user->username . ' delete mural[' . $muralid . ']');
    } else {
      drupal_set_message(t('Delete fail'), 'error');
      $html .= 'Mural ' . $node->title . ' fail.';
    }
  } else {

    $html .= 'Mural ' . $node->title . ' fail.';
  }

  $html .= 'Close it after 5 seconds';

  drupal_add_js('window.parent.nofresh = 1; setInterval(window.parent.closeFromIframe(), 3000);', array('type' => 'inline'));

  return $html;
}

function themuraly_topic_mural_create($topid = '') {

  if ($topid) {
//     watchdog("Topic Debug", 'topid' . $topid);
    $node = muralcreate();

    if ($node->nid) {
      $node->field_topic_mural['und'][0]['target_id'] = $topid;
      node_object_prepare($node);
      $status = node_save($node);

//     if ($status) {
      drupal_goto('mural/' . $node->nid);
    } else {
      return t('Create mural fail');
    }
//     }
//     else {
//       return t('Create mural fail');
//     }
  }
}

// mural web hook function , see https://mural.ly/help/api/webhooks
function muralwebhook() {
  watchdog('notification', 'call the webhook');
  $the_json_data = (file_get_contents("php://input"));
  $the_data = drupal_json_decode($the_json_data);
  watchdog('notification', print_r($the_data, true));
//   exit;
  $the_cmd = array('update', 'delete', 'create');
  $theaction = '';
  if (isset($the_data['operation']['action'])) {
    $theaction = strtolower($the_data['operation']['action']);
    if (!in_array($theaction, $the_cmd)) {
      exit;
    }
  }



  $the_mural_id = $the_data['boardId'];        // mural which the user is accessing
  //$the_mural_id = '1378180214695'; //mock data

  $str_p = preg_match("/[0-9]+$/", $the_mural_id, $matches);
  $new_mural_id = '';
  if ($str_p) {
    $new_mural_id = $matches[0];
  }

  $the_mural_id = $new_mural_id;

  watchdog('notification', 'Mural node info 598 get mural id: <pre>' . print_r($the_mural_id, TRUE) . '</pre>');

  $the_visitor_muraluser_name = $the_data['userId'];
  ;  //who accessing the mural, mural username
  //$the_visitor_muraluser_name = 'lwgmuralppp';  // mock data
  //get the drupal node according the mural id
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'murals')
          ->fieldCondition('field_muralid', 'value', $the_mural_id, '=');
  $results = $query->execute();

  watchdog('notification', 'Mural node info 609: <pre>' . print_r($results, TRUE) . '</pre>');

  //dpm($results);
  if (is_array($results['node']) && !empty($results['node'])) {
    $the_nids = array_keys($results['node']);
    $nodes = node_load_multiple($the_nids);
    watchdog('notification', 'Mural node info 601: <pre>' . print_r($nodes, TRUE) . '</pre>');
    //dpm($nodes);
    if (is_array($nodes) && count($nodes) >= 1) {
      $node = current($nodes);
      //dpm($node);
      watchdog('notification', 'Mural node info 620: <pre>' . print_r($node, TRUE) . '</pre>');
      $the_node_author_id = $node->uid;

      // get the author's mural username
      $author_account = user_load($the_node_author_id);
      // dpm($author_account);
      if (isset($author_account->name)) {
        watchdog('notification', 'Mural account info 627: <pre>' . print_r($author_account, TRUE) . '</pre>');
        $field_owner_muraluser = field_get_items('user', $author_account, 'field_muralusername');
        if ($field_owner_muraluser) {
          $owner_muraluser = $field_owner_muraluser[0]['value'];
          $owner_mail = $author_account->mail;
          watchdog('notification', 'Mural owner info 632: <pre>' . print_r($owner_muraluser, TRUE) . '</pre>');
//           dpm($owner_muraluser);
          // If the modifier is not the mural owner, then send an notification email to the owner
          if ($owner_muraluser != $the_visitor_muraluser_name) {
            $params = array('node' => $node);

            watchdog('notification', 'Mural visitor info 638: <pre>' . print_r($the_visitor_muraluser_name, TRUE) . '</pre>');

            $result = drupal_mail('themuraly', 'mural_updated', $owner_mail, language_default(), $params);
            if ($result['result'] != TRUE) {
              watchdog('notification', t('There was a problem sending notification message to @mail.', array('@mail' => $owner_mail)), NULL, WATCHDOG_WARNING);
            }
          }


          // Update local mural info in node.

          if (isset($node->field_mural_thumburl)) {



            include_once(drupal_get_path('module', 'themuraly') . '/class.muralapi.inc');

            // Sync mural data with local.
            $mural_api = new Muralapi;
            $result = $mural_api->retrieve_a_mural($owner_muraluser, $the_mural_id);
            //  dpm($result);
            $data = drupal_json_decode($result->data);
            watchdog('notification', 'Get mural info by API: <pre>' . print_r($data, TRUE) . '</pre>');
            //  dpm($data);
            // Update thumburl.
            $node->field_mural_thumburl[LANGUAGE_NONE][0]['value'] = $data['thumbUrl'];
            node_object_prepare($node);
            $status = node_save($node);
            $the_str = 'Murals\' node' . $node->title . '[' . $node->nid . ']' . t(' updated ') . $status;
            //  dpm($the_str);
            watchdog('notification', 'Murals\' node' . $node->title . '[' . $node->nid . ']' . t(' updated ') . $status);
          }
        }
      }
    }
  }



  exit;
  //return
}

/**
 * Studio/Gallery page data.
 *
 * @param string $type
 *   - studio: my/share;
 *   - gallery;
 *
 * @param int $page
 *   - Current page.
 *
 * @param string $keyword
 *   - Search keyword.
 *
 * @param unknown_type $sortby
 *
 * @return string
 *   - Mural list HTML code.
 */
function themuraly_studio_mural_list_json($type = 'gallery', $page = '0', $keyword = '', $sortby = '') {

  global $user;
  $uid = 0;

  $limit = 5;
  $start = $page * $limit;

  $html = '';

  if ($type == 'my') {
    $uid = $user->uid;
  }

  $conditions = array();

  $orderby = array();

  if ($type == 'gallery') {

    $orderby[0]['name'] = 'nid';
    $orderby[0]['direction'] = 'DESC';

    // Current sort by Alphabetical, Date, Tags
    // Sort by Alphabetical on title.
    $orderby[1]['name'] = 'title';
    $orderby[1]['direction'] = 'ASC';

    // Sort by Alphabetical on Date[nid].
    $orderby[2]['name'] = 'nid';
    $orderby[2]['direction'] = 'DESC';

    // Order by tags
    $vocab_info = field_info_field('field_tags');
    $vocab_keys = array();
    foreach ($vocab_info['settings']['allowed_values'] as $vocab_item) {
      $vocab_keys[] = $vocab_item['vocabulary'];
    }
    if (($vocab_keys[0])) {
      $vocab_name = $vocab_keys[0];
    }

  }

  if ($keyword) {
    $murals_list = _themuraly_search_execute_result($keyword, $page);
  } else {
    $conditions['field'][] = array(
      'field' => 'field_share_to_gallery',
      'column' => 'value',
      'value' => '1',
      'operator' => '=',
    );
    // Mural share property.
    $conditions['field'][] = array(
      'field' => 'field_muralshared',
      'column' => 'value',
      'value' => '1',
      'operator' => '=',
    );

    $murals_list = themuraly_mural_list($uid, $start, $limit, $conditions, $orderby);

  }

  if (count($murals_list) <= 0) {
    return '';
  }

  $i = 1;
  foreach ($murals_list as $node) {

    if ($i == 1) {
      $class = 'first';
    }

    if ($i == count($murals_list)) {
      $class = 'last';
    }

    $node_user = user_load($node->uid);
    $node_field_first_name = field_get_items('user', $node_user, 'field_firstname');
    $node_first_name = $node_field_first_name && count($node_field_first_name) > 0 ? $node_field_first_name[0]['value'] : '';
    $node_field_last_name = field_get_items('user', $node_user, 'field_lastname');
    $node_last_name = $node_field_last_name && count($node_field_last_name) > 0 ? $node_field_last_name[0]['value'] : '';
    $node_username = $node_first_name . ' ' . $node_last_name;

    $html .= '<li>';

    $html .= '<div class="set-cover">
                    <h5 title="' . $node->title . '">' . $node->title . '</h5>
                    <p class="inspiration">' . $node_username . '</p>
                  </div>';

    $node_mural_thumburl = field_get_items('node', $node, 'field_mural_thumburl');
    $defula_thumburl = 'https://s3.amazonaws.com/static.mural.ly/NoThumbnail.png';
    $mural_thumburl = empty($node_mural_thumburl[0]['value']) ? $defula_thumburl : $node_mural_thumburl[0]['value'];

    $html .= '<span class="muralthumb ' . $node->title . '">';
    $mural_thumb = array('path' => $mural_thumburl);
    $html .= theme('image', $mural_thumb);
    $html .= '</span>';

    $view_url = l('<span class =""></span>', 'mural/' . $node->nid, array(
      'html' => true,
      'attributes' => array(
        'class' => array('studio-mural-list-item-link'),
        'nid' => $node->nid,
        'title' => $node->title,
        'onClick' => '
          showMuralDialog("mural/' . $node->nid . '");
          showMuralNav("' . $type . '");
          setStudioMuralNav("' . $type . '", ' . $node->nid . ', "prev");
          setStudioMuralNav("' . $type . '", ' . $node->nid . ', "next");
          return false;',
      ),
    ));

    $html .= $view_url;

    $html .= '</li>';

    $i++;
  }

//   echo $html;
  return $html;
}
/**
 * Return mural list data by uid.
 *
 * @param int $limit
 * @return string html
 */
function themuraly_mural_list_html($limit = 5) {

  global $user;

  $my_mural_nodes = array();
  $content_type = 'murals';

  $html = '<div class="toolbar-item media">';

  if ($user->uid !== 0) {

    $my_mural_nodes = themuraly_mural_list($user->uid);

    $count = count($my_mural_nodes);
    $i = 0;

    foreach (array_values($my_mural_nodes) as $key => $node) {

      // Get prev/next.
      if (($key - 1) < 0) {
        $prev = $my_mural_nodes[$count - 1]->nid;
      }
      else {
        $prev = $my_mural_nodes[$key - 1]->nid;
      }

      if (($key + 1) > ($count - 1)) {
        $next = $my_mural_nodes[0]->nid;
      }
      else {
        $next = $my_mural_nodes[$key + 1]->nid;
      }

      if ($i < $limit) {
        $mural_item['items'][$i]['data'] = l($node->title, 'mural/' . $node->nid, array(
          'attributes' => array(
            'id' => 'media-node-' . $node->nid,
            'title' => $node->title,
            'prev' => $prev,
            'next' => $next,
            'current' => $node->nid,
            'onClick' => '
              showMuralDialog("mural/' . $node->nid . '");
              showMuralNav();
              return false;
            ',
          )
        ));
        $mural_item['items'][$i]['class'][] = 'mural-item';
        $i++;
      }
    }

    if ($count > 0) {

      $html .= '<h4 class="has-child">Mural<em></em></h4>';

      $mural_item['title'] = '';
      $mural_item['type'] = 'ul';
      $mural_item['attributes'] = array('id' => 'mural-list', 'class' => 'media-video');

      $html .= theme('item_list', $mural_item);
    }

  }

  if (count($my_mural_nodes) <= 0) {
    $html .= '<h4 class="has-child">Mural</h4>';
  }

  $html .= '</div>';

  return $html;
}

function themuraly_studio_mural_get_nav($type = 'my', $nid = '', $nav = 'prev', $keywords = '') {

  global $user;

  $nodes = array();
  $limit = 1;
  $start = 0;
  $page = 0;

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

  switch ($type) {
    case 'my':
      $nodes = themuraly_mural_list($user->uid, $start, $limit, $conditions, $orderby);
      break;

    case 'share':
      $account = user_load($user->uid);
      $the_field_obj = field_get_items('user', $account, 'field_mural_share_with_me');
      $mural_share_with_me = explode(',', $the_field_obj[0]['value']);

      if ($mural_share_with_me) {
        $query = new EntityFieldQuery();

        $query->entityCondition('entity_type', 'node')
                ->propertyCondition('status', 1)
                ->propertyCondition('nid', $nid, $operator)
                ->propertyCondition('type', array('murals'))
                ->propertyCondition('nid', $mural_share_with_me, 'IN')
                ->range($start, $limit);

        if ($nav == 'prev') {
          $query->propertyOrderBy('nid', 'ASC');
        }
        else {
          $query->propertyOrderBy('nid', 'DESC');
        }

        $result = $query->execute();

        if (!empty($result['node'])) {
          $nodes = node_load_multiple(array_keys($result['node']), '', TRUE);
        }
      }

      break;

    case 'gallery':

      if ($keywords) {
        $nodes = _themuraly_search_execute_result($keywords, $page, $limit, $conditions, $orderby);
      }
      else {
        // Current sort by Alphabetical, Date, Tags
        // Sort by Alphabetical on title.
        $orderby[1]['name'] = 'title';
        $orderby[1]['direction'] = 'ASC';

        // Sort by Alphabetical on Date[nid].
        $orderby[2]['name'] = 'nid';
        $orderby[2]['direction'] = 'DESC';

        $conditions['field'][] = array(
          'field' => 'field_share_to_gallery',
          'column' => 'value',
          'value' => '1',
          'operator' => '=',
        );
        // Mural share property.
        $conditions['field'][] = array(
          'field' => 'field_muralshared',
          'column' => 'value',
          'value' => '1',
          'operator' => '=',
        );

        $nodes = themuraly_mural_list(0, $start, $limit, $conditions, $orderby);

      }

//       $nodes = _themuraly_search_execute_result($keywords, $page, $limit, $conditions, $orderby);

      break;

    default:
      $nodes = themuraly_mural_list('', $start, $limit, $conditions, $orderby);
      break;
  }

  foreach ($nodes as $node) {
    $json[] = $node;
  }

  drupal_json_output($json);

}
/**
 * Theme mural box list.
 * @param object $node
 * @return string
 *   - HTML code.
 */
function theme_mural_item_box($item = array(), $attributes = array()) {

  global $user;
  $html = '';
  $node = $item['node'];

  foreach ($attributes AS $key => $value) {
    $item_attributes[$key] = $value;
  }

//   print('Node: <pre>' . print_r($node, TRUE) . '</pre>');
  if ($node->nid) {

    $node_user = user_load($node->uid);
//     print('User: <pre>' . print_r($node_user, TRUE) . '</pre>');
    $node_field_first_name = field_get_items('user', $node_user, 'field_firstname');
    $node_first_name = $node_field_first_name && count($node_field_first_name) > 0 ? $node_field_first_name[0]['value'] : '';
    $node_field_last_name = field_get_items('user', $node_user, 'field_lastname');
    $node_last_name = $node_field_last_name && count($node_field_last_name) > 0 ? $node_field_last_name[0]['value'] : '';
    $node_username = $node_first_name . ' ' . $node_last_name;
    $node_user_avatar = theme('user_picture', array('account' => $node_user));

    $view_url = l(t(''), 'mural/' . $node->nid, array(
      'html' => true,
      'attributes' => array(
        'class' => array('mural-list-item-link'),
        'nid' => $node->nid,
        'onClick' => '
          showMuralDialog("?q=mural/' . $node->nid . '");
          jQuery("#mural-iframe").attr("height", jQuery(window).height() + 56 + "px");
          return false;',
      ),
    ));

    $html .= '<div>';

    if ($node->field_topic_mural[LANGUAGE_NONE]['0']['target_id']) {    // Topic mural list

      $avatarUris = explode('/', variable_get('user_picture_default', ''));
      $avatarUri = file_build_uri(array_pop($avatarUris));
      if(isset($node_user->field_profile_picture[LANGUAGE_NONE])) {
        $fid = $node_user->field_profile_picture[LANGUAGE_NONE][0]['fid'];
        if($fid) {
          $profile_picture = file_load($fid);
          if(file_exists($profile_picture->uri)) {
            $avatarUri = $profile_picture->uri;
          }
        }
      }

      $avatar_img = array(
        'path' => $avatarUri,
        'width' => '74px',
        'height' => '74px',
      );
      $avatar_picture = theme('image', $avatar_img);
//       print('User image: ' . $filepath . ' | Image :' . $avatar_picture);

      $view_url = l($node->title, '#', array(
        'attributes' => array(
          'nid' => $node->nid,
          'onClick' => '
            showMuralDialog("?q=mural/' . $node->nid . '");
            jQuery("#mural-iframe").attr("height", jQuery(window).height() + 56 + "px");
            return false;',
        ),
      ));

      $html .= '<h3 class="author">' . $node_username . '</h3>';
      $html .= '<span class="mural-title">' . $view_url . '</span>';
      $html .= '<span class="user-avatar">' . $avatar_picture . '</span>';
    } else {                                                             // Default mural list
      $html .= '<div class="set-cover">
                      <h5 title ="' . $node->title . '">' . $node->title . '</h5>
                      <p class="inspiration">' . $node_username . '</p>
                    </div>';

      $node_mural_thumburl = field_get_items('node', $node, 'field_mural_thumburl');
      $defula_thumburl = 'https://s3.amazonaws.com/static.mural.ly/NoThumbnail.png';
      $mural_thumburl = empty($node_mural_thumburl[0]['value']) ? $defula_thumburl : $node_mural_thumburl[0]['value'];
      $mural_thumb = array('path' => $mural_thumburl);

      $html .= '<span class="muralthumb ' . $node->title . '">';
      $html .= theme('image', $mural_thumb);
      $html .= '</span>';

      $view_url = l(t(''), 'mural/' . $node->nid, array(
        'html' => true,
        'attributes' => array(
          'class' => array('mural-list-item-link'),
          'nid' => $node->nid,
          'onClick' => '
            showMuralDialog("?q=mural/' . $node->nid . '");
            jQuery("#mural-iframe").attr("height", jQuery(window).height() + 56 + "px");
            return false;',
        ),
      ));

      $html .= $view_url;

      if ($user->uid == $node->uid) {
        $html .= $set_url;
      }

      $html .= '<span class="user-avatar">' . $node_user_avatar . '</span>';
    }

    $html .= '</div>';

  }

  return $html;
}

/**
 * Theme mural box list.
 * @param array $nodes
 * @return string|Ambigous <string, The, unknown, A, Optional>
 */
function theme_mural_list_box($type = 'studio', $nodes) {
  $mural = array();
  $attributes = array();
  $attributes['type'] = $type;
  $mural_list = '';

  if (is_array($nodes)) {

    if (count($nodes) <= 0) {
      return '';
    }

    $i = 1;
    foreach ($nodes as $node) {
//   	  echo "topic type: " . $type;
//   	  $attributes['type'] = $type;
      $item = theme('mural_item_box', array('node' => $node), $attributes);
      $mural['items'][$i]['data'] = $item;
      $i++;
    }

    if (count($mural['items'] > 0)) {
      $mural['title'] = '';
      $mural['type'] = 'ul';
      $mural['attributes'] = array(
        'id' => 'topic-mural-list',
      );
      $mural_list = theme('item_list', $mural);
    } else {
      $mural_list = t('Mural is empty in topic.');
    }
  }

  return $mural_list;
}
function the_updatemuralnode($node) {
   if ($node->type == 'murals') {

    $l = field_get_items('node', $node, 'field_city');
    $city = '';
    $lid = '';


    if (!empty($l[0]['city'])) {
      $city = $l[0]['city'];
      $lid = $l[0]['lid'];
    }
    if ($city != '' && $lid != '') {
      // get the lat/long info again through the google api according to city, no country.
      $the_url = 'http://maps.googleapis.com/maps/api/geocode/json?address=' . $city . '&sensor=false';
      $location_info = drupal_http_request($the_url);
      $location_val = drupal_json_decode($location_info->data);

      if ($location_val['status'] == 'OK') {
        if (isset($location_val['results'][0]['geometry']['location']['lat'])) {
          $fields = array('latitude' => $location_val['results'][0]['geometry']['location']['lat'],
            'longitude' => $location_val['results'][0]['geometry']['location']['lng']
          );

          db_merge('location')
                  ->key(array('lid' => $lid))
                  ->fields($fields)
                  ->execute();
        }
      }
    }
  }
}

function _themuraly_search_func_result($keys = '', $page = 0, $limit = 5, $conditions = array(), $orderby = array()) {
  $start = $page * $limit;
  $keys = trim($keys);

//   print("Page: " . $page);
//   // Build matching conditions
//   $query = db_select('search_index', 'i', array('target' => 'slave'))->extend('SearchQuery')->extend('PagerDefault');
//   $query->join('node', 'n', 'n.nid = i.sid');
//   $query->condition('n.status', 1)->addTag('node_access')->searchExpression($keys, 'node');
//   // Insert special keywords.
//   $query->setOption('type', 'n.type');
//   $query->setOption('language', 'n.language');
//   if ($query->setOption('term', 'ti.tid')) {
//     $query->join('taxonomy_index', 'ti', 'n.nid = ti.nid');
//   }
//   // Custom field condition.
//   $query->condition('n.type', 'murals');
//   // Join "Share to gallery" field.
//   $query->innerJoin('field_data_field_share_to_gallery','field_gallery','n.nid = field_gallery.entity_id');
//   $query->condition('field_gallery.field_share_to_gallery_value', 1);
//   $query->orderBy('n.title', 'ASC');//ORDER BY title
//   $query->orderBy('n.nid', 'DESC');//ORDER BY created
//   // Join  field_tags table and term table.
//   $query->leftJoin('field_data_field_tags','field_tags','n.nid = field_tags.entity_id');
//   $query->leftJoin('taxonomy_term_data','term','field_tags.field_tags_tid = term.tid');
//   // Order by tags by term ASC.
//   $query->orderBy('term.name', 'ASC');//ORDER BY created
//   $query->range($start, $pager);
//   // END Custome field condition.
//   // Only continue if the first pass query matches.
//   if (!$query->executeFirstPass()) {
//     return array();
//   }
//   // Add the ranking expressions.
//   _node_rankings($query);
// //   $query->limit($pager);
// //   $query->offset($start);
//   $query->range($start, $pager);
//   // Load results.
//   $find = $query->execute();
//   print('Query execute result:<pre>' . print_r($find, TRUE) . '</pre>');
//   $results = array();
//   foreach ($find as $item) {
//     // Build the node body.
//     $node = node_load($item->sid);
//     node_build_content($node, 'search_result');
//     $node->body = drupal_render($node->content);
//     // Fetch comments for snippet.
//     $node->rendered .= ' ' . module_invoke('comment', 'node_update_index', $node);
//     // Fetch terms for snippet.
//     $node->rendered .= ' ' . module_invoke('taxonomy', 'node_update_index', $node);
//     $extra = module_invoke_all('node_search_result', $node);
//     $results[] = $node;
// //     $results[] = array(
// //       'link' => url('node/' . $item->sid, array('absolute' => TRUE)),
// //       'type' => check_plain(node_type_get_name($node)),
// //       'title' => $node->title,
// //       'user' => theme('username', array('account' => $node)),
// //       'date' => $node->changed,
// //       'node' => $node,
// //       'extra' => $extra,
// //       'score' => $item->calculated_score,
// //       'snippet' => search_excerpt($keys, $node->body),
// //     );
//   }
//   return $results;
//   ( (d.data LIKE :db_condition_placeholder_6 ESCAPE '\\') AND (d.data LIKE :db_condition_placeholder_7 ESCAPE '\\') )


  if ($keys) {

//     watchdog('Debug', 'Keys: ' . $keys);

    $query = db_select('search_index', 'i')
            ->condition('i.type', 'node');                      //Search node.
//       ->condition('i.word', '%' . $keys . '%', 'LIKE');  //Search key
    // Full text search, copy from search.extender.inc.
//     $query->innerJoin('search_dataset', 'd', 'i.sid = d.sid  AND i.type = d.type');

    // full text search.
//     $query->condition('d.data', '%' . strtolower($keys) . '%', 'LIKE');

    // Keys is multi and split by "space".
//     $keys_array = explode(' ', $keys);
//     $orkeys = db_or();
//     foreach ($keys_array AS $key) {
//       $orkeys->condition('i.word', '%' . strtolower($key) . '%', 'LIKE');
//     }
//     $query->condition($orkeys);

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
//         print('Order by: <pre>'.print_r($o,TRUE).'</pre>');
        $query->orderBy($o['name'], $o['direction']);
      }
    }
    else {
      $query->orderBy('n.nid', 'DESC'); //ORDER BY created
    }

    // distinct sid.
    $query->AddExpression('distinct i.sid', 'sid_node');

    $query->join('node', 'n', 'n.nid = i.sid');
    $query->condition('n.type', 'murals');
    $query->condition('n.status', 1);

    // The numeric score of the word, higher being more important.
    $query->orderBy('i.score', 'ASC'); //ORDER BY title

    $query->orderBy('n.title', 'ASC'); //ORDER BY title
    $query->orderBy('i.sid', 'DESC'); //ORDER BY title

    // Join "Share to gallery" field.
    $query->innerJoin('field_data_field_share_to_gallery', 'field_gallery', 'n.nid = field_gallery.entity_id');
    $query->condition('field_gallery.field_share_to_gallery_value', 1);

    // Join "Mural share propty".
    $query->innerJoin('field_data_field_muralshared', 'field_muralshared', 'n.nid = field_muralshared.entity_id');
    $query->condition('field_muralshared.field_muralshared_value', 1);

    // Tags search.
    // Join  field_tags table and term table.
    $query->leftJoin('field_data_field_tags', 'field_tags', 'n.nid = field_tags.entity_id');
    $query->leftJoin('taxonomy_term_data', 'term', 'field_tags.field_tags_tid = term.tid');
    // Order by tags by term ASC.
    $query->orderBy('term.name', 'ASC'); //ORDER BY created

    // Key search by normal SQL.
    $orkeys = db_or();
    $orkeys->condition('n.title', '%' . strtolower($keys) . '%', 'LIKE');
    $orkeys->condition('term.name', '%' . strtolower($keys) . '%', 'LIKE');

    $query->condition($orkeys);

    $query->range($start, $limit);

//     watchdog('Debug', 'SQL execute before: ' . ((string) $query) . '<pre>' .  print_r($query->arguments(), TRUE) . '</pre>');

    // Debug.
//     print('Query:<pre>' . print_r($query, TRUE) . '</pre>');
//     dpm($query);
    // End Debug.

    $find = $query->execute();
//     watchdog('Debug', 'Search result: <pre>' . print_r($find, TRUE) . '</pre> | $query <pre>' . print_r($query, TRUE) . '</pre>');
//     watchdog('Debug', 'SQL after execute: ' . ((string) $query) . '<pre>' .  print_r($query->arguments(), TRUE) . '</pre>');
    // Debug.
//     print('Query execute result:<pre>' . print_r($find, TRUE) . '</pre>');
//     WHERE  (i.type = "node") AND (d.data LIKE "%copy of%" ESCAPE '\\') AND( (i.word LIKE :db_condition_placeholder_2 ESCAPE '\\') OR (i.word LIKE :db_condition_placeholder_3 ESCAPE '\\') )AND (n.type = :db_condition_placeholder_4) AND (n.status = :db_condition_placeholder_5) AND (field_gallery.field_share_to_gallery_value = :db_condition_placeholder_6)
//     dpm($find);
    // End Debug.

    $results = array();

    foreach ($find as $item) {
//       watchdog('Debug', 'Item of search result: <pre>' . print_r($item, TRUE) . '</pre>');
      // Render the node.
//       print('find item: <pre>'.print_r($item, TRUE).'</pre>');
      $node = node_load($item->sid_node);
      $results[] = $node;
    }

    return $results;
  }

  return false;
}
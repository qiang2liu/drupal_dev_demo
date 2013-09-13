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
//   watchdog("Topic Debug", 'account info' . print_r($account, TRUE) . '</pre>');
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
//   watchdog("Topic Debug", '$muralusername info' . print_r($muralusername, TRUE) . '</pre>');
//   watchdog("Topic Debug", '$$muralroomid info' . print_r($muralroomid, TRUE) . '</pre>');
  if ($muralusername == '' || $muralroomid == '') {
    watchdog("Muraly", '$muralusername and $muralroomid empty' . print_r($muralroomid, TRUE) . '</pre>');
//     drupal_set_message(t('can\'t get link to the mural account!'), 'error');

    return '';
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
    watchdog('Muraly', 'mural api info:' . $mural_api_result);
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
    watchdog('Muraly', 'Create mural fial.');
// 	  drupal_set_message(t('Can\'t create mural on create page.'));
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

  drupal_add_js('setInterval(window.parent.closeFromIframe(), 5000);', array('type' => 'inline'));

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
  $the_json_data =(file_get_contents("php://input"));
  $the_data = drupal_json_decode($the_json_data);
  watchdog('notification', print_r($the_data,true));
  exit;
  $the_cmd = array('update', 'delete', 'create');
  $theaction = '';
  if (isset($the_data['operation']['action'])) {
    $theaction = strtolower($the_data['operation']['action']);
    if (!in_array($theaction, $the_cmd )) {
      exit;
    }
  }
  
  

  $the_mural_id = $the_data['boardId'];        // mural which the user is accessing
  //$the_mural_id = '1378180214695'; //mock data

  $the_visitor_muraluser_name = $the_data['userId']; ;  //who accessing the mural, mural username
  //$the_visitor_muraluser_name = 'lwgmuralppp';  // mock data
  //get the drupal node according the mural id
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'murals')
          ->fieldCondition('field_muralid', 'value', $the_mural_id, '=');
  $results = $query->execute();
  //dpm($results);
  if (is_array($results['node']) && !empty($results['node'])) {
    $the_nids = array_keys($results['node']);
    $nodes = node_load_multiple($the_nids);
    //dpm($nodes);
    if (is_array($nodes) && count($nodes) >= 1) {
      $node = current($nodes);
      //dpm($node);
      $the_node_author_id = $node->uid;

      // get the author's mural username
      $author_account = user_load($the_node_author_id);
     // dpm($author_account);
      if (isset($author_account->name)) {
        $field_owner_muraluser = field_get_items('user', $author_account, 'field_muralusername');
        if ($field_owner_muraluser) {
          $owner_muraluser = $field_owner_muraluser[0]['value'];
          $owner_mail = $author_account->mail;
          dpm($owner_muraluser);
          // If the modifier is not the mural owner, then send an notification email to the owner
          if ($owner_muraluser != $the_visitor_muraluser_name) {
            $params = array('node' => $node);
           
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
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
function get_myideas($uid, $musername, $mroomid) {

  // call mural api to get list 
  $mural_api = new Muralapi;
  $result = $mural_api->get_all_murals($musername);
  if (is_object($rersult) && isset($result->data)) {
    $data = drupal_json_decode($result->data);
    $mural_list = array();
    if (is_array($data)) {
      foreach ($data as $k => $mobj) {
        if (!empty($mobj['members'][$musername])) {
          if ($mobj['members'][$musername]['role'] == 'owner') {
           // $mural_list[]
          }
        }
      }
    }
  }




  /*
    $the_user_muralusername = $the_field_obj[0]['value'];
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'murals')
    ->propertyCondition('uid', $uid);
    $results = $query->execute();
    if (!empty($results['node'])) {
    $the_mids = array_keys($results['node']);
    $mymurals = node_load_multiple($the_mids);
    get_murals_detail($mymurals);
    }
   * 
   */
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

function muralshow_share($nid) {


  global $user;
  $the_node = node_load($nid);
  $muralid_obj = field_get_items('node', $the_node, 'field_muralid');
  $muralowner_obj = field_get_items('node', $the_node, 'field_muraluser');
  $mid = 0;
  $node_uid = 0;
  if (isset($the_node->uid)) {
    $node_uid = $the_node->uid;
  }

  if (!empty($muralid_obj[0]['value'])) {
    $the_muralid = $muralid_obj[0]['value'];
    $mid = $the_muralid;
  }
  if (!empty($muralowner_obj[0]['value'])) {
    $the_muralowner = $muralowner_obj[0]['value'];
  }
  if (!empty($the_muralid) && !empty($the_muralowner)) {

    $account = user_load($user->uid);
    if (!empty($account->field_muralusername)) {
      $fieldinfo = field_get_items('user', $account, 'field_muralusername');
      if ($fieldinfo) {
        $muraluser_invite = $fieldinfo[0]['value'];
      }
    }


    if ($user->uid > 0 && !empty($muraluser_invite)) {

      $mural_api = new Muralapi;
      $result = $mural_api->invite_user_mural($the_muralowner, $the_muralid, array($muraluser_invite));
    }
  }
  return muralshow($nid, $mid, $node_uid);
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


  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();

  $img_gear = '<img title="set" alt="set" src="' . $GLOBALS['base_path'] . path_to_theme() . '/images/mock-gear.png"/>';
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



  return theme("muralypage", array('data' => array('m_id' => $mid,
              'seturl' => $edit_url,
                  )));
}

function muralcreate($template_id = 0) {
  global $user;

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
    drupal_set_message(t('can\'t get link to the mural account!'), 'error');

    return '';
  }

  if ($template_id == 0) {
    //create new mural
    $the_m_id = create_mural($mural_api, $muralusername, $muralroomid);
    if ($the_m_id == '') {
      drupal_set_message(t('can\'t create mural!'), 'error');
      return '';
    }
  } else {
    // duplicate the mural
    $title = 'my mural';
    $the_m_id = create_mural($mural_api, $muralusername, $muralroomid, $title, $template_id);
    if ($the_m_id == '') {
      drupal_set_message(t('can\'t create mural!'), 'error');
      return '';
    }
  }

  $newNode = (object) NULL;
  $newNode->type = 'murals';
  $newNode->title = 'my mural';
  $newNode->created = strtotime("now");
  $newNode->changed = strtotime("now");
  $newNode->status = 1;
  $newNode->comment = 0;
  $newNode->promote = 0;
  $newNode->moderate = 0;
  $newNode->sticky = 0;
  $newNode->language = 'und';
  $newNode->field_muralid['und'][0]['value'] = $the_m_id;
  $newNode->field_muraluser['und'][0]['value'] = $muralusername;

  node_object_prepare($newNode);
  node_save($newNode);
  $the_nid = $newNode->nid;
  drupal_goto('mural/' . $the_nid);
}

function create_mural($mural_api, $muser, $mroomid, $title = 'my mural', $duplicate_id = '') {
  $params = array('title' => $title, 'room' => $mroomid);
  if ($duplicate_id != '') {
    $mural_api_result = $mural_api->duplicate_mural($muser, $duplicate_id, $params);
  } else {
    $mural_api_result = $mural_api->create_mural($muser, $params);
  }
  dpm($mural_api_result);
  if (is_object($mural_api_result) && isset($mural_api_result->data)) {
    $muralapi_response_obj = drupal_json_decode($mural_api_result->data);
    dpm($muralapi_response_obj);
    if (!empty($muralapi_response_obj['id'])) {
      $str_p = preg_match("/[0-9]+$/", $muralapi_response_obj['id'], $matches);
      $new_mural_id = '';
      if ($str_p) {
        $new_mural_id = $matches[0];
      }
      return $new_mural_id;
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


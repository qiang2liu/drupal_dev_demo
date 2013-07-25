<?php

function muralshow($nid, $mid = 0) {

  if ($mid == 0) {
    $the_node = node_load($nid);
    $muralid_array = field_get_items('node', $the_node, 'field_muralid');
    $mid = $muralid_array[0]['value'];
  }

  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();

  $img_gear = '<img title="set" alt="set" src="' . $GLOBALS['base_path'] . path_to_theme() . '/images/mock-gear.png"/>';

  $edit_url = l($img_gear, 'modal/node/' . $nid . '/edit/nojs/1', array(
    'query' => array(
     'destination' => $GLOBALS['base_path'] . 'mural/' . $nid,
    ),
    'html' => true,
    'attributes' => array(
      'class' => array('ctools-use-modal'),
    ),
          )
  );


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
  drupal_goto( 'mural/' . $the_nid);
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


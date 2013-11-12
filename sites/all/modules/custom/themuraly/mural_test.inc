<?php
function muralapi_test() {

  global $user;

  print('Test: <pre>' . print_r($user, TRUE) . '</pre>');
//   dpm($user);

  $output_html = '';

//   include_once('mural_op.inc');
//   muralshow_share('lwgmural', '1376967210186');
//   themuraly_get_mural_info('http://staging.mural.ly/!/#/lwgmural/1377006043205');
//   _get_node_from_mural_id('1377006043205');
//   themuraly_studio_mural_list_json('gallery', 1, 'Copy of');
//  themuraly_topic_mural_list(539);
//   _test_mural_list_for_a_user();
 // _test_user_add();
 _test_change_profile();
  //_test_change_password();
  //_test_create_room();
//   _test_mural_create_mural();
  //_test_mural_duplicate_mural();
  //_test_mural_update_property_mural();
  //_test_mural_archive();
  //_test_mural_del();
//   _test_mural_list_for_a_user();
  // _test_mural_invite_member();
  // _test_retrieve_a_mural();
//   themuraly_mural_list_html();
//   themuraly_get_mural_info('http://staging.mural.ly/!/#/lwgmural/1376967210186');
  // $output_html = "<iframe frameborder='0' src='http://staging.mural.ly/embed/edgemakers/edgemakers/1374110398829' width=500px height=500px'></iframe>";
//   $output_html = "<iframe frameborder='0' src='http://staging.mural.ly/embed/edgemakers/edgemakers/1374641493558' width=500px height=500px'></iframe>";


  return $output_html;
}

function _test_change_profile() {
  $username = 'zzxxcc001';
  $profile['name'] = 'fg';
  $profile['surname'] = 'ii';
  $profile['thumbUrl'] = rawurlencode('http://tp4.sinaimg.cn/1189615035/180/5675994286/1');
  $mural_api = new Muralapi;
  $result = $mural_api->mural_profile_change($username, $profile);
  dpm($result);
}
function _test_change_password() {
  $username = 'cldf6668';
  $newpass = '12345';
  $mural_api = new Muralapi;
  $result = $mural_api->change_password($username, $newpass);
  dpm($result);
}

function _test_mural_invite_member() {
  $username = 'kk2t';
  $muralid = '1375063051875';
  $muraluserids = array('kikora');
  $mural_api = new Muralapi;
  $result = $mural_api->invite_user_mural($username, $muralid, $muraluserids);
  dpm($result);
  $data = $result->data;
  $r = drupal_json_decode($data);
  dpm($r);
}

function _test_mural_del() {
  $mural_api = new Muralapi;
  $username = "testuser";
  $muralid = "1374197201377";
  $result = $mural_api->delete_mural($username, $muralid);
  $data = $result->data;  //it is a string
  //$r = drupal_json_decode($data);
  dpm($result);
  dpm($data);
}

function _test_create_room() {
  $mural_api = new Muralapi;
  $username = "testuser";
  $title = 'mymuralroom';
  $result = $mural_api->create_room($username, $title);
  $data = $result->data;
  $r = drupal_json_decode($data);
  dpm($result);
  dpm($r);
}

function _test_retrieve_a_mural() {
  $username = 'kk2t';  //owner
  // $username = 'kikora';
  $muralid = '1375231303413';
  $muralid = '1375063051875';
  $muralid = '1375252040839';
  $muralid = '1375252809540';

  $username = 'dev_student1';
  $username = 'lugaltest';
  $muralid = '1379327802962';
  $muralid = '1379337407854';
  $muralid = '1379338377473';
  $muralid = '1379338517428';
  $muralid = '1379040192281';

  $mural_api = new Muralapi;
  $result = $mural_api->retrieve_a_mural($username, $muralid);
  $data = $result->data;
  $r = drupal_json_decode($data);
  dpm($result);
  dpm($r);
  print('Mural API $result info: <pre>' . print_r($result, TRUE) . '</pre>');
  print('Mural info: <pre>' . print_r($r, TRUE) . '</pre>');
}

function _test_mural_archive() {
  $mural_api = new Muralapi;
  $username = "testuser";
  $muralid = "1374197201377";
  $archive_flag = 1;
  $result = $mural_api->archive_mural($username, $muralid, $archive_flag);
  $data = $result->data;
  //$r = drupal_json_decode($data);
  dpm($result);
  dpm($data);
}

function _test_mural_update_property_mural() {
  $mural_api = new Muralapi;

  $username = 'kk2t';
  $muralid = '1375063051875';
  $property_name = "shared";
  $property_value = (bool) 1;
  $result = $mural_api->update_mural_properties($username, $muralid, $property_name, $property_value);
  $data = $result->data;
  $r = drupal_json_decode($data);
  dpm($result);
  dpm($r);
}

function _test_mural_duplicate_mural() {
  $mural_api = new Muralapi;
  $params = array('title' => 'this is a duplicate from a mural', 'room' => 1373060830214,);
  $result = $mural_api->duplicate_mural('testuser', '1373655313624', $params);
  $data = $result->data;
  $r = drupal_json_decode($data);
  dpm($result);
  dpm($r);
}
function _test_mural_create_mural() {
  $mural_api = new Muralapi;
  $str = rand(800, 10000);
  $params = array('title' => $str . ' this is a mural', 'room' => 1378864394167,);
  $result = $mural_api->create_mural('cldf5418', $params);
  $data = $result->data;
  $r = drupal_json_decode($data);
  dpm($result);
  dpm($r);
}

function _test_mural_list_for_a_user() {
  $mural_api = new Muralapi;
  $result = $mural_api->get_all_murals('cldf5418');
  $data = $result->data;
  $r = drupal_json_decode($data);
  dpm($result);
  dpm($r);
}

function _test_user_add() {

  $mural_api = new Muralapi;
  $str = rand(800, 10000);
  $user = array();
  $user['username'] = "cldf" . $str;
  //$user['username'] = "dev-edgemakers";
  $user['email'] = "dev_devedgemakers" . $str . "@symbio.com";
  $user['source'] = "dev-edgemakers";
  $user['nameIdentifier'] = 3;
  $user['password'] = '123';

  $mural_api_result = $mural_api->create_user($user, '/api/organizations/dev-edgemakers/users', 'POST');
  dpm($mural_api_result);
  //dd($mural_api_result);
  $muralapi_response_obj = drupal_json_decode($mural_api_result->data);
  dpm($muralapi_response_obj);

  if (isset($muralapi_response_obj['hasErrors'])) {
    if (!$muralapi_response_obj['hasErrors']) {
      // successful, then
      $edit = array();
      // the $muralapi_response_obj will contain the user attribute ($muralapi_response_obj->user)
      // but now ,it has no this attribute, so , just reguard the $account->name as the  mural username
      $the_mural_username = "";
      if (isset($muralapi_response_obj['user'])) {
        if (isset($muralapi_response_obj['user']['username'])) {
          $the_mural_username = $muralapi_response_obj['user']['username'];
        }
      }


      $edit['field_muralusername'][LANGUAGE_NONE][0]['value'] = $the_mural_username;
      // user_save($account, $edit);
      dpm($edit);
    }
  }
}

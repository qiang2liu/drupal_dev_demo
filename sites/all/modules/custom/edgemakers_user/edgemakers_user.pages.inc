<?php
/**
 * functions for user profile view
 *
 */
function edgemakers_user_view($account) {
  if($account->uid == 0) return false;

  //userpic, username, school, class generation  
  $avatarUris = explode('/', variable_get('user_picture_default', ''));
  $avatarUri = file_build_uri(array_pop($avatarUris));
  if($account->picture) {
    $avatarUri = $account->picture->uri;
  }
  if(isset($avatarUri) && file_exists($avatarUri))
    $userpic = theme('image_style', array('style_name' => 'edgemakers_avatar', 'path' => $avatarUri));
  if(user_access('access user profiles'))
    $userpic = l($userpic, 'user/'.$account->uid, array('html' => TRUE));
  
  $firstnames = field_get_items('user', $account, 'field_firstname');
  $firstname = $firstnames && count($firstnames) > 0 ? $firstnames[0]['value'] : '';
  $lastnames = field_get_items('user', $account, 'field_lastname');
  $lastname = $lastnames && count($lastnames) > 0 ? $lastnames[0]['value'] : '';
  
  $username = $firstnames .' '. $lastname;
  $userschool = 'Riverdale Country School';
  $userclass = 'Class: Jed Silverstein';
  
  $output = '<div class="username">'.$username.'</div>';
  $output .= $userpic;
  $output .= '<div class="userinfo">';
  $output .= '  <div class="userschool">'.$userschool.'</div>';
  $output .= '  <div class="userclass">'.$userclass.'</div>';
  $output .= '</div>';
  echo $output;
  return;
}
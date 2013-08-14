<?php
/**
 * functions for user profile view
 *
 */
function edgemakers_user_view($account) {
  if($account->uid == 0) return false;

  //userpic, username, school, class generation  
  if($account->picture) {
    $avatarUri = $account->picture->uri;
  } else {
    $avatarUris = explode('/', variable_get('user_picture_default', ''));
    $avatarUri = file_build_uri(array_pop($avatarUris));
  }
  if(isset($avatarUri) && file_exists($avatarUri))
    $userpic = '<div class="userpic">'.theme('image_style', array('style_name' => 'edgemakers_avatar', 'path' => $avatarUri)).'</div>';
  
  $firstnames = field_get_items('user', $account, 'field_firstname');
  $firstname = $firstnames && count($firstnames) > 0 ? $firstnames[0]['value'] : '';
  $lastnames = field_get_items('user', $account, 'field_lastname');
  $lastname = $lastnames && count($lastnames) > 0 ? $lastnames[0]['value'] : '';
  
  if($firstname) {
    $username = $firstname .' '. $lastname;
  } else {
    $username = $account->name;
  }
  $userschool = 'Riverdale Country School';
  $userclass = 'Class: Jed Silverstein';
  
  $output = '<div class="userinfo"><div class="username">'.$username.'</div>';
  $output .= $userpic;
  $output .= '<div class="useredu">';
  $output .= '  <div class="userschool">'.$userschool.'</div>';
  $output .= '  <div class="userclass">'.$userclass.'</div>';
  $output .= '</div></div>';
  $output .= '<div id="back-community"> ' . t('Back to Community') . '</div>';
  echo $output;
}
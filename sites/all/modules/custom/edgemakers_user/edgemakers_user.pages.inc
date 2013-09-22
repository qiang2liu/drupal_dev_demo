<?php
/**
 * functions for user profile view
 *
 */
function edgemakers_user_profile_view($account) {
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
function user_profile_callback($ajax) {
  if (!$ajax) {
    return drupal_get_form('edgemakers_user_profile_settings_form');
  }
  $commands = array();
  ctools_include('user.pages', 'user', '');
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();

  $form_state = array(
    'ajax' => TRUE,
    'title' => t('PROFILE SETTINGS'),
  );

	drupal_add_library('system', 'ui.dialog');
  $commands = ctools_modal_form_wrapper('edgemakers_user_profile_settings_form', $form_state);

  if (!empty($form_state['executed']) && empty($form_state['rebuild'])) {
    $commands = array();
    ctools_add_js('ajax-responder');
    $commands[] = ctools_modal_command_dismiss();
  }
  // Return the ajax instructions to the browser via ajax_render().
  print ajax_render($commands);
  drupal_exit();
}
/*
 * functions for user profile settings form
 *
 */
function edgemakers_user_profile_settings_form($form, &$form_state) {
  global $user;
  $user = user_load($user->uid);
  $category = 'account';
  $account = $user;
  if (!isset($form_state['user'])) {
    $form_state['user'] = $account;
  }
  else {
    $account = $form_state['user'];
  }
  $form['#user'] = $account;
  $form['#user_category'] = $category;  
  $langcode = entity_language('user', $account);
  $options = array(
    'field_name'=>'field_firstname'
  );
  field_attach_form('user', $account, $form, $form_state, $langcode, $options);
  $form['field_firstname'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('FIRST NAME');
  $options = array(
    'field_name'=>'field_lastname'
  );
  field_attach_form('user', $account, $form, $form_state, $langcode, $options);
  $form['field_lastname'][LANGUAGE_NONE][0]['value']['#attributes']['placeholder'] = t('LAST NAME');
  $form['account']['pass'] = array(
    '#type' => 'password_confirm',
    '#size' => 25,
    '#description' => t('To change the current user password, enter the new password in both fields.'),
  );
  $options = array(
    'field_name'=>'field_profile_picture'
  );
  field_attach_form('user', $account, $form, $form_state, $langcode, $options);
  $options = array(
    'field_name'=>'field_profile_background'
  );
  field_attach_form('user', $account, $form, $form_state, $langcode, $options);
  $form['preset_background'] = array(
    '#type' => 'radios',
    '#title' => '',
    '#options' => edgemakers_user_get_bgimages_options(),
    '#attributes' => array('style'=>'display:none'),
    '#weight' => 20,
    '#after_build' => array('_edgemakers_user_load_my_javascript'),
  );
  unset($form['field_firstname'][LANGUAGE_NONE][0]['value']['#title'], $form['field_lastname'][LANGUAGE_NONE][0]['value']['#title'], $form['account']['pass']['#description'], $form['field_profile_background'][LANGUAGE_NONE][0]['#description']);
  $element_info = element_info('password_confirm');
  $process = $element_info['#process'];
  $process[] = 'edgemakers_user_process_password_confirm';
  $form['account']['pass']['#process'] = $process;
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('SAVE'),
    '#suffix' => '<script>profileBackground();</script>',
  );
  return $form;
}
function edgemakers_user_profile_settings_form_validate($form, &$form_state) {
  _edgemakers_user_editform_validate($form, $form_state);
  entity_form_field_validate('user', $form, $form_state);
}
function _edgemakers_user_editform_validate($form, &$form_state) {
  if(isset($form_state['values']['field_firstname'][LANGUAGE_NONE])) {
    if ($error = edgemakers_user_validate_name('firstname', $form_state['values']['field_firstname'][LANGUAGE_NONE][0]['value'])) {
      form_set_error('field_firstname', $error);
    }
  }
  if(isset($form_state['values']['field_lastname'][LANGUAGE_NONE])) {
    if ($error = edgemakers_user_validate_name('lastname', $form_state['values']['field_lastname'][LANGUAGE_NONE][0]['value'])) {
      form_set_error('field_lastname', $error);
    }
  }
}
function edgemakers_user_profile_settings_form_submit($form, &$form_state) {
  $account = $form_state['user'];
  $category = $form['#user_category'];
  // Remove unneeded values.
  form_state_values_clean($form_state);

  // Before updating the account entity, keep an unchanged copy for use with
  // user_save() later. This is necessary for modules implementing the user
  // hooks to be able to react on changes by comparing the values of $account
  // and $edit.
  $account_unchanged = clone $account;

  //user picture
  $old_file = $account->picture;
  if($old_file) {
    file_usage_delete($old_file, 'user', 'user', $account->uid);
    file_delete($old_file);
    $account->picture = 0;
  }
  if(isset($form_state['values']['field_profile_picture'][LANGUAGE_NONE])) {
    $fid = $form_state['values']['field_profile_picture'][LANGUAGE_NONE][0]['fid'];
    if ($fid) {
      $picture = file_load($fid);
      $info = image_get_info($picture->uri);
      $picture_directory =  file_default_scheme() . '://' . variable_get('user_picture_path', 'pictures');
      file_prepare_directory($picture_directory, FILE_CREATE_DIRECTORY);
      $destination = file_stream_wrapper_uri_normalize($picture_directory . '/picture-' . $account->uid . '-' . REQUEST_TIME . '.' . $info['extension']);
      // Move the temporary file into the final location.
      if ($picture = file_copy($picture, $destination, FILE_EXISTS_RENAME)) {
        $picture->status = FILE_STATUS_PERMANENT;
        $account->picture = file_save($picture);
        file_usage_add($picture, 'user', 'user', $account->uid);
      }
    }
  }
  //background image
  $imageNid = $form_state['values']['preset_background'];
  if($imageNid) {
    $bgimage_directory =  file_default_scheme() . '://user_background';
    file_prepare_directory($bgimage_directory, FILE_CREATE_DIRECTORY);
    $node = node_load($imageNid);
    $images = field_get_items('node', $node, 'field_sitebg_image');
    $imageUri = $images && count($images) > 0 ? $images[0]['uri'] : '';
    $fid = $images && count($images) > 0 ? $images[0]['fid'] : '';
    if ($fid) {
      $file = file_load($fid);
      $file->uid = $account->uid;
      $image_info = image_get_info($imageUri);
      $filename = 'bgimage-' . $account->uid . '-' . REQUEST_TIME . '.' . $image_info['extension'];
      $destination = file_stream_wrapper_uri_normalize($bgimage_directory . '/' . $filename);
      if($file = file_copy($file, $destination, FILE_EXISTS_REPLACE)) {
        $file->status = FILE_STATUS_PERMANENT;
        $old_fid = $form_state['values']['field_profile_background'][LANGUAGE_NONE][0]['fid'];
        if($old_fid) {
          $old_file = file_load($old_fid);
          if($old_file) {
            file_usage_delete($old_file, 'file', 'user', $account->uid);
            file_delete($old_file);
          }
        }
        $form_state['values']['field_profile_background'][LANGUAGE_NONE][0] = (array)$file;
      }
    }
  }

  entity_form_submit_build_entity('user', $account, $form, $form_state);

  // Populate $edit with the properties of $account, which have been edited on
  // this form by taking over all values, which appear in the form values too.
  $edit = array_intersect_key((array) $account, $form_state['values']);
  //picture isn't in the form, so we deal with it separately
  $edit['picture'] = $account->picture;
  
  user_save($account_unchanged, $edit, $category);
  $form_state['values']['uid'] = $account->uid;
  if ($category == 'account' && !empty($edit['pass'])) {
    // Remove the password reset tag since a new password was saved.
    unset($_SESSION['pass_reset_'. $account->uid]);
  }
  // Clear the page cache because pages can contain usernames and/or profile information:
  cache_clear_all();
}
function edgemakers_user_validate_name($type, $name) {
  if (!$name) {
    return t('You must enter a '.$type.'.');
  }
  if (substr($name, 0, 1) == ' ') {
    return t('The '.$type.' cannot begin with a space.');
  }
  if (substr($name, -1) == ' ') {
    return t('The '.$type.' cannot end with a space.');
  }
  if (strpos($name, '  ') !== FALSE) {
    return t('The '.$type.' cannot contain multiple spaces in a row.');
  }
  if (preg_match('/[^\x{80}-\x{F7} a-z0-9@_.\'-]/i', $name)) {
    return t('The '.$type.' contains an illegal character.');
  }
  if (preg_match('/[\x{80}-\x{A0}' . // Non-printable ISO-8859-1 + NBSP
  '\x{AD}' . // Soft-hyphen
  '\x{2000}-\x{200F}' . // Various space characters
  '\x{2028}-\x{202F}' . // Bidirectional text overrides
  '\x{205F}-\x{206F}' . // Various text hinting characters
  '\x{FEFF}' . // Byte order mark
  '\x{FF01}-\x{FF60}' . // Full-width latin
  '\x{FFF9}-\x{FFFD}' . // Replacement characters
  '\x{0}-\x{1F}]/u', // NULL byte and control characters
  $name)) {
    return t('The '.$type.' contains an illegal character.');
  }
}
function edgemakers_user_get_bgimages_list() {
  $bgimages = array();
  $query = db_select('node', 'n');
  $nodes = array();
  $nids = $query->condition('n.type', 'site_bg_image')->condition('n.status', NODE_PUBLISHED)->fields('n', array('nid'))->orderBy('n.created', 'DESC')->addTag('node_access')->range(0, 11)->execute()->fetchCol();
  if($nids) {
    $nodes = node_load_multiple($nids);
    foreach($nodes as $node) {
      $images = field_get_items('node', $node, 'field_sitebg_image');
      $image = $images && count($images) > 0 ? $images[0]['uri'] : '';
      if ($image) {
        $bgimages[$node->nid] = array('title'=>$node->title, 'image'=>theme('image_style', array('style_name' => 'edgemakers_set', 'path' => $image)));
      }
    }
  }
  return $bgimages;
}
function edgemakers_user_get_bgimages_options() {
  $options = array();
  $bgimages = edgemakers_user_get_bgimages_list();
  foreach($bgimages as $nid=>$bgimage) {
    $option = '   <div nid="'.$nid.'">';
    $option .= '   <span class="title">'.$bgimage['title'].'<span>';
    $option .= '   <span class="image">'.$bgimage['image'].'<span>';
    $option .= '  </div>';
    $options[$nid] = $option;
  }
  return $options;
}
function _edgemakers_user_load_my_javascript($element){
  drupal_add_js(drupal_get_path('module', 'edgemakers_user').'/js/edgemakers_user.js');
  return($element);
}
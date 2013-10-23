<?php
/**
 *  home page callback
 */
function edgemakers_homepage() {
  $image_path = _edgemakers_get_bg_image();
  if ($image_path !== false) {
    require_once drupal_get_path('module', 'bg_image').'/bg_image.module';
    bg_image_add_background_image($image_path);
  }
  $messages = drupal_get_messages();
  if(isset($messages['status'])) {
    $messages = $messages['status'];
    foreach($messages as $message) {
      if($message == t('A validation e-mail has been sent to your e-mail address. In order to gain full access to the site, you will need to follow the instructions in that message.') || $message == '<span class="firstlogin">'.t('You are now an EdgeMaker!').'</span>' || $message == t('Further instructions have been sent to your e-mail address.')) {
        drupal_set_message($message);
      }
    }
  }
  return '';
}
/**
 *  edgemakers settings form callback 
 */
function edgemakers_admin_settings() {
  
  $form['mural_api'] = array(
      '#type' => 'fieldset',
      '#title' => t('mural api settings'),
  );
  $form['mural_api']['muralapi_org'] = array(
      '#type' => 'textfield',
      '#title' => t('organization in mural'),
      '#default_value' => variable_get('muralapi_org', 'edgemakers'),
      '#description' => t('input the organization name for mural api'),
      '#required' => true,
  );
  $form['mural_api']['muralapi_secretkey'] = array(
      '#type' => 'textfield',
      '#title' => t('secretkey'),
      '#default_value' => variable_get('muralapi_secretkey', 'C54DC45B6C1E4A9321936349FC8BB'),
      '#description' => t('input the secretkey for mural api'),
      '#required' => true,
  );
  $form['mural_api']['muralapi_baseurl'] = array(
      '#type' => 'textfield',
      '#title' => t('mural api baseurl'),
      '#default_value' => variable_get('muralapi_baseurl', 'http://staging.mural.ly'),
      '#description' => t('input the base url for mural api'),
      '#required' => true,
  );
  $form['mural_api']['muralapi_useragent'] = array(
      '#type' => 'textfield',
      '#title' => t('user agent setting'),
      '#default_value' => variable_get('muralapi_useragent', 'curl/7.22.0 (i686-pc-linux-gnu) libcurl/7.22.0 OpenSSL/1.0.1 zlib/1.2.3.4 libidn/1.23 librtmp/2.3'),
      '#description' => t('mural api has the right response only for some user agent '),
      '#required' => true,
  );

  return system_settings_form($form);
}
/**
 *  community activity block callback
 */
function edgemakers_community_contents() {
  $items = array();
  $content_types = array_filter(array_values(variable_get('edgemakers_community_content_type', array())));
  $comment_types = array_filter(array_values(variable_get('edgemakers_community_comment_type', array())));
  $num = variable_get('edgemakers_community_activity_num', 5);
  if(count($content_types)>0)
    $nodes = _edgemakers_node_get_recent($content_types, $num);
  if(count($comment_types)>0)
    $comments = _edgemakers_comment_get_recent($comment_types, $num);
  $contents = array_merge($nodes, $comments);
  if(count($contents)>0) {
    usort($contents, '_edgemakers_nodes_comp');
  }
  return $contents;
}
/**
 *  forbidden page callback
 */
function edgemakers_forbidden_page() {
  if(user_is_logged_in()) {
    return t("Access denied, please !logout and switch to another user", array('!logout'=>l('logout', 'user/logout', array('query' => array('destination' => 'home')))));
  } else {
    if($_SERVER["REQUEST_URI"] == '/user/logout') {
      header('Location: '.url('home'));
      exit;
    }
    return t("Access denied, please !login first", array('!login'=>l('login', 'user/login')));
  }
}
function _edgemakers_get_bg_image() {
  if(user_is_logged_in()) {
    global $user;
    $user = user_load($user->uid);    
    $images = field_get_items('user', $user, 'field_profile_background');
    $imageUri = $images && count($images) > 0 ? $images[0]['uri'] : '';
    if($imageUri) {
      return file_create_url($imageUri);
    }
  }
  return false;
}
function _edgemakers_nodes_comp($a, $b) {
  if ($a == $b) {
    return 0;
  }
  return ($a->changed < $b->changed) ? 1 : -1;
}
function _edgemakers_node_get_recent($types, $number = 5) {
  $query = db_select('node', 'n');

  $nodes = array();
  $nids = $query->condition('n.type', $types, 'IN')->condition('n.status', NODE_PUBLISHED)->fields('n', array('nid'))->orderBy('n.changed', 'DESC')->addTag('node_access')->execute()->fetchCol();

  if($nids) {
    foreach($nids as $nid) {
      if(count($nodes) == $number) break;
      $node = node_load($nid);
      switch($node->type) {
        case 'media_for_upload':
          $shares = field_get_items('node', $node, 'field_share');
          $share = $shares && count($shares) > 0 ? $shares[0]['value'] : '';
          if($share)
            $nodes[] = $node;
          break;
        default:
          $nodes[] = $node;
          break;
      }
    }
  }
  return $nodes;
}
function _edgemakers_comment_get_recent($types, $number = 5) {
  $query = db_select('comment', 'c');
  $query->innerJoin('node', 'n', 'n.nid = c.nid');
  $query->addTag('node_access');
  $results = $query->fields('c', array('cid'))->fields('n', array('title'))->condition('n.type', $types, 'IN')->condition('c.status', COMMENT_PUBLISHED)->condition('n.status', NODE_PUBLISHED)->orderBy('c.created', 'DESC')
  // Additionally order by cid to ensure that comments with the same timestamp
  // are returned in the exact order posted.
  ->orderBy('c.cid', 'DESC')->range(0, $number)->execute()->fetchAll();

  if(in_array('edgemakers_set', $types)) {
    require_once drupal_get_path('module', 'edgemakers_set').'/edgemakers_set.pages.inc';
    $terms = _edgemakers_set_get_terms();
  }
  $comments = array();
  if($results) {
    foreach($results as $result) {
      if(count($comments) == $number) break;
      $comment = comment_load($result->cid);
      $comment->node_title = $result->title;
      if($comment->node_type == 'comment_node_edgemakers_set') {
        $node = node_load($comment->nid);
        $types = field_get_items('node', $node, 'field_set_type');
        $type = $types && count($types) > 0 ? $terms[$types[0]['tid']] : '';
        if($type == 'Video with Comments')
          $comments[] = $comment;
      } else {
        $comments[] = $comment;
      }
    }
  }
  return $comments;
}
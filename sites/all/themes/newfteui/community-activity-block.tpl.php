<?php
$realnum = count($contents);
if($realnum>0) {
  $items = array();
  require_once drupal_get_path('module', 'edgemakers_set').'/edgemakers_set.pages.inc';
  $terms = _edgemakers_set_get_terms();
  for($i = 0; $i < $num && $i < $realnum; $i ++) {
    $item = '';
    $content = $contents[$i];
    $avatarUris = explode('/', variable_get('user_picture_default', ''));
    $avatarUri = file_build_uri(array_pop($avatarUris));
    if($content->picture) {
      $account = user_load($content->uid);
      $avatarUri = $account->picture->uri;
    }
    if(isset($avatarUri) && file_exists($avatarUri))
      $userpic = theme('image_style', array('style_name' => 'edgemakers_avatar', 'path' => $avatarUri));
    if(user_access('access user profiles'))
      $userpic = l($userpic, 'edgemakers/user/profile/ajax/'.$content->uid, array('html' => TRUE, 'attributes'=> array('class' => array('community-user-profile'))));
    $variables = array(
      'account' => $content, 
    );
    $username = theme('username', $variables);
    $date = format_interval(time()-$content->created) . ' ago';
    $item .= $userpic.'<div class="cont">';
    $item .= '<div class="usertime">'.$username.'<div class="time">'.$date.'</div></div>';
    if ($content->cid) {
      //comment
      //$title = l($content->title, 'node/'.$content->nid, array('fragment' => 'comment-'.$content->cid));
      $title = $content->node_title;
      $item .= '<div class="activity">Left a comment on '.$title.'</div>';
    }
    else {
      // If this is a new node.
      if ($content->created == $content->changed) {
        //$title = l($content->title, 'node/'.$content->nid);
        $title = $content->title;
        $type = $content->type;
        if($type == 'edgemakers_set') {
          $types = field_get_items('node', $content, 'field_set_type');
          $type = $types && count($types) > 0 ? $terms[$types[0]['tid']] : '';
        } else if($type == 'murals') {
          $type = 'Mural';
        } else if($type == 'media_for_upload') {
          $type = 'Media';
        }
        $item .= '<div class="activity">Created a '.$type.' named "'.$title.'"</div>';
      }
      else {
        $title = $content->title;
        $type = $content->type;
        if($type == 'edgemakers_set') {
          $types = field_get_items('node', $content, 'field_set_type');
          $type = $types && count($types) > 0 ? $terms[$types[0]['tid']] : '';
        } else if($type == 'murals') {
          $type = 'Mural';
        } else if($type == 'media_for_upload') {
          $type = 'Media';
        }
        $item .= '<div class="activity">Edited '.$type.' "'.$title.'"</div>';
      }
    }
    $item .= '</div>';
    $items[] = $item;
  }
  echo theme('item_list', array('items' => $items));
} else {
  echo t("No Activity.");
}
?>
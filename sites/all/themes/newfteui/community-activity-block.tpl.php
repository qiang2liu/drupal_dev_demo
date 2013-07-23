<?php
$realnum = count($contents);
if($realnum>0) {
  $items = array();
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
      $userpic = l($userpic, 'user/'.$content->uid, array('html' => TRUE));
    $variables = array(
      'account' => $content, 
    );
    $username = theme('username', $variables);
    $date = format_interval(time()-$content->created) . ' ago';
    $item .= $userpic.'<div class="cont">';
    if($content->cid) {
      //comment
      $title = l($content->title, 'node/'.$content->nid, array('fragment' => 'comment-'.$comment->cid));
      $item .= '<div class="activity">'.$username.' Submitted a commnet: '.$title.'</div>';
    } else {
      //node
      $title = l($content->title, 'node/'.$content->nid);
      $type = $content->type;
      $item .= '<div class="activity">'.$username.' Submitted a '.$type.': '.$title.'</div>';
    }
    $item .= '<div class="time">'.$date.'</div></div>';
    $items[] = $item;
  }
  echo theme('item_list', array('items' => $items));
} else {
  echo t("No Activity.");
}
?>
<?php
if(count($contents)>0) {
  $items = array();
  for($i = 0; $i < $num; $i ++) {
    $item = '';
    $content = $contents[$i];
    $variables = array(
      'account' => $content,
    );
    $userpic = theme('user_picture', $variables);
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
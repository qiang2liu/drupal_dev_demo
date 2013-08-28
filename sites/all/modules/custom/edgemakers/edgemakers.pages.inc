<?php
function edgemakers_community_contents() {
  $items = array();
  $content_types = array_filter(array_values(variable_get('edgemakers_community_content_type', array())));
  $comment_types = array_filter(array_values(variable_get('edgemakers_community_comment_type', array())));
  $num = variable_get('edgemakers_community_activity_num', 5);
  if(count($content_types)>0)
    $nodes = edgemakers_node_get_recent($content_types, $num);
  if(count($comment_types)>0)
    $comments = edgemakers_comment_get_recent($comment_types, $num);
  $contents = array_merge($nodes, $comments);
  if(count($contents)>0) {
    usort($contents, 'edgemakers_nodes_comp');
  }
  return $contents;
}
function edgemakers_nodes_comp($a, $b) {
  if ($a == $b) {
    return 0;
  }
  return ($a->created < $b->created) ? 1 : -1;
}
function edgemakers_node_get_recent($types, $number = 5) {
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
function edgemakers_comment_get_recent($types, $number = 5) {
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
function edgemakers_forbidden_page() {
  if(user_is_logged_in()) {
    return t("Access denied, please !logout and switch to another user", array('!logout'=>l('logout', 'user/logout', array('query' => array('destination' => 'home')))));
  } else {
    return t("Access denied, please !login first", array('!login'=>l('login', 'user/login')));
  }
}
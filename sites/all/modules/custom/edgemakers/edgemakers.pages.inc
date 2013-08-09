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

  if (!user_access('bypass node access')) {
    // If the user is able to view their own unpublished nodes, allow them to
    // see these in addition to published nodes. Check that they actually have
    // some unpublished nodes to view before adding the condition.
    if (user_access('view own unpublished content') && $own_unpublished = db_query('SELECT nid FROM {node} WHERE uid = :uid AND status = :status', array(':uid' => $GLOBALS['user']->uid, ':status' => NODE_NOT_PUBLISHED))->fetchCol()) {
      $query->condition(db_or()->condition('n.status', NODE_PUBLISHED)->condition('n.nid', $own_unpublished, 'IN'));
    }
    else {
      // If not, restrict the query to published nodes.
      $query->condition('n.status', NODE_PUBLISHED);
    }
  }
  $nids = $query->condition('n.type', $types, 'IN')->fields('n', array('nid'))->orderBy('n.created', 'DESC')->range(0, $number)->addTag('node_access')->execute()->fetchCol();
  $nodes = node_load_multiple($nids);

  return $nodes ? $nodes : array();
}
function edgemakers_comment_get_recent($types, $number = 5) {
  $query = db_select('comment', 'c');
  $query->innerJoin('node', 'n', 'n.nid = c.nid');
  $query->addTag('node_access');
  $allcomments = $query->fields('c')->fields('n', array('title', 'type'))->condition('n.type', $types, 'IN')->condition('c.status', COMMENT_PUBLISHED)->condition('n.status', NODE_PUBLISHED)->orderBy('c.created', 'DESC')
  // Additionally order by cid to ensure that comments with the same timestamp
  // are returned in the exact order posted.
  ->orderBy('c.cid', 'DESC')->range(0, $number)->execute()->fetchAll();

  require_once drupal_get_path('module', 'edgemakers_set').'/edgemakers_set.pages.inc';
  $terms = _edgemakers_set_get_terms();
  $comments = array();
  foreach($allcomments as $comment) {
    if($comment->type == 'edgemakers_set') {
      $node = node_load($comment->nid);
      $types = field_get_items('node', $node, 'field_set_type');
      $type = $types && count($types) > 0 ? $terms[$types[0]['tid']] : '';
      if($type == 'Video with Comments')
        $comments[] = $comment;
    } else {
      $comments[] = $comment;
    }
  }
  return $comments ? $comments : array();
}
function edgemakers_forbidden_page() {
  if(user_is_logged_in()) {
    return t("Access denied, please !logout and switch to another user", array('!logout'=>l('logout', 'user/logout', array('query' => array('destination' => 'home')))));
  } else {
    return t("Access denied, please !login first", array('!login'=>l('login', 'user/login')));
  }
}
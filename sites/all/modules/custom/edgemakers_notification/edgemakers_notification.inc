<?php

/**
 * @params
 * $data: POST data
 */
function _edgemakers_notification_mural_updated($data) {

  global $user;

  if (user_is_anonymous()) {
    return array('status' => 1, 'error' => 'Invalid user.');
  }

  if (!isset($data['mural_id'])) {
    return array('status' => 1, 'error' => 'Mural ID is missing.');
  }

//   global $user;

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'murals')
    ->fieldCondition('field_muralid', 'value', $data['mural_id'], '=')
    ->addMetaData('account', $user);
  $result = $query->execute();

  if (!isset($result['node'])) {
    return array('status' => 1, 'error' => 'Invalid Mural ID.');
  }

  $node = array_pop($result['node']);
  $tmp = entity_load('node', array($node->nid));
  $node = $tmp[$node->nid];
//   node_save($node->nid);
  node_save($node);        // Fix by lugal
  watchdog('Notification Debug', '<pre>' . print_r($node, TRUE) . '</pre>');
  $author = user_load($node->uid);

  $recipients = array($user);
  if ($user->uid != $author->uid) {
    $recipients[] = $author;
  }

  foreach ($recipients as $recipient) {
    $params = array('node' => $node);
    $result = drupal_mail('edgemakers_notification', 'mural_updated', $recipient->mail, language_default(), $params);
    if ($result['result'] != TRUE) {
      watchdog('notification', t('There was a problem sending notification message to @mail.', array('@mail' => $recipient->mail)), NULL, WATCHDOG_WARNING);
    }
  }

  // Update local mural info in node.
  $node = node_load($node->nid);
  if (isset($node->field_mural_thumburl[LANGUAGE_NONE])) {

    $fieldinfo = field_get_items('user', $author, 'field_muralusername');
    if ($fieldinfo) {
      $muralusername = $fieldinfo[0]['value'];
    }

    include_once(drupal_get_path('module', 'themuraly') . '/class.muralapi.inc');

    // Sync mural data with local.
    $mural_api = new Muralapi;
    $result = $mural_api->retrieve_a_mural($muralusername, $data['mural_id']);
    $data = drupal_json_decode($result->data);

    // Update thumburl.
    $node->field_mural_thumburl[LANGUAGE_NONE][0]['value'] = $data['thumbUrl'];
    node_object_prepare($node);
    $status = node_save($node);

    watchdog('notification', 'Murals\' node' . $node->title . '[' . $node->nid. ']' . t(' updated ') . $status);

  }

  return array('status' => 0);
}

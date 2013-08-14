<?php

/**
 * @params
 * $data: POST data
 */
function _edgemakers_notification_mural_updated($data) {
  if (user_is_anonymous()) {
    return array('status' => 1, 'error' => 'Invalid user.');
  }

  if (!isset($data['mural_id'])) {
    return array('status' => 1, 'error' => 'Mural ID is missing.');
  }

  global $user;

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
  $node = entity_load('node', array($node->nid))[$node->nid];
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

  return array('status' => 0);
}

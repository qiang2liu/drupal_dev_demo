<?php
/**
 * @file
 * Admin UI for clients.
 */

/**
 * UI controller.
 */
class OAuth2ServerClientUIController extends EntityDefaultUIController {

  public function __construct($entity_type, $entity_info) {
    $this->statusKey = 'status';
    $this->entityType = $entity_type;
    $this->entityInfo = $entity_info;
    // Stop the UI from mentioning "OAuth2 client" everywhere.
    $this->entityInfo['label'] = 'Client';
    // Replace the client placeholder with the server name, since the path
    // is used for links and redirects.
    $this->path = str_replace('%oauth2_server_client', arg(4), $this->entityInfo['admin ui']['path']);
  }

  /**
   * Overrides EntityDefaultUIController::hook_menu().
   */
  public function hook_menu() {
    $items = array();
    $path = 'admin/structure/oauth2-servers/manage/%/clients';
    $id_pos = count(explode('/', $path));

    $items[$path] = array(
      'title' => 'Clients',
      'page callback' => 'drupal_get_form',
      'page arguments' => array('oauth2_server_client_overview_form', 'oauth2_server_client'),
      'description' => 'Manage clients.',
      'access callback' => 'entity_access',
      'access arguments' => array('view', 'oauth2_server_client'),
      'type' => MENU_LOCAL_TASK,
      'file' => 'includes/entity.ui.inc',
      'weight' => 10,
    );
    $items[$path . '/add'] = array(
      'title' => 'Add client',
      'page callback' => 'entity_ui_get_form',
      'page arguments' => array('oauth2_server_client', NULL, 'add'),
      'access callback' => 'entity_access',
      'access arguments' => array('create', 'oauth2_server_client'),
      'type' => MENU_LOCAL_ACTION,
      'file' => $this->entityInfo['admin ui']['file'],
      'file path' => drupal_get_path('module', 'oauth2_server')
    );
    // The regular Entity API way would be to use
    // $path . '/manage/%entity_object' here, but Drupal's Menu API is limited
    // to 9 levels, one too little for that to work.
    $items[$path . '/%entity_object'] = array(
      'title' => 'Edit',
      'title callback' => 'entity_label',
      'title arguments' => array('oauth2_server_client', $id_pos),
      'page callback' => 'entity_ui_get_form',
      'page arguments' => array('oauth2_server_client', $id_pos),
      'load arguments' => array('oauth2_server_client'),
      'access callback' => 'entity_access',
      'access arguments' => array('update', 'oauth2_server_client', $id_pos),
      'file' => $this->entityInfo['admin ui']['file'],
      'file path' => drupal_get_path('module', 'oauth2_server')
    );
    $items[$path . '/%entity_object/edit'] = array(
      'title' => 'Edit',
      'load arguments' => array('oauth2_server_client'),
      'type' => MENU_DEFAULT_LOCAL_TASK,
    );
    $items[$path . '/%entity_object/delete'] = array(
      'page callback' => 'drupal_get_form',
      'page arguments' => array('oauth2_server_client_operation_form', 'oauth2_server_client', $id_pos, 'delete'),
      'load arguments' => array('oauth2_server_client'),
      'access callback' => 'entity_access',
      'access arguments' => array('delete', 'oauth2_server_client', $id_pos),
      'file' => 'includes/entity.ui.inc',
    );

    return $items;
  }

  /**
   * Overrides EntityDefaultUIController::overviewTable().
   */
  public function overviewTable($conditions = array()) {
    $conditions['server'] = arg(4);
    return parent::overviewTable($conditions);
  }

  /**
   * Overrides EntityDefaultUIController::overviewTableRow().
   */
  protected function overviewTableRow($conditions, $id, $entity, $additional_cols = array()) {
    $entity_uri = entity_uri($this->entityType, $entity);

    $row[] = array('data' => array(
      '#theme' => 'entity_ui_overview_item',
      '#label' => entity_label($this->entityType, $entity),
      '#name' => FALSE,
      '#url' => $entity_uri ? $entity_uri : FALSE,
      '#entity_type' => $this->entityType),
    );
    // Add in any passed additional cols.
    foreach ($additional_cols as $col) {
      $row[] = $col;
    }

    // Add the edit and delete links.
    $row[] = l(t('edit'), $this->path . '/' . $id);
    $row[] = l(t('delete'), $this->path . '/' . $id . '/delete', array('query' => drupal_get_destination()));

    return $row;
  }
}

/**
 * Generates the client editing form.
 */
function oauth2_server_client_form($form, &$form_state, $client, $op = 'edit') {
  // Make sure the parent server is present in form state.
  if (!isset($form_state['server'])) {
    $server = oauth2_server_load(arg(4));
    if (!$server) {
      return $form;
    }
    $form_state['server'] = $server;
  }
  // Set the server on new client entities, since it serves as the bundle.
  if (empty($client->server)) {
    $client->server = $form_state['server']->name;
  }
  // entity_form_field_validate() builds a fake entity from
  // $form_state['values'], so the bundle needs to be in there.
  $form['server'] = array(
    '#type' => 'value',
    '#value' => $form_state['server']->name,
  );

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $client->label,
    '#description' => t('The human-readable name of this client.'),
    '#required' => TRUE,
    '#weight' => -4,
  );
  $form['client_key'] = array(
    '#title' => t('Client ID'),
    '#type' => 'textfield',
    '#default_value' => $client->client_key,
    '#required' => TRUE,
    '#weight' => -3,
  );
  $form['client_secret'] = array(
    '#title' => t('Client secret'),
    '#type' => 'textarea',
    '#default_value' => $client->client_secret,
    '#required' => TRUE,
    '#weight' => -2,
  );
  $form['redirect_uri'] = array(
    '#title' => t('Redirect URI'),
    '#type' => 'textfield',
    '#default_value' => $client->redirect_uri,
    '#description' => t('The absolute URI to redirect to after authorization'),
    '#required' => TRUE,
    '#weight' => -1,
  );

  field_attach_form('oauth2_server_client', $client, $form, $form_state);

  $form['automatic_authorization'] = array(
    '#title' => t('Automatically authorize this client'),
    '#type' => 'checkbox',
    '#default_value' => $client->automatic_authorization,
    '#description' => t('This will cause the authorization form to be skipped. <b>Warning:</b> Give to trusted clients only!'),
    '#weight' => 39,
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save client'),
    '#weight' => 40,
  );

  if ($op != 'add') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete client'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('oauth2_server_client_form_submit_delete')
    );
  }
  return $form;
}

/**
 * Validation callback.
 */
function oauth2_server_client_form_validate($form, &$form_state) {
  entity_form_field_validate('oauth2_server_client', $form, $form_state);

  // The client key must be unique across servers.
  $client = $form_state['build_info']['args'][0];
  $client_key = $form_state['values']['client_key'];
  if (empty($client->client_id) || $client->client_key != $client_key) {
    if ($client = oauth2_server_client_load($client_key)) {
      form_set_error('client_key', t('The chosen Client ID is already in use.'));
    }
  }
}

/**
 * Form API submit callback for the type form.
 */
function oauth2_server_client_form_submit(&$form, &$form_state) {
  $client = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  $client->save();

  $server = arg(4);
  $form_state['redirect'] = 'admin/structure/oauth2-servers/manage/' . $server . '/clients';
}

/**
 * Form API submit callback for the delete button.
 */
function oauth2_server_client_form_submit_delete(&$form, &$form_state) {
  $server = arg(4);
  $form_state['redirect'] = 'admin/structure/oauth2-servers/manage/' . $server
                             . '/clients/' . $form_state['oauth2_server_client']->client_id . '/delete';
}

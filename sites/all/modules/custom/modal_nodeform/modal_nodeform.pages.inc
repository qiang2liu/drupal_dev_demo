<?php 
/**
  * Page Callback - Modal: Add Node
  */
function modal_nodeform_node_page_add($type, $js, $force_page_reload = FALSE) {
  // Fall back if $js is not set.
  if (!$js) {
    return drupal_goto('node/add/' . str_replace('_', '-', $type));
  }

  // Get node form defaults.
  global $user;
  $types = node_type_get_types();
  $node = (object) array(
    'uid' => $user->uid,
    'name' => (isset($user->name) ? $user->name : ''),
    'type' => $type,
    'language' => LANGUAGE_NONE
  );

  $title = t('Create @name', array('@name' => $types[$type]->name));

  modal_nodeform_node_form($node, $title, $force_page_reload);
}

/**
 * Page Callback - Modal: Edit Node
 */
function modal_nodeform_node_page_edit($node, $js, $force_page_reload = FALSE) {
  // Fall back if $js is not set.
  if (!$js) {
    return drupal_goto('node/' . $node->nid . '/edit/');
  }

  $type_name = node_type_get_name($node);
  $title = t('<em>Edit @type</em> @title', array('@type' => $type_name, '@title' => $node->title));

  modal_nodeform_node_form($node, $title, $force_page_reload);
}


/**
 * Build the Modal Form.
 *
 * @param object $node
 *   The node Object in edit case. In Add case it's only a pseudo node object.
 * @param string $title
 *   The Modal Popup Title.
 * @param boolean $force_page_reload 
 *   Indicates if page should be reloaded after form submission.
 */
function modal_nodeform_node_form($node, $title, $force_page_reload = FALSE) {
  $commands = array();

  ctools_include('node.pages', 'node', '');
  ctools_include('modal');
  ctools_include('ajax');

  $form_state = array(
    'ajax'  => TRUE,
    'build_info' => array(
      'args'  => array($node),
    ),
  );
  if(!isset($form_state['title'])) $form_state['title'] = $title;
	drupal_add_library('system', 'ui.dialog');
  $commands = ctools_modal_form_wrapper($node->type . '_node_form', $form_state);

  if (!empty($form_state['executed']) && empty($form_state['rebuild'])) {

      // overwrite commands.
      $commands = array();

      ctools_add_js('ajax-responder');
      $commands[] = ctools_modal_command_dismiss();
      // if (t('Delete') == $form_state['values']['op']) {
      //   $commands[] = ctools_ajax_command_redirect('modal/node/' . $node->nid . '/delete/ajax/reload');
      // }
      // else 
      if ($force_page_reload) {
        $commands[] = ctools_ajax_command_reload();
      }
  }

  // add CSS class to Modal-Frame
  //$commands[] = ajax_command_invoke('#modalContent', 'addClass', array('custom-module-node', 'custom-module-node-form'));

  print ajax_render($commands);
  exit;
}
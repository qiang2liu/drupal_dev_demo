<?php

/**
 * @file
 * Page of stage manage.
 */

/**
 * Edgemakers_stage_page().
 */
function edgemakers_stage_page() {

  ctools_include('modal');
  ctools_modal_add_js();

  $type = variable_get('edgemakers_stage_content_type', 'stage');
  $nodes = node_load_multiple(array(), array('type' => $type));

  $header = array(
    'title' => array('data' => t('Set Title')),
    'dimension' => array('data' => t('Dimension')),
    'operations' => t('Operations'),
  );

  $options = array();
  foreach ($nodes as $node) {

    $langcode = entity_language('node', $node);
    $l_options = $langcode != LANGUAGE_NONE && isset($languages[$langcode]) ? array('language' => $languages[$langcode]) : array();
    $destination = drupal_get_destination();

    // Dimension.
    if (isset($node->dimension_x[LANGUAGE_NONE])) {
      $dimension_x = $node->dimension_x[LANGUAGE_NONE][0]['value'];
    }
    if (isset($node->dimension_y[LANGUAGE_NONE])) {
      $dimension_y = $node->dimension_y[LANGUAGE_NONE][0]['value'];
    }

    $dimension = $dimension_x . " X " . $dimension_y;

    // Operations.
    $edit_url = l(t('Edit'),
      'modal/node/' . $node->nid . '/edit/nojs/1',
      array(
        'query' => array(
          'destination' => $_GET["q"],
        ),
        'attributes' => array(
          'class' => array('ctools-use-modal'),
        ),
      )
    );
    $managebox_url = l(t('Manage Stage'), 'admin/edgemakers/stage/managebox/' . $node->nid);
    $delete_url = l(t('Delete'), 'node/' . $node->nid . '/delete',
      array(
        'query' => array(
          'destination' => 'admin/edgemakers/stage',
        ),
        'attributes' => array(
          'onClick' => 'disp_confirm(this.id);return FALSE;',
          'id' => 'edgemakers-delete-' . $node->nid,
        ),
      )
    );

    $options[$node->nid] = array(
      'title' => check_plain($node->title),
      'dimension' => $dimension,
      'operations' => $delete_url . ' | ' . $edit_url . ' | ' . $managebox_url,
    );
  }
  $form['nodes'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $options,
    '#empty' => t('No content available.'),
  );
  $form['pager'] = array('#markup' => theme('pager'));
  $form['#prefix'] = '<div id="setesListDiv">';
  $form['#suffix'] = '</div>';

  drupal_add_js(drupal_get_path('module', 'edgemakers_stage') . '/js/edgemakers_stage_admin.js');

  return $form;

}

/**
 * Mangement box index.
 *
 * @param int $sid
 *   - Stage id.
 *
 * @return string
 *   - HTML code.
 */
function edgemakers_stage_managebox_page($sid = '') {

  drupal_add_library('system', 'drupal.ajax');
  ctools_include('modal');
  ctools_modal_add_js();

  $output = '';

  if ($sid) {

    $form = drupal_get_form('edgemakers_stage_managebox_form');
    $output .= drupal_render($form);

    $list_form = drupal_get_form('edgemakers_stage_set_list_form', $sid);
    $output .= '<div id="stage_manage_box_index_list">';
    $output .= drupal_render($list_form);
    $output .= '</div>';

  }
  else {
    drupal_goto('admin/edgemakers/stage');
  }

  return $output;

}

/**
 * Implements hook_form() for edgemakers_stage_managebox_form().
 */
function edgemakers_stage_managebox_form($form, &$form_state) {

  $form = array();
  $sid = arg(4);

  $form['stage_id'] = array(
    '#type' => 'hidden',
    '#default_value' => $sid,
  );

  $vid = variable_get('edgemakers_set_type_term', 1);

  $terms_tree = taxonomy_get_tree($vid);
  foreach ($terms_tree as $ter) {
    $perfix = '';
    for ($i = 0; $i < $ter->depth; $i++) {
      $perfix .= '-';
    }
    $terms_optins[$ter->tid] = $perfix . $ter->name;
  }

  // Get the list of options to populate the first dropdown.
  $options_first = $terms_optins;
  // If we have a value for the first dropdown from $form_state['values'] we use
  // this both as the default value for the first dropdown and also as a
  // parameter to pass to the function that retrieves the options for the
  // second dropdown.
  $selected = isset($form_state['values']['set_types']) ? $form_state['values']['set_types'] : key($options_first);

  $form['Set_Fields'] = array(
    '#type' => 'fieldset',
  );

  $form['Set_Fields']['set_types'] = array(
    '#type' => 'select',
    '#title' => 'Set Type',
    '#options' => $options_first,
    '#default_value' => $selected,

    // Bind an ajax callback to the change event (which is the default for the
    // select form type) of the first dropdown. It will replace the second
    // dropdown when rebuilt.
    '#ajax' => array(
      // When 'event' occurs, Drupal will perform an ajax request in the
      // background. Usually the default value is sufficient (eg. change for
      // select elements), but valid values include any jQuery event,
      // most notably 'mousedown', 'blur', and 'submit'.
      // 'event' => 'change',
      'callback' => '_ajax_set_types_dropdown_callback',
      'wrapper' => 'dropdown-title-replace',
    ),
  );

  $form['Set_Fields']['set_title'] = array(
    '#type' => 'select',
    '#title' => t('Set Title'),

    // The entire enclosing div created here gets replaced when dropdown_first
    // is changed.
    '#prefix' => '<div id="dropdown-title-replace">',
    '#suffix' => '</div>',

    // When the form is rebuilt during ajax processing, the $selected variable
    // will now have the new value and so the options will change.
    '#options' => _ajax_get_set_title_dropdown_options($selected),
    '#default_value' => isset($form_state['values']['set_title']) ? $form_state['values']['set_title'] : '',
  );

  $form['Set_Fields']['set_location_index'] = array(
    '#type' => 'hidden',
    '#title' => 'Set Location Index',
    '#required' => FALSE,
  );

  $form['add_set_to_stage'] = array(
    '#type' => 'submit',
    '#value' => t('Add set to stage'),
  );

  return $form;

}

/**
 * Build options of set_edgemakers_stage_managebox_form
 * @param int $sid
 */
/*function edgemakers_stage_default_set_list_table($sid) {
  $output = '';
  $sets = node_load($sid);
  $output = stage_list_table($sid);
  return $output;
}*/

/**
 * Get dropdown callback.
 *
 * @param array $form
 *   - $FORM element.
 *
 * @param array $form_state
 *   - $FORM form_state data.
 *
 * @return array
 *   - $form elements.
 */
function _ajax_set_types_dropdown_callback($form, $form_state) {
  return $form['Set_Fields']['set_title'];
}

/**
 * Get title options list by AJAX.
 *
 * @param int $tid
 *   - Term id.
 *
 * @return Ambigous
 *   - <An, multitype:>|multitype:
 */
function _ajax_get_set_title_dropdown_options($tid = '') {

  if ($tid) {
    if ($nids = taxonomy_select_nodes($tid)) {
      $set_options = array();
      $nodes = node_load_multiple($nids);
      foreach ($nodes as $n) {
        $set_options[$n->nid . ':' . $n->title] = $n->title;
      }
      return $set_options;
    }
  }

  return array();

}

/**
 * Implements hook_form_validate() for edgemakers_stage_managebox_form().
 */
function edgemakers_stage_managebox_form_validate($form, &$form_state) {

  $values = $form_state['values'];
  $set_info = explode(':', $values['set_title']);

  $set_nid = isset($set_info[0])?$set_info[0] : 0;
  $set_title = isset($set_info[1])?$set_info[1] : ' ';

  if (_has_set_in_stage($values['stage_id'], $set_nid)) {
    form_set_error('set_title', t('Set "@set" has in Stage now.', array('@set' => $set_title)));
  }

}

/**
 * Is exists set in stage list.
 *
 * @param int $stage_id
 *   - Stage id
 *
 * @param int $set_id
 *   - Set id
 *
 * @return bool
 *   - boolean.
 */
function _has_set_in_stage($stage_id = '', $set_id = '') {

  if ($stage_id && $set_id) {
    $stage = node_load($stage_id);

    if (isset($stage->box_index_data[LANGUAGE_NONE])) {
      $node_box_index_data = unserialize($stage->box_index_data[LANGUAGE_NONE][0]['value']);
      foreach ($node_box_index_data as $index) {
        if ($index['set_id'] == $set_id) {
          return TRUE;
        }
      }
      return FALSE;
    }
    else {
      return FALSE;
    }

  }
}

/**
 * Implements hook_form_submit() for edgemakers_stage_managebox_form().
 */
function edgemakers_stage_managebox_form_submit($form, &$form_state) {

  global $user;

  // Form data.
  if (empty($form_state['values']['set_location_index'])) {
    $form_state['values']['set_location_index'] = 0;
  }

  $values = $form_state['values'];
  $set_info = explode(':', $values['set_title']);
  $set_nid = isset($set_info[0])?$set_info[0] : 0;
  $ignore = array(
    'form_build_id',
    'form_token',
    'form_id',
    'op',
    'submit',
    'set_types',
    'set_title',
  );

  // Stage node data.
  $node = node_load($form_state['values']['stage_id']);

  if (isset($node->box_index_data[LANGUAGE_NONE])) {

    $node_box_index_data = unserialize($node->box_index_data[LANGUAGE_NONE][0]['value']);
    aasort($node_box_index_data, 'location_index');

    $i = -10;

    // Clean up while set node was deleted.
    foreach ($node_box_index_data as $key => $set_node) {
      if (!node_load($set_node['set_id'])) {
        drupal_set_message(t('Set list id: @key, Node @set_id has remove by other, remove it from list.',
          array(
            '@key' => $key,
            '@set_id' => $set_node['set_id'],
          )
        ));
        unset($node_box_index_data[$key]);
      }
      $node_box_index_data[$key]['location_index'] = $i;
      $i++;
    }

    if (empty($form_state['values']['set_location_index'])) {
      $max_index = $node_box_index_data[count($node_box_index_data) - 1]['location_index'];
      $set_location_index = 10;
    }
    else {
      $set_location_index = $form_state['values']['set_location_index'];
    }

  }
  else {
    $node_box_index_data = array();
    $set_location_index = 10;
  }

  $node_box_index_data[] = array(
    'stage_id' => $form_state['values']['stage_id'],
    'set_id' => $set_nid,
    'location_index' => $set_location_index,
  );

  $values['box_index_data'] = serialize($node_box_index_data);

  // Loop through the values.
  foreach ($values as $key => $value) {
    if (in_array($key, $ignore)) {
      continue;
    }
    $node->{$key}[$node->language][0]['value'] = $value;
  }

  $submit_status = node_submit($node);
  $save_status = node_save($node);

}

/**
 * Implements hook_form() for edgemakers_stage_set_list_form().
 */
function edgemakers_stage_set_list_form($form, &$form_state, $stage_id = '') {

  $operation = array();
  $destination = $_GET["q"];

  $stage = node_load($stage_id);

  if (isset($stage->box_index_data[LANGUAGE_NONE])) {
    $nodes = array();
    $stage_index = unserialize($stage->box_index_data[LANGUAGE_NONE][0]['value']);

    $stage_index_sort = array();
    foreach ($stage_index as $key => $row) {
      $stage_index_sort[$key] = $row['location_index'];
    }
    array_multisort($stage_index_sort, SORT_ASC, $stage_index);

    foreach ($stage_index as $index) {
      $nid = !empty($index['set_id'])?$index['set_id'] : 0;
      if ($nid) {
        $node = node_load($nid);

        if (isset($node->nid)) {
          $node->weight = $index['location_index'];

          // Get box type by tid.
          if (isset($node->field_set_type[LANGUAGE_NONE])) {
            $node->tname = taxonomy_term_load($node->field_set_type[LANGUAGE_NONE][0]['tid']);
          }
        }

        $nodes[] = $node;
      }
    }

    $results = $tree = $nodes;

  }

  $header = array(
    'title' => array('data' => t('Set Title')),
    'type' => array('data' => t('Set Type')),
    'weight' => t('Weight'),
  );

  $form['#tree'] = TRUE;
  $form['stage_id'] = array(
    '#type' => 'hidden',
    '#value' => $stage_id,
  );

  // Fetch the example data from the database, ordered by weight ascending.
  // This query excludes the last two tabledrag_example database rows, as
  // they are intended only for the 'parent/child' tabledrag examples.
  // Iterate through each database result.
  if (isset($results)) {
    foreach ($results as $item) {

      if (isset($item->nid)) {

        // Create a form entry for this item.
        // Each entry will be an array using the the unique id for that item as
        // the array key, and an array of table row data as the value.
        $delete_url = url('admin/edgemakers/stage/setindex/ajaxdelete/' . $stage_id . '/' . $item->nid . '/nojs/1',
          array(
            'query' => array(
              'destination' => $_GET["q"],
            ),
          )
        );

        $delete_url = 'admin/edgemakers/stage/setindex/delete/'
          . $stage_id . '/' . $item->nid . '/0/0/&destination=' . $_GET["q"];

        $form['set_' . $item->nid] = array(

          // We'll use a form element of type '#markup' to display the item
          // title.
          'name' => array(
            '#markup' => check_plain($item->title),
          ),

          'type' => array(
            '#markup' => check_plain($item->tname->name),
          ),

          'operations' => array(
            '#type' => 'link',
            '#title' => t('delete'),
            '#href' => $delete_url,
            '#attributes' => array(
              'class' => array(
                'delete-action',
              ),
              'onClick' => 'disp_confirm(this.id);return FALSE;',
              'id' => 'edgemakers-delete-set-' . $item->nid,
            ),
          ),

          // The 'weight' field will be manipulated as we move the items around
          // in the table using the tabledrag activity.  We use the 'weight'
          // element defined in Drupal's Form API.
          'weight' => array(
            '#type' => 'weight',
            '#title' => t('Weight'),
            '#default_value' => $item->weight,
            '#delta' => 10,
            '#title-display' => 'invisible',
          ),
        );

      }

    }
  }

  // Now we add our submit button, for submitting the form results.
  // The 'actions' wrapper used here isn't strictly necessary for tabledrag,
  // but is included as a Form API recommended practice.
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Changes'),
  );

  drupal_add_js(drupal_get_path('module', 'edgemakers_stage') . '/js/edgemakers_stage_admin.js');

  return $form;

}

/**
 * Implements hook_form_validate() for edgemakers_stage_set_list_form().
 */
function edgemakers_stage_set_list_form_validate($form, &$form_state) {

}

/**
 * Implements hook_form_submit() for edgemakers_stage_set_list_form().
 */
function edgemakers_stage_set_list_form_submit($form, &$form_state) {

  $values = $form_state['values'];

  $stage = node_load($values['stage_id']);

  if (isset($stage->box_index_data[LANGUAGE_NONE])) {

    $stage_index = unserialize($stage->box_index_data[LANGUAGE_NONE][0]['value']);

    foreach ($stage_index as $key => $index) {
      if (is_numeric($index['set_id'])) {
        if (isset($values['set_' . $index['set_id']])) {
          $location_index = $values['set_' . $index['set_id']];
          $stage_index[$key]['location_index'] = $values['set_' . $index['set_id']]['weight'];
        }
      }
    }

    // Update index data in stage.
    $stage->box_index_data[$stage->language][0]['value'] = serialize($stage_index);

    node_submit($stage);
    $save_status = node_save($stage);

  }

}

/**
 * Implements hook_theme_form() for edgemakers_stage_set_list_form().
 */
function theme_edgemakers_stage_set_list_form($variables) {

  $form = $variables['form'];

  // Initialize the variable which will store our table rows.
  $rows = array();

  // Iterate over each element in our $form['example_items'] array.
  foreach (element_children($form) as $id) {

    // Before we add our 'weight' column to the row, we need to give the
    // element a custom class so that it can be identified in the
    // drupal_add_tabledrag call.
    //
    // This could also have been done during the form declaration by adding
    // '#attributes' => array('class' => 'example-item-weight'),
    // directy to the 'weight' element in tabledrag_example_simple_form().
    $form[$id]['weight']['#attributes']['class'] = array('example-item-weight');

    // We are now ready to add each element of our $form data to the $rows
    // array, so that they end up as individual table cells when rendered
    // in the final table.  We run each element through the drupal_render()
    // function to generate the final html markup for that element.
    if (isset($form[$id]['name'])) {
      $rows[] = array(
        'data' => array(

          // Add our 'name' column.
          drupal_render($form[$id]['name']),

          // Add our 'description' column.
          drupal_render($form[$id]['type']),

          // Add our 'weight' column.
          drupal_render($form[$id]['weight']),

          drupal_render($form[$id]['operations']),
        ),

        // To support the tabledrag behaviour, we need to assign each row of the
        // table a class attribute of 'draggable'. This will add the 'draggable'
        // class to the <tr> element for that row when the final table is
        // rendered.
        'class' => array('draggable'),
      );
    }
  }

  // We now define the table header values.  Ensure that the 'header' count
  // matches the final column count for your table.
  $header = array(t('Name'), t('Type'), t('Weight'), t('Operations'));

  // We also need to pass the drupal_add_tabledrag() function an id which will
  // be used to identify the <table> element containing our tabledrag form.
  // Because an element's 'id' should be unique on a page, make sure the value
  // you select is NOT the same as the form ID used in your form declaration.
  $table_id = 'example-items-table';

  // We can render our tabledrag table for output.
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => $table_id),
  ));

  // And then render any remaining form elements (such as our submit button).
  $output .= drupal_render_children($form);

  // We now call the drupal_add_tabledrag() function in order to add the
  // tabledrag.js goodness onto our page.
  //
  // For a basic sortable table, we need to pass it:
  // - the $table_id of our <table> element,
  // - the $action to be performed on our form items ('order'),
  // - a string describing where $action should be applied ('siblings'),
  // - and the class of the element containing our 'weight' element.
  drupal_add_tabledrag($table_id, 'order', 'sibling', 'example-item-weight');

  return $output;

}

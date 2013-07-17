<?php

/**
 * page callback function  of the menu item $items['learn/%modulestages/stage']
 * @param type $fte_learn_module_obj 
 */
function fte_modulestage_view($mid, $sid) {
  global $base_url, $is_showstage_page;
  $is_showstage_page = 1;
  //drupal_add_library('system', 'jquery.cookie');
  // $the_path = drupal_get_path('module', 'fte_curriculum');
  // drupal_add_js($the_path.'/js/fte_stage_show.js');
  $mid = (int) $mid;
  $sid = (int) $sid;
  if ($mid <= 1) {
    $mid = 1;
  }
  if ($sid <= 0) {
    $sid = 0;
  }
  $current_yid = isset($_COOKIE['fte_learn_current_yid']) ? $_COOKIE['fte_learn_current_yid'] : '';
  $current_time = isset($_COOKIE['fte_learn_playtime']) ? $_COOKIE['fte_learn_playtime'] : 0;
  $current_mid = isset($_COOKIE['fte_learn_current_mid']) ? $_COOKIE['fte_learn_current_mid'] : 1;
  $current_stage_id = isset($_COOKIE['current_stage_id']) ? $_COOKIE['current_stage_id'] : 1;


 


  $ret = new stdClass();

  $stage_list = get_stage_list($mid);
  if ($stage_list == -1) {
    return "no stages";
  }
  dpm($stage_list);
  $index_sid = 1;
  foreach ($stage_list as $k => $v) {
    $v1 = new stdClass();
    $v1->title = check_plain($v->title);
    $v1->sid = $index_sid;
    $v1->desc = render(field_view_field('node',$v,'body',array('label'=>'hidden')));

    switch ($v->type) {
      case 'stages_template1': //stage text template
        $v1->yid = '';
        $v1->play = 0;
        $v1->time = 0;
        $the_desc_array = field_get_items('node', $v, 'field_stage_text');
        $v1->content = $the_desc_array[0]['safe_value'];
        $v1->content_bottom = theme('fte_learn_module_stage_bottom_style_1', array('data' => $v1));

        break;
      case 'stage_mural_template':
       

        $v1->yid = '';
        $v1->content = '<iframe src="http://mrl.li/14zQVid" width="730" height="330" frameborder="0" webkitAllowFullScreen mozallowfullscreen allowFullScreen></iframe>';

        $v1->content_bottom = theme('fte_learn_module_stage_bottom_style_3', array('data' => $v1));

        $v1->content_right = theme('fte_learn_module_stage_right', array('data' => $v1));

        break;
      case 'stages_template2': //stage video template
        $the_video_array = field_get_items('node', $v, 'field_video_key');
        $the_video_url = $the_video_array[0]['safe_value'];
      
        $str_p = preg_match("/[a-z|A-Z|0-9]+$/", $the_video_url, $matches);
        $v1->yid = '';
        if ($str_p) {
          $v1->yid = $matches[0];
         
         
        }
         $v1->play = 0;
          $v1->time = 0;
          $v1->content_bottom = theme('fte_learn_module_stage_bottom_style_2', array('data' => $v1));

       break;
       case 'stage_assignment_template':
         $v1->yid = '';
    
      $the_node = clone $v;
      unset($the_node->field_stage_order);
      unset($the_node->field_parent_m);
      unset($the_node->body);
      $v1->content = render(node_view($the_node,'full',NULL));
      unset($the_node);
      $v1->content_bottom = theme('fte_learn_module_stage_bottom_style_4', array('data' => $v1->sid));
      $v1->content_right = theme('fte_learn_module_stage_right', array('data' => $v1->sid));
    
         
       break;  
        
    }
    $ret->stages[$index_sid] = $v1;
       $index_sid++;
  }
   $ret->mid = $mid;
   
  
    dpm($ret);


    if ($current_mid == $mid ) {
      if ($sid == $current_stage_id) {
       
        $ret->stagedata = clone $ret->stages[$current_stage_id];
        $ret->stagedata->time = $current_time;
      } else {
        if ($sid > 0 && isset($ret->stages[$sid])) {
          $ret->stagedata = clone $ret->stages[$sid];
          $ret->stagedata->time = 0;
        } else { //$sid == 0
          $ret->stagedata = clone $ret->stages[$current_stage_id];
          $ret->stagedata->time = $current_time;
        }
      }
    } else {
      if ($sid > 0 && isset($ret->stages[$sid])) {
        $ret->stagedata = clone $ret->stages[$sid];
        $ret->stagedata->time = 0;
      } else {
        $ret->stagedata = clone $ret->stages[1];
        $ret->stagedata->time = 0;
      }
    }

    $the_next_item_index = $ret->stagedata->sid + 1;
    if (isset($ret->stages[$the_next_item_index])) {
      $ret->stagedata->next_sid = $the_next_item_index;
    } else {
      $ret->stagedata->next_sid = '-1';
    }
    $ret->stagedata->next_mid = $mid;
    dpm($ret);
    return theme('fte_learn_module_stage_show', array('data' => $ret));
  }

  function learnnavpage() {

    $data = get_learn_nav_info();
    //drupal_add_js(array('fte_learn_nav' => $data), 'setting');

    return theme('fte_learn_nav', array('data' => $data));
  }

  function get_learn_nav_info() {
    $ret = array();
    // get theme list
    $ftetheme_list = get_ftetheme_list();
    $ret = $ftetheme_list;
    //get module list
    if (!empty($ftetheme_list)) {
      $ftetheme_ids = array_keys($ftetheme_list);
      $ftemodule_list = get_ftemodule_list($ftetheme_ids);
      if (is_array($ftemodule_list)) {
        foreach ($ftemodule_list as $m_nid => $v) {
          $the_parent_v = field_get_items('node', $v, 'field_parent');
          $the_parent_id = $the_parent_v[0]['target_id'];
          if (isset($ret[$the_parent_id])) {
            $ret[$the_parent_id]->modules[$m_nid] = $v;
          }
        }
      }
    }

    $data = array();
    if (!empty($ret)) {
      foreach ($ret as $k => $v) {
        $data[$k]['title'] = check_plain($v->title);
        $data[$k]['ftemodule'] = array();
        if (isset($v->modules)) {
          foreach ($v->modules as $m_k => $m_v) {
            $data[$k]['ftemodule'][$m_k]['title'] = check_plain($m_v->title);
            // $the_desc_array  = field_view_field('node',$m_v,'body',array('label'=>'hidden'));
            // $data[$k]['ftemodule'][$m_k]['desc'] = render($the_desc_array);
            $the_desc_array = field_get_items('node', $m_v, 'body');
            $data[$k]['ftemodule'][$m_k]['desc'] = $the_desc_array[0]['safe_value'];
          }
        }
      }
    }

    return $data;
  }

  function get_ftemodule_list($ftetheme_ids) {
    $ret = array();
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'curriculum_modules')
            ->fieldCondition('field_parent', 'target_id', $ftetheme_ids, 'in')
            ->fieldOrderBy('field_parent', 'target_id', 'ASC')
            ->fieldOrderBy('field_sequence_order', 'value', 'ASC');

    $results = $query->execute();
    $the_modules_nid = array_keys($results['node']);
    return node_load_multiple($the_modules_nid);
  }

  function get_ftetheme_list() {

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'educational_curriculum_theme')
            ->fieldCondition('field_active', 'value', 1, '=')
            ->fieldOrderBy('field_sequence_order', 'value', 'ASC');

    $results = $query->execute();
    $the_themes_nid = array_keys($results['node']);
    return node_load_multiple($the_themes_nid);
  }

  function get_stage_list($mid) {
    $the_stage_bundles = array('stages_template2', 'stages_template1', 'stage_mural_template', 'stage_assignment_template');
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', $the_stage_bundles, 'IN')
            ->fieldCondition('field_parent_m', 'target_id', $mid, '=')
            ->fieldOrderBy('field_stage_order', 'value', 'ASC');
    $results = $query->execute();
    if (!isset($results['node'])) {
      return -1; // no data;
    }
    $the_stage_nid = array_keys($results['node']);
    return node_load_multiple($the_stage_nid);
  }

 
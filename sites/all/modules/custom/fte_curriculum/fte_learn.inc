<?php

/**
 * page callback function  of the menu item $items['learn/%modulestages/stage']
 * @param type $fte_learn_module_obj 
 */
function fte_modulestage_view($mid, $sid) {

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


  if ($mid == 1) {
    $v1 = new stdClass();
    $v1->title = 'stage1';
    $v1->sid = 1;
    $v1->content = '';
    $v1->yid = '6rSHgAcL0cQ';
    $v1->play = 0;
    $v1->time = 0;
    $ret->stages[1] = $v1;

    $v1 = new stdClass();
    $v1->title = 'stage2';
    $v1->sid = 2;
    $v1->yid = 'gAEFqKEfJok';
    $v1->play = 0;
    $v1->time = 0;
    $ret->stages[2] = $v1;
    
    $v1 = new stdClass();
    $v1->title = 'stage3';
    $v1->yid = '_NyrClqr8zo';
    $v1->sid = 3;
    $v1->play = 0;
    $v1->time = 0;
    $ret->stages[3] = $v1;
    

    $v1 = new stdClass();    
    $v1->title = 'stage4';
    $v1->yid = 'ukijAPN6bkw';
    $v1->sid = 4;
    $v1->play = 0;
    $v1->time = 0;
   
    $ret->stages[4] = $v1;


   

    $v1 = new stdClass();
    $v1->title = 'stage5';
    $v1->sid = 5;
    $v1->yid = '';
    $v1->content = '<h2>Murally page.</h2>';
    $ret->stages[5] = $v1;

    $v1 = new stdClass();
    $v1->title = 'stage6';
    $v1->yid = '';
    $v1->sid = 6;
    $v1->content = '<h2>Self Assessment</h2> 
      <br/>How did that last activity make me feel? <input type="text" name="input1" size="20"/>
      <br/>How well do I think I did on that last activity? <input type="text" name="input2" size="20"/> 
      <br/>How do I think I am doing against a long-tern goal? 
      <input type="radio" name="input3" value="1"/> No
      <input type="radio" name="input3" value="2" checked/> Yes
      <input type="radio" name="input3" value="3"/> Other
      <input type="text" name="input4" size="20"/>
        
      <br/>
      
        How much did I like that last activity? 
      <input type="radio" name="input4" value="1"/> Liked it
      <input type="radio" name="input4" value="2" checked/> Loved it
      <input type="radio" name="input4" value="3"/> Comments
      <input type="text" name="input5" size="20"/>
        
      <br/>
What was your favorite activity?why?: <input type="text" name="input6" size="20"/>



';
    $ret->stages[6] = $v1;

    $v1 = new stdClass();
    $v1->title = 'stage7';
    $v1->yid = '';
    $v1->sid = 7;
    $v1->content = '<h2>Murally page.</h2>';
    $ret->stages[7] = $v1;


    $v1 = new stdClass();
    $v1->title = 'stage8';
    $v1->sid = 8;
    $v1->yid = '';
    $v1->content = '<h2>Self Assessment</h2> 
      <br/>How did that last activity make me feel? <input type="text" name="input1" size="20"/>
      <br/>How well do I think I did on that last activity? <input type="text" name="input2" size="20"/> 
      <br/>How do I think I am doing against a long-tern goal? 
      <input type="radio" name="input3" value="1"/> No
      <input type="radio" name="input3" value="2" checked/> Yes
      <input type="radio" name="input3" value="3"/> Other
      <input type="text" name="input4" size="20"/>
        
      <br/>
      
        How much did I like that last activity? 
      <input type="radio" name="input4" value="1"/> Liked it
      <input type="radio" name="input4" value="2" checked/> Loved it
      <input type="radio" name="input4" value="3"/> Comments
      <input type="text" name="input5" size="20"/>
        
      <br/>
What was your favorite activity?why?: <input type="text" name="input6" size="20"/>



';
    $ret->stages[8] = $v1;

    $ret->mid = 1;
    $ret->title = check_plain('module 1');
  }

  if ($mid == 2) {
    $v1 = new stdClass();
    $v1->title = 'stage1';
    $v1->sid = 1;
    $v1->yid = 'O5rTcz7EXEQ';
    $v1->play = 0;
    $v1->time = 0;
    $ret->stages[1] = $v1;

    $v1 = new stdClass();
    $v1->title = 'stage2';
    $v1->sid = 2;
    $v1->yid = 'wJ4iT0QQ1do';
    $v1->play = 0;
    $v1->time = 0;
    $ret->stages[2] = $v1;

    $v1 = new stdClass();
    $v1->title = 'stage3';
    $v1->yid = 'WTsfdROiotA';
    $v1->sid = 3;
    $v1->play = 0;
    $v1->time = 0;
    $ret->stages[3] = $v1;
    $ret->mid = 2;
    $ret->title = check_plain('module 2');
  }

  if ($current_mid == $mid) {
    if ($sid == $current_stage_id) {
      $ret->stagedata = $ret->stages[$current_stage_id];
      $ret->stagedata->time = $current_time;
    } else {
      if ($sid > 0 && isset($ret->stages[$sid])) {
        $ret->stagedata = $ret->stages[$sid];
        $ret->stagedata->time = 0;
      } 
      else { //$sid == 0
        $ret->stagedata = $ret->stages[$current_stage_id];
        $ret->stagedata->time = $current_time;
      }
    }
  } else {
    if ($sid > 0 && isset($ret->stages[$sid])) {
      $ret->stagedata = $ret->stages[$sid];
      $ret->stagedata->time = 0;
    } else {
      $ret->stagedata = $ret->stages[1];
      $ret->stagedata->time = 0;
    }
  }
  
  $the_next_item_index =   $ret->stagedata->sid + 1;
  if (isset ($ret->stages[$the_next_item_index])) {
    $ret->stagedata->next_sid = $the_next_item_index;
  } else {
     $ret->stagedata->next_sid = '-1';
  }
  $ret->stagedata->next_mid = $mid;

  return theme('fte_learn_module_stage_show', array('data' => $ret));
}

function learnnavpage() {

  $data = get_learn_nav_info();
  //drupal_add_js(array('fte_learn_nav' => $data), 'setting');


  return theme('fte_learn_nav');
}

function get_learn_nav_info() {
  $ret = array();

  $nav = new stdClass();
  $nav->id = '';
  $nav->url = '';
  $nav->name = check_plain('Finding our bearing');
  $nav->type = 'curriculum';
  $nav->children = array();

  $module = new stdClass();
  $module->name = check_plain('Learning forward');
  $module->type = 'module';
  $module->id = '';
  $module->url = '';
  $module->children = array();

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/111';
  $stage->name = check_plain('Intro to FTE');
  $stage->type = 'stage';
  $stage->children = '';

  $module->children[] = $stage;


  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/112';
  $stage->name = check_plain('Brieana video');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/113';
  $stage->name = check_plain('John video');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/114';
  $stage->name = check_plain('Think Different');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/115';
  $stage->name = check_plain('Project assignment');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/116';
  $stage->name = check_plain('Murally assignment');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/117';
  $stage->name = check_plain('Self Assessment');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $nav->children[] = $module;



  $module = new stdClass();
  $module->name = check_plain('Innovation 101');
  $module->type = 'module';
  $module->id = '';
  $module->url = '';
  $module->children = array();

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/118';
  $stage->name = check_plain('Innovation stage 1');
  $stage->type = 'stage';
  $stage->children = '';

  $module->children[] = $stage;


  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/119';
  $stage->name = check_plain('Innovation stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/120';
  $stage->name = check_plain('Innovation stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/121';
  $stage->name = check_plain('Innovation stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $nav->children[] = $module;


  $module = new stdClass();
  $module->name = check_plain('collaboration');
  $module->type = 'module';
  $module->id = '';
  $module->url = '';
  $module->children = array();

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/122';
  $stage->name = check_plain('collaboration stage 1');
  $stage->type = 'stage';
  $stage->children = '';

  $module->children[] = $stage;


  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/123';
  $stage->name = check_plain('collaboration stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/124';
  $stage->name = check_plain('collaboration stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/125';
  $stage->name = check_plain('collaboration stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $nav->children[] = $module;


  $module = new stdClass();
  $module->name = check_plain('Team building');
  $module->type = 'module';
  $module->id = '';
  $module->url = '';
  $module->children = array();

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/122';
  $stage->name = check_plain('Team building stage 1');
  $stage->type = 'stage';
  $stage->children = '';

  $module->children[] = $stage;


  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/123';
  $stage->name = check_plain('Team building stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/124';
  $stage->name = check_plain('Team building stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/125';
  $stage->name = check_plain('Team building stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $nav->children[] = $module;

  $ret[] = $nav;


  /*   * **************** */
  $nav = new stdClass();
  $nav->id = '';
  $nav->url = '';
  $nav->name = check_plain('Finding our purpose');
  $nav->type = 'curriculum';
  $nav->children = array();

  $module = new stdClass();
  $module->name = check_plain('purpose module 1');
  $module->type = 'module';
  $module->id = '';
  $module->url = '';
  $module->children = array();

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/111';
  $stage->name = check_plain('purpose module 1 stage 1');
  $stage->type = 'stage';
  $stage->children = '';

  $module->children[] = $stage;


  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/112';
  $stage->name = check_plain('purpose module 1 stage 2 ');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/113';
  $stage->name = check_plain('purpose module 1 stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/114';
  $stage->name = check_plain('purpose module 1 stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/115';
  $stage->name = check_plain('purpose module 1 stage 5');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/116';
  $stage->name = check_plain('purpose module 1 stage 6');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/117';
  $stage->name = check_plain('purpose module 1 stage 7');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $nav->children[] = $module;



  $module = new stdClass();
  $module->name = check_plain('purpose module 2');
  $module->type = 'module';
  $module->id = '';
  $module->url = '';
  $module->children = array();

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/118';
  $stage->name = check_plain('purpose module 2 stage 1');
  $stage->type = 'stage';
  $stage->children = '';

  $module->children[] = $stage;


  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/119';
  $stage->name = check_plain('purpose module 2 stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/120';
  $stage->name = check_plain('purpose module 2  stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/121';
  $stage->name = check_plain('purpose module 2  stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $nav->children[] = $module;


  $module = new stdClass();
  $module->name = check_plain('purpose module 3');
  $module->type = 'module';
  $module->id = '';
  $module->url = '';
  $module->children = array();

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/122';
  $stage->name = check_plain('purpose module 3 stage 1');
  $stage->type = 'stage';
  $stage->children = '';

  $module->children[] = $stage;


  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/123';
  $stage->name = check_plain('purpose module 3 stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/124';
  $stage->name = check_plain('purpose module 3 stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/125';
  $stage->name = check_plain('purpose module 3 stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $nav->children[] = $module;


  $module = new stdClass();
  $module->name = check_plain('purpose module 4');
  $module->type = 'module';
  $module->id = '';
  $module->url = '';
  $module->children = array();

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/122';
  $stage->name = check_plain('purpose module 4 stage 1');
  $stage->type = 'stage';
  $stage->children = '';

  $module->children[] = $stage;


  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/123';
  $stage->name = check_plain('purpose module 4 stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/124';
  $stage->name = check_plain('purpose module 4 stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/125';
  $stage->name = check_plain('purpose module 4 stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $nav->children[] = $module;

  $ret[] = $nav;


  /*   * **************** */
  /*   * **************** */
  $nav = new stdClass();
  $nav->id = '';
  $nav->url = '';
  $nav->name = check_plain('Finding our "how"');
  $nav->type = 'curriculum';
  $nav->children = array();

  $module = new stdClass();
  $module->name = check_plain('how module 1');
  $module->type = 'module';
  $module->id = '';
  $module->url = '';
  $module->children = array();

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/111';
  $stage->name = check_plain('how module 1 stage 1');
  $stage->type = 'stage';
  $stage->children = '';

  $module->children[] = $stage;


  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/112';
  $stage->name = check_plain('how module 1 stage 2 ');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/113';
  $stage->name = check_plain('how module 1 stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/114';
  $stage->name = check_plain('how module 1 stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/115';
  $stage->name = check_plain('how module 1 stage 5');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/116';
  $stage->name = check_plain('how module 1 stage 6');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/117';
  $stage->name = check_plain('how module 1 stage 7');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $nav->children[] = $module;



  $module = new stdClass();
  $module->name = check_plain('how module 2');
  $module->type = 'module';
  $module->id = '';
  $module->url = '';
  $module->children = array();

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/118';
  $stage->name = check_plain('how module 2 stage 1');
  $stage->type = 'stage';
  $stage->children = '';

  $module->children[] = $stage;


  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/119';
  $stage->name = check_plain('how module 2 stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/120';
  $stage->name = check_plain('how module 2  stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/121';
  $stage->name = check_plain('how module 2  stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $nav->children[] = $module;


  $module = new stdClass();
  $module->name = check_plain('how module 3');
  $module->type = 'module';
  $module->id = '';
  $module->url = '';
  $module->children = array();

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/122';
  $stage->name = check_plain('how module 3 stage 1');
  $stage->type = 'stage';
  $stage->children = '';

  $module->children[] = $stage;


  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/123';
  $stage->name = check_plain('how module 3 stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/124';
  $stage->name = check_plain('how module 3 stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/125';
  $stage->name = check_plain('how module 3 stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $nav->children[] = $module;


  $module = new stdClass();
  $module->name = check_plain('how module 4');
  $module->type = 'module';
  $module->id = '';
  $module->url = '';
  $module->children = array();

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/122';
  $stage->name = check_plain('how module 4 stage 1');
  $stage->type = 'stage';
  $stage->children = '';

  $module->children[] = $stage;


  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/123';
  $stage->name = check_plain('how module 4 stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/124';
  $stage->name = check_plain('how module 4 stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $stage = new stdClass();
  $stage->id = '';
  $stage->url = 'node/125';
  $stage->name = check_plain('how module 4 stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;

  $nav->children[] = $module;

  $ret[] = $nav;

  return $ret;
}


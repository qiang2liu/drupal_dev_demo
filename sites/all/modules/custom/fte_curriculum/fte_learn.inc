<?php

/**
 * page callback function  of the menu item $items['learn/%modulestages/stage']
 * @param type $fte_learn_module_obj 
 */
function fte_modulestage_view($mid, $sid) {
  global $base_url;
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
    $v1->content = "<p>You see the state of the world and you want to make a difference.</p>

<p>You have an idea about your future and you want to make it real</p>

<p>You have a burning desire to realize an idea and make it come alive.</p>

<p></h2>AND YOU WANT TO KNOW HOW.</h2></p>

<p>To do these things, you’ll have to learn to lean forward – how to create new ideas, to breathe life into them and make them real.</p>

<p>When you’ve gone through these courses, you’ll have acquired a whole new set of perspectives and skills that will allow you to find the edge – the edge for you, the edge of cool, the edge of what’s possible. </p>

<p>When this module is over, you will be clearer on your own calling and more able to lean forward yourself.  To make new and valuable things come to life.  You will understand more about what people who are able to lean forward are good at.</p>

<p>And you’ll be ready to take more steps into the learning journey that we have created for you</p>

";
    $v1->yid = '';    //'6rSHgAcL0cQ';
    $v1->play = 0;
    $v1->time = 0;
    $v1->content_bottom = theme('fte_learn_module_stage_bottom_style_1',array('data' => 1));
    
    $ret->stages[1] = $v1;

    $v1 = new stdClass();
    $v1->title = 'stage2';
    $v1->sid = 2;
    $v1->yid = '6rSHgAcL0cQ'; //'gAEFqKEfJok';
    $v1->content_bottom = theme('fte_learn_module_stage_bottom_style_2',array('data' => 2));
    $v1->play = 0;
    $v1->time = 0;
    $ret->stages[2] = $v1;
    
    $v1 = new stdClass();
    $v1->title = 'stage3';
    $v1->yid = '_NyrClqr8zo';
    $v1->sid = 3;
    $v1->play = 0;
    $v1->time = 0;
    $v1->content_bottom = theme('fte_learn_module_stage_bottom_style_2',array('data' => 3));
    $ret->stages[3] = $v1;
    

    $v1 = new stdClass();    
    $v1->title = 'stage4';
    $v1->yid = 'ukijAPN6bkw';
    $v1->sid = 4;
    $v1->play = 0;
    $v1->time = 0;
    $v1->content_bottom = theme('fte_learn_module_stage_bottom_style_2',array('data' => 4));
   
    $ret->stages[4] = $v1;


   

    $v1 = new stdClass();
    $v1->title = 'stage5';
    $v1->sid = 5;
    $v1->yid = '';
    $v1->content = '<h2>Murally page.</h2>';
   
   $v1->content_bottom = theme('fte_learn_module_stage_bottom_style_3',array('data' => 5));
    
   $v1->content_right = theme('fte_learn_module_stage_right',array('data' => 5));
   
   $ret->stages[5] = $v1;
    
    $v1 = new stdClass();
    $v1->title = 'stage6';
    $v1->sid = 6;
    $v1->yid = '';
    $v1->content = '<h2>Murally page.</h2>';
    $v1->content_bottom = theme('fte_learn_module_stage_bottom_style_3',array('data' => 6));
   $v1->content_right = theme('fte_learn_module_stage_right',array('data' => 6));
    $ret->stages[6] = $v1;
    
    

    $v1 = new stdClass();
    $v1->title = 'stage7';
    $v1->yid = '';
    $v1->sid = 7;
    $v1->content = '<h2> Assessment</h2> 
      <br/>How doyou feel about this Module?
      <select>
        <option>0</option>
        <option>1</option>
        <option>2</option>
        <option>3</option>
        <option>4</option>
        <option>5</option>
        <option>6</option>
        <option>7</option>
        <option>8</option>
        <option>9</option>
        <option>10</option>
        
      </select>
      <br/>
      <br/>Please type in your feelings about your performance? <br/>
      &nbsp;&nbsp;<textarea rows="6" cols="30"></textarea>
     
        
      <br/><br/>
      
       Please select which of the statement is most true for you...<br/>
     <select>
        <option>incredible site!</option>
        <option>pretty cool site</option>
        <option>yah-whatever site</option>
        <option>this site sucks...</option>
       
        
      </select>
      
      <br/><br/>
      Here\'s what I would suggest to make this module better...<br/>
       &nbsp;&nbsp;<textarea rows="6" cols="30"></textarea>
       
      <br/><br/>
      
There images should have been used for this Module<br/>
<input name="shouldusedimage" value="image1" type="checkbox">
<img width=30px height=30px src="'.$base_url.'/images/mock_challenges_1.jpg"/>

<input name="shouldusedimage" value="image2" type="checkbox">
<img width=30px height=30px src="'.$base_url.'/images/mock_challenges_2.jpg"/>


<input name="shouldusedimage" value="image3" type="checkbox">
<img width=30px height=30px src="'.$base_url.'/images/mock_challenges_3.jpg"/>
<input name="shouldusedimage" value="image4" type="checkbox">
<img width=30px height=30px src="'.$base_url.'/images/mock_challenges_4.jpg"/>  
        
    <br/>


';
   $v1->content_bottom = theme('fte_learn_module_stage_bottom_style_4',array('data' => 7));
   $v1->content_right = theme('fte_learn_module_stage_right',array('data' => 7));
     $ret->stages[7] = $v1;
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


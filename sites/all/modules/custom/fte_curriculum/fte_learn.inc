<?php

function learnnavpage() {
  
  $data = get_learn_nav_info();
  drupal_add_js(array('fte_learn_nav' => $data), 'setting');
  $the_path = drupal_get_path('module', 'fte_curriculum');
  drupal_add_js($the_path.'/js/fte_learn.js');
  
  
  return theme('fte_learn_nav');
  
  
  
}

function get_learn_nav_info() {
  $ret = array();
  
  $nav = new stdClass();
  $nav->id= '';
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
  $stage->id= '';
  $stage->url = 'node/111';
  $stage->name = check_plain('Intro to FTE');
  $stage->type = 'stage';
  $stage->children = '';
  
  $module->children[] = $stage;
  
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/112';
  $stage->name = check_plain('Brieana video');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/113';
  $stage->name = check_plain('John video');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/114';
  $stage->name = check_plain('Think Different');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/115';
  $stage->name = check_plain('Project assignment');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/116';
  $stage->name = check_plain('Murally assignment');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
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
  $stage->id= '';
  $stage->url = 'node/118';
  $stage->name = check_plain('Innovation stage 1');
  $stage->type = 'stage';
  $stage->children = '';
  
  $module->children[] = $stage;
  
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/119';
  $stage->name = check_plain('Innovation stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/120';
  $stage->name = check_plain('Innovation stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
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
  $stage->id= '';
  $stage->url = 'node/122';
  $stage->name = check_plain('collaboration stage 1');
  $stage->type = 'stage';
  $stage->children = '';
  
  $module->children[] = $stage;
  
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/123';
  $stage->name = check_plain('collaboration stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/124';
  $stage->name = check_plain('collaboration stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
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
  $stage->id= '';
  $stage->url = 'node/122';
  $stage->name = check_plain('Team building stage 1');
  $stage->type = 'stage';
  $stage->children = '';
  
  $module->children[] = $stage;
  
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/123';
  $stage->name = check_plain('Team building stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/124';
  $stage->name = check_plain('Team building stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/125';
  $stage->name = check_plain('Team building stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $nav->children[] = $module;
  
  $ret[] = $nav;
  
  
  /*******************/
  $nav = new stdClass();
  $nav->id= '';
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
  $stage->id= '';
  $stage->url = 'node/111';
  $stage->name = check_plain('purpose module 1 stage 1');
  $stage->type = 'stage';
  $stage->children = '';
  
  $module->children[] = $stage;
  
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/112';
  $stage->name = check_plain('purpose module 1 stage 2 ');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/113';
  $stage->name = check_plain('purpose module 1 stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/114';
  $stage->name = check_plain('purpose module 1 stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/115';
  $stage->name = check_plain('purpose module 1 stage 5');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/116';
  $stage->name = check_plain('purpose module 1 stage 6');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
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
  $stage->id= '';
  $stage->url = 'node/118';
  $stage->name = check_plain('purpose module 2 stage 1');
  $stage->type = 'stage';
  $stage->children = '';
  
  $module->children[] = $stage;
  
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/119';
  $stage->name = check_plain('purpose module 2 stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/120';
  $stage->name = check_plain('purpose module 2  stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
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
  $stage->id= '';
  $stage->url = 'node/122';
  $stage->name = check_plain('purpose module 3 stage 1');
  $stage->type = 'stage';
  $stage->children = '';
  
  $module->children[] = $stage;
  
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/123';
  $stage->name = check_plain('purpose module 3 stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/124';
  $stage->name = check_plain('purpose module 3 stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
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
  $stage->id= '';
  $stage->url = 'node/122';
  $stage->name = check_plain('purpose module 4 stage 1');
  $stage->type = 'stage';
  $stage->children = '';
  
  $module->children[] = $stage;
  
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/123';
  $stage->name = check_plain('purpose module 4 stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/124';
  $stage->name = check_plain('purpose module 4 stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/125';
  $stage->name = check_plain('purpose module 4 stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $nav->children[] = $module;
  
  $ret[] = $nav;
  
  
  /*******************/
  /*******************/
  $nav = new stdClass();
  $nav->id= '';
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
  $stage->id= '';
  $stage->url = 'node/111';
  $stage->name = check_plain('how module 1 stage 1');
  $stage->type = 'stage';
  $stage->children = '';
  
  $module->children[] = $stage;
  
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/112';
  $stage->name = check_plain('how module 1 stage 2 ');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/113';
  $stage->name = check_plain('how module 1 stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/114';
  $stage->name = check_plain('how module 1 stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/115';
  $stage->name = check_plain('how module 1 stage 5');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/116';
  $stage->name = check_plain('how module 1 stage 6');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
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
  $stage->id= '';
  $stage->url = 'node/118';
  $stage->name = check_plain('how module 2 stage 1');
  $stage->type = 'stage';
  $stage->children = '';
  
  $module->children[] = $stage;
  
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/119';
  $stage->name = check_plain('how module 2 stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/120';
  $stage->name = check_plain('how module 2  stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
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
  $stage->id= '';
  $stage->url = 'node/122';
  $stage->name = check_plain('how module 3 stage 1');
  $stage->type = 'stage';
  $stage->children = '';
  
  $module->children[] = $stage;
  
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/123';
  $stage->name = check_plain('how module 3 stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/124';
  $stage->name = check_plain('how module 3 stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
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
  $stage->id= '';
  $stage->url = 'node/122';
  $stage->name = check_plain('how module 4 stage 1');
  $stage->type = 'stage';
  $stage->children = '';
  
  $module->children[] = $stage;
  
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/123';
  $stage->name = check_plain('how module 4 stage 2');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/124';
  $stage->name = check_plain('how module 4 stage 3');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $stage = new stdClass();
  $stage->id= '';
  $stage->url = 'node/125';
  $stage->name = check_plain('how module 4 stage 4');
  $stage->type = 'stage';
  $stage->children = '';
  $module->children[] = $stage;
  
  $nav->children[] = $module;
  
  $ret[] = $nav;
  
  return $ret;
 
}





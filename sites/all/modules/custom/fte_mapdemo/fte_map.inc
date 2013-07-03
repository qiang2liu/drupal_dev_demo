<?php
/**
 * menu page callback function 
 */
function showchallengemap() {
  
  // get the challenge points info
  $the_points = get_challenge_points();
  fte_map_js();
  if (!empty($the_points['data'])) {
    drupal_add_js(array('the_challenge_points' => $the_points['data']), 'setting');
  } else {
    drupal_add_js(array('the_challenge_points' => ''), 'setting');
  }
  return theme('fte_challenge_map');
}
/**
 *  return challenge points info,now it is mock data
 */
function get_challenge_points() {
  $the_icons_array = get_point_icon_settings();
  $ret = array();
  // mock data
  $nid = 29;
  $item['nid'] = $nid++;
  $item['lat'] = 14.079752;
  $item['lon'] = 19.76367;  // chad africa 
  $item['type'] = 'main';   // grant challenge created by fte admin/teacher
  $item['title'] = 'Water:Chad';
  $item['location'] = 'Chad';
  $item['brief'] = 'Water status in Chad';
  $item['icon'] = $the_icons_array[$item['type']];
  $item['info'] = theme('fte_marker_infowin', array('data'=>$item));
  $ret['data'][$item['nid']] = $item;
  
  $item['nid'] = $nid++;
  $item['lat'] = 15.10041;
  $item['lon'] = 31.54101;  //sudan africa  
  $item['type'] = 'main';   // grant challenge created by fte admin/teacher
  $item['title'] = 'Water:Sudan';
   $item['location'] = 'Sudan';
  $item['brief'] = 'Water status in sudan';
  $item['icon'] = $the_icons_array[$item['type']];
  $item['info'] = theme('fte_marker_infowin', array('data'=>$item));
  $ret['data'][$item['nid']] = $item;
  
  
  $item['nid'] = $nid++;
  $item['lat'] = -14.95893;
  $item['lon'] = 28.02539;   //zambia    
  $item['type'] = 'main';   // grant challenge created by fte admin/teacher
  $item['title'] = 'Water:Zambia';
   $item['location'] = 'Zambia';
  $item['brief'] = 'Water status in zambia';
  $item['icon'] = $the_icons_array[$item['type']];
  $item['info'] = theme('fte_marker_infowin', array('data'=>$item));
  $ret['data'][$item['nid']] = $item;
  
  
  $item['nid'] = $nid++;
  $item['lat'] = 39.90060;
  $item['lon'] = 116.42688;   //Beijing  
  $item['type'] = 'inst';   // grant challenge instance  created by student
  $item['title'] = 'instance of the challenge Water:Zambia';
  $item['brief'] = 'a student lived in Beijing created the challenge instance "Water status in zambia"';
  $item['icon'] = $the_icons_array[$item['type']];
  $item['info'] = theme('fte_marker_infowin', array('data'=>$item));
   $item['location'] = 'Zambia';
  $ret['data'][$item['nid']] = $item;
  
  
   $item['nid'] = $nid++;
  $item['lat'] = 37.27551;
  $item['lon'] = -85.30407;   //Green River lake stte park in kentucky 
  $item['type'] = 'project';  
  $item['title'] = 'project in the kentucky';
   $item['location'] = 'kentucky';
  $item['brief'] = 'project at Green River lake state park in kentucky';
  $item['icon'] = $the_icons_array[$item['type']];
  $item['info'] = theme('fte_marker_infowin', array('data'=>$item));
  $ret['data'][$item['nid']] = $item;
  
  
  $item['nid'] = $nid++;
  $item['lat'] = 40.64174;
  $item['lon'] = -74.05370;   //new york
  $item['type'] = 'project';  
  $item['title'] = 'project in New York';
  $item['brief'] = 'project in New York';
   $item['location'] = 'New York';
  $item['icon'] = $the_icons_array[$item['type']];
  $item['info'] = theme('fte_marker_infowin', array('data'=>$item));
  $ret['data'][$item['nid']] = $item;
  
 
  
  
  return $ret;
  
}
function fte_map_js() {
  $script_str = '<script  type="text/javascript" src="https://maps.googleapis.com/maps/api/js?sensor=false"></script>';
  $ele = array('#type' => 'markup', '#markup' => $script_str,);
  drupal_add_html_head($ele, 'google-map-library');
  $the_mapdemp_path = drupal_get_path('module', 'fte_mapdemo');
  drupal_add_js($the_mapdemp_path.'/js/fte_map_gmapapi_v3.js');
}
function get_point_icon_settings(){
  global $base_url;
  $ret = array();
  $the_mapdemp_path = drupal_get_path('module', 'fte_mapdemo');
  $map_icon_path = $base_url . '/' . $the_mapdemp_path; 
  $ret['main'] = $map_icon_path . "/images/yellow-dot.png";
  $ret['inst'] = $map_icon_path . "/images/blue-dot.png";
  $ret['project'] = $map_icon_path . "/images/red-dot.png";
  return  $ret;  
}
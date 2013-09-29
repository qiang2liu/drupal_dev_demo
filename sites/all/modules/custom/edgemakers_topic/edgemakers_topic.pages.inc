<?php

define('GMAP3_TOOLS_MAP_TYPE_ID_HYBRID', 'hybrid');
define('GMAP3_TOOLS_MAP_TYPE_ID_ROADMAP', 'roadmap');
define('GMAP3_TOOLS_MAP_TYPE_ID_SATELLITE', 'satellite');
define('GMAP3_TOOLS_MAP_TYPE_ID_TERRAIN', 'terrain');

define('GMAP3_TOOLS_CONTROL_POSITION_TOP_LEFT', 1);
define('GMAP3_TOOLS_CONTROL_POSITION_TOP', 2);
define('GMAP3_TOOLS_CONTROL_POSITION_TOP_CENTER', 2);
define('GMAP3_TOOLS_CONTROL_POSITION_TOP_RIGHT', 3);
define('GMAP3_TOOLS_CONTROL_POSITION_LEFT_CENTER', 4);
define('GMAP3_TOOLS_CONTROL_POSITION_LEFT', 5);
define('GMAP3_TOOLS_CONTROL_POSITION_LEFT_TOP', 5);
define('GMAP3_TOOLS_CONTROL_POSITION_LEFT_BOTTOM', 6);
define('GMAP3_TOOLS_CONTROL_POSITION_RIGHT', 7);
define('GMAP3_TOOLS_CONTROL_POSITION_RIGHT_TOP', 7);
define('GMAP3_TOOLS_CONTROL_POSITION_RIGHT_CENTER', 8);
define('GMAP3_TOOLS_CONTROL_POSITION_RIGHT_BOTTOM', 9);
define('GMAP3_TOOLS_CONTROL_POSITION_BOTTOM_LEFT', 10);
define('GMAP3_TOOLS_CONTROL_POSITION_BOTTOM', 11);
define('GMAP3_TOOLS_CONTROL_POSITION_BOTTOM_CENTER', 11);
define('GMAP3_TOOLS_CONTROL_POSITION_BOTTOM_RIGHT', 12);

define('GMAP3_TOOLS_ZOOM_CONTROL_STYLE_DEFAULT', 0);
define('GMAP3_TOOLS_ZOOM_CONTROL_STYLE_SMALL', 1);
define('GMAP3_TOOLS_ZOOM_CONTROL_STYLE_LARGE', 2);
define('GMAP3_TOOLS_ZOOM_CONTROL_STYLE_ANDROID', 4);

/**
 * Default markers position which does nothing.
 */
define('GMAP3_TOOLS_DEFAULT_MARKERS_POSITION', 'default');
/**
 * Default markers position which center markers on map.
 */
define('GMAP3_TOOLS_DEFAULT_MARKERS_POSITION_CENTER', 'center');
/**
 * Default markers position which center and zoom markers on map so they will
 * fit into map.
 */
define('GMAP3_TOOLS_DEFAULT_MARKERS_POSITION_CENTER_ZOOM', 'center zoom');
/**
 * number of the murals in one page in the gmap infowindow
 */
define('GMAP_INFOWINDOW_ITEMS_PER_PAGE', 10);

/**
 * get items for carousel block to display
 */
function edgemakers_topic_carousel_items() {
  $renderable_array = array();
  $nodes = node_load_multiple(array(), array('type' => 'carousel_item'));
  foreach ($nodes as $node) {
    $topics = field_get_items('node', $node, 'field_carousel_item_topic');
    $topicid = $topics && count($topics) > 0 ? $topics[0]['target_id'] : '';
    if($topicid) {
      $topic = node_load($topicid);
      $title = $topic->title;
      $descriptions = field_get_items('node', $topic, 'field_topic_problem');
      $description = $descriptions && count($descriptions) ? $descriptions[0]['value'] : '';
      $description = text_summary($description, NULL, 185);
      $imageuris = field_get_items('node', $topic, 'field_topic_images');
      $imageuri = $imageuris && count($imageuris) ? $imageuris[0]['uri'] : '';
      if($imageuri) {
        $renderable_array[] = array(
          'topicid' => $topicid,
          'title' => $title,
          'description' => $description,
          'imageurl' => file_create_url($imageuri),
        );
      }
    }
  }
  return $renderable_array;
}

/**
 * get items for wicked problems block to display
 */
function edgemakers_topic_problems_items() {
  $terms = array();
  $vocabulary = taxonomy_vocabulary_machine_name_load('challenges_vocabulary');
  $oterms = taxonomy_get_tree($vocabulary->vid);
  foreach ($oterms as $term) {
    $tid = $term->tid;
    $term = taxonomy_term_load($tid);
    $topic = field_get_items('taxonomy_term', $term, 'field_challenge_topic');
    $terms[$tid] = array(
      'tid' => $tid,
      'name' => $term->name,
      'topicid' => $topic[0]['target_id'],
    );
  }
  return $terms;
}

/**
 * get items of murals data for the map in the  block
 */
function edgemakers_get_map_data() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
          ->entityCondition('bundle', 'murals')
          ->fieldCondition('field_muralshared', 'value', 1, '=');
  $results = $query->execute();
  if (is_array($results['node']) && !empty($results['node'])) {
    $the_nids = array_keys($results['node']);
    $nodes = node_load_multiple($the_nids);

    ////
    $markers = array();
    $marker_array = array();
    if (is_array($nodes)) {
      foreach ($nodes as $node) {
        
        $city_field = field_get_items('node', $node, 'field_city');
        
		  // dpm($city_field);
        if (is_array($city_field) && isset($city_field[0]['lid'])) {

          $city_name = strtolower(str_replace(' ' , '', $city_field[0]['city']));
          if (empty($city_name)) {
            $city_name = strtolower(str_replace(' ' , '', $city_field[0]['country']));
          }
          $marker_array[$city_name]['latitude'] = $city_field[0]['latitude'];
          $marker_array[$city_name]['longitude'] = $city_field[0]['longitude'];
          $marker_array[$city_name]['title'] = $node->title;
          $marker_array[$city_name]['cityname'] = !empty($city_field[0]['city']) ? $city_field[0]['city'] : $city_field[0]['country'];
          if (isset($marker_array[$city_name]['totalc'])) {
            $marker_array[$city_name]['content'].= make_content_output($node);
            $marker_array[$city_name]['totalc'] = (int) $marker_array[$city_name]['totalc'] + 1;
          } else {
            $marker_array[$city_name]['content'] = make_content_output($node);
            $marker_array[$city_name]['totalc'] = 1;
          }
        }
      }

      /*
        foreach ($marker_array AS $the_key => $marker) {

        $marker_array[$the_key]['content_output'] = pager_infowindow($marker['content']);
        }
       */
//      dpm($marker_array);
      foreach ($marker_array AS $the_key => $marker) {
        $marker_array[$the_key]['content'] = '<div class= "cityname"> ' . $marker['cityname'] . ' </div><ul class="infowindowlist">' . $marker['content'] . '</ul>';
      }
      $i = 1;

      foreach ($marker_array AS $city => $maker) {

        $icon = 'http://google-maps-utility-library-v3.googlecode.com/svn/trunk/markerclusterer/images/m' . $i . '.png';


        $markers[] = gmap3_tools_create_marker(
                $maker['latitude'], $maker['longitude'], $maker['cityname'], "{$maker['content']}", array(
          'animation' => 'BOUNCE',
          'icon' => url($icon),
                ), $maker['totalc']
        );
      }
      gmap3_tools_add_map(array(
        'mapId' => 'map-canvas-02',
        'mapOptions' => array(
          //'centerX' => $api_data['lat'] + 2,
          //'centerY' => $api_data['lon'] + 0.2,
          'zoom' => 3,
        ),
        'markers' => $markers,
        'gmap3ToolsOptions' => array(
          'defaultMarkersPosition' => GMAP3_TOOLS_DEFAULT_MARKERS_POSITION_CENTER,
        ),
      ));
      $output = '<div id="map-canvas-02" style="width:1024; height:400px"></div>';

      return $output;
    }
  }
}

/**
 * Add and configure js which is needed for map rendering.
 *
 * @param array $options
 *   Gmap configuration array. Check $defaults array for list of all supported
 *   options.
 */
function gmap3_tools_add_map($options) {
  static $init = FALSE;

  static $defaults = array(
// Map html element id.
'mapId' => NULL,
 // Map options.
'mapOptions' => array(
// Center X of map.
'centerX' => 0,
 // Center Y of map.
'centerY' => 0,
 // Disable double click zooming.
'disableDoubleClickZoom' => FALSE,
 // Show controls for map type change.
'mapTypeControl' => TRUE,
 // Map type id.
'mapTypeId' => GMAP3_TOOLS_MAP_TYPE_ID_ROADMAP,
 // The maximum zoom level which will be displayed on the map. If null,
// then maximum zoom from the current map type is used instead.
'maxZoom' => NULL,
 // The minimum zoom level which will be displayed on the map. If null,
// then minimum zoom from the current map type is used instead.
'minZoom' => NULL,
 // Show pan contro.
'panControl' => FALSE,
 // Enable scroll wheel zooming.
'scrollwheel' => TRUE,
 // Show street view controls.
'streetViewControl' => FALSE,
 // Zoom of map.
'zoom' => 4,
 // Enable zoom controls.
'zoomControl' => TRUE,
 // Zoom controls options.
'zoomControlOptions' => array(
// Position of controls.
'position' => GMAP3_TOOLS_CONTROL_POSITION_TOP_LEFT,
 // Controls style.
'style' => GMAP3_TOOLS_ZOOM_CONTROL_STYLE_DEFAULT,
),
),
 // Each marker can have custom markerOptions array. You should be able to
// use all properties from google.maps.MarkerOptions object specification.
// See https://developers.google.com/maps/documentation/javascript/reference#MarkerOptions
'markers' => array(),
 // Default markers options - will be applied to all markers in map.
'markerOptions' => array(
// Marker icon image URL.
//'icon' => 'http://your-site/custom-marker-icon.png',
),
 // Info window options.
'infoWindowOptions' => array(),
 // Custom options for gmap3_tools API.
'gmap3ToolsOptions' => array(
// Close current opened infoWindow when opening new one.
'closeCurrentInfoWindow' => TRUE,
 // Default position and zoom level of markers on map.
'defaultMarkersPosition' => GMAP3_TOOLS_DEFAULT_MARKERS_POSITION,
 // Try to position map center based on current user geo location.
'geolocation' => FALSE,
),
  );

  if (!$init) {
    $init = TRUE;
    // Visit https://code.google.com/apis/console and generate new api key if
    // you need it.
    $lib_url = 'http://maps.googleapis.com/maps/api/js?&sensor=false';
    if ($api_key = variable_get('gmap3_tools_api_key', NULL)) {
      $lib_url .= '&key=' . $api_key;
    }
    drupal_add_js($lib_url, 'external', array('scope' => 'footer'));
    drupal_add_js(drupal_get_path('module', 'themuraly') . '/js/themuraly.js', array('scope' => 'footer'));
    drupal_add_js(drupal_get_path('module', 'edgemakers_topic') . '/js/marker_clusterer_demo.js', array('scope' => 'footer'));
    $path = libraries_get_path('jpagnate');
    if (file_exists($path . '/jquery.paginate.js'))
      drupal_add_js($path . '/jquery.paginate.js');
    drupal_add_js(drupal_get_path('module', 'edgemakers_topic') . '/js/infowin_items_pager.js', array('scope' => 'footer'));

    //drupal_add_js(drupal_get_path('module', 'gmap3_tools') . '/gmap3_tools.js', array('scope' => 'footer'));
  }

  // Merge custom map options with defaults.
  $options = gmap3_tools_array_union_recursive($defaults, $options);

  //dpm($options);
  // Add map configuration options to js.
  drupal_add_js(array('gmap3_tools' => array('maps' => array($options))), 'setting');
}

/**
 * Helper for creatin marker options array.
 *
 * @param float $lat
 * @param float $lng
 * @param string $title
 *   Title is used for marker label.
 * @param string $content
 *   Content is used for marker's info window popup.
 * @param array $marker_options
 *   Holds all marker options for this marker.
 *   @see https://developers.google.com/maps/documentation/javascript/reference#MarkerOptions
 *   for all posible options.
 *
 *   Special gmap3_tools options:
 *
 *     relative - boolean. If TRUE then lat and lng coordinates are applied from
 *       current map center.
 * @param int $label
 *   Add by lugal, display number below marker.
 *
 * @return array
 *   Marker options array.
 */
function gmap3_tools_create_marker($lat, $lng, $title = NULL, $content = NULL, $marker_options = array(), $label = NULL) {
  $marker = array('lat' => $lat, 'lng' => $lng);
  if (isset($title)) {
    $marker['title'] = $title;
  }
  if (isset($content)) {
    $marker['content'] = $content;
  }

  if (!isset($marker_options['relative'])) {
    $marker_options['relative'] = FALSE;
  }

  $marker['markerOptions'] = $marker_options;

  $marker['label'] = $label;

  //dpm($marker);

  return $marker;
}

/**
 * Recursive union of two arrays. Works similar to + array operator but is also
 * taking care case when array values are also arrays.
 *
 * @param array $array1
 *   First array for union operation.
 * @param array $array2
 *   Second array for union operation.
 * @return array.
 *   Union result.
 */
function gmap3_tools_array_union_recursive($array1, $array2) {
  $union = $array1;
  foreach ($array2 as $key => $value) {
    if (array_key_exists($key, $union) && is_array($union[$key]) && is_array($value)) {
      $union[$key] = gmap3_tools_array_union_recursive($union[$key], $value);
    } else {
      $union[$key] = $value;
    }
  }
  return $union;
}

function pager_infowindow($the_items) {


  $data = array();
  foreach ($the_items as $k => $v) {
    $data[$k] = '<li>' . $v . '</li>';
  }
  $total = count($data);
  $per_num = GMAP_INFOWINDOW_ITEMS_PER_PAGE;
  $pages = ceil($total / GMAP_INFOWINDOW_ITEMS_PER_PAGE);
  $the_counter = 1;
  $items_counter = 1;
  $page_num = 1;
  $output = '';
  foreach ($data as $v) {
    if ($the_counter == 1) {
      $output .= "<ul pagenum='" . $page_num . "' >";
    }
    $output .= $v;

    if ($the_counter == $per_num || $items_counter == $total) {
      $output .= "</ul>";
    }
    $the_counter++;
    $items_counter++;
    if ($the_counter > $per_num) {
      $the_counter = 1;
      $page_num++;
    }
  }

  if ($page_num > 1) {
    $output .= '<div class="mural_pager">';
    for ($i = 1; $i <= $page_num; $i++) {
      $output .= "<span>" . $i . "</span>";
    }
    $output .= "</div>";
  }


  return $ret;
}

function make_content_output($node) {
  $ret = '';
  $title = $node->title;

  $x = field_get_items('node', $node, 'body');


  $desc = render(field_view_value('node', $node, 'body', $x[0]));

  $result = field_view_field('node', $node, 'field_tags', array('default'));
  $arrItems = '';
  if (isset($result['#object']) && isset($result['#object']->field_tags['und'])) {
    $arrItems = $result['#object']->field_tags['und'];
  }

  $tags = "";

  $i = 0;
  if (is_array($arrItems)) {
    foreach ($arrItems as $new) {
      if ($i < count($arrItems) && $i > 0) {
        $tags .= ",";
      }
      $tags .= $arrItems[$i]['taxonomy_term']->name;
      $i++;
    }
  }


  /*
    $uid = $node->uid;
    $creater = user_load($uid);
    $fname = $creater->field_firstname['und']['0']['safe_value'];
    $lname = $creater->field_lastname['und']['0']['safe_value'];
   *
   */
  $name = $node->name;
  $source = 'mural/' . $node->nid;
  if (user_is_logged_in()) {
    $clickfunction = "parent.showMuralDialog('" . $source . "');parent.jQuery('#mural-back-to-dashboard').attr('style', 'display: inline;');parent.jQuery('#mural-back-to-dashboard').show();parent.jQuery('#refresh-mural').val(0);parent.nofresh = 0;";
  }
  else {
   $clickfunction = 'parent.showLogin()';
  }
  $ret .= '<li>';
  $ret .= '<p class="title"><a href="javascript:void(0);" onclick= "' . $clickfunction. '">' . $title . '</a></p>';

  $ret .= '<p class="desc">'
          . $desc . '</p><p class="tags">' . $tags . '</p><p class="creator">'
          . $name . '</p></li>';


  return $ret;
}
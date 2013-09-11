<?php
/**
 * @file
 * edgemakers_features_other.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function edgemakers_features_other_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_mediafront_default_presets().
 */
function edgemakers_features_other_mediafront_default_presets() {
  $items = array(
    'player' => array(
      'name' => 'player',
      'description' => 'video/audio player',
      'player' => 'minplayer',
      'connect' => array(
        'iscontroller' => array(
          0 => 0,
        ),
        'isplaylist' => array(
          0 => 0,
        ),
      ),
      'settings' => array(
        'template' => 'default',
        'volume' => 80,
        'wmode' => 'transparent',
        'preload' => 1,
        'width' => '100%',
        'height' => '400px',
        'fluidWidth' => TRUE,
        'showWhenEmpty' => 1,
        'debug' => 0,
        'loop' => 0,
        'autoplay' => 0,
        'player_settings__active_tab' => 'edit-player-settings-presentation',
      ),
    ),
  );
  return $items;
}

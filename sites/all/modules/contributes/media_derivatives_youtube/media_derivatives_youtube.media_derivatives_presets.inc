<?php
/**
 * @file
 * add a new preset to Derivatives API
 */

/**
 * Implements hook_media_derivatives_presets().
 */
function media_derivatives_youtube_media_derivatives_presets() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->machine_name = 'youtube_video';
  $preset->engine = 'media_derivatives_youtube';
  $preset->engine_settings = array(
    'youtube_username' => '',
    'youtube_password' => '',
    'youtube_key' => '',
    'youtube_default_title' => '',
    'youtube_default_description' => '',
    'youtube_default_tags' => '',
  );
  $preset->conditions = array(
    0 => 'file_type',
    1 => 'derivatives_of_derivatives',
  );
  $preset->conditions_settings = array(
    'type' => 'video',
    'encode_derivatives' => 0,
  );
  $preset->events = array(
    0 => 'file_insert',
  );
  $preset->events_settings = array();
  $preset->scheduler = 'scheduler_immediate';
  $preset->scheduler_settings = array();
  $preset->settings = array(
    'recursive_delete' => 1,
    'delete_source' => 0,
    'user' => '0',
    'type' => 0,
  );
  $export['youtube_video'] = $preset;

  return $export;
}

<?php
/**
 * @file
 * media_derivatives_youtube.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function media_derivatives_youtube_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "media_derivatives" && $api == "media_derivatives_presets") {
    return array("version" => "1");
  }
}

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
 * Implements hook_image_default_styles().
 */
function edgemakers_features_other_image_default_styles() {
  $styles = array();

  // Exported image style: edgemakers_avatar.
  $styles['edgemakers_avatar'] = array(
    'effects' => array(
      0 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 74,
          'height' => 74,
          'upscale' => 1,
        ),
        'weight' => 0,
      ),
    ),
    'label' => 'edgemakers_avatar',
    'name' => 'edgemakers_avatar',
  );

  // Exported image style: edgemakers_profile_avatar.
  $styles['edgemakers_profile_avatar'] = array(
    'name' => 'edgemakers_profile_avatar',
    'label' => 'edgemakers_profile_avatar',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 54,
          'height' => 54,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: edgemakers_set.
  $styles['edgemakers_set'] = array(
    'effects' => array(
      0 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 133,
          'height' => 133,
        ),
        'weight' => 0,
      ),
    ),
    'label' => 'edgemakers_set',
    'name' => 'edgemakers_set',
  );

  // Exported image style: edgemakers_set_big.
  $styles['edgemakers_set_big'] = array(
    'effects' => array(
      0 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'height' => 578,
        ),
        'weight' => 0,
      ),
    ),
    'label' => 'edgemakers_set_big',
    'name' => 'edgemakers_set_big',
  );

  // Exported image style: edgemakers_studio_gallery_list.
  $styles['edgemakers_studio_gallery_list'] = array(
    'label' => 'edgemakers_studio_gallery_list',
    'name' => 'edgemakers_studio_gallery_list',
    'effects' => array(
      7 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 156,
          'height' => 106,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: edgemakers_topic_image.
  $styles['edgemakers_topic_image'] = array(
    'label' => 'edgemakers_topic_image',
    'effects' => array(
      0 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 360,
          'height' => 300,
        ),
        'weight' => 0,
      ),
    ),
    'name' => 'edgemakers_topic_image',
  );

  return $styles;
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

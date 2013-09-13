<?php
/**
 * @file
 * edgemakers_views_blocks.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function edgemakers_views_blocks_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home_blocks';
  $context->description = '';
  $context->tag = 'home';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'home' => 'home',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'edgemakers_media_upload-media_upload_link' => array(
          'module' => 'edgemakers_media_upload',
          'delta' => 'media_upload_link',
          'region' => 'tool_bar',
          'weight' => '-33',
        ),
        'themuraly-mural_link' => array(
          'module' => 'themuraly',
          'delta' => 'mural_link',
          'region' => 'tool_bar',
          'weight' => '-32',
        ),
        'edgemakers_media_upload-media_list' => array(
          'module' => 'edgemakers_media_upload',
          'delta' => 'media_list',
          'region' => 'tool_bar',
          'weight' => '-31',
        ),
        'themuraly-mural_list' => array(
          'module' => 'themuraly',
          'delta' => 'mural_list',
          'region' => 'tool_bar',
          'weight' => '-30',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-33',
        ),
        'edgemakers_stage-stage_list' => array(
          'module' => 'edgemakers_stage',
          'delta' => 'stage_list',
          'region' => 'content',
          'weight' => '-32',
        ),
        'views-community_users-block' => array(
          'module' => 'views',
          'delta' => 'community_users-block',
          'region' => 'community',
          'weight' => '-10',
        ),
        'edgemakers-community_activity' => array(
          'module' => 'edgemakers',
          'delta' => 'community_activity',
          'region' => 'community',
          'weight' => '-9',
        ),
        'themuraly-studio_list' => array(
          'module' => 'themuraly',
          'delta' => 'studio_list',
          'region' => 'studio_pane',
          'weight' => '-10',
        ),
        'edgemakers_media_upload-studio_media_list' => array(
          'module' => 'edgemakers_media_upload',
          'delta' => 'studio_media_list',
          'region' => 'studio_pane',
          'weight' => '-9',
        ),
        'themuraly-gallery_mural_list' => array(
          'module' => 'themuraly',
          'delta' => 'gallery_mural_list',
          'region' => 'gallery_pane',
          'weight' => '-10',
        ),
        'edgemakers_media_upload-gallery_media_list' => array(
          'module' => 'edgemakers_media_upload',
          'delta' => 'gallery_media_list',
          'region' => 'gallery_pane',
          'weight' => '-9',
        ),
        'edgemakers_topic-carousel' => array(
          'module' => 'edgemakers_topic',
          'delta' => 'carousel',
          'region' => 'challenge',
          'weight' => '-10',
        ),
        'edgemakers_topic-problems' => array(
          'module' => 'edgemakers_topic',
          'delta' => 'problems',
          'region' => 'challenge',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('home');
  $export['home_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'topic_blocks';
  $context->description = '';
  $context->tag = 'topic';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'edgemakers_topic' => 'edgemakers_topic',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'themuraly-topic_mural_list' => array(
          'module' => 'themuraly',
          'delta' => 'topic_mural_list',
          'region' => 'topic_murals',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('topic');
  $export['topic_blocks'] = $context;

  return $export;
}

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
        'block-12' => array(
          'module' => 'block',
          'delta' => '12',
          'region' => 'user_profile',
          'weight' => '-10',
        ),
        'block-11' => array(
          'module' => 'block',
          'delta' => '11',
          'region' => 'user_profile',
          'weight' => '-9',
        ),
        'edgemakers_media_upload-media_upload_link' => array(
          'module' => 'edgemakers_media_upload',
          'delta' => 'media_upload_link',
          'region' => 'tool_bar',
          'weight' => '-10',
        ),
        'edgemakers_media_upload-media_list' => array(
          'module' => 'edgemakers_media_upload',
          'delta' => 'media_list',
          'region' => 'tool_bar',
          'weight' => '-9',
        ),
        'themuraly-mural_link' => array(
          'module' => 'themuraly',
          'delta' => 'mural_link',
          'region' => 'tool_bar',
          'weight' => '-8',
        ),
        'themuraly-mural_list' => array(
          'module' => 'themuraly',
          'delta' => 'mural_list',
          'region' => 'tool_bar',
          'weight' => '-7',
        ),
        'edgemakers_stage-stage_list' => array(
          'module' => 'edgemakers_stage',
          'delta' => 'stage_list',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
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
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('topic');
  $export['topic_blocks'] = $context;

  return $export;
}

<?php
/**
 * @file
 * edgemakers_features_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function edgemakers_features_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'Administer force password change'.
  $permissions['Administer force password change'] = array(
    'name' => 'Administer force password change',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'force_password_change',
  );

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access better messages'.
  $permissions['access better messages'] = array(
    'name' => 'access better messages',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'better_messages',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access direct download file'.
  $permissions['access direct download file'] = array(
    'name' => 'access direct download file',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'download_file',
  );

  // Exported permission: 'access overlay'.
  $permissions['access overlay'] = array(
    'name' => 'access overlay',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'overlay',
  );

  // Exported permission: 'access own authorizations'.
  $permissions['access own authorizations'] = array(
    'name' => 'access own authorizations',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own consumers'.
  $permissions['access own consumers'] = array(
    'name' => 'access own consumers',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer background image'.
  $permissions['administer background image'] = array(
    'name' => 'administer background image',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'bg_image',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer better messages'.
  $permissions['administer better messages'] = array(
    'name' => 'administer better messages',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'better_messages',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer consumers'.
  $permissions['administer consumers'] = array(
    'name' => 'administer consumers',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer date tools'.
  $permissions['administer date tools'] = array(
    'name' => 'administer date tools',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'date_tools',
  );

  // Exported permission: 'administer download file'.
  $permissions['administer download file'] = array(
    'name' => 'administer download file',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'download_file',
  );

  // Exported permission: 'administer edgemakers'.
  $permissions['administer edgemakers'] = array(
    'name' => 'administer edgemakers',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'edgemakers',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer invitations'.
  $permissions['administer invitations'] = array(
    'name' => 'administer invitations',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'administer mailsystem'.
  $permissions['administer mailsystem'] = array(
    'name' => 'administer mailsystem',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'mailsystem',
  );

  // Exported permission: 'administer media'.
  $permissions['administer media'] = array(
    'name' => 'administer media',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer mediafront'.
  $permissions['administer mediafront'] = array(
    'name' => 'administer mediafront',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'mediafront',
  );

  // Exported permission: 'administer mediafront presets'.
  $permissions['administer mediafront presets'] = array(
    'name' => 'administer mediafront presets',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'mediafront',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer oauth'.
  $permissions['administer oauth'] = array(
    'name' => 'administer oauth',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'administer oauth2 server'.
  $permissions['administer oauth2 server'] = array(
    'name' => 'administer oauth2 server',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'oauth2_server',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer services'.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer smtp module'.
  $permissions['administer smtp module'] = array(
    'name' => 'administer smtp module',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'smtp',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer user relationships'.
  $permissions['administer user relationships'] = array(
    'name' => 'administer user relationships',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'user_relationships',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer voting api'.
  $permissions['administer voting api'] = array(
    'name' => 'administer voting api',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'votingapi',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'can have friend relationships'.
  $permissions['can have friend relationships'] = array(
    'name' => 'can have friend relationships',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user_relationships',
  );

  // Exported permission: 'can request friend relationships'.
  $permissions['can request friend relationships'] = array(
    'name' => 'can request friend relationships',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user_relationships',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create carousel_item content'.
  $permissions['create carousel_item content'] = array(
    'name' => 'create carousel_item content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create edgemakers_set content'.
  $permissions['create edgemakers_set content'] = array(
    'name' => 'create edgemakers_set content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create edgemakers_topic content'.
  $permissions['create edgemakers_topic content'] = array(
    'name' => 'create edgemakers_topic content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_curate_rank'.
  $permissions['create field_curate_rank'] = array(
    'name' => 'create field_curate_rank',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_gender'.
  $permissions['create field_gender'] = array(
    'name' => 'create field_gender',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_highlight'.
  $permissions['create field_highlight'] = array(
    'name' => 'create field_highlight',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create media_for_upload content'.
  $permissions['create media_for_upload content'] = array(
    'name' => 'create media_for_upload content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create murals content'.
  $permissions['create murals content'] = array(
    'name' => 'create murals content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create openlayers_example_content content'.
  $permissions['create openlayers_example_content content'] = array(
    'name' => 'create openlayers_example_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create site_bg_image content'.
  $permissions['create site_bg_image content'] = array(
    'name' => 'create site_bg_image content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create stage content'.
  $permissions['create stage content'] = array(
    'name' => 'create stage content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any carousel_item content'.
  $permissions['delete any carousel_item content'] = array(
    'name' => 'delete any carousel_item content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any edgemakers_set content'.
  $permissions['delete any edgemakers_set content'] = array(
    'name' => 'delete any edgemakers_set content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any edgemakers_topic content'.
  $permissions['delete any edgemakers_topic content'] = array(
    'name' => 'delete any edgemakers_topic content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any media_for_upload content'.
  $permissions['delete any media_for_upload content'] = array(
    'name' => 'delete any media_for_upload content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any murals content'.
  $permissions['delete any murals content'] = array(
    'name' => 'delete any murals content',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any openlayers_example_content content'.
  $permissions['delete any openlayers_example_content content'] = array(
    'name' => 'delete any openlayers_example_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any site_bg_image content'.
  $permissions['delete any site_bg_image content'] = array(
    'name' => 'delete any site_bg_image content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any stage content'.
  $permissions['delete any stage content'] = array(
    'name' => 'delete any stage content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete friend relationships'.
  $permissions['delete friend relationships'] = array(
    'name' => 'delete friend relationships',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user_relationships',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own carousel_item content'.
  $permissions['delete own carousel_item content'] = array(
    'name' => 'delete own carousel_item content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own comments'.
  $permissions['delete own comments'] = array(
    'name' => 'delete own comments',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'comment_goodness',
  );

  // Exported permission: 'delete own edgemakers_set content'.
  $permissions['delete own edgemakers_set content'] = array(
    'name' => 'delete own edgemakers_set content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own edgemakers_topic content'.
  $permissions['delete own edgemakers_topic content'] = array(
    'name' => 'delete own edgemakers_topic content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own media_for_upload content'.
  $permissions['delete own media_for_upload content'] = array(
    'name' => 'delete own media_for_upload content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own murals content'.
  $permissions['delete own murals content'] = array(
    'name' => 'delete own murals content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own openlayers_example_content content'.
  $permissions['delete own openlayers_example_content content'] = array(
    'name' => 'delete own openlayers_example_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own site_bg_image content'.
  $permissions['delete own site_bg_image content'] = array(
    'name' => 'delete own site_bg_image content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own stage content'.
  $permissions['delete own stage content'] = array(
    'name' => 'delete own stage content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in challenges_vocabulary'.
  $permissions['delete terms in challenges_vocabulary'] = array(
    'name' => 'delete terms in challenges_vocabulary',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in media_file_types'.
  $permissions['delete terms in media_file_types'] = array(
    'name' => 'delete terms in media_file_types',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in mural_type'.
  $permissions['delete terms in mural_type'] = array(
    'name' => 'delete terms in mural_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in set_types'.
  $permissions['delete terms in set_types'] = array(
    'name' => 'delete terms in set_types',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any carousel_item content'.
  $permissions['edit any carousel_item content'] = array(
    'name' => 'edit any carousel_item content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any edgemakers_set content'.
  $permissions['edit any edgemakers_set content'] = array(
    'name' => 'edit any edgemakers_set content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any edgemakers_topic content'.
  $permissions['edit any edgemakers_topic content'] = array(
    'name' => 'edit any edgemakers_topic content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any media_for_upload content'.
  $permissions['edit any media_for_upload content'] = array(
    'name' => 'edit any media_for_upload content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any murals content'.
  $permissions['edit any murals content'] = array(
    'name' => 'edit any murals content',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any openlayers_example_content content'.
  $permissions['edit any openlayers_example_content content'] = array(
    'name' => 'edit any openlayers_example_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any site_bg_image content'.
  $permissions['edit any site_bg_image content'] = array(
    'name' => 'edit any site_bg_image content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any stage content'.
  $permissions['edit any stage content'] = array(
    'name' => 'edit any stage content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_curate_rank'.
  $permissions['edit field_curate_rank'] = array(
    'name' => 'edit field_curate_rank',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_gender'.
  $permissions['edit field_gender'] = array(
    'name' => 'edit field_gender',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_highlight'.
  $permissions['edit field_highlight'] = array(
    'name' => 'edit field_highlight',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit media'.
  $permissions['edit media'] = array(
    'name' => 'edit media',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'edit mimemail user settings'.
  $permissions['edit mimemail user settings'] = array(
    'name' => 'edit mimemail user settings',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own carousel_item content'.
  $permissions['edit own carousel_item content'] = array(
    'name' => 'edit own carousel_item content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own edgemakers_set content'.
  $permissions['edit own edgemakers_set content'] = array(
    'name' => 'edit own edgemakers_set content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own edgemakers_topic content'.
  $permissions['edit own edgemakers_topic content'] = array(
    'name' => 'edit own edgemakers_topic content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_curate_rank'.
  $permissions['edit own field_curate_rank'] = array(
    'name' => 'edit own field_curate_rank',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_gender'.
  $permissions['edit own field_gender'] = array(
    'name' => 'edit own field_gender',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_highlight'.
  $permissions['edit own field_highlight'] = array(
    'name' => 'edit own field_highlight',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own media_for_upload content'.
  $permissions['edit own media_for_upload content'] = array(
    'name' => 'edit own media_for_upload content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own murals content'.
  $permissions['edit own murals content'] = array(
    'name' => 'edit own murals content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own openlayers_example_content content'.
  $permissions['edit own openlayers_example_content content'] = array(
    'name' => 'edit own openlayers_example_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own site_bg_image content'.
  $permissions['edit own site_bg_image content'] = array(
    'name' => 'edit own site_bg_image content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own stage content'.
  $permissions['edit own stage content'] = array(
    'name' => 'edit own stage content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'site admin' => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit terms in challenges_vocabulary'.
  $permissions['edit terms in challenges_vocabulary'] = array(
    'name' => 'edit terms in challenges_vocabulary',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in media_file_types'.
  $permissions['edit terms in media_file_types'] = array(
    'name' => 'edit terms in media_file_types',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in mural_type'.
  $permissions['edit terms in mural_type'] = array(
    'name' => 'edit terms in mural_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in set_types'.
  $permissions['edit terms in set_types'] = array(
    'name' => 'edit terms in set_types',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: 'get a system variable'.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'get any binary files'.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'get own binary files'.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'grant delete permission to related users'.
  $permissions['grant delete permission to related users'] = array(
    'name' => 'grant delete permission to related users',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'user_relationship_node_access',
  );

  // Exported permission: 'grant update permission to related users'.
  $permissions['grant update permission to related users'] = array(
    'name' => 'grant update permission to related users',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'user_relationship_node_access',
  );

  // Exported permission: 'grant view permission to related users'.
  $permissions['grant view permission to related users'] = array(
    'name' => 'grant view permission to related users',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'user_relationship_node_access',
  );

  // Exported permission: 'import media'.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'maintain friend relationships'.
  $permissions['maintain friend relationships'] = array(
    'name' => 'maintain friend relationships',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user_relationships',
  );

  // Exported permission: 'manage background images'.
  $permissions['manage background images'] = array(
    'name' => 'manage background images',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'bg_image_ui',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'oauth authorize any consumers'.
  $permissions['oauth authorize any consumers'] = array(
    'name' => 'oauth authorize any consumers',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'oauth register any consumers'.
  $permissions['oauth register any consumers'] = array(
    'name' => 'oauth register any consumers',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'oauth_common',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'perform unlimited index queries'.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'send invitations'.
  $permissions['send invitations'] = array(
    'name' => 'send invitations',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'send mass invitations'.
  $permissions['send mass invitations'] = array(
    'name' => 'send mass invitations',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'set a system variable'.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(),
    'module' => 'services',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'submit latitude/longitude'.
  $permissions['submit latitude/longitude'] = array(
    'name' => 'submit latitude/longitude',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'track invitations'.
  $permissions['track invitations'] = array(
    'name' => 'track invitations',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'use PHP for settings'.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'php',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'parent' => 'parent',
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
      'student' => 'student',
      'teacher' => 'teacher',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format gmap'.
  $permissions['use text format gmap'] = array(
    'name' => 'use text format gmap',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format php_code'.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'view all friend relationships'.
  $permissions['view all friend relationships'] = array(
    'name' => 'view all friend relationships',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'user_relationships_ui',
  );

  // Exported permission: 'view field_curate_rank'.
  $permissions['view field_curate_rank'] = array(
    'name' => 'view field_curate_rank',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_gender'.
  $permissions['view field_gender'] = array(
    'name' => 'view field_gender',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_highlight'.
  $permissions['view field_highlight'] = array(
    'name' => 'view field_highlight',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view location directory'.
  $permissions['view location directory'] = array(
    'name' => 'view location directory',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: 'view media'.
  $permissions['view media'] = array(
    'name' => 'view media',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'view node location table'.
  $permissions['view node location table'] = array(
    'name' => 'view node location table',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: 'view own field_curate_rank'.
  $permissions['view own field_curate_rank'] = array(
    'name' => 'view own field_curate_rank',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_gender'.
  $permissions['view own field_gender'] = array(
    'name' => 'view own field_gender',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_highlight'.
  $permissions['view own field_highlight'] = array(
    'name' => 'view own field_highlight',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own friend relationships'.
  $permissions['view own friend relationships'] = array(
    'name' => 'view own friend relationships',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'user_relationships_ui',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view rate results page'.
  $permissions['view rate results page'] = array(
    'name' => 'view rate results page',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'rate',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'site administrator' => 'site administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view teacher notes'.
  $permissions['view teacher notes'] = array(
    'name' => 'view teacher notes',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
      'teacher' => 'teacher',
    ),
    'module' => 'edgemakers',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view user location table'.
  $permissions['view user location table'] = array(
    'name' => 'view user location table',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'site administrator' => 'site administrator',
    ),
    'module' => 'location',
  );

  // Exported permission: 'withdraw own accepted invitations'.
  $permissions['withdraw own accepted invitations'] = array(
    'name' => 'withdraw own accepted invitations',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'invite',
  );

  // Exported permission: 'withdraw own invitations'.
  $permissions['withdraw own invitations'] = array(
    'name' => 'withdraw own invitations',
    'roles' => array(
      'site admin' => 'site admin',
      'site administrator' => 'site administrator',
    ),
    'module' => 'invite',
  );

  return $permissions;
}

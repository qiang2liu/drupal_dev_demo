<?php
/**
 * @file
 * edgemakers_features_other.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function edgemakers_features_other_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:home
  $menu_links['main-menu:home'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'home',
    'router_path' => 'home',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: main-menu:node/15
  $menu_links['main-menu:node/15'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/15',
    'router_path' => 'node/%',
    'link_title' => 'workspace',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: main-menu:node/187
  $menu_links['main-menu:node/187'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/187',
    'router_path' => 'node/%',
    'link_title' => 'Jazz Sheet Music',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: main-menu:node/23
  $menu_links['main-menu:node/23'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/23',
    'router_path' => 'node/%',
    'link_title' => 'Teacher mode',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 0,
  );
  // Exported menu link: main-menu:node/7
  $menu_links['main-menu:node/7'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'Challenges',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: main-menu:videodemo
  $menu_links['main-menu:videodemo'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'videodemo',
    'router_path' => 'videodemo',
    'link_title' => 'video demo',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: management:admin
  $menu_links['management:admin'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin',
    'router_path' => 'admin',
    'link_title' => 'Administration',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -45,
  );
  // Exported menu link: management:admin/appearance
  $menu_links['management:admin/appearance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/appearance',
    'router_path' => 'admin/appearance',
    'link_title' => 'Appearance',
    'options' => array(
      'attributes' => array(
        'title' => 'Select and configure your themes.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/config
  $menu_links['management:admin/config'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config',
    'router_path' => 'admin/config',
    'link_title' => 'Configuration',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer settings.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -43,
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/config/administration
  $menu_links['management:admin/config/administration'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/administration',
    'router_path' => 'admin/config/administration',
    'link_title' => 'Administration',
    'options' => array(
      'attributes' => array(
        'title' => 'Administration tools.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/administration/admin_menu
  $menu_links['management:admin/config/administration/admin_menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/administration/admin_menu',
    'router_path' => 'admin/config/administration/admin_menu',
    'link_title' => 'Administration menu',
    'options' => array(
      'attributes' => array(
        'title' => 'Adjust administration menu settings.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/administration',
  );
  // Exported menu link: management:admin/config/content
  $menu_links['management:admin/config/content'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content',
    'router_path' => 'admin/config/content',
    'link_title' => 'Content authoring',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings related to formatting and authoring content.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -15,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/content/background-image
  $menu_links['management:admin/config/content/background-image'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/background-image',
    'router_path' => 'admin/config/content/background-image',
    'link_title' => 'Background Image',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for how to apply the background image to the page',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/content',
  );
  // Exported menu link: management:admin/config/content/formats
  $menu_links['management:admin/config/content/formats'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/formats',
    'router_path' => 'admin/config/content/formats',
    'link_title' => 'Text formats',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure how content input by users is filtered, including allowed HTML tags. Also allows enabling of module-provided filters.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/content',
  );
  // Exported menu link: management:admin/config/content/location
  $menu_links['management:admin/config/content/location'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/location',
    'router_path' => 'admin/config/content/location',
    'link_title' => 'Location',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for Location module',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/content',
  );
  // Exported menu link: management:admin/config/content/webform
  $menu_links['management:admin/config/content/webform'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/webform',
    'router_path' => 'admin/config/content/webform',
    'link_title' => 'Webform settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Global configuration of webform functionality.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/content',
  );
  // Exported menu link: management:admin/config/content/webform_template
  $menu_links['management:admin/config/content/webform_template'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/webform_template',
    'router_path' => 'admin/config/content/webform_template',
    'link_title' => 'Webform Template settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Enable webform template for content types',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/content',
  );
  // Exported menu link: management:admin/config/content/wysiwyg
  $menu_links['management:admin/config/content/wysiwyg'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/wysiwyg',
    'router_path' => 'admin/config/content/wysiwyg',
    'link_title' => 'Wysiwyg profiles',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure client-side editors.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/content',
  );
  // Exported menu link: management:admin/config/date
  $menu_links['management:admin/config/date'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/date',
    'router_path' => 'admin/config/date',
    'link_title' => 'Date API',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for modules the use the Date API.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/date/tools
  $menu_links['management:admin/config/date/tools'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/date/tools',
    'router_path' => 'admin/config/date/tools',
    'link_title' => 'Date Tools',
    'options' => array(
      'attributes' => array(
        'title' => 'Date Wizard and other tools to manage and create dates and calendars. ',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/date',
  );
  // Exported menu link: management:admin/config/development
  $menu_links['management:admin/config/development'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development',
    'router_path' => 'admin/config/development',
    'link_title' => 'Development',
    'options' => array(
      'attributes' => array(
        'title' => 'Development tools.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/development/devel
  $menu_links['management:admin/config/development/devel'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/devel',
    'router_path' => 'admin/config/development/devel',
    'link_title' => 'Devel settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Helper functions, pages, and blocks to assist Drupal developers. The devel blocks can be managed via the <a href="/admin/structure/block">block administration</a> page.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/development',
  );
  // Exported menu link: management:admin/config/development/logging
  $menu_links['management:admin/config/development/logging'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/logging',
    'router_path' => 'admin/config/development/logging',
    'link_title' => 'Logging and errors',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for logging and alerts modules. Various modules can route Drupal\'s system events to different destinations, such as syslog, database, email, etc.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -15,
    'parent_path' => 'admin/config/development',
  );
  // Exported menu link: management:admin/config/development/maintenance
  $menu_links['management:admin/config/development/maintenance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/maintenance',
    'router_path' => 'admin/config/development/maintenance',
    'link_title' => 'Maintenance mode',
    'options' => array(
      'attributes' => array(
        'title' => 'Take the site offline for maintenance or bring it back online.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'parent_path' => 'admin/config/development',
  );
  // Exported menu link: management:admin/config/development/modal_forms
  $menu_links['management:admin/config/development/modal_forms'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/modal_forms',
    'router_path' => 'admin/config/development/modal_forms',
    'link_title' => 'Modal forms',
    'options' => array(
      'attributes' => array(
        'title' => 'Adjust Modal forms settings.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/development',
  );
  // Exported menu link: management:admin/config/development/performance
  $menu_links['management:admin/config/development/performance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/performance',
    'router_path' => 'admin/config/development/performance',
    'link_title' => 'Performance',
    'options' => array(
      'attributes' => array(
        'title' => 'Enable or disable page caching for anonymous users and set CSS and JS bandwidth optimization options.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'parent_path' => 'admin/config/development',
  );
  // Exported menu link: management:admin/config/development/strongarm
  $menu_links['management:admin/config/development/strongarm'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/development/strongarm',
    'router_path' => 'admin/config/development/strongarm',
    'link_title' => 'Strongarm',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage Drupal variable settings that have been strongarmed.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/development',
  );
  // Exported menu link: management:admin/config/media
  $menu_links['management:admin/config/media'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media',
    'router_path' => 'admin/config/media',
    'link_title' => 'Media',
    'options' => array(
      'attributes' => array(
        'title' => 'Media tools.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/media/amazons3
  $menu_links['management:admin/config/media/amazons3'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/amazons3',
    'router_path' => 'admin/config/media/amazons3',
    'link_title' => 'Amazon S3',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure your S3 credentials',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/media',
  );
  // Exported menu link: management:admin/config/media/awssdk
  $menu_links['management:admin/config/media/awssdk'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/awssdk',
    'router_path' => 'admin/config/media/awssdk',
    'link_title' => 'AWS SDK',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the Amazon Web Services SDK settings.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/media',
  );
  // Exported menu link: management:admin/config/media/browser
  $menu_links['management:admin/config/media/browser'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/browser',
    'router_path' => 'admin/config/media/browser',
    'link_title' => 'Media browser settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the behavior and display of the media browser.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/media',
  );
  // Exported menu link: management:admin/config/media/download-file
  $menu_links['management:admin/config/media/download-file'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/download-file',
    'router_path' => 'admin/config/media/download-file',
    'link_title' => 'Download file',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the format of the link accessible.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 30,
    'parent_path' => 'admin/config/media',
  );
  // Exported menu link: management:admin/config/media/file-system
  $menu_links['management:admin/config/media/file-system'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/file-system',
    'router_path' => 'admin/config/media/file-system',
    'link_title' => 'File system',
    'options' => array(
      'attributes' => array(
        'title' => 'Tell Drupal where to store uploaded files and how they are accessed.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'parent_path' => 'admin/config/media',
  );
  // Exported menu link: management:admin/config/media/file-types
  $menu_links['management:admin/config/media/file-types'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/file-types',
    'router_path' => 'admin/config/media/file-types',
    'link_title' => 'File types',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage files used on your site.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/media',
  );
  // Exported menu link: management:admin/config/media/image-styles
  $menu_links['management:admin/config/media/image-styles'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/image-styles',
    'router_path' => 'admin/config/media/image-styles',
    'link_title' => 'Image styles',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure styles that can be used for resizing or adjusting images on display.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/media',
  );
  // Exported menu link: management:admin/config/media/image-toolkit
  $menu_links['management:admin/config/media/image-toolkit'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/image-toolkit',
    'router_path' => 'admin/config/media/image-toolkit',
    'link_title' => 'Image toolkit',
    'options' => array(
      'attributes' => array(
        'title' => 'Choose which image toolkit to use if you have installed optional toolkits.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 20,
    'parent_path' => 'admin/config/media',
  );
  // Exported menu link: management:admin/config/media/rebuild_types
  $menu_links['management:admin/config/media/rebuild_types'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/media/rebuild_types',
    'router_path' => 'admin/config/media/rebuild_types',
    'link_title' => 'Rebuild type information for media',
    'options' => array(
      'attributes' => array(
        'title' => 'In case there are files in file_managed w/o a type, this function rebuilds them',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/media',
  );
  // Exported menu link: management:admin/config/people
  $menu_links['management:admin/config/people'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people',
    'router_path' => 'admin/config/people',
    'link_title' => 'People',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure user accounts.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -20,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/people/accounts
  $menu_links['management:admin/config/people/accounts'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/accounts',
    'router_path' => 'admin/config/people/accounts',
    'link_title' => 'Account settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure default behavior of users, including registration requirements, e-mails, fields, and user pictures.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'parent_path' => 'admin/config/people',
  );
  // Exported menu link: management:admin/config/people/force_password_change
  $menu_links['management:admin/config/people/force_password_change'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/force_password_change',
    'router_path' => 'admin/config/people/force_password_change',
    'link_title' => 'Force password change',
    'options' => array(
      'attributes' => array(
        'title' => 'Force users to change their password either immediately or after a period of time.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/people',
  );
  // Exported menu link: management:admin/config/people/invite
  $menu_links['management:admin/config/people/invite'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/invite',
    'router_path' => 'admin/config/people/invite',
    'link_title' => 'Invite',
    'options' => array(
      'attributes' => array(
        'title' => 'Modify invitation settings.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'parent_path' => 'admin/config/people',
  );
  // Exported menu link: management:admin/config/people/ip-blocking
  $menu_links['management:admin/config/people/ip-blocking'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/ip-blocking',
    'router_path' => 'admin/config/people/ip-blocking',
    'link_title' => 'IP address blocking',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage blocked IP addresses.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 10,
    'parent_path' => 'admin/config/people',
  );
  // Exported menu link: management:admin/config/people/relationships
  $menu_links['management:admin/config/people/relationships'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/people/relationships',
    'router_path' => 'admin/config/people/relationships',
    'link_title' => 'Relationships',
    'options' => array(
      'attributes' => array(
        'title' => 'Create relationship types',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/people',
  );
  // Exported menu link: management:admin/config/regional
  $menu_links['management:admin/config/regional'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional',
    'router_path' => 'admin/config/regional',
    'link_title' => 'Regional and language',
    'options' => array(
      'attributes' => array(
        'title' => 'Regional settings, localization and translation.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -5,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/regional/date-time
  $menu_links['management:admin/config/regional/date-time'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/date-time',
    'router_path' => 'admin/config/regional/date-time',
    'link_title' => 'Date and time',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure display formats for date and time.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -15,
    'parent_path' => 'admin/config/regional',
  );
  // Exported menu link: management:admin/config/regional/settings
  $menu_links['management:admin/config/regional/settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/regional/settings',
    'router_path' => 'admin/config/regional/settings',
    'link_title' => 'Regional settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for the site\'s default time zone and country.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -20,
    'parent_path' => 'admin/config/regional',
  );
  // Exported menu link: management:admin/config/search
  $menu_links['management:admin/config/search'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search',
    'router_path' => 'admin/config/search',
    'link_title' => 'Search and metadata',
    'options' => array(
      'attributes' => array(
        'title' => 'Local site search, metadata and SEO.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -10,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/search/clean-urls
  $menu_links['management:admin/config/search/clean-urls'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/clean-urls',
    'router_path' => 'admin/config/search/clean-urls',
    'link_title' => 'Clean URLs',
    'options' => array(
      'attributes' => array(
        'title' => 'Enable or disable clean URLs for your site.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'parent_path' => 'admin/config/search',
  );
  // Exported menu link: management:admin/config/search/path
  $menu_links['management:admin/config/search/path'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/path',
    'router_path' => 'admin/config/search/path',
    'link_title' => 'URL aliases',
    'options' => array(
      'attributes' => array(
        'title' => 'Change your site\'s URL paths by aliasing them.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -5,
    'parent_path' => 'admin/config/search',
  );
  // Exported menu link: management:admin/config/search/settings
  $menu_links['management:admin/config/search/settings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/settings',
    'router_path' => 'admin/config/search/settings',
    'link_title' => 'Search settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure relevance settings for search and other indexing options.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
    'parent_path' => 'admin/config/search',
  );
  // Exported menu link: management:admin/config/search/votingapi
  $menu_links['management:admin/config/search/votingapi'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/search/votingapi',
    'router_path' => 'admin/config/search/votingapi',
    'link_title' => 'Voting API',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure sitewide settings for user-generated ratings and votes.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/search',
  );
  // Exported menu link: management:admin/config/services
  $menu_links['management:admin/config/services'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/services',
    'router_path' => 'admin/config/services',
    'link_title' => 'Web services',
    'options' => array(
      'attributes' => array(
        'title' => 'Tools related to web services.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/services/oauth
  $menu_links['management:admin/config/services/oauth'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/services/oauth',
    'router_path' => 'admin/config/services/oauth',
    'link_title' => 'OAuth',
    'options' => array(
      'attributes' => array(
        'title' => 'Settings for OAuth',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/services',
  );
  // Exported menu link: management:admin/config/services/rss-publishing
  $menu_links['management:admin/config/services/rss-publishing'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/services/rss-publishing',
    'router_path' => 'admin/config/services/rss-publishing',
    'link_title' => 'RSS publishing',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure the site description, the number of items per feed and whether feeds should be titles/teasers/full-text.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/services',
  );
  // Exported menu link: management:admin/config/system
  $menu_links['management:admin/config/system'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system',
    'router_path' => 'admin/config/system',
    'link_title' => 'System',
    'options' => array(
      'attributes' => array(
        'title' => 'General system related configuration.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -20,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/system/actions
  $menu_links['management:admin/config/system/actions'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/actions',
    'router_path' => 'admin/config/system/actions',
    'link_title' => 'Actions',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage the actions defined for your site.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'admin/config/system',
  );
  // Exported menu link: management:admin/config/system/backup_migrate
  $menu_links['management:admin/config/system/backup_migrate'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/backup_migrate',
    'router_path' => 'admin/config/system/backup_migrate',
    'link_title' => 'Backup and Migrate',
    'options' => array(
      'attributes' => array(
        'title' => 'Backup/restore your database or migrate data to or from another Drupal site.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'parent_path' => 'admin/config/system',
  );
  // Exported menu link: management:admin/config/system/cron
  $menu_links['management:admin/config/system/cron'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/cron',
    'router_path' => 'admin/config/system/cron',
    'link_title' => 'Cron',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage automatic site maintenance tasks.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'parent_path' => 'admin/config/system',
  );
  // Exported menu link: management:admin/config/system/db_maintenance
  $menu_links['management:admin/config/system/db_maintenance'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/db_maintenance',
    'router_path' => 'admin/config/system/db_maintenance',
    'link_title' => 'DB maintenance',
    'options' => array(
      'attributes' => array(
        'title' => 'Executes a cron-based query to optimize database tables.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'parent_path' => 'admin/config/system',
  );
  // Exported menu link: management:admin/config/system/ftesettings
  $menu_links['management:admin/config/system/ftesettings'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/ftesettings',
    'router_path' => 'admin/config/system/ftesettings',
    'link_title' => 'FTEsettings',
    'options' => array(
      'attributes' => array(
        'title' => 'settings for FTE',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -45,
    'parent_path' => 'admin/config/system',
  );
  // Exported menu link: management:admin/config/system/ftesettings/edgemakers
  $menu_links['management:admin/config/system/ftesettings/edgemakers'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/ftesettings/edgemakers',
    'router_path' => 'admin/config/system/ftesettings/edgemakers',
    'link_title' => 'Edgemakers Stage',
    'options' => array(
      'attributes' => array(
        'title' => 'settings for Stage',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/system/ftesettings',
  );
  // Exported menu link: management:admin/config/system/ftesettings/media
  $menu_links['management:admin/config/system/ftesettings/media'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/ftesettings/media',
    'router_path' => 'admin/config/system/ftesettings/media',
    'link_title' => 'Edgemakers Media Config',
    'options' => array(
      'attributes' => array(
        'title' => 'Edgemakers media settings.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/system/ftesettings',
  );
  // Exported menu link: management:admin/config/system/ftesettings/mural-mail
  $menu_links['management:admin/config/system/ftesettings/mural-mail'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/ftesettings/mural-mail',
    'router_path' => 'admin/config/system/ftesettings/mural-mail',
    'link_title' => 'Confirmation email configuration',
    'options' => array(
      'attributes' => array(
        'title' => 'Confirmation email configuration',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/system/ftesettings',
  );
  // Exported menu link: management:admin/config/system/mailsystem
  $menu_links['management:admin/config/system/mailsystem'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/mailsystem',
    'router_path' => 'admin/config/system/mailsystem',
    'link_title' => 'Mail System',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure per-module Mail System settings.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'parent_path' => 'admin/config/system',
  );
  // Exported menu link: management:admin/config/system/mimemail
  $menu_links['management:admin/config/system/mimemail'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/mimemail',
    'router_path' => 'admin/config/system/mimemail',
    'link_title' => 'Mime Mail',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage mime mail system settings.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'parent_path' => 'admin/config/system',
  );
  // Exported menu link: management:admin/config/system/site-information
  $menu_links['management:admin/config/system/site-information'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/site-information',
    'router_path' => 'admin/config/system/site-information',
    'link_title' => 'Site information',
    'options' => array(
      'attributes' => array(
        'title' => 'Change site name, e-mail address, slogan, default front page, and number of posts per page, error pages.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/config/system',
  );
  // Exported menu link: management:admin/config/system/smtp
  $menu_links['management:admin/config/system/smtp'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/system/smtp',
    'router_path' => 'admin/config/system/smtp',
    'link_title' => 'SMTP Authentication Support',
    'options' => array(
      'attributes' => array(
        'title' => 'Allow for site emails to be sent through an SMTP server of your choice.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'parent_path' => 'admin/config/system',
  );
  // Exported menu link: management:admin/config/user-interface
  $menu_links['management:admin/config/user-interface'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface',
    'router_path' => 'admin/config/user-interface',
    'link_title' => 'User interface',
    'options' => array(
      'attributes' => array(
        'title' => 'Tools that enhance the user interface.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -15,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/user-interface/better-messages
  $menu_links['management:admin/config/user-interface/better-messages'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface/better-messages',
    'router_path' => 'admin/config/user-interface/better-messages',
    'link_title' => 'Better Messages settings',
    'options' => array(
      'attributes' => array(
        'title' => 'Better handling of Drupal messages UI',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/user-interface',
  );
  // Exported menu link: management:admin/config/user-interface/modulefilter
  $menu_links['management:admin/config/user-interface/modulefilter'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/user-interface/modulefilter',
    'router_path' => 'admin/config/user-interface/modulefilter',
    'link_title' => 'Module filter',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure settings for Module Filter.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/user-interface',
  );
  // Exported menu link: management:admin/config/workbench
  $menu_links['management:admin/config/workbench'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workbench',
    'router_path' => 'admin/config/workbench',
    'link_title' => 'Workbench',
    'options' => array(
      'attributes' => array(
        'title' => 'Workbench',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/workflow
  $menu_links['management:admin/config/workflow'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workflow',
    'router_path' => 'admin/config/workflow',
    'link_title' => 'Workflow',
    'options' => array(
      'attributes' => array(
        'title' => 'Content workflow, editorial workflow tools.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 5,
    'parent_path' => 'admin/config',
  );
  // Exported menu link: management:admin/config/workflow/rules
  $menu_links['management:admin/config/workflow/rules'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/workflow/rules',
    'router_path' => 'admin/config/workflow/rules',
    'link_title' => 'Rules',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage reaction rules and rule components.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/config/workflow',
  );
  // Exported menu link: management:admin/content
  $menu_links['management:admin/content'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Content',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer content and comments.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/content/comment
  $menu_links['management:admin/content/comment'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content/comment',
    'router_path' => 'admin/content/comment',
    'link_title' => 'Comments',
    'options' => array(
      'attributes' => array(
        'title' => 'List and edit site comments and the comment approval queue.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/content',
  );
  // Exported menu link: management:admin/content/media
  $menu_links['management:admin/content/media'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content/media',
    'router_path' => 'admin/content/media',
    'link_title' => 'Media',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage files used on your site.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/content',
  );
  // Exported menu link: management:admin/edgemakers
  $menu_links['management:admin/edgemakers'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/edgemakers',
    'router_path' => 'admin/edgemakers',
    'link_title' => 'Edgemakers',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: management:admin/edgemakers/bgimages
  $menu_links['management:admin/edgemakers/bgimages'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/edgemakers/bgimages',
    'router_path' => 'admin/edgemakers/bgimages',
    'link_title' => 'Manage Background Image',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/edgemakers',
  );
  // Exported menu link: management:admin/edgemakers/carousel
  $menu_links['management:admin/edgemakers/carousel'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/edgemakers/carousel',
    'router_path' => 'admin/edgemakers/carousel',
    'link_title' => 'Manage Carousel',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/edgemakers',
  );
  // Exported menu link: management:admin/edgemakers/set
  $menu_links['management:admin/edgemakers/set'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/edgemakers/set',
    'router_path' => 'admin/edgemakers/set',
    'link_title' => 'Manage Set',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/edgemakers',
  );
  // Exported menu link: management:admin/edgemakers/stage
  $menu_links['management:admin/edgemakers/stage'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/edgemakers/stage',
    'router_path' => 'admin/edgemakers/stage',
    'link_title' => 'Manage Stage',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/edgemakers',
  );
  // Exported menu link: management:admin/edgemakers/topic
  $menu_links['management:admin/edgemakers/topic'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/edgemakers/topic',
    'router_path' => 'admin/edgemakers/topic',
    'link_title' => 'Manage Topics',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/edgemakers',
  );
  // Exported menu link: management:admin/help
  $menu_links['management:admin/help'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/help',
    'router_path' => 'admin/help',
    'link_title' => 'Help',
    'options' => array(
      'attributes' => array(
        'title' => 'Reference for usage, configuration, and modules.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/modules
  $menu_links['management:admin/modules'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/modules',
    'router_path' => 'admin/modules',
    'link_title' => 'Modules',
    'options' => array(
      'attributes' => array(
        'title' => 'Extend site functionality.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/people
  $menu_links['management:admin/people'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'user management',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'parent_path' => 'admin/edgemakers',
  );
  // Exported menu link: management:admin/reports
  $menu_links['management:admin/reports'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports',
    'router_path' => 'admin/reports',
    'link_title' => 'Reports',
    'options' => array(
      'attributes' => array(
        'title' => 'View reports, updates, and errors.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -42,
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/reports/access-denied
  $menu_links['management:admin/reports/access-denied'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/access-denied',
    'router_path' => 'admin/reports/access-denied',
    'link_title' => 'Top \'access denied\' errors',
    'options' => array(
      'attributes' => array(
        'title' => 'View \'access denied\' errors (403s).',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/reports',
  );
  // Exported menu link: management:admin/reports/dblog
  $menu_links['management:admin/reports/dblog'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/dblog',
    'router_path' => 'admin/reports/dblog',
    'link_title' => 'Recent log messages',
    'options' => array(
      'attributes' => array(
        'title' => 'View events that have recently been logged.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -1,
    'parent_path' => 'admin/reports',
  );
  // Exported menu link: management:admin/reports/fields
  $menu_links['management:admin/reports/fields'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/fields',
    'router_path' => 'admin/reports/fields',
    'link_title' => 'Field list',
    'options' => array(
      'attributes' => array(
        'title' => 'Overview of fields on all entity types.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/reports',
  );
  // Exported menu link: management:admin/reports/page-not-found
  $menu_links['management:admin/reports/page-not-found'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/page-not-found',
    'router_path' => 'admin/reports/page-not-found',
    'link_title' => 'Top \'page not found\' errors',
    'options' => array(
      'attributes' => array(
        'title' => 'View \'page not found\' errors (404s).',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/reports',
  );
  // Exported menu link: management:admin/reports/search
  $menu_links['management:admin/reports/search'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/search',
    'router_path' => 'admin/reports/search',
    'link_title' => 'Top search phrases',
    'options' => array(
      'attributes' => array(
        'title' => 'View most popular search phrases.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/reports',
  );
  // Exported menu link: management:admin/reports/status
  $menu_links['management:admin/reports/status'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/status',
    'router_path' => 'admin/reports/status',
    'link_title' => 'Status report',
    'options' => array(
      'attributes' => array(
        'title' => 'Get a status report about your site\'s operation and any detected problems.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/reports',
  );
  // Exported menu link: management:admin/reports/updates
  $menu_links['management:admin/reports/updates'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/updates',
    'router_path' => 'admin/reports/updates',
    'link_title' => 'Available updates',
    'options' => array(
      'attributes' => array(
        'title' => 'Get a status report about available updates for your installed modules and themes.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'admin/reports',
  );
  // Exported menu link: management:admin/reports/views-plugins
  $menu_links['management:admin/reports/views-plugins'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/reports/views-plugins',
    'router_path' => 'admin/reports/views-plugins',
    'link_title' => 'Views plugins',
    'options' => array(
      'attributes' => array(
        'title' => 'Overview of plugins used in all views.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'admin/reports',
  );
  // Exported menu link: management:admin/structure
  $menu_links['management:admin/structure'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure',
    'router_path' => 'admin/structure',
    'link_title' => 'Structure',
    'options' => array(
      'attributes' => array(
        'title' => 'Administer blocks, content types, menus, etc.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -47,
    'parent_path' => 'admin',
  );
  // Exported menu link: management:admin/structure/block
  $menu_links['management:admin/structure/block'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/block',
    'router_path' => 'admin/structure/block',
    'link_title' => 'Blocks',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure what block content appears in your site\'s sidebars and other regions.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management:admin/structure/features
  $menu_links['management:admin/structure/features'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/features',
    'router_path' => 'admin/structure/features',
    'link_title' => 'Features',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage features.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management:admin/structure/flags
  $menu_links['management:admin/structure/flags'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/flags',
    'router_path' => 'admin/structure/flags',
    'link_title' => 'Flags',
    'options' => array(
      'attributes' => array(
        'title' => 'Configure flags for marking content with arbitrary information (such as <em>offensive</em> or <em>bookmarked</em>).',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management:admin/structure/mediafront
  $menu_links['management:admin/structure/mediafront'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/mediafront',
    'router_path' => 'admin/structure/mediafront',
    'link_title' => 'MediaFront Presets',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage and configure the presets for MediaFront.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -44,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management:admin/structure/menu
  $menu_links['management:admin/structure/menu'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/menu',
    'router_path' => 'admin/structure/menu',
    'link_title' => 'Menus',
    'options' => array(
      'attributes' => array(
        'title' => 'Add new menus to your site, edit existing menus, and rename and reorganize menu links.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -43,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management:admin/structure/oauth2-servers
  $menu_links['management:admin/structure/oauth2-servers'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/oauth2-servers',
    'router_path' => 'admin/structure/oauth2-servers',
    'link_title' => 'OAuth2 Servers',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage servers and their associated clients and scopes.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -42,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management:admin/structure/rate
  $menu_links['management:admin/structure/rate'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/rate',
    'router_path' => 'admin/structure/rate',
    'link_title' => 'Rate widgets',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage rating widgets.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management:admin/structure/services
  $menu_links['management:admin/structure/services'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/services',
    'router_path' => 'admin/structure/services',
    'link_title' => 'Services',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage Services',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management:admin/structure/taxonomy
  $menu_links['management:admin/structure/taxonomy'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/taxonomy',
    'router_path' => 'admin/structure/taxonomy',
    'link_title' => 'Taxonomy',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage tagging, categorization, and classification of your content.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -39,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management:admin/structure/taxonomy/challenges_vocabulary
  $menu_links['management:admin/structure/taxonomy/challenges_vocabulary'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/taxonomy/challenges_vocabulary',
    'router_path' => 'admin/structure/taxonomy/%',
    'link_title' => 'Manage Challenges',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'parent_path' => 'admin/edgemakers',
  );
  // Exported menu link: management:admin/structure/types
  $menu_links['management:admin/structure/types'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/types',
    'router_path' => 'admin/structure/types',
    'link_title' => 'Content types',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage content types, including default status, front page promotion, comment settings, etc.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management:admin/structure/views
  $menu_links['management:admin/structure/views'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/views',
    'router_path' => 'admin/structure/views',
    'link_title' => 'Views',
    'options' => array(
      'attributes' => array(
        'title' => 'Manage customized lists of content.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -38,
    'parent_path' => 'admin/structure',
  );
  // Exported menu link: management:admin/workbench
  $menu_links['management:admin/workbench'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/workbench',
    'router_path' => 'admin/workbench',
    'link_title' => 'My Workbench',
    'options' => array(
      'attributes' => array(
        'title' => 'My Workbench area',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'admin',
  );
  // Exported menu link: management:node/add/webform
  $menu_links['management:node/add/webform'] = array(
    'menu_name' => 'management',
    'link_path' => 'node/add/webform',
    'router_path' => 'node/add/webform',
    'link_title' => 'Create Survey & Assessment',
    'options' => array(
      'attributes' => array(
        'title' => 'create survey & assessment',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'parent_path' => 'admin/edgemakers',
  );
  // Exported menu link: navigation:edgemakers/set/ajaxlike
  $menu_links['navigation:edgemakers/set/ajaxlike'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'edgemakers/set/ajaxlike',
    'router_path' => 'edgemakers/set/ajaxlike',
    'link_title' => 'Delete Set',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: navigation:edgemakers/stage/api/list
  $menu_links['navigation:edgemakers/stage/api/list'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'edgemakers/stage/api/list',
    'router_path' => 'edgemakers/stage/api/list',
    'link_title' => '',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: navigation:filter/tips
  $menu_links['navigation:filter/tips'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'filter/tips',
    'router_path' => 'filter/tips',
    'link_title' => 'Compose tips',
    'options' => array(),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: navigation:forbidden
  $menu_links['navigation:forbidden'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'forbidden',
    'router_path' => 'forbidden',
    'link_title' => 'Access Denied',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: navigation:invite
  $menu_links['navigation:invite'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'invite',
    'router_path' => 'invite',
    'link_title' => 'Invite a friend',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: navigation:node/12
  $menu_links['navigation:node/12'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/12',
    'router_path' => 'node/%',
    'link_title' => 'project directory',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'parent_path' => 'node/15',
  );
  // Exported menu link: navigation:node/13
  $menu_links['navigation:node/13'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/13',
    'router_path' => 'node/%',
    'link_title' => 'project page',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'parent_path' => 'node/12',
  );
  // Exported menu link: navigation:node/14
  $menu_links['navigation:node/14'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/14',
    'router_path' => 'node/%',
    'link_title' => 'mural.ly',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'node/15',
  );
  // Exported menu link: navigation:node/15
  $menu_links['navigation:node/15'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/15',
    'router_path' => 'node/%',
    'link_title' => 'workspace',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -42,
  );
  // Exported menu link: navigation:node/23
  $menu_links['navigation:node/23'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/23',
    'router_path' => 'node/%',
    'link_title' => 'Teacher mode',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -40,
  );
  // Exported menu link: navigation:node/24
  $menu_links['navigation:node/24'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/24',
    'router_path' => 'node/%',
    'link_title' => 'Create groups',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'node/23',
  );
  // Exported menu link: navigation:node/25
  $menu_links['navigation:node/25'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/25',
    'router_path' => 'node/%',
    'link_title' => 'Create Templates',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'node/23',
  );
  // Exported menu link: navigation:node/26
  $menu_links['navigation:node/26'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/26',
    'router_path' => 'node/%',
    'link_title' => 'Assignments',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'node/23',
  );
  // Exported menu link: navigation:node/7
  $menu_links['navigation:node/7'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'Challenges',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -41,
  );
  // Exported menu link: navigation:node/8
  $menu_links['navigation:node/8'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/8',
    'router_path' => 'node/%',
    'link_title' => 'grand challenges',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'parent_path' => 'node/7',
  );
  // Exported menu link: navigation:node/9
  $menu_links['navigation:node/9'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/9',
    'router_path' => 'node/%',
    'link_title' => 'my chanllenges',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'parent_path' => 'node/7',
  );
  // Exported menu link: navigation:node/add
  $menu_links['navigation:node/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: navigation:node/add/article
  $menu_links['navigation:node/add/article'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/article',
    'router_path' => 'node/add/article',
    'link_title' => 'Article',
    'options' => array(
      'attributes' => array(
        'title' => 'Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/carousel-item
  $menu_links['navigation:node/add/carousel-item'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/carousel-item',
    'router_path' => 'node/add/carousel-item',
    'link_title' => 'Carousel Item',
    'options' => array(
      'attributes' => array(
        'title' => 'Carousel Item Node type',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/edgemakers-set
  $menu_links['navigation:node/add/edgemakers-set'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/edgemakers-set',
    'router_path' => 'node/add/edgemakers-set',
    'link_title' => 'Set',
    'options' => array(
      'attributes' => array(
        'title' => 'Node type used for setes.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/edgemakers-topic
  $menu_links['navigation:node/add/edgemakers-topic'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/edgemakers-topic',
    'router_path' => 'node/add/edgemakers-topic',
    'link_title' => 'Topic',
    'options' => array(
      'attributes' => array(
        'title' => 'Topic is a very basic and core content type in EdgeMakers. Topics are normally linked to <em>Wicked problem</em> and <em>Carousel</em>.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/media-for-upload
  $menu_links['navigation:node/add/media-for-upload'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/media-for-upload',
    'router_path' => 'node/add/media-for-upload',
    'link_title' => 'media for upload',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/murals
  $menu_links['navigation:node/add/murals'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/murals',
    'router_path' => 'node/add/murals',
    'link_title' => 'murals',
    'options' => array(
      'attributes' => array(
        'title' => 'infos of mural  in the mural site',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/openlayers-example-content
  $menu_links['navigation:node/add/openlayers-example-content'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/openlayers-example-content',
    'router_path' => 'node/add/openlayers-example-content',
    'link_title' => 'OpenLayers Example Content',
    'options' => array(
      'attributes' => array(
        'title' => 'This is an example content type for the OpenLayers module.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/page
  $menu_links['navigation:node/add/page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/page',
    'router_path' => 'node/add/page',
    'link_title' => 'Basic page',
    'options' => array(
      'attributes' => array(
        'title' => 'Use <em>basic pages</em> for your static content, such as an \'About us\' page.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/site-bg-image
  $menu_links['navigation:node/add/site-bg-image'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/site-bg-image',
    'router_path' => 'node/add/site-bg-image',
    'link_title' => 'Site BG Image',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/stage
  $menu_links['navigation:node/add/stage'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/stage',
    'router_path' => 'node/add/stage',
    'link_title' => 'Stage',
    'options' => array(
      'attributes' => array(
        'title' => 'Node type used for making stage.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/webform
  $menu_links['navigation:node/add/webform'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/webform',
    'router_path' => 'node/add/webform',
    'link_title' => 'Webform',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:oauth2/authorize
  $menu_links['navigation:oauth2/authorize'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'oauth2/authorize',
    'router_path' => 'oauth2/authorize',
    'link_title' => '',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: navigation:oauth2/token
  $menu_links['navigation:oauth2/token'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'oauth2/token',
    'router_path' => 'oauth2/token',
    'link_title' => '',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: navigation:search
  $menu_links['navigation:search'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: navigation:tracker
  $menu_links['navigation:tracker'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'tracker',
    'router_path' => 'tracker',
    'link_title' => 'Recent posts',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: user-menu:relationships
  $menu_links['user-menu:relationships'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'relationships',
    'router_path' => 'relationships',
    'link_title' => 'My relationships',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: user-menu:user
  $menu_links['user-menu:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -10,
  );
  // Exported menu link: user-menu:user/logout
  $menu_links['user-menu:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('AWS SDK');
  t('Access Denied');
  t('Account settings');
  t('Actions');
  t('Add content');
  t('Administration');
  t('Administration menu');
  t('Amazon S3');
  t('Appearance');
  t('Article');
  t('Assignments');
  t('Available updates');
  t('Background Image');
  t('Backup and Migrate');
  t('Basic page');
  t('Better Messages settings');
  t('Blocks');
  t('Carousel Item');
  t('Challenges');
  t('Clean URLs');
  t('Comments');
  t('Compose tips');
  t('Configuration');
  t('Confirmation email configuration');
  t('Content');
  t('Content authoring');
  t('Content types');
  t('Create Survey & Assessment');
  t('Create Templates');
  t('Create groups');
  t('Cron');
  t('DB maintenance');
  t('Date API');
  t('Date Tools');
  t('Date and time');
  t('Delete Set');
  t('Devel settings');
  t('Development');
  t('Download file');
  t('Edgemakers');
  t('Edgemakers Media Config');
  t('Edgemakers Stage');
  t('FTEsettings');
  t('Features');
  t('Field list');
  t('File system');
  t('File types');
  t('Flags');
  t('Force password change');
  t('Help');
  t('Home');
  t('IP address blocking');
  t('Image styles');
  t('Image toolkit');
  t('Invite');
  t('Invite a friend');
  t('Jazz Sheet Music');
  t('Location');
  t('Log out');
  t('Logging and errors');
  t('Mail System');
  t('Maintenance mode');
  t('Manage Background Image');
  t('Manage Carousel');
  t('Manage Challenges');
  t('Manage Set');
  t('Manage Stage');
  t('Manage Topics');
  t('Media');
  t('Media browser settings');
  t('MediaFront Presets');
  t('Menus');
  t('Mime Mail');
  t('Modal forms');
  t('Module filter');
  t('Modules');
  t('My Workbench');
  t('My relationships');
  t('OAuth');
  t('OAuth2 Servers');
  t('OpenLayers Example Content');
  t('People');
  t('Performance');
  t('RSS publishing');
  t('Rate widgets');
  t('Rebuild type information for media');
  t('Recent log messages');
  t('Recent posts');
  t('Regional and language');
  t('Regional settings');
  t('Relationships');
  t('Reports');
  t('Rules');
  t('SMTP Authentication Support');
  t('Search');
  t('Search and metadata');
  t('Search settings');
  t('Services');
  t('Set');
  t('Site BG Image');
  t('Site information');
  t('Stage');
  t('Status report');
  t('Strongarm');
  t('Structure');
  t('System');
  t('Taxonomy');
  t('Teacher mode');
  t('Text formats');
  t('Top \'access denied\' errors');
  t('Top \'page not found\' errors');
  t('Top search phrases');
  t('Topic');
  t('URL aliases');
  t('User account');
  t('User interface');
  t('Views');
  t('Views plugins');
  t('Voting API');
  t('Web services');
  t('Webform');
  t('Webform Template settings');
  t('Webform settings');
  t('Workbench');
  t('Workflow');
  t('Wysiwyg profiles');
  t('grand challenges');
  t('media for upload');
  t('mural.ly');
  t('murals');
  t('my chanllenges');
  t('project directory');
  t('project page');
  t('user management');
  t('video demo');
  t('workspace');


  return $menu_links;
}

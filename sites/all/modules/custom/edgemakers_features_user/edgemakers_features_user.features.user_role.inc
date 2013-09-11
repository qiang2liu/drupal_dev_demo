<?php
/**
 * @file
 * edgemakers_features_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function edgemakers_features_user_user_default_roles() {
  $roles = array();

  // Exported role: parent.
  $roles['parent'] = array(
    'name' => 'parent',
    'weight' => 5,
  );

  // Exported role: site admin.
  $roles['site admin'] = array(
    'name' => 'site admin',
    'weight' => 6,
  );

  // Exported role: site administrator.
  $roles['site administrator'] = array(
    'name' => 'site administrator',
    'weight' => 2,
  );

  // Exported role: student.
  $roles['student'] = array(
    'name' => 'student',
    'weight' => 4,
  );

  // Exported role: teacher.
  $roles['teacher'] = array(
    'name' => 'teacher',
    'weight' => 3,
  );

  return $roles;
}

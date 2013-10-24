<?php
global $user;
$user = user_load($user->uid);
$avatarUris = explode('/', variable_get('user_picture_default', ''));
$avatarUri = file_build_uri(array_pop($avatarUris));
if(isset($user->field_profile_picture[LANGUAGE_NONE])) {
  $fid = $user->field_profile_picture[LANGUAGE_NONE][0]['fid'];
  if($fid) {
    $profile_picture = file_load($fid);
    if(file_exists($profile_picture->uri)) {
      $avatarUri = $profile_picture->uri;
    }
  }
}
$userpic = '<div class="user-picture">'.theme('image_style', array('style_name' => 'edgemakers_avatar', 'path' => $avatarUri)).'</div>';
?>
<div class="<?php print $classes . ' ' . $zebra; ?>"<?php print $attributes; ?>>

  <div class="clearfix">

    <span class="submitted"><?php print $submitted ?></span>

  <?php if ($new): ?>
    <span class="new"><?php print drupal_ucfirst($new) ?></span>
  <?php endif; ?>

  <?php print $userpic ?>

    <?php print render($title_prefix); ?>
    <h3<?php print $title_attributes; ?>><?php print $title ?></h3>
    <?php print render($title_suffix); ?>

    <div class="content"<?php print $content_attributes; ?>>
      <?php hide($content['links']); print render($content); ?>
      <?php if ($signature): ?>
      <div class="clearfix">
        <div>—</div>
        <?php print $signature ?>
      </div>
      <?php endif; ?>
    </div>
  </div>
</div>

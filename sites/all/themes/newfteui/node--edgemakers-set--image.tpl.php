<?php
//title: $title
//body: render($content['body'])
?>
<style>
#content div.tabs {
  display: none;
}
</style>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

<!--
<div id="set-type-text"><h3><?php echo isset($node->term->name)?$node->term->name: ''; ?></h3></div>
-->
<!--
<div id="set-user-info">
  <dl>
  <dt>
  <?php print $user_picture; ?>
  </dt>

  <?php print render($title_prefix); ?>
  <dd>
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <div class="shadeDiv" style="">&nbsp;</div>
  </dd>
  <?php print render($title_suffix); ?>
  </dl>

  <?php if ($display_submitted): ?>
    <span class="submitted"><?php print $submitted ?></span>
  <?php endif; ?>
</div>
-->

  <div id="<?php echo isset($node->term->name)?$node->term->name: ''; ?>-image-icon" class="set-type-icon set-image-type-icon">
    Image<br/>
  </div>

  <span id="set-title" style="display: none;"><?php print $title;?></span>
  <div class="content set-image-content clearfix"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content['field_set_image']);
      //print render($content);

      /*
      // @link https://drupal.org/node/1145890
      $image_style_name = 'medium';
      $image_uri = $file_uri = $node->field_set_image[$node->language][0]['uri'];

      $file_uri = $node->field_set_image[$node->language][0]['uri'];
      $image = theme('image_style', array('style_name' => $image_style_name, 'path' => $image_uri));
      $link = file_create_url($file_uri);
      print l($image, $link, array('html' => TRUE));
      */

      // print('<pre>' . print_r($node, TRUE) . '</pre>');
      //echo image_file_download($image_uri);

    ?>
    <span id="image-download-it">
    <?php

      //drupal_set_message('<pre>' . print_r($node, TRUE) . '</pre>');
      $image_uri = file_create_url($node->field_set_image[$node->language][0]['uri']);
      $download_uri = 'download/file/fid/' . $node->field_set_image[$node->language][0]['fid'];

      $download_icon = array('path' => drupal_get_path('theme', 'newfteui'). '/images/iconDownload.png');
      //drupal_set_message('<pre>' . print_r($download_icon, TRUE) . '</pre>');

      $download_icon_img = theme('image' , $download_icon);
      //echo image_file_download($image_uri);
      echo l($download_icon_img, $download_uri, array(
        'attributes' => array(
          //'target' => '_blank',
        ),
        'html' => TRUE,
        )
      );
    ?>
    </span>
  </div>

  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <div class="links"><?php print render($content['links']); ?></div>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>

</div>
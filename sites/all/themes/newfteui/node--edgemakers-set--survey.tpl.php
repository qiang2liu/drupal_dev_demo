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

  <div id="<?php echo isset($node->term->name)?$node->term->name: ''; ?>-video-icon" class="set-type-icon set-video-type-icon">
    <?php echo isset($node->term->name)?$node->term->name: ''; ?><br/>
  </div>

  <span id="set-title" style="display: none;"><?php print $title; ?></span>
  <div class="content set-text-content clearfix"<?php print $content_attributes; ?>>
    <div id="em-webform">
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      //print render($content);
      $surveys = field_get_items('node', $node, 'field_set_survey');
      $survey = $surveys && count($surveys) > 0 ? $surveys[0]['target_id'] : '';
      if($survey != '') {
        $node_webform = node_load($survey);
        $submission = (object) array();
        $enabled = TRUE;
        $preview = FALSE;
        $webform = drupal_get_form('webform_client_form_'.$survey, $node_webform, $submission, $enabled, $preview);
        print render($webform);
      }
    ?>
    </div>
  </div>

  <div class="clearfix">
  </div>

</div>
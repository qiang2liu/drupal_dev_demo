<?php
//title: $title
//body: render($content['body'])

// print('<pre>' . print_r($node, TRUE) . '</pre>');

$nid = '';
if (isset($node->field_set_topic['und'])) {
  $nid = $node->field_set_topic['und']['0']['target_id'];
  $topic = node_load($nid);
}

?>
<style>
#content div.tabs {
  display: none;
}
</style>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>


  <div id="topic-image-icon" class="set-type-icon set-image-type-icon">
    Topic<br/>
  </div>

  <span id="set-title"><?php print $title;?></span>
  <div class="topic-content content set-text-content clearfix"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print drupal_render(node_view($topic, 'full'));
      // Print "Did you know from topic";
//       print render($content['field_teacher_notes']);
    ?>
  </div>

  <div class="clearfix">
  </div>

</div>
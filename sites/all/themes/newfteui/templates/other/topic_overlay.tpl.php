<style>
#content div.tabs {
  display: none;
}
</style>

<div>


  <div id="topic-image-icon" class="set-type-icon set-image-type-icon">
    Topic<br/>
  </div>

  <span id="set-title"><?php print $topic->title;?></span>
  <div class="topic-content content set-text-content clearfix">
    <?php
      print drupal_render(node_view($topic, 'full'));
      $view = views_embed_view('mural_list_in_topic', 'block', $topic->nid);
      print '<div id="topic-murals">'.$view.'</div>';
    ?>
  </div>

  <div class="clearfix">
  </div>

</div>
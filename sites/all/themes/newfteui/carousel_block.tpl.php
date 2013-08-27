<div id="d3">
	<div class="d3-left-arrow"><img  src="<?php print drupal_get_path('theme', 'newfteui');?>/images/ico_da_slider_left.png"  /></div>
    
		<?php foreach($items as $item):
      if($item['topicid']) {
        $topic = node_load($item['topicid']);
        $title = $topic->title;
        $descriptions = field_get_items('node', $topic, 'field_topic_problem');
        $description = $descriptions && count($descriptions) ? $descriptions[0]['value'] : '';
      } else {
        $title = '';
        $description = '';
      }
    ?>
    <div class="d3-item">
      <img src="<?php echo $item['imageurl'];?>" />
      <div class="carousel-des">
        <h5><?php echo $title;?></h5>
        <p><?php echo $description;?></p>
        <div class="carousel-viewmore">
          <a href="node/<?php echo $item['topicid'];?>" target="_blank">View Wicked Problem</a>
        </div>
      </div>
    </div>
		<?php endforeach;?>
    
	<div class="d3-right-arrow"><img  src="<?php print drupal_get_path('theme', 'newfteui');?>/images/ico_da_slider_right.png"  /></div>
</div>
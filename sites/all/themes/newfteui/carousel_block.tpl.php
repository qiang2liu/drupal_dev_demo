<div id="d3">
	<div class="d3-left-arrow"><img  src="<?php print drupal_get_path('theme', 'newfteui');?>/images/ico_da_slider_left.png"  /></div>
		<?php foreach($items as $item): ?>
    <div class="d3-item">
      <img src="<?php echo $item['imageurl'];?>" />
      <div class="carousel-des">
        <h5><?php echo $item['title'];?></h5>
        <p><?php echo $item['description'];?></p>
        <div class="carousel-viewmore">
          <a href="node/<?php echo $item['topicid'];?>" target="_blank">View Wicked Problem</a>
        </div>
      </div>
    </div>
		<?php endforeach;?>
    
	<div class="d3-right-arrow"><img  src="<?php print drupal_get_path('theme', 'newfteui');?>/images/ico_da_slider_right.png"  /></div>
</div>
<div id="d3">
	<div class="d3-left-arrow"><img  src="<?php print drupal_get_path('theme', 'newfteui');?>/images/ico_da_slider_left.png"  /></div>
		<?php foreach($items as $item):?>	
    <div class="d3-item">
    	<a href="node/<?php echo $item['topicid'];?>" target="_blank"><img src="<?php echo $item['imageurl'];?>" /></a>
    </div>
		<?php endforeach;?>
	<div class="d3-right-arrow"><img  src="<?php print drupal_get_path('theme', 'newfteui');?>/images/ico_da_slider_right.png"  /></div>
</div>
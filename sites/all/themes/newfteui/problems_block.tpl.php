  <div class="topic-selector">
    <ul>
		  <?php foreach($items as $tid=>$term):?>
     	<li>
        <a href="<?php echo url('node/'.$term['topicid']); ?>" target="_blank"><?php echo $term['name'];?></a>
      </li>
      <?php endforeach;?>
    </ul>
  </div>
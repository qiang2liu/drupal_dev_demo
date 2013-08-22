  <div class="topic-selector">
    <ul>
		  <?php foreach($items as $tid=>$term):?>
     	<li>
        <?php echo l($term['name'], 'node/'.$term['topicid']); ?></a>
      </li>
      <?php endforeach;?>
    </ul>
  </div>
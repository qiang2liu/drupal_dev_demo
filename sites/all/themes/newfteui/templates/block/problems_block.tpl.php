  <ul class="topic-tab">
  	<li class="topic-problem actived">&nbsp;</li><li class="topic-location">&nbsp;</li>
  </ul>
  <div class="topic-content-box content-topic actived">
  	<h2>Wicked Problem</h2>

	    <ul>
			  <?php foreach($items['list'] as $tid=>$term):?>
	     	<li>

	        <a class="topic_link" href="<?php echo url('edgemakers/topic/view/'.$term['topicid']); ?>"><?php echo $term['name'];?></a>
	      </li>
	      <?php endforeach;?>
	    </ul>

  </div>
  <div class="gmap content-location">
    <iframe id="iframe-topic-gmap" border="0" scrolling="no" width="560px" height="400px" src="?q=edgemakers/topic/gmap" ></iframe>
     <?php //print $items['map'];?>
  </div>



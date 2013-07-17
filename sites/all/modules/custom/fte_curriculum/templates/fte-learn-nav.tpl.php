<?php
 global $base_url;
?>
	<ul class="menu-learn">
          
      <?php
          $the_class_var = '';
          foreach ($data as $k=>$v) {
      ?>
          
		<li <?php print $the_class_var;?>>
                <?php $the_class_var = ''; ?>  
                  
	    	<a href="#x"><?php print $v['title'];?></a>
	        <ul>
                  <?php
                    foreach ($v['ftemodule'] as $m_k=>$m_v){
                  ?>
                  
	        	<li><a href="<?php print $base_url;?>/learn/<?php print $m_k;?>/stage/0" class="menu-learn-child has-link" data-des="<?php print $m_v['desc'];?>"><?php print $m_v['title'];?></a></li>
	           
	        <?php } ?>
                </ul>
	    </li>
	    
	    
         <?php
         
          }
         ?>   
	</ul>
	<div class="menu-learn-fly-layer">
		
	</div>


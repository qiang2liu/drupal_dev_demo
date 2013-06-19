<?php

$the_path = drupal_get_path('module', 'fte_curriculum');
//drupal_add_js($the_path.'/js/fte_learn.js');
global $base_path;
global $base_url;
?>






<div class ="stage_bottom_area" style="clear: both">
	<div class="stage_bottom_content">
  	<div class="stage_bottom_content_tab">
    	<em class="stage_bottom_switcher active"></em>
        <span class="active"> NOTES</span>
        <span>MURALS</span>
     </div>
     <div class="stage_bottom_content_inner">
    	<div class="stage_bottom_content_inner_content">This is NOTES.</div>  
    	<div class="stage_bottom_content_inner_content">
          
          <ul>
            
            <li style="float:left;margin:10px">
              <div style="text-align:center"><img src="<?php print $base_url;?>/images/mock_mural_icon.jpg"/></div>
              <div><select name="pp"><option>private</option><option>public</option></select></div>
              
            </li style="float:left">
            
            <li style="float:left;margin:10px">
              <div style="text-align:center"><img src="<?php print $base_url;?>/images/mock_mural_icon.jpg"/></div>
              <div><select name="pp"><option>private</option><option>public</option></select></div>
              
            </li>
            
             <li style="float:left;margin:10px">
              <div style="text-align:center"><img src="<?php print $base_url;?>/images/mock_mural_icon.jpg"/></div>
              <div><select name="pp"><option>private</option><option selected>public</option></select></div>
              
            </li style="float:left">
            
            <li style="float:left;margin:10px">
              <div style="text-align:center"><img src="<?php print $base_url;?>/images/mock_mural_icon.jpg"/></div>
              <div><select name="pp"><option>private</option><option selected>public</option></select></div>
              
            </li>
            
            <li style="clear:both"></li>
          </ul>
          
        </div>
	</div>
  </div>  
  <div class="stage_comments" >
      <div class="stage_bottom_content_tab">
        <em class="stage_bottom_switcher active"></em>
        <span>COMMENTS</span>
      
      </div>
   	   <div class="stage_bottom_content_inner">
         <p>This is comments.</p>
        </div>
   </div>
</div>  <!-- stage_bottom_area -->

<?php

$the_path = drupal_get_path('module', 'fte_curriculum');
//drupal_add_js($the_path.'/js/fte_learn.js');
global $base_path;
?>






<div class ="stage_bottom_area" style="clear: both">
  
  <div class="stage_bottom_content">
  	<div class="stage_bottom_content_tab">
    	<em class="stage_bottom_switcher active"></em>
        <span class="active">Description</span>
        <span>Users</span>
        <span>Notes</span> 
     </div>
     <div class="stage_bottom_content_inner">
    	<div class="stage_bottom_content_inner_content">
          <p>Welcome to EDGEmakers: Finding our Bearing: Leaning Forward: Stage 1. Do not be fooled into thinking this is education. It's not. Its really just a sequence of videos, interactive interfaces and throbbing head banging ideas and content. You've been warned.</p>
        
        </div>  
    	<div class="stage_bottom_content_inner_content">
            <ul>
            <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_1.png"></li>
            <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_2.png"></li>
            <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid grey" src="<?php print $base_path;?>images/mock_user_icon_3.png"></li>
            <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_4.png"></li>     
            <div style="clear:both"></div>   
          </ul>
   		 </div>
    	<div class="stage_bottom_content_inner_content">This is others.</div>
	</div>
  </div>  
  <div class="stage_comments" >
      <div class="stage_bottom_content_tab">
        <em class="stage_bottom_switcher active"></em>
        <span>Comments</span>
      
      </div>
   	   <div class="stage_bottom_content_inner">
         <p>This is comments.</p>
        </div>
   </div>

</div>  <!-- stage_bottom_area -->

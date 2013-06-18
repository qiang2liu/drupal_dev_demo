<?php

$the_path = drupal_get_path('module', 'fte_curriculum');
//drupal_add_js($the_path.'/js/fte_learn.js');
global $base_path;
?>






<div class ="stage_bottom_area" style="clear: both">
	<div class="stage_bottom_content">
  	<div class="stage_bottom_content_tab">
    	<em class="stage_bottom_switcher active"></em>
        <span class="active"> stage description</span>
        <span>stage users</span>
        <span>NOTES</span> 
        <span>MURALS</span>
        <span>TEMPLATES</span>
     </div>
     <div class="stage_bottom_content_inner">
    	<div class="stage_bottom_content_inner_content">This is stage description.</div>  
    	<div class="stage_bottom_content_inner_content">
            <ul>
            <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_1.png"></li>
            <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_2.png"></li>
            <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid grey" src="<?php print $base_path;?>images/mock_user_icon_3.png"></li>
            <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_4.png"></li>     
            <div style="clear:both"></div>   
          </ul>
   		 </div>
    	<div class="stage_bottom_content_inner_content">This is NOTES.</div>
        <div class="stage_bottom_content_inner_content">This is MURALS.</div>
         <div class="stage_bottom_content_inner_content">This is TEMPLATES.</div>
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

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
        <span>others</span> 
     </div>
     <div class="stage_bottom_content_inner">
    	<div class="stage_bottom_content_inner_content">
          Think of somebody who you admire - who are they?<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <br>
WHY DID YOU PICK THEM?<br>
&nbsp; <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; WHAT DID YOU ADMIRE
ABOUT THEM?<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; WHAT WERE THEY GOOD AT?<br>
<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; WHY DID THEY DO WHAT
THEY DID?<br>
<br>
IF YOU WERE GOING TO LEAN FORWARD LIKE THEY DID, WHAT WOULD YOU LIKE
PEOPLE TO SAY ABOUT YOU?<br>
<br>
<span style="color: rgb(0, 0, 102); font-weight: bold;">NOTE:</span>
THIS ACTIVITY CAN BE DONE INDIVIDUALLY OR IN A GROUP<br>
<br>
<span style="color: rgb(0, 0, 102);"><span style="font-weight: bold;">NOTE2:</span>
</span>Users fill in answers into thr mural - hit save.......<br>

        
        
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
        <span>COMMENTS</span>
      
      </div>
   	   <div class="stage_bottom_content_inner">
         <p>This is comments.</p>
        </div>
   </div>

</div>  <!-- stage_bottom_area -->

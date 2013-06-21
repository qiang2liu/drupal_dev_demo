<?php

$the_path = drupal_get_path('module', 'fte_curriculum');
//drupal_add_js($the_path.'/js/fte_learn.js');
global $base_path, $base_url;
?>






<div class ="stage_bottom_area" style="clear: both">
	<div class="stage_bottom_content">
  	<div class="stage_bottom_content_tab">
    	<em class="stage_bottom_switcher active"></em>
        <span class="active">Description</span>
        <span>Templates</span>
        <span>Murals</span> 
        <span>Users</span>
        <span>Notes</span>
     </div>
     <div class="stage_bottom_content_inner">
    	<div class="stage_bottom_content_inner_content">
           <?php  if ($data==5) {?>
          <p>We've partnered with a tool company which makes a collaborative canvas called MURAL.LY. We're going to be sending you to Mural.ly throughout our LEARN Stages - asking you to think visually; utilizing templates, graphics, text, external documents and videos and images. Mural.ly produces documenst called "murals" and every EDGEmaker will have their own set of murals, or be able to participate in shared murals.</p>
         <p>Mural.ly is a collaborative canvas - that you can use to design, produce and organize Projects - which can then be submitted as entries to Competitions.</p>
         <p>We're also going to show you how to use Mural.ly murals to build and maintain Portfolios - which you can then use to send to colleges or internship applications.</p>

            <?php
             }
			  
			?>
            
            <?php  if ($data==6) {?>
          <p>Here's another usage of Mural.ly - starting with a template and modifying it and saving off your own version.</p>
         

            <?php
             }
			  
			?>
         
          
        </div>  
        <div class="stage_bottom_content_inner_content">
        	<ul>
            
            <li style="float:left;margin:10px">
              <div style="text-align:center"><img src="<?php print $base_url;?>/images/mock_mural_icon.jpg"/></div>
              
              
            </li style="float:left">
            
            <li style="float:left;margin:10px">
              <div style="text-align:center"><img src="<?php print $base_url;?>/images/mock_mural_icon.jpg"/></div>
             
              
            </li>
            
             <li style="float:left;margin:10px">
              <div style="text-align:center"><img src="<?php print $base_url;?>/images/mock_mural_icon.jpg"/></div>
            
              
            </li style="float:left">
            
            <li style="float:left;margin:10px">
              <div style="text-align:center"><img src="<?php print $base_url;?>/images/mock_mural_icon.jpg"/></div>
              
              
            </li>
            
            <li style="clear:both"></li>
          </ul>
        </div>
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
    	<div class="stage_bottom_content_inner_content">
            <ul>
            <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_1.png"></li>
            <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_2.png"></li>
            <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid grey" src="<?php print $base_path;?>images/mock_user_icon_3.png"></li>
            <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_4.png"></li>     
            <div style="clear:both"></div>   
          </ul>
   		 </div>
    	
        <div class="stage_bottom_content_inner_content">
         
          <p>This is Notes.</p>
          
          
          
          
          
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

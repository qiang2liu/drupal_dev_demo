<?php
global $base_url;
function _get_terms_list() {
  $terms_list = array();
	$terms = taxonomy_get_tree(3);
	foreach($terms as $term) {
	  if($term->parents[0] == 0) {
			$terms_list[$term->tid] = array();
		  $terms_list[$term->tid]['name'] = $term->name;
		} else {
			$terms_list[$term->parents[0]]['children'][$term->tid] = array();
			$terms_list[$term->parents[0]]['children'][$term->tid]['name'] = $term->name;
		}
	}
	return $terms_list;
}
$terms_list = _get_terms_list();

function _get_carousel_items_list() {
  $renderable_array = array();
  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.status = :status';
  $result = db_query($sql, array(
    ':type' => 'carousel_item',
    ':status' => 1,
  ));
  foreach ($result as $row) {
    $node = node_load($row->nid);
		$link = field_get_items('node', $node, 'field_carousel_item_link');
		$image = field_get_items('node', $node, 'field_carousel_item_image');
		$renderable_array[] = array(
			'nid'=>$row->nid,
			'link'=>$link[0]['safe_value'],
			'imageurl'=>file_create_url($image[0]['uri']),
		);
  }
  return $renderable_array;
}
$carousel_items_list = _get_carousel_items_list();
?>

<style>
  
  .showcase_videos ul li {
    float:left;
  }
  .taglevel0 {
    font-size:8px;  
  }
  .taglevel1 {
    font-size:15px;  
  }
  .taglevel2 {
    font-size:22px;  
  }
  .taglevel3 {
    font-size:30px;  
    color:red
  }

  
</style>


<!--<div>
  <h2 style="text-align: center; background:#6fa8dc; padding:1em; font-size:1.6em; font-weight:bold; color:#fff;">Challenges</h2>
</div>-->

<div id="d3">
	<div class="d3-left-arrow"><img  src="<?php print $base_url;?>/images/ico_da_slider_left.png"  /></div>
		<?php foreach($carousel_items_list as $item):?>	
    <div class="d3-item">
    	<a href="<?php echo $item['link'];?>" target="_blank"><img src="<?php echo $item['imageurl'];?>" /></a>
    </div>
		<?php endforeach;?>
	<div class="d3-right-arrow"><img  src="<?php print $base_url;?>/images/ico_da_slider_right.png"  /></div>
</div>


<!-- map section -->
<!--<h3>TOPIC SELECTOR</h3>-->
<div class='mapsection'>
  
  <div class="topic-selector">
    
     <ul>
		  <?php foreach($terms_list as $tid=>$terminfo):?>
     	<li>
        	<?php echo $terminfo['name']; ?>
        	<?php if(isset($terminfo['children'])): ?>					
            <ul class="topic-selector-sub-menu">
							<?php foreach($terminfo['children'] as $subtid=>$subterminfo):?>
            	<li><a href="<?php echo $base_url; ?>/Challenges/Topic"><?php echo $subterminfo['name']; ?></a></li>
							<?php endforeach;?>
            </ul>
        	<?php endif; ?>	
         </li>
				 <?php endforeach;?>
     </ul>
     
    
    
  </div>
  
  <div class="cha-map-area">
    <div id="map_canvas" style="width:831px;height:520px;"></div>
    
   
  
  </div>
  
</div>
<!-- chanllenge slider-->
<!--<h3>Showcase</h3>-->
<div class="cha-slider">
	<div class="cha-slider-left"></div>
    <div class="cha-slider-middle">
      <div class="cha-slider-middle-inner">
    	<ul>
        	<li><img src="<?php print $base_url;?>/sites/all/themes/fte/images/mock_cha_slide_01.png" /></li>
            <li><img src="<?php print $base_url;?>/sites/all/themes/fte/images/mock_cha_slide_02.png" /></li>
            <li><img src="<?php print $base_url;?>/sites/all/themes/fte/images/mock_cha_slide_03.png" /></li>
            <li><img src="<?php print $base_url;?>/sites/all/themes/fte/images/mock_cha_slide_04.png" /></li>
        </ul>
      </div>
    </div>
    <div class="cha-slider-right"></div>
</div>

<!-- project section -->

<div style="margin-top:1em;">
  
  <div class='project_directory' style='width:70%; float:left;border:solid 1px #c065f1;margin-right:10px;'>
    <!--<div class="project_directory-title">
      <span style="font-size:1.2em; font-weight:bold;">Project Directory</span> <span style="float:right; position:relative; top:-6px;"><input type="text" value="search"/></span>
    </div>-->
    <div>
      <div class='project_tabs'>
        <em class="active"></em>
        <span class="tab_1">All</span><span class="tab_2 active">Location</span><span class="tab_3">Topic</span><span class="tab_4">Rating</span>
        
      </div>
      <div class="project_tabs_bottom">
      <div class="tab_1 content">
        <div>All</div>
        
        
        
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_2.jpg" class="project-directroy-img"/></div>
          
          <div style="float:left" class="project-directory-content">
              Playing for Change<br/>
              Soweto,S.Africa<br/>
              Friends go around their town to speak out for change through music.
            
            
          </div>
          <div style="clear:both"></div>
          
        </div>
       <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_1.jpg" class="project-directroy-img"/></div>
          
            <div style="float:left" class="project-directory-content">
              Green Library<br/>
              Johannesbug,S.Africa<br/>
              Community project creating a sustainble green library.
            
            
            </div>
          <div style="clear:both"></div>
          
        </div>
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_3.jpg" class="project-directroy-img"/></div>
          
          <div style="float:left" class="project-directory-content">
              Woodworking for Homes<br/>
              The Garden Route, S. Africa<br/>
              Jery and Robyn shows you how they build<br/>
              new homes for the homeless victims of the <br/>
              Oklahoma tornado.
            
            
          </div>
          <div style="clear:both"></div>
          
        </div>
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_4.jpg"  class="project-directroy-img"/></div>
          
          <div style="float:left" class="project-directory-content">
              Filming for Fundraising<br/>
              Cope Town,S. Africa<br/>
              Students in Cope Town documents<br/>
              the lives of their community to fundraise for<br/>
              local support to build a new classroom.
            
            
          </div>
          <div style="clear:both"></div>
          
        </div>
        
      </div>
      <div class="tab_2 content">
      <div class="cha-location">
      	<div class="location-tab active"><span>location: South Aftica</span></div>
        <div class="location-content">
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_1.jpg" class="project-directroy-img"/></div>
          
            <div style="float:left" class="project-directory-content">
              Green Library<br/>
              Johannesbug,S.Africa<br/>
              Community project creating a sustainble green library.
            
            
            </div>
          <div style="clear:both"></div>
          
        </div>
        
        
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_2.jpg" class="project-directroy-img"/></div>
          
          <div style="float:left" class="project-directory-content">
              Playing for Change<br/>
              Soweto,S.Africa<br/>
              Friends go around their town to speak out for change through music.
            
            
          </div>
          <div style="clear:both"></div>
          
        </div>
       
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_3.jpg" class="project-directroy-img"/></div>
          
          <div style="float:left" class="project-directory-content">
              Woodworking for Homes<br/>
              The Garden Route, S. Africa<br/>
              Jery and Robyn shows you how they build<br/>
              new homes for the homeless victims of the <br/>
              Oklahoma tornado.
            
            
          </div>
          <div style="clear:both"></div>
          
        </div>
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_4.jpg"  class="project-directroy-img"/></div>
          
          <div style="float:left" class="project-directory-content">
              Filming for Fundraising<br/>
              Cope Town,S. Africa<br/>
              Students in Cope Town documents<br/>
              the lives of their community to fundraise for<br/>
              local support to build a new classroom.
            
            
          </div>
          <div style="clear:both"></div>
          
        </div>
        </div>
      </div>
        <div class="cha-location">
      	<div class="location-tab"><span>location: South Aftica</span></div>
        	<div class="location-content hide">
                    <div style="margin-bottom:10px;">
                      <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_1.jpg" class="project-directroy-img"/></div>
                      
                        <div style="float:left" class="project-directory-content">
                          Green Library<br/>
                          Johannesbug,S.Africa<br/>
                          Community project creating a sustainble green library.
                        
                        
                        </div>
                      <div style="clear:both"></div>
                      
                    </div>
        
        
                    <div style="margin-bottom:10px;">
                      <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_2.jpg" class="project-directroy-img"/></div>
                      
                      <div style="float:left" class="project-directory-content">
                          Playing for Change<br/>
                          Soweto,S.Africa<br/>
                          Friends go around their town to speak out for change through music.
                        
                        
                      </div>
                      <div style="clear:both"></div>
                      
                    </div>
           
                    <div style="margin-bottom:10px;">
                      <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_3.jpg" class="project-directroy-img"/></div>
                      
                      <div style="float:left" class="project-directory-content">
                          Woodworking for Homes<br/>
                          The Garden Route, S. Africa<br/>
                          Jery and Robyn shows you how they build<br/>
                          new homes for the homeless victims of the <br/>
                          Oklahoma tornado.
                        
                        
                      </div>
                      <div style="clear:both"></div>
                      
                    </div>
                    <div style="margin-bottom:10px;">
                      <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_4.jpg"  class="project-directroy-img"/></div>
                      
                      <div style="float:left" class="project-directory-content">
                          Filming for Fundraising<br/>
                          Cope Town,S. Africa<br/>
                          Students in Cope Town documents<br/>
                          the lives of their community to fundraise for<br/>
                          local support to build a new classroom.
                        
                        
                      </div>
                      <div style="clear:both"></div>
                      
                    </div>
                   </div>
      </div>
        
      </div>
      <div class="tab_3 content" >
        <div>Topic</div>
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_1.jpg" class="project-directroy-img"/></div>
          
            <div style="float:left" class="project-directory-content">
              Green Library<br/>
              Johannesbug,S.Africa<br/>
              Community project creating a sustainble green library.
            
            
            </div>
          <div style="clear:both"></div>
          
        </div>
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_3.jpg" class="project-directroy-img"/></div>
          
          <div style="float:left" class="project-directory-content">
              Woodworking for Homes<br/>
              The Garden Route, S. Africa<br/>
              Jery and Robyn shows you how they build<br/>
              new homes for the homeless victims of the <br/>
              Oklahoma tornado.
            
            
          </div>
          <div style="clear:both"></div>
          
        </div>
        
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_2.jpg" class="project-directroy-img"/></div>
          
          <div style="float:left" class="project-directory-content">
              Playing for Change<br/>
              Soweto,S.Africa<br/>
              Friends go around their town to speak out for change through music.
            
            
          </div>
          <div style="clear:both"></div>
          
        </div>
       
        
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_4.jpg"  class="project-directroy-img"/></div>
          
          <div style="float:left" class="project-directory-content">
              Filming for Fundraising<br/>
              Cope Town,S. Africa<br/>
              Students in Cope Town documents<br/>
              the lives of their community to fundraise for<br/>
              local support to build a new classroom.
            
            
          </div>
          <div style="clear:both"></div>
          
        </div>
        
      </div>
      <div class="tab_4 content" >
         <div>Rating List</div>
         <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_4.jpg"  class="project-directroy-img"/></div>
          
          <div style="float:left" class="project-directory-content">
              Filming for Fundraising<br/>
              Cope Town,S. Africa<br/>
              Students in Cope Town documents<br/>
              the lives of their community to fundraise for<br/>
              local support to build a new classroom.
            
            
          </div>
          <div style="clear:both"></div>
          
        </div>
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_1.jpg" class="project-directroy-img"/></div>
          
            <div style="float:left" class="project-directory-content">
              Green Library<br/>
              Johannesbug,S.Africa<br/>
              Community project creating a sustainble green library.
            
            
            </div>
          <div style="clear:both"></div>
          
        </div>
        
        
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_2.jpg" class="project-directroy-img"/></div>
          
          <div style="float:left" class="project-directory-content">
              Playing for Change<br/>
              Soweto,S.Africa<br/>
              Friends go around their town to speak out for change through music.
            
            
          </div>
          <div style="clear:both"></div>
          
        </div>
       
        <div style="margin-bottom:10px;">
          <div style="float:left"><img src="<?php print $base_url; ?>/images/mock_p_3.jpg" class="project-directroy-img"/></div>
          
          <div style="float:left" class="project-directory-content">
              Woodworking for Homes<br/>
              The Garden Route, S. Africa<br/>
              Jery and Robyn shows you how they build<br/>
              new homes for the homeless victims of the <br/>
              Oklahoma tornado.
            
            
          </div>
          <div style="clear:both"></div>
          
        </div>
        
        
      </div>
      </div>
      
    </div>
  </div>
  <div class="project_tags">
    
    <span class="taglevel0">tornado</span>
    <span class="taglevel1">web2.0</span>
    <span class="taglevel0">fte</span>
    <span class="taglevel3">chart</span>
    <span class="taglevel2">project</span>
    
    
    <span class="taglevel2">x</span>
    <span class="taglevel0">apatana</span>
    <span class="taglevel3">water</span>
    <span class="taglevel1">america</span>
    <span class="taglevel2">reg</span>
    
    
    <span class="taglevel1">student</span>
    <span class="taglevel0">fat</span>
    <span class="taglevel3">dam</span>
    <span class="taglevel2">drupal dev</span>
    <span class="taglevel2">smoke</span>
    
    
    <span class="taglevel0">drug</span>
    <span class="taglevel1">community</span>
    <span class="taglevel0">play</span>
    <span class="taglevel3">prism</span>
    <span class="taglevel2">sundry</span>
    <span class="taglevel0">tornado</span>
    <span class="taglevel1">web2.0</span>
    <span class="taglevel0">fte</span>
    <span class="taglevel3">chart</span>
    <span class="taglevel2">project</span>
    
    
    <span class="taglevel2">x</span>
    <span class="taglevel0">apatana</span>
    <span class="taglevel3">water</span>
    <span class="taglevel1">america</span>
    <span class="taglevel2">reg</span>
    
   
    <span class="taglevel2">smoke</span>
    
    
    <span class="taglevel0">drug</span>
    <span class="taglevel1">community</span>
    <span class="taglevel0">play</span>
    <span class="taglevel3">prism</span>
    <span class="taglevel2">sundry</span>
    <span class="taglevel0">tornado</span>
    <span class="taglevel1">web2.0</span>
    <span class="taglevel0">fte</span>
    <span class="taglevel3">chart</span>
    <span class="taglevel2">project</span>
    
    
    <span class="taglevel2">x</span>
    <span class="taglevel0">apatana</span>
    <span class="taglevel3">water</span>
    <span class="taglevel1">america</span>
    <span class="taglevel2">reg</span>
    
    
    <span class="taglevel1">student</span>
    <span class="taglevel0">fat</span>
    <span class="taglevel3">dam</span>
    <span class="taglevel2">drupal dev</span>
    <span class="taglevel2">smoke</span>
    
    
    <span class="taglevel0">drug</span>
    <span class="taglevel1">community</span>
    <span class="taglevel0">play</span>
    <span class="taglevel3">prism</span>
    <span class="taglevel2">sundry</span>
    
  </div>
  
  
</div>
  
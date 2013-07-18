<?php
?>

    <!-- /community -->
    
      <div class="community">
      	<h2>Community</h2>
        <div class="inner community-inner"><p>This is the sample date of the Community.</p></div>
        <div class="indicator"><span></span></div>
      </div>       
	
	
	<!-- /tool bar and stage selector -->
   
      <div class="toolbar-stage">
      	<div class="tool-bar">
      		<!-- {{{toolbar start-->
	      	<div class="toolbar-handler"></div>
	      	<div class="toolbar-box">
	      		<!--<div class="toolbar-item title">
	      			<h4>Toolbar</h4>
	      		</div>
	      		<div class="toolbar-item upload">
	      			<h4>Upload</h4>
	      		</div>
	      		<div class="toolbar-item add-an-idea">
	      			<h4>Add an Idea</h4>
	      		</div>
	      		<div class="toolbar-item murals">
	      			<h4>Murals</h4>
	      		</div>
	      		<div class="toolbar-item media">
	      			<h4 class="has-child">Media<em></em></h4>
	      			<ul>
	      				<li class="media-video">Video</li>
	      				<li class="media-image">Images</li>
	      				<li class="media-audio">Audio</li>
	      				<li class="media-docs">Docs</li>
	      			</ul>
	      		</div>
	      		<div class="toolbar-item social">
	      			<span class="social-twitter"></span>
	      			<span class="social-facebook"></span>
	      			<span class="social-gmail"></span>
	      		</div>
	      		<div class="toolbar-item tour-guides">
	      			<h4>Tour Guides</h4>
	      			<p>images here</p>
	      		</div>-->
	      	</div>
	      	<!-- }}} toolbar end -->
	      	
	      	<!-- {{{ Stage Selector start -->
	      	<div class="stage-selector">
	      		<div class="stage-selector-inner">
		      		<div class="stage-selector-handler"><em></em><span>Stage Selector</span></div>
		      		<div class="stage-box"></div>
		      	</div>
	      	</div>
	      	<!-- }}} Stage Selector end -->
	      </div>
        <!--<?php print render($page['tool_bar']); ?>-->
      </div> 
	
	
	<!-- /main content -->
      <div class="main-content">
        <?php print render($page['content']); ?>
      </div> 
	
	
	<!-- /sliding panes -->
      <div class="sliding-panes">
      	<div class="studio-handler pane-handler" data-aim="studio"></div>
      	<div class="chanllenge-handler pane-handler" data-aim="challenge"></div>
      	<div class="competitions-handler pane-handler"  data-aim="competitions"></div>
        <?php print render($page['sliding_panes']); ?>
      </div>
      <div class="pane" id="studio"></div>
      <div class="pane" id="challenge"></div>
      <div class="pane" id="competitions"></div>
	
	
	

  

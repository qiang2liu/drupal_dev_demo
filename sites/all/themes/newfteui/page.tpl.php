<?php
?>

    <!-- /community -->
    <?php if ($page['community']): ?>
      <div class="community">
        <?php print render($page['community']); ?>
        <div class="indicator"><span></span></div>
      </div>       
	<?php endif; ?>

	<!-- /tool bar -->
    <!--<?php if ($page['tool_bar']): ?>-->
      <div class="tool-bar">
      	<div class="toolbar-handler"></div>
      	<div class="toolbar-box">
      		<div class="toolbar-item title">
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
      		</div>
      	</div>
        <!--<?php print render($page['tool_bar']); ?>-->
      </div> 
	<!--<?php endif; ?>-->
	
	<!-- /main content -->
      <div class="main-content">
        <?php print render($page['content']); ?>
      </div> 
	
	
	<!-- /sliding panes -->
    <?php if ($page['sliding_panes']): ?>
      <div class="sliding-panes">
        <?php print render($page['sliding_panes']); ?>
      </div> 
	<?php endif; ?>
	
	

  

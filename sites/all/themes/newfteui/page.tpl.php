<?php
?>
  <?php print render($page['header']); ?>

<<<<<<< HEAD
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
        <?php if ($messages): ?>
          <div id="messages"><div class="section clearfix">
            <?php print $messages; ?>
          </div></div> <!-- /.section, /#messages -->
        <?php endif; ?>

        <?php if ($breadcrumb && 1 == 0): ?>
          <div id="breadcrumb"><?php  print $breadcrumb; ?></div>
        <?php endif; ?>

        <?php if ($tabs): ?>
          <div class="tabs">
            <?php print render($tabs); ?>
          </div>
        <?php endif; ?>

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

    <!-- / user profile-->
	  <div class="user-profile">
	  		<div class="user-box">
	  		  <?php if (user_is_logged_in()):?>
    			<h4><?php echo $user->name; ?></h4>
    			<?php if ($secondary_menu): ?>
          <nav id="secondary-menu" role="navigation">
            <?php print theme('links__system_secondary_menu', array(
              'links' => $secondary_menu,
              'attributes' => array(
                'class' => array('links', 'inline', 'clearfix'),
              ),
            )); ?>
          </nav>
          <?php endif; ?>
          <?php endif; ?>
    		</div>
    		<?php if (user_is_logged_in()):?>
	    	<div class="user-profile-inner">
	    	</div>
	    	<?php else: ?>
	    	<?php
	    	$login_div = '<div class="user-profile-inner-url">
	    	</div>';
	    	echo l($login_div, 'user/login',
          array(
            'html'=>TRUE,
            'attributes' => array(
              'style' => 'display: block;',
            )
          )
        );
	    	?>
	    	<?php endif;?>
	  </div>





=======
  <div id="wrapper">
    <div id="container" class="clearfix">

      <div id="header">
        <div id="logo-floater">
        <?php if ($logo || $site_title): ?>
          <?php if ($title): ?>
            <div id="branding"><strong><a href="<?php print $front_page ?>">
            <?php if ($logo): ?>
              <img src="<?php print $logo ?>" alt="<?php print $site_name_and_slogan ?>" title="<?php print $site_name_and_slogan ?>" id="logo" />
            <?php endif; ?>
            <?php print $site_html ?>
            </a></strong></div>
          <?php else: /* Use h1 when the content title is empty */ ?>
            <h1 id="branding"><a href="<?php print $front_page ?>">
            <?php if ($logo): ?>
              <img src="<?php print $logo ?>" alt="<?php print $site_name_and_slogan ?>" title="<?php print $site_name_and_slogan ?>" id="logo" />
            <?php endif; ?>
            <?php print $site_html ?>
            </a></h1>
        <?php endif; ?>
        <?php endif; ?>
        </div>

        <?php if ($primary_nav): print $primary_nav; endif; ?>
        <?php if ($secondary_nav): print $secondary_nav; endif; ?>
      </div> <!-- /#header -->

      <?php if ($page['sidebar_first']): ?>
        <div id="sidebar-first" class="sidebar">
          <?php print render($page['sidebar_first']); ?>
        </div>
      <?php endif; ?>

      <div id="center"><div id="squeeze"><div class="right-corner"><div class="left-corner">
          <?php print $breadcrumb; ?>
          <?php if ($page['highlighted']): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
          <a id="main-content"></a>
          <?php if ($tabs): ?><div id="tabs-wrapper" class="clearfix"><?php endif; ?>
          <?php print render($title_prefix); ?>
          <?php if ($title): ?>
            <h1<?php print $tabs ? ' class="with-tabs"' : '' ?>><?php print $title ?></h1>
          <?php endif; ?>
          <?php print render($title_suffix); ?>
          <?php if ($tabs): ?><?php print render($tabs); ?></div><?php endif; ?>
          <?php print render($tabs2); ?>
          <?php print $messages; ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
          <div class="clearfix">
            <?php print render($page['content']); ?>
          </div>
          <?php print $feed_icons ?>
          <?php print render($page['footer']); ?>
      </div></div></div></div> <!-- /.left-corner, /.right-corner, /#squeeze, /#center -->

      <?php if ($page['sidebar_second']): ?>
        <div id="sidebar-second" class="sidebar">
          <?php print render($page['sidebar_second']); ?>
        </div>
      <?php endif; ?>

    </div> <!-- /#container -->
  </div> <!-- /#wrapper -->
>>>>>>> 4ac43c7771bb49d5ebd31545c4b72cb260d6b54a

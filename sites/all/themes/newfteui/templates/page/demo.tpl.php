<?php
?>
  <?php print render($page['header']); ?>
  <div id="wrapper">
    <div id="container" class="clearfix">

      <div id="header">
        <div id="logo-floater">
        <?php if (isset($logo) || isset($site_title)): ?>
          <?php if ($title): ?>
            <div id="branding"><strong><a href="<?php print $front_page ?>">
            <?php if ($logo): ?>
              <img src="<?php print $logo ?>" alt="<?php print isset($site_name_and_slogan)?$site_name_and_slogan:''; ?>" title="<?php print isset($site_name_and_slogan)?$site_name_and_slogan:''; ?>" id="logo" />
            <?php endif; ?>
            <?php print isset($site_html)?$site_html:''; ?>
            </a></strong></div>
          <?php else: /* Use h1 when the content title is empty */ ?>
            <h1 id="branding"><a href="<?php print $front_page ?>">
            <?php if ($logo): ?>
              <img src="<?php print $logo ?>" alt="<?php print isset($site_name_and_slogan)?$site_name_and_slogan:''; ?>" title="<?php print isset($site_name_and_slogan)?$site_name_and_slogan:''; ?>" id="logo" />
            <?php endif; ?>
            <?php print isset($site_html)?$site_html:''; ?>
            </a></h1>
        <?php endif; ?>
        <?php endif; ?>
        </div>

        <?php if (isset($primary_nav)): print $primary_nav; endif; ?>
        <?php if (isset($secondary_nav)): print $secondary_nav; endif; ?>
      </div> <!-- /#header -->

      <?php if (isset($page['sidebar_first'])): ?>
        <div id="sidebar-first" class="sidebar">
          <?php print render($page['sidebar_first']); ?>
        </div>
      <?php endif; ?>

      <div id="center"><div id="squeeze"><div class="right-corner"><div class="left-corner">
          <?php print $breadcrumb; ?>
          <?php if (isset($page['highlighted'])): ?><div id="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
          <a id="main-content"></a>
          <?php echo theme('set_item', array('item' => $item));?>
          <?php if ($tabs): ?><div id="tabs-wrapper" class="clearfix"><?php endif; ?>
          <?php print render($title_prefix); ?>
          <?php if ($title): ?>
            <h1<?php print $tabs ? ' class="with-tabs"' : '' ?>><?php print $title ?></h1>
          <?php endif; ?>
          <?php print render($title_suffix); ?>
          <?php if ($tabs): ?><?php print render($tabs); ?></div><?php endif; ?>
          <?php print render($tabs2); ?>
          <?php //print $messages; ?>
          <?php print render($page['help']); ?>
          <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
          <div class="clearfix">
            <?php print render($page['content']); ?>
          </div>
          <?php print $feed_icons ?>
          <?php print render($page['footer']); ?>
      </div></div></div></div> <!-- /.left-corner, /.right-corner, /#squeeze, /#center -->

      <?php if (isset($page['sidebar_second'])): ?>
        <div id="sidebar-second" class="sidebar">
          <?php print render($page['sidebar_second']); ?>
        </div>
      <?php endif; ?>

    </div> <!-- /#container -->
  </div> <!-- /#wrapper -->
  <div id="topic-murals">
    <?php print render($page['topic_murals']); ?>
  </div>
<?php
?>

    <!-- /top menu -->
    <?php if ($page['top_menu']): ?>
      <div class="top-menu">
        <?php print render($page['top_menu']); ?>
      </div> 
	<?php endif; ?>
	
	<!-- /tool bar -->
    <?php if ($page['tool_bar']): ?>
      <div class="tool-bar">
        <?php print render($page['tool_bar']); ?>
      </div> 
	<?php endif; ?>
	
	<!-- /main content -->
    <?php if ($page['main_content']): ?>
      <div class="main-content">
        <?php print render($page['main_content']); ?>
      </div> 
	<?php endif; ?>
	
	<!-- /sliding panes -->
    <?php if ($page['sliding_panes']): ?>
      <div class="sliding-panes">
        <?php print render($page['sliding_panes']); ?>
      </div> 
	<?php endif; ?>
	
	<!-- /community -->
    <?php if ($page['community']): ?>
      <div class="community">
        <?php print render($page['community']); ?>
      </div> 
	<?php endif; ?>
	

  

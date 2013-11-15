<style>
html {
  background:#fff;
}
.breadcrumb,
#tabs-wrapper {
  display:none;
}
#wrapper {
  width: 100%;
  height: 100%;
}
.demo_cont {
  width: 815px;
  margin: 0 auto;
}
.set-image-content {
  margin: 0 auto;
  width: 800px;
}
</style>
<div class="compration-test" style="width:100%; background:#fff; text-align:center;">
   <img src = '<?php echo $base_url;?>/sites/all/themes/newfteui/images/header.png' />
   <div>
   <div class="demo_cont"><?php echo l('< Back', 'demo');?></div>
   <?php echo drupal_render(node_view($item, 'full'));?>
   </div>
</div>
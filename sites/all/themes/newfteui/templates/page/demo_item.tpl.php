<style>
.breadcrumb,
#tabs-wrapper {
  display:none;
}
#wrapper {
  width: 100%;
  height: 100%;
}
</style>
<div class="compration-test" style="width:100%; background:#fff; text-align:center;">
   <img src = '<?echo $base_url;?>/sites/all/themes/newfteui/images/header.png' />
   <?php echo l('< Back', 'demo');?>
   <?php echo drupal_render(node_view($item, 'full'));?>
</div>
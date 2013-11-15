<style>
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
</style>
<div class="compration-test" style="width:100%; background:#fff; text-align:center;">
   <img src = 'sites/all/themes/newfteui/images/header.png' />
   <div class="demo_cont"><?php echo theme('image_set_item_demo', array('item' => $item));?></div>
</div>
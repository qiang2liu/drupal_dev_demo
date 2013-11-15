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
  position:absolute;
  top:186px;
  left:77px;
  margin: 0 auto;
}
.demo_cont img{
	width:146px;
	height:119px;
}
.set-cover{
	display:none;
}
</style>
<div class="compration-test" style="background:#fff; text-align:center; width:823px; margin:0 auto; position: relative">
   <img src = 'sites/all/themes/newfteui/images/test-body.png' />
   <div class="demo_cont"><?php echo theme('image_set_item_demo', array('item' => $item));?></div>
</div>
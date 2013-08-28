jQuery(document).ready(function(){
  media_ajax_load_list();
  studio_media_list_ajax_load();
  //Drupal.behaviors.mediaListAjaxload();
});


/**
 * Note: Change it should sync to mediaListAjaxLoad.js
 */
function media_ajax_load_list() {

  jQuery('#my-media-list').load("?q=edgemarkers/media/get/list/ajax", function(data){
    
//    console.log(data);
   
  	jQuery('.toolbar-item').each(function(){
  		var self = jQuery(this);
  		
  		if(self.children().first().hasClass('has-child')){
  			self.find('h4>em').bind('click', function(){
  				if(!self.find('.item-list').hasClass('active')){
  					jQuery('.toolbar-item').find('.item-list').removeClass('active');
  					self.find('.item-list').addClass('active')
  				}
  			})
  		}
  	});

    jQuery('ul#media-list li a').each(function( index ) {
      var nid = jQuery(this).attr('id').substring(11);
      var title = jQuery(this).html();
      
      jQuery(this).bind('click', function(){
        showMediaOnDestination(nid, title);
        return false;
      });

    });
    
    
  });
}

function showMediaOnDestination(nid, title) {

  var ajaxUrl = '?q=edgemakers/media/info/ajax/' + nid;
    
  jQuery.ajax({
    url: ajaxUrl,
    type: "GET",
    success: function(data) {

      jQuery("#stage-set-view").html(data);
      jQuery("#set-view-region").show();
      jQuery("#back-to-dashboard").show();
      jQuery("#set-nav").hide();
      
      //Set title
      jQuery(".s-s-title h3").html(title);
      
      return false;

    },
    error :function(){
      jQuery("#stage-set-view").html("Load set data error.");
      jQuery("#set-view-region").show();
      jQuery("#back-to-dashboard").show();
      jQuery("#set-nav").hide();
      return false;
    }
  });
  
  return false;
  
}

function studio_media_list_ajax_load(pager) {
  
  if (pager == null) {
    pager = 0;
  }
  
  jQuery.ajax({
    url: "?q=edgemarkers/studio/media/get/list/ajax/" + pager,
    dataType: 'html',
    type : 'GET',
    success : function(data){
      if (data.length === 0) {
        alert("not enough content to turning page");
      }
      else {
//        alert(data.length);
        jQuery("#studio-media-list").html(data);
        
        jQuery('ul#studio-media-list li a').each(function( index ) {
          var nid = jQuery(this).attr('nid');
          var title = jQuery(this).html();

          jQuery(this).unbind("click");
          jQuery(this).bind("click", function(){
            showMediaOnDestination(nid, title);
            return false;
          });
        });
        
        reBindLeftRight(pager);
        
        
      }
      
    }
    
  });
  
  /*jQuery("#studio-media-list").load("?q=edgemarkers/studio/media/get/list/ajax/" + pager, function(data){
    
    //console.log(data);
    console.log(pager);
    if (data.length !== 0) {
      
      jQuery('ul#studio-media-list li a').each(function( index ) {
        var nid = jQuery(this).attr('nid');
        var title = jQuery(this).html();
        
        jQuery(this).unbind("click");
        jQuery(this).bind("click", function(){
          showMediaOnDestination(nid, title);
          return false;
        });
      });
      
      if (pager == 0) {
        var prevPager = 0;
        var nextPager = 1;
      }
      else {
        var prevPager = parseInt(pager) - 1;
        var nextPager = parseInt(pager) + 1;
      }
      
      jQuery("#studio-media-list-pane .scroll-wrapper .arrow-left").attr("pager", prevPager);
      jQuery("#studio-media-list-pane .scroll-wrapper .arrow-right").attr("pager", nextPager);
      
      jQuery("#studio-media-list-pane .arrow-left").unbind("click");
      jQuery("#studio-media-list-pane .arrow-left").bind("click", function(){
        var pager = jQuery(this).attr("pager");
        studio_media_list_ajax_load(pager);
        return false;
      });
      
      jQuery("#studio-media-list-pane .arrow-right").unbind("click");
      jQuery("#studio-media-list-pane .arrow-right").bind("click", function(){
        var pager = jQuery(this).attr("pager");
        studio_media_list_ajax_load(pager);
        return false;
      });

    }
  });
  */
 
  
}

function reBindLeftRight(pager) {
  
  if (pager == 0) {
    var prevPager = 0;
    var nextPager = 1;
  }
  else {
    var prevPager = parseInt(pager) - 1;
    var nextPager = parseInt(pager) + 1;
  }
  
  jQuery("#studio-media-list-pane .scroll-wrapper .arrow-left").attr("pager", prevPager);
  jQuery("#studio-media-list-pane .scroll-wrapper .arrow-right").attr("pager", nextPager);
  
  jQuery("#studio-media-list-pane .arrow-left").unbind("click");
  jQuery("#studio-media-list-pane .arrow-left").bind("click", function(){
    var pager = jQuery(this).attr("pager");
    studio_media_list_ajax_load(pager);
    return false;
  });
  
  jQuery("#studio-media-list-pane .arrow-right").unbind("click");
  jQuery("#studio-media-list-pane .arrow-right").bind("click", function(){
    var pager = jQuery(this).attr("pager");
    studio_media_list_ajax_load(pager);
    return false;
  });
  
}
/**
 * @file 
 * edgemakers module js file.
 */

jQuery(document).ready(function(){
  media_ajax_load_list();
  studio_media_list_ajax_load();
  gallery_media_list_ajax_load('media', 0);
  gallery_media_list_ajax_load('video', 0);
  gallery_media_list_ajax_load('image', 0);
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
        //alert("not enough content to turning page");
      }
      else {
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
        studioBindLeftRight(pager);
      }
    }
  });
  
}

function gallery_media_list_ajax_load(type, pager) {
  
  if (type == null) {
    return false;
  }

  if (pager == null) {
    pager = 0;
  }
  
  var reloadElement = "gallery-" + type +"-list";
  
//  switch(type) {
//    case "media":
//      var reloadElement = "gallery-media-list";
//      break;
//    case "video":
//      var reloadElement = "gallery-video-list";
//      break;
//    case "image":
//      var reloadElement = "gallery-image-list";
//      break;
//  }
  
  var keyword = '';
  if(jQuery("#gallery-keyword").length)
    keyword = jQuery("#gallery-keyword").val();
  
  jQuery.ajax({
    url: "?q=edgemarkers/gallery/media/get/list/ajax/" + type + "/" + pager + "/" + keyword,
    dataType: 'html',
    type : 'GET',
    success : function(data){
      if (data.length === 0) {
        if (keyword.length === 0) {
          console.log("data is empty");
        }
        else {
          jQuery("#" + reloadElement).html(type + " search result is empty, replace other keyword to search or clean keyword.");
//          alert("Search result is empty");
        }
      }
      else {
        jQuery("#" + reloadElement).html(data);
        
        jQuery("ul#" + reloadElement + " li a").each(function( index ) {
          var nid = jQuery(this).attr('nid');
          var title = jQuery(this).html();
          jQuery(this).unbind("click");
          jQuery(this).bind("click", function(){
            showMediaOnDestination(nid, title);
            return false;
          });
        });
        galleryBindLeftRight(type, pager);
      }
    }
  });
  
}

function studioBindLeftRight(pager) {
  
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

function galleryBindLeftRight(type, pager) {
  if (pager == 0) {
    var prevPager = 0;
    var nextPager = 1;
  }
  else {
    var prevPager = parseInt(pager) - 1;
    var nextPager = parseInt(pager) + 1;
  }
  
  var arrowElement;
  arrowElement = 'gallery-' + type + '-list-pane';
//  alert("arrowElement load data.");
    
  jQuery("#" + arrowElement + " .scroll-wrapper .arrow-left").attr("pager", prevPager);
  jQuery("#" + arrowElement + " .scroll-wrapper .arrow-right").attr("pager", nextPager);
  
  jQuery("#" + arrowElement + " .arrow-left").unbind("click");
  jQuery("#" + arrowElement + " .arrow-left").bind("click", function(){
    var pager = jQuery(this).attr("pager");
    gallery_media_list_ajax_load(type, pager);
    return false;
  });
  
  jQuery("#" + arrowElement + " .arrow-right").unbind("click");
  jQuery("#" + arrowElement + " .arrow-right").bind("click", function(){
    var pager = jQuery(this).attr("pager");
    gallery_media_list_ajax_load(type, pager);
    return false;
  });
}

function _refreshStudioGallery() {
  // Refresh media list on toolbar.
  media_ajax_load_list();
  
  // Refresh media on studio.
  var studio_media_next_page = jQuery("#studio-media-list-pane .scroll-wrapper .arrow-right").attr("pager");
  var studio_media_current_page = parseInt(studio_media_next_page) - 1;
  console.log("Studio media current page: " + studio_media_current_page);
  studio_media_list_ajax_load(studio_media_current_page);
  

  // Refresh media on gallery.
  var gallery_media_next_page = jQuery("#gallery-media-list-pane .scroll-wrapper .arrow-right").attr("pager");
  var gallery_media_current_page = parseInt(gallery_media_next_page) - 1;
  console.log("Studio media current page: " + gallery_media_current_page);
  gallery_media_list_ajax_load('media', gallery_media_current_page);
  
}
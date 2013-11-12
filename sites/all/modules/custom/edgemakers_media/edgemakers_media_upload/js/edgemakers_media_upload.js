/**
 * @file 
 * edgemakers module js file.
 */

jQuery(document).ready(function(){
  var ulWidth;
  var num = 0;
  function getNum(){
  	ulWidth = jQuery(window).width() - 100;
	
	if(ulWidth>=0){
		num = Math.floor(ulWidth/164);
	}
	
	return num;
  }
  getNum();
  jQuery(window).bind('resize',function(){
  	getNum();
  });
  if (jQuery("#my-media-list").length !== 0) {
    media_ajax_load_list();
  }

  if (jQuery("#studio-panes-mural-list").length !== 0) {
    studio_media_list_ajax_load();
  }
  
  if (jQuery("#gallery-panes-mural-list").length !== 0) {
    gallery_media_list_ajax_load('media', 0, num);
  }
  //gallery_media_list_ajax_load('video', 0);
  //gallery_media_list_ajax_load('image', 0);
  var studioMediaListEmpty = 0;
var galleryMediaListEmpty = 0;

/**
 * Note: Change it should sync to mediaListAjaxLoad.js
 */

//added by Guo Tao
function bindArrowfuc(){
	//jQuery('.scroll-wrapper .arrow-left, .scroll-wrapper .arrow-right').css('top',(jQuery(this).parent().height()-42)/2 + 'px');
}


function media_ajax_load_list() {

  var opened = jQuery('#my-media-list .item-list').hasClass('active');
  jQuery('#my-media-list').load("?q=edgemarkers/media/get/list/ajax", function(data){
    
    console.log(opened);
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
    if(opened) jQuery('#my-media-list h4.has-child em')[0].click();

    jQuery('ul#media-list li a').each(function( index ) {
      var nid = jQuery(this).attr('id').substring(11);
      var title = jQuery(this).html();
      
      jQuery(this).bind('click', function(){
        showMediaOnDestination(nid, title, 'toolbar');
        return false;
      });

    });
    bindArrowfuc();
    
  });
}

function showMediaOnDestination(nid, title, position) {

  var ajaxUrl = '?q=edgemakers/media/info/ajax/' + nid + '/' + position;
    
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
      bindArrowfuc();
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
  
  var studioMuralEmptyMsg = '<li style="width:100%"><p class="empty-data">There is no media available for you.</p></li>';
  var studioMuralMoreEmptyMsg = '<li style="width:100%"><p class="empty-data">There is no more media available for you.</p></li>';
  
  if (pager == null) {
    pager = 0;
  }
  
  jQuery.ajax({
    url: "?q=edgemarkers/studio/media/get/list/ajax/" + pager + "/" + num,
    dataType: 'html',
    type : 'GET',
    success : function(data){

      if (data.length === 0) {
        if (pager <= 0) {
          jQuery("#studio-media-list").html(studioMuralEmptyMsg);
        }
        else{
          jQuery("#studio-media-list").html(studioMuralMoreEmptyMsg);
          if (studioMediaListEmpty == 0) {
            studioBindLeftRight(pager);
          }
          setArrowTop();
          bindArrowfuc();
          studioMediaListEmpty = 1;
          //console.log("studio_media_list_ajax_load data is empty.");
        }
     
//        alert("not enough content to turning page");
      }
      else {
      	
        jQuery("#studio-media-list").html(data);
        setArrowTop();
        jQuery('ul#studio-media-list li a').each(function( index ) {
          var nid = jQuery(this).attr('nid');
          var title = jQuery(this).html();
          jQuery(this).unbind("click");
          jQuery(this).bind("click", function(){
            showMediaOnDestination(nid, title, 'studio');
            return false;
          });
        });
        studioBindLeftRight(pager);
        bindArrowfuc();
      }
    }
  });
  
}

function gallery_media_list_ajax_load(type, pager, num) {
   
  if (type == null) {
    return false;
  }

  if (pager == null) {
    pager = 0;
  }
  
  var reloadElement = "gallery-" + type +"-list";
  var galleryMuralEmptyMsg = '<li style="width:100%"><p class="empty-data">There is no ' + type + ' available</p></li>';
  var galleryMediaMoreEmptyMsg = '<li style="width:100%"><p class="empty-data">There is no ' + type + ' available</p></li>';
  
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
  console.log('media:   ');
  console.log(num);
  jQuery.ajax({
  	
    url: "?q=edgemarkers/gallery/media/get/list/ajax/" + type + "/" + pager + "/" + keyword + "/" + num,
    dataType: 'html',
    type : 'GET',
    success : function(data){
    	
    	
      if (data.length === 0) {
      	
        if (keyword.length === 0) {
          console.log("gallery media data is empty");

          if (pager <= 0) {
            jQuery("#" + reloadElement).html(galleryMuralEmptyMsg);
          }
          else {
            jQuery("#" + reloadElement).html(galleryMediaMoreEmptyMsg);
          }
          
          setArrowTop();
          
          if (galleryMediaListEmpty === 0) {
            galleryBindLeftRight(type, pager);
          }
          galleryMediaListEmpty = 1;

        }
        else {
          jQuery("#" + reloadElement).html(type + " search result is empty, replace other keyword to search or clean keyword.");
		setArrowTop();
			//          alert("Search result is empty");
        }
        
      }
      else {
      
        jQuery("#" + reloadElement).html(data);
        setArrowTop();
        jQuery("ul#" + reloadElement + " li a").each(function( index ) {
          var nid = jQuery(this).attr('nid');
          var title = jQuery(this).html();
          jQuery(this).unbind("click");
          jQuery(this).bind("click", function(){
            showMediaOnDestination(nid, title, 'gallery');
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
    gallery_media_list_ajax_load(type, pager, num);
    return false;
  });
  
  jQuery("#" + arrowElement + " .arrow-right").unbind("click");
  jQuery("#" + arrowElement + " .arrow-right").bind("click", function(){
    var pager = jQuery(this).attr("pager");
    gallery_media_list_ajax_load(type, pager, num);
    return false;
  });
}

function _refreshStudioGallery() {  
  // Refresh media on studio.
  var studio_media_next_page = jQuery("#studio-media-list-pane .scroll-wrapper .arrow-right").attr("pager");
  var studio_media_current_page = parseInt(studio_media_next_page) - 1;
  console.log("Studio media current page: " + studio_media_current_page);
  studio_media_list_ajax_load(studio_media_current_page);
  

  // Refresh media on gallery.
  var gallery_media_next_page = jQuery("#gallery-media-list-pane .scroll-wrapper .arrow-right").attr("pager");
  var gallery_media_current_page = parseInt(gallery_media_next_page) - 1;

  console.log("Studio media current page: " + gallery_media_current_page);
  gallery_media_list_ajax_load('media', gallery_media_current_page, num);

  
}
Drupal.behaviors.autoUpload = {
  attach: function(context, settings) {
    jQuery('.form-item input.form-submit[value=Upload]').hide();
    jQuery('.form-item input.form-file').change(function() {
      var parent = jQuery(this).closest('.form-item');

      //setTimeout to allow for validation
      //would prefer an event, but there isn't one
      setTimeout(function() {
        if(!jQuery('.error', parent).length) {
          jQuery('input.form-submit[value=Upload]', parent).mousedown();
        }
      }, 100);
    });
  }
};


function setStudioMediaNav(type, id, navOp) {
  
  console.log("Type= " + type +"|id = " + id + "|navOp=" +navOp);

  jQuery("#media-studio-nav ." + navOp).unbind("click");

  jQuery("#media-studio-nav ." + navOp).bind("click", function(){
    var keyword = jQuery("#gallery-keyword").val();
    jQuery.ajax({
      url: "?q=/edgemakers/media/studio/get/nav/ajax/" + type + "/" + id + "/" + navOp + "/" + keyword,
      dataType: 'json',
      type : "GET",
      success : function(data){
        console.log(data);

        if (data) {

          // Clean.
          var stageNotes = jQuery("#stage-notes").html();
          teacherNotes(stageNotes);
          jQuery(".s-s-title h3").empty();
          
          // Show media.
          showMediaOnDestination(data[0].nid, data[0].title, type);
          
          // Reset nav.
          setStudioMediaNav(type, data[0].nid, "prev");
          setStudioMediaNav(type, data[0].nid, "next");
        }
        else {
          //alert("Not media");
          console.log("Not media");
        }
      }
    });
  });
  
}

});




jQuery(document).ready(function(){
  
  jQuery(".toolbar-item.add-an-idea").show();
  jQuery(".create-mural").show();
  jQuery(".create-mural").bind("click", function(){

    //bigFrame.attr('src', source);
    if (jQuery("#mural-region").length !== 0) {
      var source = jQuery(this).attr("href");
      jQuery("#mural-back-to-dashboard").show();
      showMuralDialog(source);
    }
    //alert("Hook create mural link. and should set iframe src to " + source);
    return false;
  });
  
  mural_ajax_load_list();
  
  studio_mural_ajax_load_list();
  
  gallery_mural_ajax_load_list();
  
  jQuery("#gallery-search").bind("click", function(){search_gallery();});
  
});

function closeFromIframe()
{
  mural_ajax_load_list();
//  jQuery("#mural-iframe").empty();
  jQuery("#mural-back-to-dashboard").hide();
  jQuery('#mural-region').dialog('close');
  jQuery('body').css({
	'height': 'auto',
	'overflow-y': 'auto'
  });
  return false;
}

function setMuralWidth(){
  jQuery('body').css({
    'height': jQuery(window).height()+ 'px',
    'overflow': 'hidden'
  });
  jQuery("#mural-iframe").attr("width", jQuery(window).width() + 'px');
  jQuery("#mural-iframe").attr("height", jQuery(window).height()-56 + 'px');
  jQuery("#mural-region").css("height", jQuery(window).height() + 'px');
  
}

function showMuralDialog(source) {
  
  var seconds = new Date().getTime() / 1000;
//  var urlHash = jQuery.md5(seconds);
  
  source = source + "#" + seconds;
  
  jQuery("#mural-set-nav").hide();
  
  jQuery("#mural-back-to-dashboard").bind("click", function(){
    closeFromIframe();
  });
  
  var iframeHtml = "<iframe id=\"mural-iframe\" width=\"100%\" height=\"90%\" src=\"?q=" + source + "\"></iframe>";
  
  //jQuery("#mural-region").html("Mural display here by iframe " + source);
  jQuery("#mural-iframe").attr("src", source);

  setMuralWidth();
  
  jQuery(window).resize(function(){
  	setMuralWidth();
  })
  
  jQuery( "#mural-region" ).dialog({
    resizable: false,
    modal: true,
    position: ["left", "top"],
    width: "100%",
    height: jQuery(window).height() + 56,
    zIndex: 1000,
    /*buttons: {
      Ok: function() {
        jQuery(this).dialog( "close" );
      }
    }*/
  });
  
  jQuery('.ui-dialog-titlebar').attr("style", "display: none;");
  jQuery('.ui-dialog.ui-widget.ui-widget-content').css("border-radius", "0px");
  jQuery('.ui-dialog.ui-widget.ui-widget-content').css("padding", "0px");
  jQuery('.ui-dialog.ui-widget.ui-widget-content').css("margin", "0px");
  
  jQuery('.ui-dialog.ui-widget.ui-widget-content').css("left", "1px");

}

function mural_ajax_load_list() {

  jQuery('#my-mural-list').load("?q=mural/get/list/ajax", function(){

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

    jQuery('ul#mural-list li a').each(function( index ) {
      jQuery(this).bind('click', function(){
        if (jQuery("#mural-region").length !== 0) {
          var source = jQuery(this).attr("href");
          jQuery("#mural-back-to-dashboard").show();
          showMuralDialog(source);
        }
        return false;
      });
    });
    
    
  });
}

// Studio/Gallery mural list json
//   @type my[idea], share[with me], ideas
function studio_mural_ajax_page_load(type, pager) {
  
  if (pager == null) {
    pager = 0;
  }
  
  var replaceElement;
  
  switch (type) {
    case "my":
      replaceElement = "studio-mural-list";
      break;
    case "share":
      replaceElement = "studio-mural-share-with-me-list";
      break;
    default:
      type = 'no';
      break;
  }
  
  jQuery.ajax({
    url: "mural/studio/get/list/ajax/" + type + "/" + pager,
    dataType: 'html',
    type : 'GET',
    success : function(data){
      if (data.length === 0) {
        console.log("data is empty");
      }
      else {
//        alert(data.length);
        jQuery("#" + replaceElement).html(data);
        
        studio_mural_item_bind_link();
        setLeftRightPager(type, pager);

      }
      
    }
    
  });

  /*jQuery.ajax({
    url: "?q=mural/studio/list/page/ajax/" + type + "/" +pager,
    success: (function(data){
      console.log(data);
      studio_mural_item_bind_link();
      //@TODO GT change mural list.
    }),
  });*/
  
}

function setLeftRightPager(type, pager) {
  if (pager == 0) {
    var prevPager = 0;
    var nextPager = 1;
  }
  else {
    var prevPager = parseInt(pager) - 1;
    var nextPager = parseInt(pager) + 1;
  }

  switch (type) {
    case "my":
      jQuery("#studio-panes-mural-list #studio-my-idea .scroll-wrapper .arrow-left").attr("pager", prevPager);
      jQuery("#studio-panes-mural-list #studio-my-idea .scroll-wrapper .arrow-right").attr("pager", nextPager);
      break;
    case "share":
      jQuery("#studio-panes-mural-list #studio-share-with-me .scroll-wrapper .arrow-left").attr("pager", prevPager);
      jQuery("#studio-panes-mural-list #studio-share-with-me .scroll-wrapper .arrow-right").attr("pager", nextPager);
      break;
    case "gallery":
      jQuery("#gallery-ideas .arrow-left").attr("pager", prevPager);
      jQuery("#gallery-ideas .arrow-right").attr("pager", nextPager);
      break;
  }
}

function studio_mural_item_bind_link() {
  
  // View mural link bind click.
  jQuery('ul li a.studio-mural-list-item-link').each(function( index ) {
    jQuery(this).unbind('click');
    jQuery(this).bind('click', function(){
      if (jQuery("#mural-region").length !== 0) {
        var source = jQuery(this).attr("href");
        jQuery("#mural-back-to-dashboard").show();
        showMuralDialog(source);
      }
      return false;
    });
  });
    
  // Mural setting link bind click.
  jQuery('ul li a.studio-mural-settings').each(function( index ) {
    jQuery(this).unbind("click");
    jQuery(this).bind('click', function(){
      var nid = jQuery(this).attr("nid");
      mural_setting(nid);
      return false;
    });
  });
  
}

function studio_mural_ajax_load_list() {

  jQuery("#studio-mural-list").load("?q=mural/studio/get/list/ajax/my/0", function(){
    
    studio_mural_item_bind_link();
    
    jQuery("#studio-my-idea .arrow-left").unbind("click");
    jQuery("#studio-my-idea .arrow-left").bind("click", function(){
      var pager = jQuery(this).attr("pager");
//      alert("Prev page: " + pager);
      studio_mural_ajax_page_load('my', pager);
      return false;
    });
    
    jQuery("#studio-my-idea .arrow-right").unbind("click");
    jQuery("#studio-my-idea .arrow-right").bind("click", function(){
      var pager = jQuery(this).attr("pager");
//      alert("Next page: " + pager);
      studio_mural_ajax_page_load('my', pager);
      return false;
    });
          
  });
  
  jQuery("#studio-mural-share-with-me-list").load("?q=mural/studio/get/list/ajax/share/0", function(){
    
    studio_mural_item_bind_link();
    
    jQuery("#studio-share-with-me .arrow-left").bind("click", function(){
      var pager = jQuery(this).attr("pager");
//      alert("Prev page: " + pager);
      studio_mural_ajax_page_load('share', pager);
      return false;
    });
    
    jQuery("#studio-share-with-me .arrow-right").bind("click", function(){
      var pager = jQuery(this).attr("pager");
//      alert("Next page: " + pager);
      studio_mural_ajax_page_load('share', pager);
      return false;
    });
          
  });
  
}

function gallery_mural_ajax_load_list(pager) {
  
  var keyword = jQuery("#gallery-keyword").val();
  //var sortby = jQuery("#gallery-sort-by").val();
  
  if (pager == null) {
    pager = 0;
  }
  
  jQuery.ajax({
    url: "?q=mural/studio/list/page/ajax/gallery/" + pager + "/" + keyword,
    dataType: 'html',
    type : 'GET',
    success : function(data){
      if (data.length === 0) {
        console.log("data is empty");
      }
      else {
        jQuery("#gallery-mural-list").html(data);
        studio_mural_item_bind_link();
        setLeftRightPager('gallery', pager);
      }
    }
  });
  
  // Bind left/right arrow operation.
  jQuery("#gallery-ideas .arrow-left").unbind("click");
  jQuery("#gallery-ideas .arrow-left").bind("click", function(){
    var pager = jQuery(this).attr("pager");
    gallery_mural_ajax_load_list(pager);
    return false;
  });
  
  jQuery("#gallery-ideas .arrow-right").unbind("click");
  jQuery("#gallery-ideas .arrow-right").bind("click", function(){
    var pager = jQuery(this).attr("pager");
    gallery_mural_ajax_load_list(pager);
    return false;
  });
  // End bind.
  
}

// @TODO
function mural_setting(nid) {
  alert("Mural " + nid + " setting popup change to dialog!?");
}

function search_gallery() {
  var mural_list_refresh = gallery_mural_ajax_load_list();
  // @TODO on media upload module.
//  var gallery_video_list_refresh = gallery_video_ajax_load_list();
//  var gallery_image_list_refresh = gallery_image_ajax_load_list();
}
var nofresh = 0;
var studioMyMuralListEmpty = 0;
var studioShareMuralListEmpty = 0;
var galleryMuralListEmpty = 0;
var ulWidth;
var num = [];
jQuery(document).ready(function(){
 
  function getNum(){
  	ulWidth = jQuery(window).width() - 100;
	console.log(ulWidth);
	if(ulWidth>=0){
		num[0] = Math.floor(ulWidth/132);
		num[1] = Math.floor(ulWidth/164);
	}
	console.log(num);
	return num;
  }
  getNum();
  jQuery(window).bind('resize',function(){
  	getNum();
  });
  
  
  jQuery('.scroll-wrapper ul');
  jQuery(".toolbar-item.add-an-idea").show();
  jQuery(".create-mural").show();
  jQuery(".create-mural").bind("click", function(){

    if (jQuery("#mural-region").length !== 0) {
      var source = jQuery(this).attr("href");
      jQuery("#mural-back-to-dashboard").show();
      showMuralDialog(source);
      jQuery("#mural-studio-nav").hide();
      jQuery("#mural-iframe").attr("height", jQuery(window).height() + 56 + 'px');
    }

    return false;
  });
  
  
  if (jQuery("#my-mural-list").length !== 0) {
    mural_ajax_load_list();
  }
  
  if (jQuery("#studio-panes-mural-list").length !== 0) {
    studio_mural_ajax_load_list();
  }
  
  if (jQuery("#gallery-panes-mural-list").length !== 0) {
    gallery_mural_ajax_load_list();
    jQuery("#gallery-search").bind("click", function(){search_gallery();});
    
    jQuery("#gallery-keyword").keyup(function(event){
      if(event.keyCode == 13){
        search_gallery();
      }
    });
  }
  
  openDefaultMural();
  
});

function openDefaultMural() {
  var url = document.URL;
  var muralUrl = document.URL.split("#")[1];

  if (typeof(muralUrl) !== "undefined") {

    if (muralUrl.substring(0, 6) == "mural/") {
      jQuery("#mural-back-to-dashboard").show();
      showMuralDialog(muralUrl);
      jQuery("#mural-title").focus();
    }

  }
}

function closeFromIframe()
{
  jQuery("#mural-back-to-dashboard").hide();
  jQuery("#mural-iframe").attr("src", "");
  jQuery("#mural-region").dialog("close");
  jQuery("body").css({
    "height": "auto"
  });
  jQuery("body").removeClass("no-scroll-bar");
  
  // Refresh murals list on toolbar.
  mural_ajax_load_list();
  
  // Refresh murals list on studio/gallery.
  _refreshStudioGalleryMural();
  
  if (nofresh == 1) {
    console.log("closeFromIframe: nofresh = " + nofresh);

    // Reload google map.
    jQuery("#iframe-topic-gmap").attr("src", "?q=edgemakers/topic/gmap");
  }
}

function setMuralWidth(){
	jQuery("body").addClass("no-scroll-bar");
  jQuery("body").css({
    "height": jQuery(window).height()+ "px"
  });
  
  jQuery("#mural-iframe").attr("width", jQuery(window).width() + "px");
  if(jQuery("#mural-region").attr("data-user") === "1"){
  	jQuery("#mural-iframe").attr("height", jQuery(window).height() + 85 + "px");
  	jQuery("#mural-back-to-dashboard").css("top","34px");
  }else{
  	 jQuery("#mural-iframe").attr("height", jQuery(window).height() + "px");
  }
  jQuery("#mural-region").css("height", jQuery(window).height() + "px");
  
}

function _showMuralClose() {
  jQuery("#mural-back-to-dashboard").show();
  jQuery("#mural-back-to-dashboard").unbind("click");
  jQuery("#mural-back-to-dashboard").bind("click", function(){
    closeFromIframe();
  });
}

function showMuralNav(type) {
  
  jQuery("#mural-iframe").attr("height", jQuery(window).height() - 56 + 'px');
  jQuery("#mural-studio-nav").show();
  jQuery("#mural-display-type").attr("value", type);
    
}

function setStudioMuralNav(type, id, navOp) {
  
  jQuery("#mural-studio-nav ." + navOp).unbind("click");
  jQuery("#mural-studio-nav ." + navOp).bind("click", function(){

    var keyword = jQuery("#gallery-keyword").val();
    
    jQuery.ajax({
      url: "?q=/mural/studio/get/nav/ajax/" + type + "/" + id + "/" + navOp + "/" + keyword,
      dataType: 'json',
      type : "GET",
      success : function(data){
        console.log(data);

        if (data) {
//          alert(data[0].nid);
          jQuery("#mural-studio-nav .prev").attr("id", data[0].nid);
          closeFromIframe();
          showMuralDialog("mural/" + data[0].nid);
          showMuralNav(type);
          setStudioMuralNav(type, data[0].nid, "prev");
          setStudioMuralNav(type, data[0].nid, "next");
        }
        else {
          //alert("Not mural");
          console.log("Not mural");
        }
      }
    });
  });
  
}

function showMuralDialog(source) {
  
  nofresh = 0;
  
  var seconds = new Date().getTime() / 1000;
  source = source + "#" + seconds;

  jQuery("#mural-set-nav").hide();
  _showMuralClose();
  
  var iframeHtml = "<iframe id=\"mural-iframe\" width=\"100%\" height=\"90%\" src=\"?q=" + source + "\"></iframe>";
  
  jQuery("#mural-iframe").attr("src", source);
    
  jQuery( "#mural-region" ).dialog({
    resizable: false,
    modal: true,
    position: ["left", "top"],
    width: "100%",
    height: jQuery(window).height(),
    zIndex: 1000,
    /*buttons: {
      Ok: function() {
        jQuery(this).dialog( "close" );
      }
    }*/
  });
  
  setMuralWidth();
  
  jQuery(".ui-dialog-titlebar").attr("style", "display: none;");
  jQuery(".ui-dialog.ui-widget.ui-widget-content").css("border-radius", "0px");
  jQuery(".ui-dialog.ui-widget.ui-widget-content").css("padding", "0px");
  jQuery(".ui-dialog.ui-widget.ui-widget-content").css("margin", "0px");
  
  jQuery(".ui-dialog.ui-widget.ui-widget-content").css("left", "1px");
  jQuery(".ui-dialog.ui-widget.ui-widget-content").css("top", jQuery(window).scrollTop() + "px");
  
  showMuralNav();

}

function mural_ajax_load_list() {

  jQuery("#my-mural-list").load("?q=mural/get/list/ajax", function(){

    jQuery(".toolbar-item").each(function(){
      var self = jQuery(this);
      
      if(self.children().first().hasClass("has-child")){
        self.find("h4>em").bind("click", function(){
          if(!self.find(".item-list").hasClass("active")){
            jQuery(".toolbar-item").find(".item-list").removeClass("active");
            self.find(".item-list").addClass("active")
          }
        })
      }
    });
  
    jQuery("ul#mural-list li a").each(function( index ) {
      jQuery(this).bind("click", function(){
        if (jQuery("#mural-region").length !== 0) {
          var source = jQuery(this).attr("href");
          jQuery("#mural-back-to-dashboard").show();
          showMuralDialog(source);
          jQuery("#mural-studio-nav").hide();
          jQuery("#mural-iframe").attr("height", jQuery(window).height() + 56 + 'px');
        }
        return false;
      });
    });
    
  });
}

// Studio/Gallery mural list json
//   @type my[idea], share[with me], ideas
function studio_mural_ajax_page_load(type, pager, num) {
  
  var EmptyMsg;
  
  if (pager == null) {
    pager = 0;
  }
  
  if (isNaN(pager)) {
    pager = 0;
  }
  
  var replaceElement;
  
  switch (type) {
    case "my":
      EmptyMsg = "<p class=\"empty-data\">There is no more mural available for you.</p>";
      replaceElement = "studio-mural-list";
      break;
    case "share":
      EmptyMsg = "<p class=\"empty-data\">There are no more ideas shared with you.</p>";
      replaceElement = "studio-mural-share-with-me-list";
      break;
    default:
      type = "no";
      break;
  }
  
  jQuery.ajax({
    url: "?q=/mural/studio/get/list/ajax/" + type + "/" + pager + '/' + num[0],
    dataType: "html",
    type : "GET",
    success : function(data){
//      console.log(studioMyMuralListEmpty + "|" + studioShareMuralListEmpty);
      if (data.length === 0) {
        jQuery("#" + replaceElement).html(EmptyMsg);
        
        switch (type) {
          case "my":
//            console.log('My: ' + studioMyMuralListEmpty);
            if (studioMyMuralListEmpty === 0) {
              setLeftRightPager(type, pager);
            }
            studioMyMuralListEmpty = 1;
            break;
          case "share":
//            console.log('Share: ' + studioMyMuralListEmpty);
            if (studioShareMuralListEmpty === 0) {
              setLeftRightPager(type, pager);
            }
            studioShareMuralListEmpty = 1;
            break;

        }
        //alert("not enough content to turning page");
      }
      else {
        //alert(data);
        //jQuery("#" + replaceElement).find("li").fadeOut(300);
        jQuery("#" + replaceElement).html(data).find("li").hide().fadeIn(300);
//        Drupal.CTools.AJAX.refreshElements();
        
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
  jQuery("ul li a.studio-mural-list-item-link").each(function( index ) {
    jQuery(this).unbind("click");
    jQuery(this).bind("click", function(){
      if (jQuery("#mural-region").length !== 0) {
        var source = jQuery(this).attr("href");
        jQuery("#mural-back-to-dashboard").show();
        showMuralDialog(source);
      }
      return false;
    });
  });
    
//  Drupal.behaviors.ZZCToolsModal;
  
//  jQuery("area.ctools-use-modal, a.ctools-use-modal", context).once("ctools-use-modal", function() {
//    var $this = jQuery(this);
//    $this.click(Drupal.CTools.Modal.clickAjaxLink);
//    // Create a drupal ajax object
//    var element_settings = {};
//    if ($this.attr("href")) {
//      element_settings.url = $this.attr("href");
//      element_settings.event = "click";
//      element_settings.progress = { type: "throbber" };
//    }
//    var base = $this.attr("href");
//    Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
//  });
  
  // Mural setting link bind click.
  jQuery("ul li a.studio-mural-settings").each(function( index ) {
    
    jQuery(this).unbind("click");


    // @link https://drupal.org/node/1744818
    // Bind modal link.
    jQuery(this).click(Drupal.CTools.Modal.clickAjaxLink);

    // Create a drupal ajax object
    var element_settings = {};
    if (jQuery(this).attr("href")) {
      element_settings.url = jQuery(this).attr("href");
      element_settings.event = "click";
      element_settings.progress = { type: "throbber" };
    }
    var base = jQuery(this).attr("href");
    Drupal.ajax[base] = new Drupal.ajax(base, this, element_settings);
    
  });
  
//  Drupal.CTools.AJAX.refreshElements();
  
}


function setArrowTop(){
	jQuery("#block-edgemakers-media-upload-gallery-image-list .scroll-wrapper .arrow-left, #block-edgemakers-media-upload-gallery-image-list .scroll-wrapper .arrow-right, #studio-media-list-pane .scroll-wrapper .arrow-left, #studio-media-list-pane .scroll-wrapper .arrow-right,#gallery-media-list-pane .scroll-wrapper .arrow-left, #gallery-media-list-pane .scroll-wrapper .arrow-right").each(function(){
		var l =jQuery(this).siblings("ul").find("li").length;
		if(l>8){
			jQuery(this).css("top", "150px")
		}else if(l>4){
			jQuery(this).css("top", "89px")
		}else{
			jQuery(this).css("top", "38px")
		}
	});
	
}


function studio_mural_ajax_load_list() {

  var myIdeaEmptyMsg = "<p class=\"empty-data\">There is no mural available for you.</p>";
  var shareWithMeEmptyMsg = "<p class=\"empty-data\">There are no ideas shared with you.</p>";
  
  jQuery.ajax({
    url: "?q=/mural/studio/get/list/ajax/my/0/"+num[0],
    dataType: "html",
    type : "GET",
    success : function(data){
      
      if (data.length === 0) {
        console.log("data is empty");
        var pager = jQuery("#studio-my-idea .arrow-left").attr("pager");
        if (pager === "0") {
          jQuery("#studio-mural-list").html(myIdeaEmptyMsg);
        }
      }
      else {
        jQuery("#studio-mural-list").html(data);
        
        jQuery("#studio-my-idea .arrow-left").unbind("click");
        jQuery("#studio-my-idea .arrow-left").bind("click", function(){
          
          var pager = jQuery(this).attr("pager");
          
          studio_mural_ajax_page_load("my", pager, num[0]);
          return false;
        });
        
        jQuery("#studio-my-idea .arrow-right").unbind("click");
        jQuery("#studio-my-idea .arrow-right").bind("click", function(){
          var pager = jQuery(this).attr("pager");
          studio_mural_ajax_page_load("my", pager, num[0]);
          return false;
        });
        
      }
    }
  });
  
  jQuery.ajax({
    url: "?q=/mural/studio/get/list/ajax/share/0/" + num[0],
    dataType: "html",
    type : "GET",
    success : function(data){
      
      if (data.length === 0) {
        console.log("data is empty");
        var pager = jQuery("#studio-share-with-me .arrow-left").attr("pager");
        if (pager === "0") {
          jQuery("#studio-mural-share-with-me-list").html(shareWithMeEmptyMsg);
        }
      }
      else {
        jQuery("#studio-mural-share-with-me-list").html(data);
        studio_mural_item_bind_link();

         jQuery("#studio-share-with-me .arrow-left").unbind("click");
         jQuery("#studio-share-with-me .arrow-left").bind("click", function(){
           var pager = jQuery(this).attr("pager");
           studio_mural_ajax_page_load("share", pager, num[0]);
           return false;
         });
         
         jQuery("#studio-share-with-me .arrow-right").unbind("click");
         jQuery("#studio-share-with-me .arrow-right").bind("click", function(){
           var pager = jQuery(this).attr("pager");
           studio_mural_ajax_page_load("share", pager, num[0]);
           return false;
         });
        
      }
    }
  });
  
  // Change load function to ajax above.
//  jQuery("#studio-mural-list").load("?q=mural/studio/get/list/ajax/my/0", function(){
//    
//    studio_mural_item_bind_link();
//   //setArrowTop();
//    
//    jQuery("#studio-my-idea .arrow-left").unbind("click");
//    jQuery("#studio-my-idea .arrow-left").bind("click", function(){
//      var pager = jQuery(this).attr("pager");
////      alert("Prev page: " + pager);
//      studio_mural_ajax_page_load("my", pager);
//      return false;
//    });
//    
//    jQuery("#studio-my-idea .arrow-right").unbind("click");
//    jQuery("#studio-my-idea .arrow-right").bind("click", function(){
//      var pager = jQuery(this).attr("pager");
////      alert("Next page: " + pager);
//      studio_mural_ajax_page_load("my", pager);
//      return false;
//    });
//          
//  });
  
//  jQuery("#studio-mural-share-with-me-list").load("?q=mural/studio/get/list/ajax/share/0", function(){
//    
//    studio_mural_item_bind_link();
//   //setArrowTop();
//    jQuery("#studio-share-with-me .arrow-left").unbind("click");
//    jQuery("#studio-share-with-me .arrow-left").bind("click", function(){
//      var pager = jQuery(this).attr("pager");
////      alert("Prev page: " + pager);
//      studio_mural_ajax_page_load("share", pager);
//      return false;
//    });
//    
//    jQuery("#studio-share-with-me .arrow-right").unbind("click");
//    jQuery("#studio-share-with-me .arrow-right").bind("click", function(){
//      var pager = jQuery(this).attr("pager");
////      alert("Next page: " + pager);
//      studio_mural_ajax_page_load("share", pager);
//      return false;
//    });
//          
//  });
  
}

function gallery_mural_ajax_load_list(pager) {
  
  var keyword = jQuery("#gallery-keyword").val();
  
  var galleryMuralEmptyMsg = "<p class=\"empty-data\">There are no more murals.</p>";
  
  //var sortby = jQuery("#gallery-sort-by").val();
  if (keyword == null) {
    keyword = "";
  }
  
  if (pager == null) {
    pager = 0;
  }
  console.log('mural/studio/list/page/ajax/gallery/' + num[1]);
  jQuery.ajax({
    url: "?q=mural/studio/list/page/ajax/gallery/" + pager + "/" + keyword + "/" + num[1],
    dataType: "html",
    type : "GET",
    success : function(data){
      
      if (data.length === 0) {
        if (keyword.length === 0) {
          console.log("galery mural data is empty");
          jQuery("#gallery-mural-list").html(galleryMuralEmptyMsg);
          if (galleryMuralListEmpty === 0) {
            setLeftRightPager("gallery", pager);
          }
          galleryMuralListEmpty = 1;
          
        }
        else {
          jQuery("#gallery-mural-list").html("Search result is empty, replace other keyword to search or clean keyword.");
//          alert("Search result is empty");
        }
      }
      else {
      	
      	
        jQuery("#gallery-mural-list").html(data);
       //setArrowTop();
        studio_mural_item_bind_link();
        setLeftRightPager("gallery", pager);
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
  jQuery("#studio-mural-list li a.studio-mural-settings").addClass("ctools-use-modal-processed").click(Drupal.CTools.Modal.clickAjaxLink).click();
//  $("<a></a>").attr("href","/select2/ajax/add/place").addClass("ctools-use-modal-processed").click(Drupal.CTools.Modal.clickAjaxLink).click();
  alert("Mural " + nid + " setting popup change to dialog!?");
}

function search_gallery() {
  
  jQuery("#gallery-keyword").addClass("searching");
  
  var mural_list_refresh = gallery_mural_ajax_load_list();

  // @TODO on media upload module.
//  var gallery_video_list_refresh = gallery_video_ajax_load_list();
//  var gallery_image_list_refresh = gallery_image_ajax_load_list();
  // gallery_media_list_ajax_load on media upload module.
  gallery_media_list_ajax_load("media");
  //gallery_media_list_ajax_load("video");
  //gallery_media_list_ajax_load("image");
  
  jQuery( document ).ajaxComplete(function( event,request, settings) {
    console.log(event);
    console.log(request);
    console.log(settings);
    jQuery("#gallery-keyword").removeClass("searching");
  });
}

function showInviteEmailBox() {

  var v = jQuery(".field-name-field-muralshared select :selected").val();
  //var v = jQuery("#edit-field-muralshared-und:selected").text();
  //alert("Select value: " + v);
  if (v == "1") {
    jQuery("#invite_email_box").show();
  }
  else {
    jQuery("#invite_email_box").hide();
  }
  //alert("Show invite box.");
}

function showLogin() {
  jQuery("a[href$=\"modal_forms/nojs/login\"]").trigger("click");
}

function changeTitleAfterSetting() {
  var title = jQuery(".form-item-title input").val();
  var mural_title = jQuery("#mural-top-bar #mural-title").val();
//  alert("Mural default title is: " + mural_title);
  jQuery("#mural-top-bar #mural-title").html(title);
}


function _refreshStudioGalleryMural() {
  
  // Refresh studio murals.
  var studio_me_next_page = jQuery("#studio-my-idea .scroll-wrapper .arrow-right").attr("pager");
  var studio_me_current_page = parseInt(studio_me_next_page) - 1;
  console.log("Studio me current page: " + studio_me_current_page);
  studio_mural_ajax_page_load("my", studio_me_current_page, num[0]);
  
  var studio_share_next_page = jQuery("#studio-share-with-me .scroll-wrapper .arrow-right").attr("pager");
  var studio_share_current_page = parseInt(studio_share_next_page) - 1;
  console.log("Studio share with me current page: " + studio_share_current_page);
  studio_mural_ajax_page_load("share", studio_share_current_page, num[0]);
  
  // Refresh gallery murals.
  var gallery_next_page = jQuery("#gallery-ideas .scroll-wrapper .arrow-right").attr("pager");
  var gallery_current_page = parseInt(gallery_next_page) - 1;
  console.log("Gallery current page: " + gallery_current_page);
  gallery_mural_ajax_load_list(gallery_current_page);

}

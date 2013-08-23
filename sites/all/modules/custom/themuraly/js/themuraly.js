
jQuery(document).ready(function(){
  
  jQuery(".toolbar-item.add-an-idea").show();
  jQuery(".create-mural").show();
  jQuery(".create-mural").bind("click", function(){

    //bigFrame.attr('src', source);
    if (jQuery("#mural-region").length !== 0) {
      var source = jQuery(this).attr("href");
      showMuralDialog(source);
    }
    //alert("Hook create mural link. and should set iframe src to " + source);
    return false;
  });
  
  mural_ajax_load_list();
  
  studio_mural_ajax_load_list();
  
});

function closeFromIframe()
{
  mural_ajax_load_list();
  jQuery('#mural-region').dialog('close');
  jQuery('body').css({
	'height': 'auto',
	'overflow-y': 'auto'
  });
  return false;
}

function showMuralDialog(source) {
  
  jQuery("#mural-set-nav").hide();
  jQuery("#mural-back-to-dashboard").show();
  
  jQuery("#mural-back-to-dashboard").bind("click", function(){
    jQuery("#mural-back-to-dashboard").hide();
    closeFromIframe();
    
  });
  
  var iframeHtml = "<iframe id=\"mural-iframe\" width=\"100%\" height=\"90%\" src=\"?q=" + source + "\"></iframe>";
  
  //jQuery("#mural-region").html("Mural display here by iframe " + source);
  jQuery("#mural-iframe").attr("src", source);
  function setMuralWidth(){
  	jQuery('body').css({
  		'height': jQuery(window).height()+ 'px',
  		'overflow': 'hidden'
  	});
  	jQuery("#mural-iframe").attr("width", jQuery(window).width() + 'px');
    jQuery("#mural-iframe").attr("height", jQuery(window).height()-56 + 'px');
    jQuery("#mural-region").css("height", jQuery(window).height() + 'px');
    
  }
  setMuralWidth();
  
  jQuery(window).resize(function(){
  	setMuralWidth();
  })
  
  jQuery( "#mural-region" ).dialog({
    resizable: false,
    modal: true,
    position: ["left", "top"],
    width: "100%",
    height: jQuery(window).height()+56,
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

      //alert("Hook mural list link.");
      jQuery(this).bind('click', function(){

        //alert("click mural link.");
        if (jQuery("#mural-region").length !== 0) {
          var source = jQuery(this).attr("href");
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

  jQuery.ajax({
    url: "?q=mural/studio/list/page/ajax/" + type + "/" +pager,
    type: "JSON",
    success: (function(data){
      console.log(data);
      studio_mural_item_bind_link();
      //@TODO GT change mural list.
    }),
  });
  
}

function studio_mural_item_bind_link() {
  jQuery('ul#studio-mural-list li a ').each(function( index ) {

    //alert("Hook mural list link.");
    jQuery(this).bind('click', function(){

      //alert("click mural link.");
      if (jQuery("#mural-region").length !== 0) {
        var source = jQuery(this).attr("href");
        showMuralDialog(source);
      }
      
      return false;

    });
  });
  
  jQuery('ul#studio-mural-list li a.studio-mural-settings').each(function( index ) {
  
    jQuery(this).unbind("click");

    //alert("Hook mural list link.");
    jQuery(this).bind('click', function(){

      alert("click mural link.");

      return false;

    });
  });
}

function studio_mural_ajax_load_list() {

  jQuery("#studio-mural-list").load("?q=mural/studio/get/list/ajax", function(){
    
    jQuery("#studio-my-idea .prev").bind("click", function(){
      var pager = jQuery(this).find("a").attr("id").substring(5);
//      alert("Prev page: " + pager);
      studio_mural_ajax_page_load('my', pager);
      return false;
    });
    
    jQuery("#studio-my-idea .next").bind("click", function(){
      var pager = jQuery(this).find("a").attr("id").substring(5);
//      alert("Next page: " + pager);
      studio_mural_ajax_page_load('my', pager);
      return false;
    });
          
  });
  
}
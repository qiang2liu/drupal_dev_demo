
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
  
});

function closeFromIframe()
{
  mural_ajax_load_list();
  jQuery('#mural-region').dialog('close');
  return false;
}

function showMuralDialog(source) {
  
  jQuery("#mural-set-nav").hide();
  jQuery("#mural-back-to-dashbord").show();
  
  jQuery("#mural-back-to-dashbord").bind("click", function(){
    jQuery("#mural-back-to-dashbord").hide();
    closeFromIframe();
  });
  
  var iframeHtml = "<iframe id=\"mural-iframe\" width=\"100%\" height=\"90%\" src=\"?q=" + source + "\"></iframe>";
  
  //jQuery("#mural-region").html("Mural display here by iframe " + source);
  jQuery("#mural-iframe").attr("src", source);
  function setMuralWidth(){
  	jQuery("#mural-iframe").attr("width", jQuery(window).width() + 'px');
    /*jQuery("#mural-iframe").attr("height", jQuery(window).height()-40 + 'px');
    jQuery( "#mural-region" ).css({
    	'height' : jQuery(window).height() + 40 + 'px'
    })*/
  }
  setMuralWidth();
  jQuery("#mural-iframe").attr("height", jQuery(window).height()-40 + 'px');
  jQuery(window).resize(function(){
  	setMuralWidth();
  })
  
  jQuery( "#mural-region" ).dialog({
    resizable: false,
    modal: true,
    position: ["left", "top"],
    width: "100%",
    height: jQuery(window).height() + 40,
    zIndex: 1000,
    resize: function(event,ui){
    	console.log('resize');
    }
    
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
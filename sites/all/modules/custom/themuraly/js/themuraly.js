
jQuery(document).ready(function(){
  
  jQuery(".toolbar-item.add-an-idea").show();
  jQuery(".create-mural").show();
  jQuery(".create-mural").bind("click", function(){

    //bigFrame.attr('src', source);
    if (jQuery("#mural-region").length !== 0) {

      var source = jQuery(this).attr("href");
      showMuralDialog(source);

      //jQuery("#stage-set-list").hide();
      //jQuery('.ui-dialog-titlebar').attr("style", "height: 21px;");
      //jQuery(".ui-dialog").attr("style", "padding-left: 1px;");
      //jQuery("#mural-region").show();

    }
    //alert("Hook create mural link. and should set iframe src to " + source);
    return false;
  });
});

function closeFromIframe()
{
  jQuery('#mural-region').dialog('close');
  return false;
}

function showMuralDialog(source) {
  
  var iframeHtml = "<iframe id=\"mural-iframe\" width=\"100%\" height=\"600\" src=\"?q=" + source + "\"></iframe>";
  
  //jQuery("#mural-region").html("Mural display here by iframe " + source);
  jQuery("#mural-iframe").attr("src", source);
  jQuery("#mural-iframe").attr("width", jQuery(window).width());
  jQuery("#mural-iframe").attr("height", jQuery(window).height() - 90);
  
  jQuery( "#mural-region" ).dialog({
    resizable: false,
    modal: true,
    position: ["left", "top"],
    width: "99%",
    height: jQuery(document).height() + 50,
    zIndex: 1000,
    /*buttons: {
      Ok: function() {
        jQuery(this).dialog( "close" );
      }
    }*/
  });
  
  jQuery('.ui-dialog-titlebar').attr("style", "display: none;");
}
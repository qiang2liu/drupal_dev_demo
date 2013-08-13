
jQuery(document).ready(function(){
  
  jQuery(".toolbar-item.add-an-idea").show();
  jQuery(".create-mural").show();
  jQuery(".create-mural").bind("click", function(){

    //bigFrame.attr('src', source);
    if (jQuery("#mural-region").length !== 0) {
      
      var source = jQuery(this).attr("href");

      jQuery("#stage-set-list").hide();
      
      var iframeHtml = "<iframe id=\"mural-iframe\" width=\"100%\" height=\"80%\" src=\"?q=mural/create\"></iframe>";
      
      //jQuery("#mural-region").html("Mural display here by iframe " + source);
      jQuery("#mural-iframe").attr("src", source);
      jQuery("#mural-iframe").attr("width", jQuery(window).width());
      jQuery("#mural-iframe").attr("height", jQuery(window).height() - 20);
      
      jQuery( "#mural-region" ).dialog({
        resizable: false,
        modal: true,
        position: ["left","top"],
        width: "100%",
        height: jQuery(window).height() + 80,
        zIndex: 1000,
        buttons: {
          Ok: function() {
            $( this ).dialog( "close" );
          }
        }
      });
      jQuery('.ui-dialog-titlebar').attr("style", "display: none;");
      //jQuery("#mural-region").show();

    }
    //alert("Hook create mural link. and should set iframe src to " + source);
    return false;
  });
});

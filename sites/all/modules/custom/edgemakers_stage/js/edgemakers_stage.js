/**
 * @file edgemakers_stage.js
 */

  // Load stage list on front page.
  // stage ajax.
  //alert(jQuery(".stage-selector").length);
  if (jQuery(".stage-selector").length !== 0) {
    jQuery('.stage-box').html("");
    jQuery.ajax({
      url: '?q=edgemakers/stage/api/list',
      dataType: 'json',
      type : 'GET',
      success : function(data){
        for(var i=0; i<data.length; i++){
          console.log(data[i]);
          var img = data[i].defualt_image;
          var sta_url = '<a class="ctools-use-modal" href="#" onclick="set_ajax_load_by_stage(' + data[i].nid + ');return true;">' + data[i].defualt_image + '<br/>' + data[i].title + '</a>';
          jQuery('.stage-box').append('<div class="stage-item">' + sta_url + '</div>');
        }
      },
      error :function(){
        alert('An error occurs when getting the stage sets!')
      }
    });
    
    jQuery("#back-set-list").bind("click", function(){
      jQuery("#set-view-region").slideToggle();
      jQuery("#stage-set-list").show();
    });
  }
  
  
  function openAjaxLoad(id) {
    jQuery("#" + id).html("Loading......");
    jQuery("#" + id).dialog({modal: true});
    jQuery('.ui-dialog-titlebar').attr("style", "display: none;");
  }
  
  function closeAjaxLoad(id) {
    jQuery("#" + id).dialog("close");
  }
  
  function set_ajax_load_by_stage($stage_id) {
    //jQuery("#ajax-target").load("?q=edgemarkers/stage/get/set/ajax/" + $stage_id);
    jQuery("#set-view-region").hide();
    jQuery('#stage-set-list').show();
    jQuery('#stage-set-list').html("Loading......");
    
    openAjaxLoad("ajaxload");
    
    jQuery('#stage-set-list').load("?q=edgemarkers/stage/get/set/ajax/" + $stage_id);
    
    jQuery('#stage-set-list').animate({
      opacity: 1
    }, 5000, 'linear', function() {
      
      jQuery('#stage-set-list ul li a').each(function( index ) {
        
        var ajaxUrl = jQuery(this).attr('href');
        
        jQuery(this).bind('click', function(){
          
          var nid = jQuery(this).attr('id').substring(5);

          ajaxUrl = '?q=edgemakers/stage/api/set/info/ajax/' + nid;
          
          var ajaxContent;
          
          jQuery.ajax({
            url: ajaxUrl,
            type: "GET",
            success: function(data) {

              //closeAjaxLoad("stage-set-view");
              
              ajaxContent = data;
              

              jQuery("#stage-set-view").html(ajaxContent);
              jQuery("#set-view-region").slideToggle();

              jQuery("#stage-set-list").hide();

              /*jQuery("#stage-set-view").dialog({
                closeText: "hide",
                width: 600,
                height: 400,
                modal: true,
                buttons: {
                  Ok: function() {
                    jQuery( this ).dialog( "close" );
                  }
                }
              });*/

              //return false;
            },
            error :function(){
              jQuery("#stage-set-view").html("Load set data error.");
              alert("Error");
              //ajaxContent = "Load set data error.";
              //jQuery("stage-set-view").html("Load set data error.");
              return false;
            }
          });
          
          //jQuery("#stage-set-view").html(ajaxContent);
          
          /*jQuery("#stage-set-view").dialog({
            closeText: "hide",
            left: 200,
            top: 90,
            width: 800,
            height: 550,
            modal: true,
            buttons: {
              Ok: function() {
                jQuery( this ).dialog( "close" );
              }
            }
          });*/
          
          /*
          jQuery(".ui-dialog").addClass("fixBoxPosition");
          jQuery('.ui-dialog-titlebar').addClass("fixBoxToolbar");
          jQuery('.ui-dialog-titlebar').attr("style", "display: none;");
          */
          
          //jQuery('.community').setCommunity();
          //jQuery('.toolbar-handler').bind('click', jQuery.fn.toggleToolbar);
          
          return false;
          
        });
      });
      
      /* jQuery("#stage-set-view").dialog("close"); */
      
      closeAjaxLoad("ajaxload");
      
    });


    //jQuery("#stage-set-view").dialog("close");
    
    /*jQuery('#stage-set-list ul li').each(function( index ) {
      alert(jQuery(this).attr("class"));
    });*/

  }
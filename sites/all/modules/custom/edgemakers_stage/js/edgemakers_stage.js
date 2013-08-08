/**
 * @file edgemakers_stage.js
 */
  
  var initStage;
  var initStageTitle;
  
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
        
        initStage = data[0].nid;
        initStageTitle = data[0].title;

        for(var i=0; i<data.length; i++){
          console.log(data[i]);
          var img = data[i].defualt_image;
          var sta_url = '<a class="ctools-use-modal" href="#" onclick="set_ajax_load_by_stage(' + data[i].nid + ');return true;">' + data[i].defualt_image + '<br/>' + data[i].title + '</a>';
          jQuery('.stage-box').append('<div class="stage-item">' + sta_url + '</div>');
        }
        jQuery('.stage-item').bind('click', function(){
			jQuery('.stage-selector').removeClass('active');
		});
        set_ajax_load_by_stage(initStage);
        
      },
      error :function(){
        alert('An error occurs when getting the stage sets!')
      }
    });
    
    jQuery("#back-set-list").bind("click", function(){
      jQuery("#set-view-region").slideToggle();
      jQuery("#stage-set-list").show();
      jQuery(".s-s-title h3").empty();
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
    //jQuery('#stage-set-list').html("Loading......");
    
    //openAjaxLoad("ajaxload");
    
    jQuery('#stage-set-list').load("?q=edgemarkers/stage/get/set/ajax/" + $stage_id, function(){
      
      var stageTitle = jQuery("#stage-title h2").html();

      jQuery(".s-s-title h2").html(stageTitle);

      jQuery('#stage-set-list ul li a').each(function( index ) {
        
        var ajaxUrl = jQuery(this).attr('href');
        
        jQuery(this).bind('click', function(){
          
          var nid = jQuery(this).attr('id').substring(5);
          var ajaxUrl = '?q=edgemakers/stage/api/set/info/ajax/' + nid;
          var ajaxContent;
          
          //openAjaxLoad("ajaxload");
          
          jQuery.ajax({
            url: ajaxUrl,
            type: "GET",
            success: function(data) {
              
              jQuery("#stage-set-view").html(data);
              
              var setTitle = jQuery("#set-title").html();

              jQuery(".s-s-title h3").html(setTitle);
              
              jQuery("#set-view-region").slideToggle();
              jQuery("#stage-set-list").hide();
              jQuery("#back-set-list").show();
              //make small image bigger to reach the edge of the content!
              if(jQuery('#stage-set-view .field-name-field-set-image .field-items img')){
              	
              	var ratio = (jQuery('.main-content').width()*0.96)/jQuery('#stage-set-view .field-name-field-set-image .field-items img').width();
              	
              	if(ratio>1){
              		var w = jQuery('#stage-set-view .field-name-field-set-image .field-items img').width();
              		var h = jQuery('#stage-set-view .field-name-field-set-image .field-items img').height();
              		jQuery('#stage-set-view .field-name-field-set-image .field-items img').css({
              			'width' : w * ratio + 'px',
              			'height' : h * ratio + 'px'
              		})
              	}
              }
              
              /*jQuery('#set-view-region').css({
              	'width' : jQuery(window).width()-400 + 'px'
              })*/
              //closeAjaxLoad("ajaxload");
            },
            error :function(){
              jQuery("#stage-set-view").html("Load set data error.");
              //closeAjaxLoad("ajaxload");
              return false;
            }
          });
          
          return false;
          
        });
      });
      
      //closeAjaxLoad("ajaxload");
      
    });
    
    //Move to load complate function
    /*jQuery('#stage-set-list').animate({
      opacity: 1
    }, 1000, 'linear', function() {
      
    });*/
  }

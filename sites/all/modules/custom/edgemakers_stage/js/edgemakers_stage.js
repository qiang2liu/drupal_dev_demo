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
          var img = data[i].defualt_image;
          var sta_url = '<a class="" href="#" onclick="set_ajax_load_by_stage(' + data[i].nid + ');return true;">' + data[i].defualt_image + '<br/>' + data[i].title + '</a>';
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
  
  function set_ajax_load_by_stage(stage_id) {
    //jQuery("#ajax-target").load("?q=edgemarkers/stage/get/set/ajax/" + stage_id);
    jQuery("#set-view-region").hide();
    jQuery('#stage-set-list').show();
    //jQuery('#stage-set-list').html("Loading......");
    
    //openAjaxLoad("ajaxload");
    
    jQuery('#stage-set-list').load("?q=edgemarkers/stage/get/set/ajax/" + stage_id, function(){
      function numbering(){
      	var el = jQuery('#stage-set-list .item-list:first li');
      	el.each(function(i){
      		jQuery(this).append('<span class="set-numbering">' + (i+1) + '</span>');
      	});
      }
      numbering();
      var stageTitle = jQuery("#stage-title h2").html();

      jQuery(".s-s-title h2").html(stageTitle);

      jQuery('#stage-set-list ul li .set-cover').each(function( index ) {
        
        var ajaxUrl = jQuery(this).siblings('a').attr('href');
        
        jQuery(this).bind('click', function(){
          
          var nid = jQuery(this).siblings('a').attr('id').substring(5);
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
              /*if(jQuery('#stage-set-view .field-name-field-set-image .field-items img')){
              	
              	var ratio = (jQuery('.main-content').width()*0.96)/jQuery('#stage-set-view .field-name-field-set-image .field-items img').width();
              	
              	if(ratio>1){
              		var w = jQuery('#stage-set-view .field-name-field-set-image .field-items img').width();
              		var h = jQuery('#stage-set-view .field-name-field-set-image .field-items img').height();
              		jQuery('#stage-set-view .field-name-field-set-image .field-items img').css({
              			'width' : w * ratio + 'px',
              			'height' : h * ratio + 'px'
              		})
              	}
              }*/
              
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

  if (jQuery(".view-community-users a.community-user-profile").length !== 0) {
    jQuery(".view-community-users a.community-user-profile").live('click', function() {
      jQuery.ajax({
        url: this.href,
        type : 'GET',
        success : function(data){
          var el = document.getElementById('community-user-profile');
          if(!el)
            jQuery('<div id="community-user-profile">'+data+'</div>').insertAfter(jQuery('.region-community'));
          else 
            jQuery('#community-user-profile').html(data);
          jQuery("#back-community").bind("click", function(){
            jQuery(".region-community").slideToggle();
            jQuery("#community-user-profile").hide();
          });
          jQuery(".region-community").slideToggle();
          jQuery("#community-user-profile").show();
        },
        error :function(){
        }
      });
      return false;
    });
  }
  if (jQuery("a.set-to-destination").length !== 0) {
    jQuery("a.set-to-destination").bind('click', function() {
      jQuery("#stage-set-view").html('<div class="set-video-content"><div id="yt">You need Flash player 8+ and JavaScript enabled to view this video.</div></div><div id="back-dashboard">Back to Dashboard</div>');
      videoid = this.getAttribute('videoid');
      setTimeout(function() {loadVideo(videoid);}, 100);
      jQuery("#back-dashboard").bind("click", function(){
        var stageTitle = jQuery("#stage-title h2").html();
        jQuery(".s-s-title h2").html(stageTitle);
        jQuery("#set-view-region").hide();
        jQuery("#stage-set-list").show();
        jQuery("#back-set-list").hide();
      });
      jQuery(".s-s-title h2").html('Tour Guide');
      jQuery(".s-s-title h3").empty();
      jQuery("#set-view-region").show();
      jQuery("#stage-set-list").hide();
      jQuery("#back-set-list").hide();
      return false;
    });
  }
function loadVideo(videoid) {
	var params = { allowScriptAccess: "always", wmode : 'opaque' };
	var atts = { id: "myytplayer" };

  //Get width from video destination element continar
  var videoWidth = jQuery(".set-video-content").width();
  var whratio = 64/39*1.0;
  var vHeight = videoWidth/whratio;

	swfobject.embedSWF("http://www.youtube.com/v/"+videoid+"?enablejsapi=1&playerapiid=playerapi&version=3",
		"yt", "100%", vHeight, "8", null, null, params, atts);
}
function viewallChange() {
  if(jQuery('.region-community').hasClass('allusers')) {
    jQuery('.region-community a.viewall')[0].innerHTML = 'View Less';
  } else {
    jQuery('.region-community a.viewall')[0].innerHTML = 'View All';
  }
}
function viewallusers() {
  if(jQuery('.region-community').hasClass('allusers')) {
    jQuery('.region-community').removeClass('allusers');
    jQuery('.region-community a.viewall')[0].innerHTML = 'View All';
  } else {
    jQuery('.region-community').addClass('allusers');
    jQuery('.region-community a.viewall')[0].innerHTML = 'View Less';
  }
  
}

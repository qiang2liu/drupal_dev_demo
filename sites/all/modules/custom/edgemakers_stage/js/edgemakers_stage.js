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
        
        initNav();
        
      },
      error :function(){
//        alert('An error occurs when getting the stage sets!');
      }
    });

  }
  
  function backToStage() {
    var stageNotes = jQuery("#stage-notes").html();
    teacherNotes(stageNotes);
    jQuery("#set-view-region").hide();
    jQuery("#stage-set-list").show();
    jQuery(".s-s-title h3").empty();
    adjustDestinationArea();
  }
  
  function openAjaxLoad(id) {
    jQuery("#" + id).html("Loading......");
    jQuery("#" + id).dialog({modal: true});
    jQuery('.ui-dialog-titlebar').attr("style", "display: none;");
  }
  
  function closeAjaxLoad(id) {
    jQuery("#" + id).dialog("close");
  }
  
  function initNav() {
    
    jQuery("#back-to-dashboard").bind("click", function(){
      var stageNotes = jQuery("#stage-notes").html();
      teacherNotes(stageNotes);
      
      // Clean audio/video.
      jQuery("#stage-set-view").html("Empty");
      
      jQuery("#set-view-region").hide();
      jQuery("#stage-set-list").show();
      jQuery(".s-s-title h3").empty();
      adjustDestinationArea();
    });
    
    jQuery("#mural-back-set-list").bind("click", function(){
      closeFromIframe();
      backToStage();
    });

    jQuery("#back-set-list").bind("click", function(){
      backToStage();
    });
    
    //Set destination nav.
    jQuery(".set-nav .next").bind("click", function(){
      var nid = jQuery(this).attr("id").substring(5);
      var setType = jQuery(this).attr("settype");
      
      if (setType == "mural") {
        var source = jQuery('[current="'+nid+'"] a').attr("href");
        
        showMuralDialog(source);
        jQuery("#mural-iframe").attr("height", jQuery(window).height() - 56 + 'px');
        jQuery("#mural-back-to-dashboard").hide();
        jQuery("#mural-set-nav").show();

        resetDestinationNav(nid);
  		
        jQuery("#set-view-region").hide();
        jQuery("#stage-set-list").show();
      }
      else {
        showSetOnDestion(nid, setType);
      }
      return false;
    });
    
    jQuery(".set-nav .prev").bind("click", function(){
      var nid = jQuery(this).attr("id").substring(5);
      var setType = jQuery(this).attr("settype");
     
      if (setType == "mural") {
        var source = jQuery('[current="'+nid+'"] a').attr("href");
  //      alert("Mural opeaation on nav." + source);
        showMuralDialog(source);
        jQuery("#mural-iframe").attr("height", jQuery(window).height() - 56 + 'px');
        jQuery("#mural-back-to-dashboard").hide();
        jQuery("#mural-set-nav").show();

        resetDestinationNav(nid);
  		 
        jQuery("#set-view-region").hide();
        jQuery("#stage-set-list").show();
      }
      else {
        showSetOnDestion(nid, setType);
      }
      return false;
    });
  }
  
  function set_ajax_load_by_stage(stage_id) {
    //jQuery("#ajax-target").load("?q=edgemarkers/stage/get/set/ajax/" + stage_id);
    jQuery("#set-view-region").hide();
    jQuery('#stage-set-list').show();
    //jQuery('#stage-set-list').html("Loading......");

//    jQuery("#set-nav-prev").attr('href', 'node/' + nid + '/prev');
    
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
      
      var stageNotes = jQuery("#stage-notes").html();
      teacherNotes(stageNotes);

      jQuery('#stage-set-list ul li .set-cover').each(function( index ) {
        
        var ajaxUrl = jQuery(this).siblings('a').attr('href');
        
        jQuery(this).bind('click', function(){
          jQuery('.stage-selector').removeClass('active');
          var setType = jQuery(this).siblings('a').attr("class");
          
          var nid = jQuery(this).siblings('a').attr('id').substring(5);
          showSetOnDestion(nid, setType);

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
  
  function teacherNotes(notes) {
  	jQuery('.teacher-notes').removeClass('active');
  	jQuery('.teacher-notes').css('top','835px');
  	jQuery(".teacher-notes .indicator").unbind('click');
    if(notes!='') {
      jQuery('.teacher-notes').show();
      jQuery('.teacher-notes-cont').html(notes);
      jQuery(".teacher-notes .indicator").bind('click', function() {
      	
      	jQuery('.teacher-notes').toggleClass('active');
      	var h = jQuery('.teacher-notes-cont').height();
      	
      	//jQuery('.teacher-notes-cont').css('height', h + 'px');
      	var t= 835 -h;
        jQuery('.teacher-notes').css('top', t + 'px');
      });
    } else {
      jQuery(".teacher-notes").css('display', 'none');
    }
  }

  if (jQuery(".region-community a.community-user-profile").length !== 0) {
    jQuery(".region-community a.community-user-profile").live('click', function() {
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
  
  jQuery("a.topic_link").bind('click', function() {
    jQuery.ajax({
      url: this.href,
      type : 'GET',
      success : function(data){      
        jQuery("#stage-set-view").html(data);
        
        var setTitle = jQuery("#set-title").html();
  
        jQuery(".s-s-title h2").html('Topic');
        jQuery(".s-s-title h3").empty();
        
        teacherNotes('');
        jQuery("#set-view-region").show();
        jQuery("#stage-set-list").hide();
        
        jQuery("#mural-back-to-dashboard").hide();
        jQuery("#back-to-dashboard").show();
        jQuery("#set-nav").hide();
        
        adjustDestinationArea(true);
      },
      error :function(){
      }
    });
    return false;
  });
  
  if (jQuery("a.set-to-destination").length !== 0) {
    
    var flashDownUrl = '<a href="http://get.adobe.com/flashplayer/" target="_blank">Get Flash Player</a>';
    var tourGuideHtml = '<div class="set-type-icon set-video-type-icon">Tour Guide</div>';
    tourGuideHtml = tourGuideHtml + '<div class="set-video-content">';
    tourGuideHtml = tourGuideHtml + '<div id="yt">You need Flash player 8+ and JavaScript enabled to view this video.';
    tourGuideHtml = tourGuideHtml + '<p>' + flashDownUrl + '</p>';
    tourGuideHtml = tourGuideHtml + '</div></div>';
    
    jQuery("a.set-to-destination").bind('click', function() {
      jQuery("#stage-set-view").html(tourGuideHtml);
      videoid = this.getAttribute('videoid');
      setTimeout(function() {loadVideo(videoid);}, 100);
      
      jQuery("#back-dashboard").bind("click", function(){
        var stageNotes = jQuery("#stage-notes").html();
        teacherNotes(stageNotes);
        var stageTitle = jQuery("#stage-title h2").html();
        jQuery(".s-s-title h2").html(stageTitle);
        jQuery("#set-view-region").hide();
        jQuery("#stage-set-list").show();
//        jQuery("#back-to-dashboard").hide();
        jQuery("#back-set-list").hide();
//        jQuery("#set-nav").hide();
      });
      
      jQuery("#set-nav").hide();
      jQuery("#back-to-dashboard").show();
      
      teacherNotes('');
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

	swfobject.embedSWF("http://www.youtube.com/v/"+videoid+"?rel=0&enablejsapi=1&playerapiid=playerapi&version=3",
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


function resetDestinationNav(nid) {
//Nav reset.
  var prevId = jQuery('[current="'+nid+'"]').attr("prev");
  var nextId = jQuery('[current="'+nid+'"]').attr("next");
  var prevType = jQuery('[current="'+nid+'"]').attr("prevtype");
  var nextType = jQuery('[current="'+nid+'"]').attr("nexttype");
  jQuery(".set-nav .prev").attr("id", "node-" + prevId);
  jQuery(".set-nav .prev").attr("settype", prevType);
  jQuery(".set-nav .next").attr("id", "node-" + nextId);
  jQuery(".set-nav .next").attr("settype", nextType);
  // End nav.
}

function showSetOnDestion(nid, setType) {

  var ajaxUrl = '?q=edgemakers/stage/api/set/info/ajax/' + nid;
  var ajaxContent;
  
  closeFromIframe();

  resetDestinationNav(nid);
  

  if (setType == "mural") {
    var source = jQuery('[current="'+nid+'"] a').attr("href");
//    alert('Mural operation.' + source);
//    var source = jQuery(this).attr("href");
    
    showMuralDialog(source);
    jQuery("#mural-iframe").attr("height", jQuery(window).height() - 56 + 'px');
    jQuery("#mural-back-to-dashboard").hide();
    jQuery("#mural-set-nav").show();

    jQuery("#set-view-region").hide();
    jQuery("#stage-set-list").show();
  }
  else {

    //openAjaxLoad("ajaxload");
    jQuery.ajax({
      url: ajaxUrl,
      type: "GET",
      success: function(data) {
        
        jQuery("#stage-set-view").html(data);
        
        var setTitle = jQuery("#set-title").html();
  
        jQuery(".s-s-title h3").html(setTitle);
        
        var setNotes = jQuery("#set-notes").html();
        teacherNotes(setNotes);
        
        jQuery("#set-view-region").show();
        jQuery("#stage-set-list").hide();
        
        jQuery("#mural-back-to-dashboard").hide();
        jQuery("#back-to-dashboard").hide();
        jQuery("#set-nav").show();
        jQuery("#back-set-list").show();
        jQuery(".set-nav .prev").show();
        jQuery(".set-nav .next").show();
        
        adjustDestinationArea(setType == "topic_page");
        
//        jQuery("#back-to-dashboard").hide();
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
  }

}
function adjustDestinationArea(wider) {
  if(wider) {
    var top = 35;
    var height = jQuery(window).height()-top-5;
    jQuery('.main-content').css({'width': '99%', 'height':height+'px', 'top':top+'px', 'z-index':'100'});
    jQuery('.set-text-content').css('height', (height-(jQuery('#set-nav').css('display') == 'block' ? 190 : 155))+'px');
  } else {
    jQuery('.main-content').css({'width': '70%', 'height':'auto', 'top':'90px', 'z-index':'auto'});
    jQuery('.set-text-content').css('height', '400px');
  }
  jQuery.fn.setPositionofElements();
}
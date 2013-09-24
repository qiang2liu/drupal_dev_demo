
var ytplayer;
var params = {allowScriptAccess: "always"};
var atts = {id: "myytplayer"};
function play_videos(vlist) {
    var play_ytid = '';
    for (var i = 0; i < vlist.length; i++) {
      if (vlist[i].play == 1) {
          play_ytid = vlist[i].yid;
          break;
      }
    }
    
    swfobject.embedSWF("http://www.youtube.com/v/"+play_ytid+"?rel=0&enablejsapi=1&playerapiid=ytplayer&version=3&modestbranding=1",
      "ytapiplayer", "780", "439", "8", null, null, params, atts);
  

}

function onYouTubePlayerReady(playerId) {
  ytplayer = document.getElementById("myytplayer");
  // make vedio list array
  var the_list_array = [];
  var num = 0;
  var starttime = 0;
  var vdatas = Drupal.settings.fte_video_demo;
  for (var i = 0; i < vdatas.length; i++) {
    the_list_array[i] = vdatas[i].yid;
    if (vdatas[i].play == 1) {
      starttime = vdatas[i].time;
      num = i;
     
    }
  }
  ytplayer.loadPlaylist(the_list_array, num, starttime,'default');
  ytplayer.addEventListener("onStateChange", "onytplayerStateChange");
  setup_video_status_capture(ytplayer);
  
}

function onytplayerStateChange(newState) {
  

}

function getnextvideo(current_ytid) {
  if (current_ytid ) {
     var eles = $('.video_container');
     for(var i = 0; i< eles.lenght; i++) {
       if (eles[i].attr('data-ytid') == current_ytid) {
         var the_index = i+1;
         if (the_index >= eles.lenght) {
           return '';
         } else {
           return eles[the_index].attr('data-ytid');
         }
       }
     }
  } 
  return '';
}
var timerId;
function  setup_video_status_capture(ytplayer) {
  
  
  timerId = setInterval(function() {capture_video_process(ytplayer);},1000);
}

function capture_video_process(ytplayer) {
  var current_v_index = ytplayer.getPlaylistIndex();
  var current_yid = Drupal.settings.fte_video_demo[current_v_index].yid;
  //var current_yid = ytplayer.getVideoEmbedCode();
  var playtime = ytplayer.getCurrentTime();
  setCookie("current_yid",current_yid,30);
  setCookie("playtime", playtime,30);
  
}

function setCookie(c_name,value,expiredays)
{
  var exdate=new Date()
  exdate.setDate(exdate.getDate()+expiredays)
  document.cookie=c_name+ "=" +escape(value)+
  ((expiredays==null) ? "" : ";expires="+exdate.toGMTString())
}

function play_the_video(yid) {
  
  var vdatas = Drupal.settings.fte_video_demo;
  var the_index = 0;
  for (var i = 0; i < vdatas.length; i++) {
   
    if (vdatas[i].yid == yid) {
        
      the_index = i ; 
      ytplayer.playVideoAt(the_index);
    
      window.location.href="#top";
      break;
    }
  }
  
}
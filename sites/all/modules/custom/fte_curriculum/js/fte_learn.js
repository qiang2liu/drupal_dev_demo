
    
    function onYouTubePlayerReady(playerId) {
      
      ytplayer = document.getElementById("myytplayer");
      if(Drupal.settings.fte_learn_stages_playtime > 0) {
         ytplayer.seekTo(Drupal.settings.fte_learn_stages_playtime,false);
      } 
      
      ytplayer.playVideo();
      ytplayer.addEventListener("onStateChange", "onytplayerStateChange");
      setup_video_status_capture(ytplayer);
  
    }
    

    function onytplayerStateChange(newState) {
     
      if (newState == 0) {//end
        if (Drupal.settings.fte_learn_stages.next_sid != -1) {
          location.href ="/learn/"+Drupal.settings.fte_learn_stages.next_mid+"/stage/"+Drupal.settings.fte_learn_stages.next_sid;
        }
      }

    }
    
    
    var timerId;
function  setup_video_status_capture(ytplayer) {
  
  
  timerId = setInterval(function() {capture_video_process(ytplayer);},1000);
}
    
    function capture_video_process(ytplayer) {





  var playtime = ytplayer.getCurrentTime();
  setCookie("fte_learn_current_yid",Drupal.settings.fte_learn_stages_yid,30);
  setCookie("fte_learn_playtime", playtime,30);

  
}

    function setCookie(c_name,value,expiredays)
{
  var exdate=new Date()
  exdate.setDate(exdate.getDate()+expiredays)
  document.cookie=c_name+ "=" +escape(value)+
  ((expiredays==null) ? "" : ";expires="+exdate.toGMTString())
}
    
  
  
  
  




    
(
  function ($, Drupal){
    
    
    $(document).ready(function(){
     
      swfobject.embedSWF("http://www.youtube.com/v/"+Drupal.settings.fte_learn_stages_yid
        +"?enablejsapi=1&rel=0&playerapiid=ytplayer&version=3&modestbranding=1",
        "ytapiplayer", "540", "320", "8", null, null, params, atts);
  
    
  



    }
    


    ); 
   
  }
)(jQuery,Drupal);
    
    
   

function setCookie(c_name,value,expiredays)
{
  var exdate=new Date()
  exdate.setDate(exdate.getDate()+expiredays)
  document.cookie=c_name+ "=" +escape(value)+
  ((expiredays==null) ? "" : ";expires="+exdate.toGMTString())
}
    
  
  
  
  



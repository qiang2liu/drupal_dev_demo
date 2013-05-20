$(document).ready(function(){
	parallax.add($("#home"))
			.add($("#qa"))
			.add($("#photo"))
			.add($("#video"))
			.add($('#news'));
	//home
	parallax.home.onload=function(){
		setRight("qa",'Q&A');
		setTop("photo",'Photo');
		setLeft("video",'Video');
		setBottom("news",'News');
	};
	parallax.home.show();
	
	//Q&A
	parallax.qa.onload=function(){
		setRight("video",'Video');
		setTop("photo",'Photo');
		setLeft("home",'Home');
		setBottom("news",'News');
	};
	
	//video
	parallax.video.onload=function(){
		setLeft("qa",'Q&A');
		setTop("photo",'Photo');
		setRight("home",'Home');
		setBottom("news",'News');
	};
	
	//photo
	parallax.photo.onload=function(){
		setLeft("video",'Video');
		setTop("news",'News');
		setRight("qa",'Q&A');
		setBottom("home",'Home');
	};
	
	//news
	parallax.news.onload=function(){
		setRight("qa",'Q&A');
		setTop("home",'Home');
		setLeft("video",'Video');
		setBottom("photo",'Photo');
	};
	
	//Sets the correct triggers for the arrows, plus arrow keys
	function setRight(page,text){
		$('.right-text').text(text);
		$(".c-right").unbind('click').click(function(){
			parallax[page].right();
		});
	}

	function setLeft(page,text){
		$('.left-text').text(text);
		$(".c-left").unbind('click').click(function(){
			parallax[page].left();
		});
	}

	function setTop(page,text){
		$('.top-text').text(text);
		$(".c-top").unbind('click').click(function(){
			parallax[page].top();
		});
	}

	function setBottom(page,text){
		$('.bottom-text').text(text);
		$(".c-bottom").unbind('click').click(function(){
			parallax[page].bottom();
		});
	}
	
	//pop-up
	$('.login, .register').bind('click', function(){
		if($('.pop-up').css('display').trim() === 'none'){
			$('.pop-up').stop().fadeIn(500);
		}
	})
	$('.pop-close').bind('click', function(){
		$('.pop-up').stop().fadeOut(500);
	})
});

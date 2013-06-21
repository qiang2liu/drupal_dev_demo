$(document).ready(function(){
	/*parallax.add($("#home"))
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
	})*/
	
	//mockup
	$(window).bind('mouseover', function(event){
		if($(event.target).hasClass('menu-learn-child')){
			var t = $(event.target).offset().top - $('#content').offset().top;
			var l = $(event.target).offset().left- $('#content').offset().left;
			var h = $(event.target).width();
			$('.menu-learn li li a').removeClass('active');
			$(event.target).addClass('active');
			$('.menu-learn-fly-layer').css({
				top  : t + 'px',
				left : l + h +21 + 'px'
			});
			$('.menu-learn-fly-layer').show();
		}
		if($(event.target).hasClass('menu-learn-fly-layer')){
			$('.menu-learn-fly-layer').show();
		}
		if(!$(event.target).hasClass('menu-learn-fly-layer') && !$(event.target).hasClass('menu-learn-child')){
			$('.menu-learn-fly-layer').hide();
			$('.menu-learn li li a').removeClass('active');
		}
	});
	
	$('.menu-learn>li a').bind('click', function(){
		$(this).siblings('ul').toggle(200);
		$(this).parent().toggleClass('active');
	});
	
	$('.level-first-has-child > li > a, .level-second-has-child > li > a').bind('click', function(){
		$(this).toggleClass('active');
		$(this).siblings('ul').toggle(400);
	});
	$('.stage_breadcrumb').bind('click', function(){
		$(this).toggleClass('active');
		$(this).siblings('.learn-main-content').toggle(400);
		$(this).siblings('object').toggle(400);
	})
	$('.stage_bottom_content_inner').find('.stage_bottom_content_inner_content').not(':first').hide();
	$('em.stage_bottom_switcher').bind('click', function(){
		//
		$(this).toggleClass('active');
		$(this).parent().siblings('.stage_bottom_content_inner').toggle(400);
		//
		//
	});
	$('.stage_bottom_content_tab span').bind('click', function(){
		$('.stage_bottom_content_tab span').removeClass('active');
		var idx = $(this).index();
		$(this).addClass('active');
		$(this).parent().siblings('.stage_bottom_content_inner').find('.stage_bottom_content_inner_content').hide();
		$(this).parent().siblings('.stage_bottom_content_inner').find('.stage_bottom_content_inner_content').eq(idx-1).show();
	});
	//dashboard
	$('.facewall').not(':first').hide();
	$('.sortitem li').bind('click', function(){
		$('.sortitem li').removeClass('active');									 	
		$(this).addClass('active');
		var idx= $(this).index();
		$('.facewall').hide();
		$('.facewall').eq(idx).show();
	});
        
        $('#colla_all').bind('click',function(){
          $('#collamore').css('display','block');
        });
	//challenge
	$('.project_directory .content').hide();
	$('.project_directory .content').eq(1).show();
	$('.project_directory .project_tabs span').bind('click', function(){
		var idx = $(this).index();
		$('.project_directory .project_tabs span').removeClass('active');
		$(this).addClass('active');
		$('.project_directory .content').hide();
		$('.project_directory .content').eq(idx).show();
	});
	//studio
	$('.studio-side-inner h5').bind('click', function(){
		$(this).toggleClass('active');
		$(this).next('ul').toggle(400);
		console.log($(this).next('ul'));
	});
	$('.studio-side h4').bind('click', function(){
		$(this).toggleClass('active');
		$(this).next('.studio-side-inner').toggle(400);
	});
	$(document).bind('mouseover', function(event){
		if($(event.target).hasClass('setting-img') ||$(event.target).hasClass('studio-setting')){
			var x = $(event.target).offset().left + $(event.target).width() - 100;
			var y = $(event.target).offset().top + $(event.target).height() - 30;
			$('.studio-setting').css({'top': y + 'px', 'left' : x + 'px'}).fadeIn(200);
		}else{
			$('.studio-setting').fadeOut(200);
		};
	});
	$('body').append('<div class="studio-cover"></div>')
	$('.studio-cover').css({
		'width' : $(document).width()+ 'px',
		'height': $(document).height()+ 'px'
	});
	$('.studio-setting').bind('click', function(){
		$('.studio-cover').show();
		$('.studio-popup').css({
				'top' : $(window).scrollTop()+($(window).height() - 320)/2 + 'px',
				'left': ($(window).width() - 300)/2 + 'px',
			}).show();
	})
	$('.studio-close').bind('click', function(){
		$('.studio-cover').hide();
		$('.studio-popup').hide();
	});
	$('.page-learn-stage').find('#content').prepend('<div class="learn-nav" class="active"><em></em>FINDING OUR BEARING - Learning Forward</div>');
	$('.learn-nav').bind('click', function(){
		$(this).find('em').toggleClass('active');
		$(this).siblings('.section').toggle(400);
	})
        
});

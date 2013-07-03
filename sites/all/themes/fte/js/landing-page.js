(function($){
  

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
			var t = $(event.target).offset().top;
			var l = $(event.target).offset().left;
			var h = $(event.target).width();
			$('.menu-learn li li a').removeClass('active');
			$(event.target).addClass('active');
			$('.menu-learn-fly-layer').css({
				top  : t + 'px',
				left : l + h +20 + 'px'
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
		$('.stage_comments').toggle(400);
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
		if($(event.target).hasClass('setting-img') ||$(event.target).hasClass('studio-setting') || $(event.target).hasClass('studio-setting-img')){
			var x = $(event.target).offset().left;
			var y = $(event.target).offset().top + $(event.target).height() - 41;
			$('.studio-setting').css({'top': y + 'px', 'left' : x + 'px'}).show();
		}else{
			$('.studio-setting').hide();
		};
	});
	$('body').append('<div class="studio-cover"></div>')
	$('.studio-cover').css({
		'width' : $(document).width()+ 'px',
		'height': $(document).height()+ 'px'
	});
	$('.studio-setting').bind('click', function(){
		$('.studio-cover').show();
		$('.studio-popup.studio-popup2').css({
				'top' : $(window).scrollTop()+($(window).height() - 320)/2 + 'px',
				'left': ($(window).width() - 300)/2 + 'px',
			}).show();
	});
        $('.upload_v').bind('click', function(){
		$('.studio-cover').show();
		$('.studio-popup1.studio-popup').css({
				'top' : $(window).scrollTop()+($(window).height() - 500)/2 + 'px',
				'left': ($(window).width() - 500)/2 + 'px',
			}).show();
	});
	$('.studio-close').bind('click', function(){
		$('.studio-cover').hide();
		$('.studio-popup').hide();
	});
	$('.page-learn-stage').find('#content').prepend('<div class="learn-nav" class="active"><em></em>FINDING OUR BEARING - Leaning Forward</div>');
	$('.learn-nav').bind('click', function(){
		$(this).find('em').toggleClass('active');
		$(this).siblings('.section').toggle(400);
	});
	$('.da-tabs-box em').bind('click', function(){
		$(this).toggleClass('active');
		$(this).parent().siblings('.da-content-box').toggle();
	});
	$('.da-tabs-box span').bind('click', function(){
		$(this).siblings('span').removeClass('active');
		$(this).addClass('active');
		var idx = $(this).index();
		$(this).parent().siblings('.da-content-box').find('.da-content').addClass('hide');
		$(this).parent().siblings('.da-content-box').find('.da-content').eq(idx-1).removeClass('hide');
	});
  
	$('.topic-selector >ul > li').bind('click', function(){
		if($(this).hasClass('active')){
			$(this)	.removeClass('active');
		}else{
			$('.topic-selector >ul > li.active').removeClass('active');
			$(this).addClass('active');
		}
		
		
	});
	$('.cha-slider-middle-inner').css('width', $('.cha-slider-middle-inner li').length * 2 * 282 + 'px' );
	$('.location-tab').bind('click', function(){
		
		$(this).toggleClass('active');
		$(this).siblings('.location-content').toggle(400);
	});
	var h = $('.region-sidebar-first').height();
	$('.toolbar-wrapper-control').bind('click', function(){
		$(this).toggleClass('active');
		h = $('.region-sidebar-first').height();
		$('.region-sidebar-first').css('minHeight', h+ 'px').toggleClass('active');
	});
	$('#d3').carrousel();
});
$.fn.extend({
	carrousel: function(options){
		var defaults = {
			count      : 9,
			item       : '.d3-item',
			leftClass  : 'preserve-left',
			rightClass : 'preserve-right',
			leftController: '.d3-left-arrow',
			rightController: '.d3-right-arrow'
		};
		var options = $.extend(defaults, options);
		return this.each(function(){
			var self = $(this);
			//set index
			
			//prepare layout
			var idx = options.count % 2;
			for(var i = options.count-1; i > parseInt(options.count / 2, 10); i--){
				$(this).find(options.item).eq(i).find('img').addClass(options.rightClass);
				$(this).find(options.item).eq(i).addClass('top-margin').addClass('transformed');
			}
			if(idx ==1){
				for(var i = 0; i < parseInt(options.count / 2, 10); i++){
					$(this).find(options.item).eq(i).find('img').addClass(options.leftClass);
					if(i !=0){
						$(this).find(options.item).eq(i).addClass('top-margin').addClass('transformed');
					}else{
						$(this).find(options.item).eq(i).addClass('top-margin');
					}		
				}
				$(this).find(options.item).eq(parseInt(options.count / 2, 10) + 1).removeClass('transformed').addClass('active-left');
				$(this).find(options.item).eq(parseInt(options.count / 2, 10)).addClass('active');
				
			}else{
				for(var i = 0; i < parseInt(options.count / 2 -1, 10); i++){
					$(this).find(options.item).eq(i).find('img').addClass(options.leftClass);
					$(this).find(options.item).eq(i).addClass('top-margin').addClass('transformed');
					if(i !=0){
						$(this).find(options.item).eq(i).addClass('top-margin').addClass('transformed');
					}else{
						$(this).find(options.item).eq(i).addClass('top-margin');
					}
				}
				$(this).find(options.item).eq(parseInt(options.count / 2, 10)).removeClass('transformed').addClass('active-left');
				$(this).find(options.item).eq(parseInt(options.count / 2, 10)-1).addClass('active');
			}
			function setIndex(){
				self.find(options.item).css('zIndex','0');
				var idx = self.find('.active').index(options.item);
				var itemLength = self.find(options.item).length-1;
				for(var i=itemLength; i>=idx; i--){
					self.find(options.item).eq(i).css('zIndex', itemLength - i);
				}
			}
			setIndex();
			//arrow click
			
			/*function imgFlow(idx,imgClass,imgRemovedClass,itemClass1,itemClass2,theLeftClass,theFirst,theRightClass){
				var currentActive = self.find(options.item + '.active').index(options.item);
				var aimItem = currentActive + idx;
				if(aimItem > -1 && aimItem < $(options.item).length){
					console.log(aimItem);
					self.find(options.item).eq(currentActive).removeClass('active').addClass(itemClass1).addClass(theLeftClass).addClass(theRightClass);
					self.find(options.item).eq(currentActive).find('img').addClass(imgClass);
					self.find(options.item).eq(aimItem).addClass('active').removeClass(itemClass1).removeClass(itemClass2).removeClass(theLeftClass);
					self.find(options.item).eq(aimItem).find('img').removeClass(imgRemovedClass);
					if(aimItem < $(options.item).length -2){
						self.find(options.item).eq(aimItem + 2).removeClass(theLeftClass).addClass(itemClass2);
					}
					self.find(options.item).eq(0).addClass(theFirst);
				}
				
			}
			$(this).find(options.leftController).bind('click', function(){
				imgFlow.call($(this),-1,'preserve-right','preserve-left','top-margin', 'transformed','active-left','the-first','');
			});
			$(this).find(options.rightController).bind('click', function(){
				imgFlow.call($(this),1,'preserve-left','preserve-right','top-margin', 'transformed','','the-first','transformed');
			});*/
			
			function addAnimate(){
				self.find(options.item).addClass('reload');
				self.find(options.item).find('img').addClass('reload');
			}
			self.find(options.leftController).bind('click', function(){
				var currentActive = self.find(options.item + '.active').index(options.item);
				var aimItem = currentActive-1;
				var addi = currentActive + 1;
				if(aimItem > -1){
					addAnimate();
					self.find(options.item).eq(currentActive).removeClass('active').addClass('active-left').addClass('top-margin');
					self.find(options.item).eq(currentActive).find('img').removeClass('preserve-left').addClass('preserve-right');
					self.find(options.item).eq(aimItem).removeClass('top-margin').removeClass('transformed').addClass('active');
					self.find(options.item).eq(aimItem).find('img').removeClass('preserve-left');
					self.find(options.item).eq(addi).removeClass('active-left').addClass('transformed');
					self.find(options.item).eq(0).addClass('the-first');
				}
				setIndex();
				//setTimeout(setIndex,1)
			});
			self.find(options.rightController).bind('click', function(){
				var currentActive = self.find(options.item + '.active').index(options.item);
				var aimItem = currentActive+1;
				var addi = currentActive + 2;
				if(aimItem < $(options.item).length){
					addAnimate();
					self.find(options.item).eq(currentActive).removeClass('active').addClass('transformed').addClass('top-margin');
					self.find(options.item).eq(currentActive).find('img').removeClass('preserve-right').addClass('preserve-left');
					self.find(options.item).eq(aimItem).removeClass('top-margin').removeClass('active-left').addClass('active');
					self.find(options.item).eq(aimItem).find('img').removeClass('preserve-right');
					self.find(options.item).eq(addi).removeClass('transformed').addClass('active-left');
					self.find(options.item).eq(0).addClass('the-first').removeClass('transformed');
					self.find(options.item).eq(self.find(options.item).length-1).addClass('the-last');
				}
				setIndex();
				//setTimeout(setIndex,1)
			});
			/*self.find(options.item).find('img').bind('mouseover', function(){
				var currentActive = self.find(options.item + '.active').index(options.item);
				var aimItem = $(this).parent().index(options.item);
				var addi = aimItem + 1;
				if(aimItem > currentActive){
					
					addAnimate();
					self.find(options.item).eq(currentActive).removeClass('active').addClass('transformed').addClass('top-margin');
					self.find(options.item).eq(currentActive).find('img').removeClass('preserve-right').addClass('preserve-left');
					self.find(options.item).eq(aimItem).removeClass('top-margin').removeClass('active-left').addClass('active');
					self.find(options.item).eq(aimItem).find('img').removeClass('preserve-right');
					self.find(options.item).eq(addi).removeClass('transformed').addClass('active-left');
					self.find(options.item).eq(0).addClass('the-first').removeClass('transformed');
					self.find(options.item).eq(self.find(options.item).length-1).addClass('the-last');
				}
				if(aimItem < currentActive){
					addAnimate();
					self.find(options.item).eq(currentActive).removeClass('active').addClass('active-left').addClass('top-margin');
					self.find(options.item).eq(currentActive).find('img').removeClass('preserve-left').addClass('preserve-right');
					self.find(options.item).eq(aimItem).removeClass('top-margin').removeClass('transformed').addClass('active');
					self.find(options.item).eq(aimItem).find('img').removeClass('preserve-left');
					self.find(options.item).eq(addi).removeClass('active-left').addClass('transformed');
					self.find(options.item).eq(0).addClass('the-first');
				}
				setIndex();
				//setTimeout(setIndex,1)
			})*/
		});
	}
 });

})(jQuery);

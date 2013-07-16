(function(){
	$.fn.extend({
			/*set image to real wdth, .e.g. prevent the huge image to zoom in*/
			baseUrl:'/fte_demo',
			setRealWidth:function(){
				return this.each(function(){
					//get real width
					var id = $(this).attr('id');
					var screenImage = $(this).find('.ribbon-stuff');
					var theImage = new Image();
					theImage.src = screenImage.attr('src');
					
					var width = theImage.width;
					var height = theImage.height;
					//prepare layout
					var url = $(this).find('.ribbon-stuff').attr('src');
					$(this).find('.ribbon-stuff').remove();
					$(this).find('.ribbon-inner').css('width', 2*width + 'px').prepend('<div class="ribbon-frame f-a" id="' + id + '-a"></div><div class="ribbon-frame f-b" id="' + id + '-b"></div>');
					$(this).find('.ribbon-frame').css('width', width + 'px').css('height', height + 'px').css('background','url('+ url + ') no-repeat');
				});
			},
		
			/* ribbon */
			ribbon:function(options){
				var defaults = {
					direction : 'left',
					distance  : 1
				};
				var options = $.extend(defaults, options);
				return this.each(function(){
					
					var self = $(this);
					var wrapperWidth = self.width();
					if(options.direction === 'right'){
						self.find('.ribbon-inner').css('left', -(2*(self.find('.ribbon-frame').width()) - wrapperWidth) + 'px');
					}else{
						self.find('.ribbon-inner').css('left','0px');
					}
					
					//set animation
					function frameMove(speed,direction){
						if(self.hasClass('active')){
							var orginalLeft = parseInt(self.find('.ribbon-inner').css('left'),10);
							if(direction === 'left'){
								self.find('.ribbon-inner').css('left', orginalLeft - speed + 'px');
								var deviation = parseInt(self.find('.ribbon-inner').css('left'),10) + (2*(self.find('.ribbon-frame').width()) - wrapperWidth);
								if(deviation<=speed && deviation>=-speed){
									self.find('.ribbon-inner').css('left', -(self.find('.ribbon-frame').width() - wrapperWidth) + 'px' );
								}
							}
							if(direction === 'right'){
								self.find('.ribbon-inner').css('left', orginalLeft + speed + 'px');
								var deviation = parseInt(self.find('.ribbon-inner').css('left'),10);
								if(deviation<=speed && deviation>=-speed){
									self.find('.ribbon-inner').css('left', - self.find('.ribbon-frame').width() + 'px');
								}
							}
						}
					}
					
					var frameAnimation;
					var clicked = false;
					
					function startSlide(){
						var orginalX = 0;
						var currentX = 0;
						//var mouseDownFlag = false;
						frameAnimation = setInterval(function(){frameMove(options.distance,options.direction)},1);
						//drag to spped up or speed down and click / dbclick event 
						self.bind('mousedown', function(event){
							event.preventDefault(); //this is real important!
							orginalX = event.clientX;
						});
						var mouseUp = 0;
						var speed = options.distance;
						var direction = options.direction;
						self.bind('mouseup',function(event){
							currentX = event.clientX;
							if(currentX - orginalX>80 || currentX - orginalX < -80){
								//drag
								clearInterval(frameAnimation);
								if(currentX - orginalX>80 && direction === 'right'){
									speed +=1;
									direction = 'right';
								}
								if(currentX - orginalX<-80 && direction === 'left'){
									speed +=1;
									direction = 'left';
								}
								if(currentX - orginalX<-80 && direction === 'right'){
									direction = 'left';
									speed = options.distance;
								}
								if(currentX - orginalX>80 && direction === 'left'){
									direction = 'right';
									speed = options.distance;
								}
								frameAnimation = setInterval(function(){frameMove(speed,direction)},1);
								mouseUp = 0;
							}else{
								mouseUp++;
								if(mouseUp == 1){
									setTimeout(function(){
										if(mouseUp == 1){
											//single click
											clicked = true;
											clearInterval(frameAnimation);
											speed = options.distance;
											mouseUp = 0;
										}else{
											//double click remove db click function for now
											
											clicked = true;
											clearInterval(frameAnimation);
											speed = options.distance;
											mouseUp = 0;
											
										}
									},200)
								}
							}
						}); 
						
					}
					startSlide();
					
					self.bind('mouseover', function(){
						if(!$(this).hasClass('active')){
							$('.ribbon.active').removeClass('active');
							$(this).addClass('active');
							
							if(clicked){
								clearInterval(frameAnimation);
								frameAnimation = setInterval(function(){frameMove(options.distance,options.direction)},1);
							}	
						}
					});
					
					//music
					
					function playMusic(){
						
						//pause all ribbon music first
						$('.ribbon').each(function(){
							$(this).find('audio').each(
								function(){
									$(this).removeClass('active-audio');
									$(this).get(0).pause();
								}
							);
						});
						
						$(this).find('audio').eq(0).addClass('active-audio');
						$(this).find('audio.active-audio').get(0).play();
						
						
						/* listen the moving mouse over times and set the correspoding audio to play,
						var times = parseInt($(this).attr('data-times'),10);
						times += 1;
						$(this).attr('data-times', times.toString());
						if(times <= 1){
							$(this).find('audio').eq(0).addClass('active-audio');
							$(this).find('audio').eq(1).removeClass('active-audio');
						}else{
							$(this).find('audio').eq(1).addClass('active-audio');
							$(this).find('audio').eq(0).removeClass('active-audio');
						}
						$(this).find('audio.active-audio').get(0).play();*/
						
					}
					self.bind('mouseover.playMusic', playMusic);
					
					
					$('.sound-controller').bind('click', function(){
						
						if(!$(this).hasClass('active')){
							$(this).addClass('active');
							$('.ribbon').each(function(){
								
								$(this).find('audio').get(0).pause();
								$(this).find('audio').get(1).pause();
							});
							$('.ribbon').unbind('mouseover.playMusic');
						}else{
							$(this).removeClass('active');
							$('.ribbon.active').find('audio.active-audio').get(0).play();
							$('.ribbon').bind('mouseover.playMusic', playMusic);
						}
					});
					
				});
			},
			
			/*hot spot*/
			hotSpot : function(options){
				var defaults = {
					url:''
				};
				var options = $.extend(defaults, options);
				
				return this.each(function(){
					var self = $(this);
					var idx = self.index();
					$.ajax({
						url      : options.url,
						dataType : JSON,
						type     : 'GET',
						success  :function(data){
							var data = eval('(' + data + ')');
							drawHotSpots(data);
						}
					});
					function drawHotSpots(data){
						
						self.find('.ribbon-frame').each(function(){
							  var id = $(this).attr('id');
							  var w = $(this).width();
							  var h = $(this).height();
							  var stage = new Kinetic.Stage({
						        container: id,
						        width: w,
						        height: h
						      });
						      var layer = new Kinetic.Layer();
						      layer.on('mouseover', function(evt) {
						        $('.ribbon').css('cursor','pointer');
						        var shape = evt.targetNode;
								shape.setFill('rgba(3,150,83,0.0)');
								layer.draw();
						      });
							  layer.on('mouseout', function(evt) {
						        $('.ribbon').css('cursor','');
						        var shape = evt.targetNode;
						        
								shape.setFill('rgba(3,150,83,0.0)');
								layer.draw();
						      });
						      layer.on('dblclick', function(evt) {
						      	$('.vertical-column-cover').css('height', $('body').height()+32 + 'px');
						      	$('.vertical-column-cover').show();
						        $('.pop-up, .pop-up-inner').removeClass('small-video').removeClass('big-video');
						        $('.pop-up').css({
										'width' : '660px',
										'height':'500px'
									});
						        var shape = evt.targetNode;
						        var left = ($(document).width()-680)/2 + 'px';
								var top = ($(window).height()-500)/2;
								
								function audioFadeOut(){
									
									$('audio.active-audio').animate({
										volume : 0
									},1000);
								}
								
								audioFadeOut();
									
								
								
								if(shape.getName().indexOf('small-video') != -1){
									$('.pop-up, .pop-up-inner').addClass('small-video');
									left = ($(document).width()-570)/2 + 'px';
									top = ($(window).height()-350)/2;
									$('.pop-up').css({
										'width' : '570px',
										'height':  '350px'
									});
									audioFadeOut();
								};
								
								if(shape.getName().indexOf('big-video') != -1){
									$('.pop-up, .pop-up-inner').addClass('big-video');
									left = '0px';
									top = 0;
									$('.pop-up.big-video').css({
										'width' : $(document).width() + 'px',
										'height': $(document).height() + 'px'
									});
									audioFadeOut();
								};
								$('.pop-up .pop-up-inner').html('<span class="close">X</span>' + shape.getName());
								$('.pop-up').css({'left':left,'top':$(window).scrollTop() + top + 'px'}).fadeIn(500); 
						      });
							  var star = [];
							 
							  for(var i=0; i<data.hotSpot.length; i++){
							  	 var p = data.hotSpot[i].points;
							  	 var text = data.hotSpot[i].popupHtml;
							  	 
							  	 var shape = new Kinetic.Blob({
							  	 	points: p,
							  	 	//stroke: 'white',
							        //strokeWidth: 4,
							        fill: 'rgba(3,150,83,0.0)',
							        
							        tension: 0,
							        name :text
							  	 });
							  	 layer.add(shape);
							   }
							   stage.add(layer);
							  
						});
					}
					
					
					
				})
			},
			/*overlay: function(options){
				var defaults = {
					bgColor : 'rgba(5,147,194,0.5)'
				};
				var options = $.extend(defaults, options);
				return this.each(function(){
					var width = $(document).width();
					var height = $(document).height();
					console.log(height);
					var overlay = '<div class="ribbon-overlay"><div class="overlay-inner"><span class="start">Let us start!</span></div></div>';
					$(this).append(overlay);
					$('.ribbon-overlay').css({
						'height' : height + 'px',
						'width'  : width + 'px',
						'background': options.bgColor,
						'opacity' : options.opacity,
						'position': 'absolute',
						'top' : '0',
						'left' : '0',
						'zIndex': '9'
					});
					
					
				});
			},
			overLayText: function(options){
				var defaults = {
					question : 'default question',
					answer: 'default Answer',
					time : 2000
				};
				var options = $.extend(defaults, options);
				var textCount = options.textCount;
				return this.each(function(){
					
					var textCount = $('.ribbon-overlay .overlay-inner').find('.overlay-text').length || 0;
					$('.ribbon-overlay .overlay-inner').append('<div class="overlay-text"><p class="text-' + textCount +'"></p></div>');
					
					$('.text-'+textCount).text(options.question);
					function changeText(){
						if($('.text-'+textCount).text().trim() === options.question.trim()){
							$('.text-'+textCount).text(options.answer.trim());
						}else{
							$('.text-'+textCount).text(options.question.trim());
						}
					}
					var textClock = setInterval(function(){changeText();},options.time);
					$('.text-'+textCount).hover(
						function(){
							clearInterval(textClock);
							$(this).text(options.answer.trim());
						},
						function(){
							textClock = setInterval(function(){changeText();},options.time);
						}
					);
				});
			},
			flyQuestions: function(options){
				var defaults = {
					data : [
						{
							question : 'Question1',
							answer   : 'Answer1'
						},
						{
							question : 'Question2',
							answer   : 'Answer2'
						}
					],
					time : 2000,
					top  : 200,
					left : 150 
					
				};
				var options = $.extend(defaults, options);
				return this.each(function(){
					var cw = $(window).width();
					var ch = $(window).height();
					var l;
					var t;
					if(cw > 780){
						le = cw-350;
					}else{
						le = 450
					}
					if(ch <1350){
						t = ch + 200
					}else{
						t = 800
					}
					for(var i=0; i<options.data.length; i++){
						$('body').append('<div class="flying-text fly-question-' + i + '">' + options.data[i].question + '</div><div class="flying-text fly-answer-' + i +'">' + options.data[i].answer + '</div>' );
					}
					$('.fly-question-0').css({
						'top' : options.top +  'px',
						'left': options.left + 'px'
					});
					$('.fly-question-1').css({
						'top' : options.top + 100 + 'px',
						'left': le + 'px'
					});
					$('.fly-answer-0').css({
						'top' : t + 'px',
						'left': options.left + 'px'
					});
					$('.fly-answer-1').css({
						'top' : t + 100 + 'px',
						'left': le + 'px'
					});
					$('.fly-question-0, .fly-question-1').bind('click', function(){
						var top = parseInt($(this).css('top'),10);
						//window.scrollTo(0, t + top)
						$('body,html').animate({
							scrollTop: t+top
						},800);
						return false;
					})
				});
			},
			*/
			bigText: function(options){
				var defaults = {
					textArray   : ['A','B','C','D'],
					beginNumber : 0
				}
				var options = $.extend(defaults, options);
				return this.each(function(){
					var j = options.beginNumber;
					var ln = options.textArray.length-1;
					$('.big-text').html(options.textArray[j]);
					var w  = $('.big-text').width();
					var h  = $('.big-text').height();
					var sw = $(window).width();
					var sh = $(window).height();
					var st = $(window).scrollTop();
					var sl = $(window).scrollLeft();
					$(window).scroll(function(){
						st = $(window).scrollTop();
						sl = $(window).scrollLeft();
					});
					$('.big-text').css({
						top  : (sh-h)*Math.random() + st + 'px',
						left : (sw-w)*Math.random() + sl + 'px'
					});
					function textTimer(){
						if(j < ln){
							j+=1;
							$('.big-text').html(options.textArray[j]);
						}else{
							j=0;
							$('.big-text').html(options.textArray[0]);
						}
						
						$('.big-text').css({
							top : (sh-h)*Math.random() + st + 'px',
							left : (sw-w)*Math.random() + sl + 'px'
						});
					}
					window.setInterval(textTimer, 2000);
				})
			},
			getCentralPosition: function(){
				return this.each(function(){
					var w = $(this).width();
					var h = $(this).height();
					var sw = $(window).width();
					var sh = $(window).height();
					var st = $(window).scrollTop();
					var sl = $(window).scrollLeft();
					$(this).css({
						'top' : st + (sh - h)/2 + 'px',
						'left': sl + (sw - w)/2 + 'px'
					})
				});
			},
			mainTabs: function(options){
				var defaults= {
					handler : 'li>a'
				}
				var options = $.extend(defaults, options);
				var self = $(this);
				return this.each(function(){
					$(this).find(options.handler).bind('click', function(){
						
						self.find(options.handler + '.active').removeClass('active');
						$(this).addClass('active');
						//example
						$('.page p').html('This is the ' + $(this).text() + ' content.' );
					})
				});
			},
			pageDrag: function(options){
				var defaults = {
					zoomHandler : '.page-drag',
					moveHandler : '.page-controller',
					zoomFlag    : false,
					dragFlag    : false,
					zoomFlagBr  : false,
					orginalX    : 0,
					orginalY    : 0,
					currentX    : 0,
					currentY    : 0,
					orginalLeft : 0,
					orginalTop  : 0,
					orginalWidth: 0,
					orginalHeight:0,
					initialWidth : '1060',
					initialHeight: '550'
					 
				}
				var options = $.extend(defaults,options);
				return this.each(function(){
					var self = $(this);
					$(this).bind('mousedown', function(event){
						event.preventDefault();
						options.orginalX = event.clientX;
						options.orginalY = event.clientY;
						options.orginalLeft = parseInt($(this).css('left'),10);
						options.orginalTop =  parseInt($(this).css('top'),10);
						options.orginalWidth = $(this).width();
						options.orginalHeight = $(this).height();
						if($(event.target).hasClass('page-controller')){
							options.dragFlag = true;
						}
						if($(event.target).hasClass('page-drag')){
							options.zoomFlag = true;
						}
						if($(event.target).hasClass('page-zoom-br')){
							options.zoomFlagBr = true;
						}
					});
					$(window).bind('mousemove', function(event){
						options.currentX = event.clientX;
						options.currentY = event.clientY;
						var currentLeft = options.currentX - options.orginalX + options.orginalLeft;
						var currentTop  = options.currentY - options.orginalY + options.orginalTop;
						
						var currentWidth = options.orginalX - options.currentX + options.orginalWidth;
						var currentHeight= options.orginalY - options.currentY + options.orginalHeight;
						var currentBrwidth = options.currentX  - options.orginalX  + options.orginalWidth;
						var currentBrHeight = options.currentY - options.orginalY + options.orginalHeight;
						
						if( currentLeft < 0 ){
							currentLeft = 0
						}
						function setIframeWidth(width){
							$('.landing-iframe, .iframe-cover').css({
								'width' : width-2 + 'px'
							});
						}
						function setIframeHeight(height){
							$('.landing-iframe, .iframe-cover').css({
								'height': height-54+'px'
							});
						}
						//move
						if(options.dragFlag){
							$('.iframe-cover').show();
							if(currentLeft > 0 && currentLeft + self.width() < $(window).width()){
								self.css({
									'left' : currentLeft + 'px'
								})
							}
							if(currentTop > $(window).scrollTop() && currentTop - $(window).scrollTop() + self.height() < $(window).height()){
								self.css({
									'top' : currentTop + 'px'
								})
							}
						}
						//zoom lt
						if(options.zoomFlag){
							$('.iframe-cover').show();
							if(currentWidth > options.initialWidth && options.currentX > 0){
								self.css({
									'width' : currentWidth + 'px',
									'left'  : currentLeft + 'px'
								})
								//$('.page-move').css('width', currentWidth -82 + 'px');
								setIframeWidth(currentWidth);
							}
							if(currentHeight > options.initialHeight && options.currentY > 0){
								self.css({
									'height' : currentHeight + 'px',
									'top'  : currentTop + 'px'
								})
								setIframeHeight(currentHeight);
							}
						}
						//zoom br
						if(options.zoomFlagBr){
							$('.iframe-cover').show();
							if(currentBrwidth > options.initialWidth && options.currentX < $(window).width()){
								self.css({
									'width' : currentBrwidth + 'px'
									
								})
								//$('.page-move').css('width', currentBrwidth -82 + 'px');
								setIframeWidth(currentBrwidth);
							}
							if(currentBrHeight > options.initialHeight && options.currentY < $(window).width()){
								self.css({
									'height' : currentBrHeight -10 + 'px'
								});
								setIframeHeight(currentBrHeight);
							}
						}
						
					});
					$(window).bind('mouseup', function(){
						options.dragFlag = false;
						options.zoomFlag = false;
						options.zoomFlagBr = false;
						$('.iframe-cover').hide();
					});
					$('.iframe-cover').bind('mouseup',function(){
						$(this).hide();
					})
				})
			},
			setIfranmeUrl : function(){
				$.ajax({
					url      : baseUrl + '/fteuserlogon',
					dataType : 'text',
					type     : 'GET',
					success  :function(data){
						if(data === '0'){
							$('.landing-iframe').attr('src',baseUrl + '/user')
						}
					}
				});
			}
			

		});
})(jQuery);
$(window).load(function(){
	//big text
	$('body').bigText({
		textArray : ['Where do you want to go today?','What do you want to dream today?','What change do you want to make today?','What do you want to do today?'] 
	});
	//$('.big-text').getCentralPosition();
	//get realwidth
	$('.ribbon').setRealWidth();
	
	//make ribbon
	$('.ribbon').eq(0).addClass('active').find('audio.active-audio').get(0).play();
	//$('.ribbon').eq(1).addClass('active');
	//$('.ribbon').eq(2).addClass('active');
	$('.ribbon').eq(0).ribbon({
		direction : 'left',
		distance  : 1
	});
	$('.ribbon').eq(1).ribbon({
		direction : 'right',
		distance  : 1
	});
	$('.ribbon').eq(2).ribbon({
		direction : 'left',
		distance  : 1
	});
	$('.ribbon').eq(3).ribbon({
		direction : 'right',
		distance  : 1
	});
	$('.ribbon').eq(4).ribbon({
		direction : 'left',
		distance  : 1
	});
	//add hot spot ---------I don't know why make the hot spots invisible but I do it
	$('.ribbon').eq(0).hotSpot({
		url:'hotspot.asp?123'
	});
	$('.ribbon').eq(1).hotSpot({
		url:'hotspot1.asp?123'
	});
	$('.ribbon').eq(2).hotSpot({
		url:'hotspot2.asp?123'
	});
	$('.ribbon').eq(3).hotSpot({
		url:'hotspot1.asp?123'
	});
	$('.ribbon').eq(4).hotSpot({
		url:'hotspot2.asp?123'
	});
	
	//popup close function
	$('.pop-up').delegate('span.close','click',function(event){
			$('.pop-up').fadeOut(500);
			$('.pop-up-inner').find('iframe').remove();
			$('.vertical-column-cover').hide();
			$('audio.active-audio').animate({
				volume : 1
			},1000);
			//$('.active-audio').get(0).play();
	})
	
	
	//add overlay
	//$('body').overlay({});
	
	//overlay close function 
	/*$('.overlay-inner .start').bind('click', function(){
		$('.ribbon').not($('.active')[0]).removeClass('active');
		$(this).parents('.ribbon-overlay').fadeOut(500);
	})
	
	
	$('body').overLayText({
		question : 'Question 1',
		answer   : 'Answer1',
		time     : 1500
	}).overLayText({
		question : 'Question 2',
		answer   : 'Answer 2'
	}).overLayText({
		question : 'Question 3',
		answer   : 'Answer 3',
		time     : 2500
	});*/
	
	/*flyQuestions
	$('html').flyQuestions({
		
	});*/
	
	//cube and content
	function makePageDefault(){
		$('.page').css('top', ($(window).height() - 550)/2 + $(window).scrollTop()  + 'px');
		$('.page').css('left', ($(window).width() - 1060)/2   + 'px');
		$('.page').css('width', '1060px');
		$('.page').css('height','550px');
		$('.landing-iframe').css({
			'width': '1058px',
			'height' : '506px'
		})
		$('.page').removeClass('max');
		$('.page-maximize').attr('title','maximize');
		//$('.page-move').css('width', $('.page').width() -82 + 'px');
		$('.iframe-cover').hide();
	}
	makePageDefault();
	function videoStop(){
		if(typeof(fteFrame.window.ytplayer)!= undefined){
			fteFrame.window.ytplayer.stopVideo();
			//$('.landing-iframe').contents().find('#myytplayer').hide();
			clearInterval(videoTimer);
		}
	}
	var videoTimer = setInterval(videoStop, 500);
	
	
	$('.main-nav').mainTabs();
	$('.cube').bind('click', function(){
		
		if($('.page').css('display')!='none'){
			clearInterval(videoTimer);
			var videoTimer = setInterval(videoStop, 500);
		}else{
			//$('.landing-iframe').contents().find('#myytplayer').show();
		}
		
		
		$.ajax({
					url      : baseUrl + '/fteuserlogon',
					dataType : 'html',
					type     : 'GET',
					success  :function(data){
						if(data === '0'){
							$('.landing-iframe').attr('src',baseUrl + '/user')
						}
						makePageDefault();
						$('.page').toggle(400);
						$('.cover').toggle();
						$('.ribbon.active').removeClass('active').find('audio').get(0).pause();
						$('.landing-iframe').contents().find('#myytplayer').show();
					}
				});
		
		
		
		//$('.sound-controller').toggle();
	})
	$(window).scroll(function(){
		$('.page').css('top', ($(window).height() - $('.page').height())/2 + $(window).scrollTop()  + 'px');
		//$('.big-text').getCentralPosition();
	});
	
	$('.page-minimize').bind('click', function(){
		$('.page,.cover').hide(400);
		makePageDefault();
		clearInterval(videoTimer);
		var videoTimer = setInterval(videoStop, 500);
		//$('.landing-iframe').contents().find('#myytplayer').hide();
		
	});
	$('.cover').css({
		height: $('body').height() + 32 + 'px',
		width: $(window).width() + 'px'
	});
	function pageToggleSize(){
		if(!$('.page').hasClass('max')){
	 		$('.landing-iframe').animate({
		 		width : $(window).width()-2 + 'px',
		 		height : $(window).height()-54 + 'px'
		 	},400);
		 	$('.page').animate({
				top: $(window).scrollTop()  + 'px',
				left :0,
				width : $(window).width() + 'px',
				height : $(window).height() + 'px'
			},400,
			function(){
				$('.page').addClass('max');
				//$('.page-move').css('width', $('.page').width() -82 + 'px');
			});
			$('.page-maximize').attr('title','minimize');
	 }else{
	 	$('.landing-iframe').animate({
	 		width : '1058px',
	 		height : '506px'
	 	},400);
	 	$('.page').animate({
			top: ($(window).height() - 550)/2 + $(window).scrollTop()  + 'px',
			left :($(window).width() - 1060)/2   + 'px',
			width : '1060px',
			height : '550px'
		},400,
		function(){
			$('.page').removeClass('max');
			//$('.page-move').css('width', $('.page').width() -82 + 'px');
		});
		$('.page-maximize').attr('title','maximize');
	 }
	}
	$('.page-maximize').bind('click', function(){
	 	pageToggleSize();
	});
	$('.page-controller').bind('dblclick', function(){
		pageToggleSize();
	})
	
	$('.page').pageDrag();
	
	//ajax for user/anonymity
	//$.fn.setIfranmeUrl();
});

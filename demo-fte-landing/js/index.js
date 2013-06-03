(function(){
	$.fn.extend({
			/*set image to real wdth, .e.g. prevent the huge image to zoom in*/
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
						       
								shape.setFill('rgba(3,150,83,0.8)');
								layer.draw();
						      });
							  layer.on('mouseout', function(evt) {
						        $('.ribbon').css('cursor','');
						        var shape = evt.targetNode;
						        
								shape.setFill('rgba(3,150,83,0.4)');
								layer.draw();
						      });
						      layer.on('dblclick', function(evt) {
						       
						        var shape = evt.targetNode;
						        var left = ($(document).width()-450)/2 + 'px';
								var top = ($(window).height()-550)/2;
								$('.pop-up .pop-up-inner').html(shape.getName());
								$('.pop-up').css({'left':left,'top':$(window).scrollTop() + top + 'px'}).fadeIn(500); 
						      });
							  var star = [];
							 
							  for(var i=0; i<data.hotSpot.length; i++){
							  	 var p = data.hotSpot[i].points;
							  	 var text = data.hotSpot[i].popupHtml;
							  	 
							  	 var shape = new Kinetic.Blob({
							  	 	points: p,
							  	 	stroke: 'white',
							        strokeWidth: 4,
							        fill: 'rgba(3,150,83,0.4)',
							        
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
			},*/
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
			mainTabs: function(options){
				var defaults= {
					handler : 'li>a'
				}
				var options = $.extend(defaults, options);
				var self = $(this);
				return this.each(function(){
					$(this).find(options.handler).not('.active').bind('click', function(){
						
						self.find(options.handler + '.active').removeClass('active');
						$(this).addClass('active');
						//example
						$('.page p').html('This is the ' + $(this).text() + ' content.' );
					})
				});
			}
			

		});
})(jQuery);
$(window).load(function(){
	//get realwidth
	$('.ribbon').setRealWidth();
	
	//make ribbon
	$('.ribbon').eq(0).addClass('active');
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
	
	//add hot spot
	$('.ribbon').eq(0).hotSpot({
		url:'hotspot.asp'
	});
	$('.ribbon').eq(1).hotSpot({
		url:'hotspot1.asp'
	});
	$('.ribbon').eq(2).hotSpot({
		url:'hotspot2.asp'
	});
	
	//popup close function
	$('span.close').bind('click', function(){
		$('.pop-up').fadeOut(500);
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
	
	//flyQuestions
	$('html').flyQuestions({
		
	});
	
	//cube and content
	
	$('.main-nav').mainTabs();
	$('.cube').bind('click', function(){
		$('.page').css('top', $(window).height()  + $(window).scrollTop() - 300 + 'px');
		
		if($('.page').hasClass('show')){
			$('.page').removeClass('show');
		}else{
			$('.page').addClass('show');
		}
	})
	$(window).scroll(function(){
		$('.page').css('top', $(window).height()  + $(window).scrollTop() - 300 + 'px');
	});
});

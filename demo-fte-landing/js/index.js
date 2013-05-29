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
					url : 'string'
				};
				var options = $.extend(defaults, options);
				var self = this;
				$.ajax({
					url  : options.url,
					dataType : JSON,
					type     : 'GET',
					success   : function(data){
						data = eval('(' + data + ')')
						var hotSpots = data.hotSpot;
						return self.each(function(){
							$(this).find('.ribbon-frame').each(function(){
								var self = $(this);
								var width = self.width();
								var height = self.height();
								var rid = self.attr('id');
								
								var stage = new Kinetic.Stage({
									container : rid,
									width     : width,
									height    : height
								});
								var layer;
								var shape = [];
								for(var i=0; i<hotSpots.length; i++){
									
									var position = hotSpots[i].position;
									var html = hotSpots[i].popupHtml;
									
									layer = new Kinetic.Layer();
									shape[i] = new Kinetic.Shape({
										drawFunc : function(canvas){
											var context = canvas.getContext();
											context.beginPath();
								            context.moveTo(position[0][0],position[0][1]);
								            for(var j=1; j<position.length; j++){
								            	context.lineTo(position[j][0], position[j][1]);
								            }
								            context.closePath();
								            canvas.fillStroke(this);
										},
										fill : '#32dfbf',
										stroke : 'white',
										strokeWidth : 3,
										opacity : 0.2,
										id : rid+i,
										name : html
									});
									
									
									
									
									shape[i].on('mouseover touchstart', function(){
										
										$('.ribbon').css('cursor','pointer');
										this.setOpacity(0.6);
										layer.draw();
									});
									shape[i].on('mouseout touchend', function(){
										
										$('.ribbon').css('cursor','');
										this.setOpacity(0.2);
										layer.draw();
									});
									shape[i].on('dblclick', function(){
										
										var left = ($(document).width()-450)/2 + 'px';
										var top = ($(window).height()-550)/2;
										$('.pop-up .pop-up-inner').html(this.getName());
										$('.pop-up').css({'left':left,'top':$(window).scrollTop() + top + 'px'}).fadeIn(500);
			
									});
									layer.add(shape[i]);
									 
								}
								for(var i=0; i<shape.length; i++){
									layer.add(shape[i]);
								}
								
								stage.add(layer);
							});
							
						})
					}
				})
				
				
			},
			overlay: function(options){
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
			}
			

		});
})(jQuery);
$(window).load(function(){
	//get realwidth
	$('.ribbon').setRealWidth();
	
	//make ribbon
	$('.ribbon').eq(0).addClass('active');
	$('.ribbon').eq(1).addClass('active');
	$('.ribbon').eq(2).addClass('active');
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
	$('body').overlay({
		
	});
	
	//overlay close function 
	$('.overlay-inner .start').bind('click', function(){
		$('.ribbon').not($('.active')[0]).removeClass('active');
		$(this).parents('.ribbon-overlay').fadeOut(500);
	})
	
	//add overlay text
	$('body').overLayText({
		question : 'Can you take me together to the Mars?',
		answer   : 'Sure! no problem! You are welcome!',
		time     : 1500
	}).overLayText({
		question : 'Are you Tom?',
		answer   : 'No, my name is Jack.'
	}).overLayText({
		question : 'Are you married?',
		answer   : 'yes, that is many years ago.',
		time     : 2500
	});
});

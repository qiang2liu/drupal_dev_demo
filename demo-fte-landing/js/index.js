(function(){
	$.fn.extend(
		/* ribbon */
		{
			ribbon:function(options){
				var defaults = {
					direction : 'left',
					distance  : 1
				};
				var options = $.extend(defaults, options);
				
				return this.each(function(){
					//prepare layout
					var copy = $(this).find('.ribbon-stuff').clone();
					$(this).find('.ribbon-stuff').remove();
					$(this).find('.ribbon-inner').prepend('<div class="ribbon-frame f-a"></div><div class="ribbon-frame f-b"></div>');
					$(this).find('.ribbon-frame').append(copy);
					var mouseDownFlag = false;
					var orginalX = 0;
					var currentX = 0;
					var self = $(this);
					var wrapperWidth = self.width();
					if(options.direction === 'right'){
						self.find('.ribbon-inner').css('left', -(2*($('.ribbon-frame').width()) - wrapperWidth) + 'px');
					}else{
						self.find('.ribbon-inner').css('left','0px');
					}
					
					//set animation
					function frameMove(speed,direction){
						
						if(direction === 'left'){
							var orginalLeft = parseInt(self.find('.ribbon-inner').css('left'),10);
							self.find('.ribbon-inner').css('left', orginalLeft - speed + 'px');
							var deviation = parseInt(self.find('.ribbon-inner').css('left'),10) + (2*($('.ribbon-frame').width()) - wrapperWidth);
							if(deviation<=speed && deviation>=-speed){
								self.find('.ribbon-inner').css('left', -($('.ribbon-frame').width() - wrapperWidth) + 'px' );
							}
						}
						if(direction === 'right'){
							var orginalLeft = parseInt(self.find('.ribbon-inner').css('left'),10);
							self.find('.ribbon-inner').css('left', orginalLeft + speed + 'px');
							var deviation = parseInt(self.find('.ribbon-inner').css('left'),10);
							if(deviation<=speed && deviation>=-speed){
								self.find('.ribbon-inner').css('left', - $('.ribbon-frame').width() + 'px');
							}
						}
					}
					var frameAnimation = setInterval(function(){frameMove(options.distance,options.direction)},1);
					
					
					//drag to spped up or speed down
					self.bind('mousedown', function(event){
						event.preventDefault(); //this is real important!
						orginalX = event.clientX;
						mouseDownFlag = true;
					});
					self.bind('mousemove', function(event){
						//now we know it's a drag but not a click
						if(mouseDownFlag){
							currentX = event.clientX;
						}
						
					});
					var mouseUp = 0;
					var speed = options.distance;
					var direction = options.direction;
					self.bind('mouseup',function(event){
						
						if(currentX - orginalX>20 || currentX - orginalX < -20){
							//drag
							clearInterval(frameAnimation);
							if(currentX - orginalX>20 && direction === 'left'){
								speed +=1;
								direction = 'left';
							}
							if(currentX - orginalX<-20 && direction === 'right'){
								speed +=1;
								direction = 'right';
							}
							if(currentX - orginalX<-20 && direction === 'left'){
								direction = 'right';
								speed = options.distance;
							}
							if(currentX - orginalX>20 && direction === 'right'){
								direction = 'left';
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
										clearInterval(frameAnimation);
										speed = options.distance;
										mouseUp = 0;
									}else{
										//double click
										var left = ($(document).width()-450)/2 + 'px'
										$('.pop-up').css('left',left).fadeIn(500);
										$('span.close').bind('click', function(){
											$('.pop-up').fadeOut(500);
										})
										mouseUp = 0;
									}
								},200)
							}
						}
					}); 
					
					
				});
			}

		}
	);
})(jQuery);
$(document).ready(function(){
	$('.ribbon').ribbon({
		direction : 'right',
		distance  : 1
	});
});

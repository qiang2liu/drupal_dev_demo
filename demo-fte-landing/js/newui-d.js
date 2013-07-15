(function(){
	$.fn.extend({
		slidingPane: function(options){
			var defaults = {
				direction : 'left'
			};
			var options = $.extend(defaults,options);
			return this.each(function(){
				var distance = $(this).parent().width()-14;
				var disranceVertical = $(this).parent().height()-$(this).siblings('h4').height()-14;
				var height = $(this).height();
				var controller = $(this).find('.nd-slide-controller');
				var originalGap = 0;
				if(options.direction == 'left' || options.direction == 'right'){
					controller.css('height', height + 'px');
				}
				
				if(options.direction == 'left'){
					$(this).css('left', -distance + 'px');
					originalGap = -distance;
				};
				if(options.direction == 'right'){
					$(this).css('left', distance + 'px');
					originalGap = distance;
				};
				if(options.direction == 'bottom'){
					$(this).parent().css('top', disranceVertical + 'px');
					originalGap = disranceVertical;
				};
				if(options.direction == 'left' || options.direction == 'right'){
					controller.bind('click', function(){
						var parent = $(this).parent();
						if(!parent.hasClass('active')){
							parent.animate(
								{'left': 0},
								500,
								function(){
									parent.addClass('active');
								}
							)
						}else{
							parent.animate(
								{'left': originalGap + 'px'},
								500,
								function(){
									parent.removeClass('active');
								}
							)
						}
					})
				}
				if(options.direction == 'bottom'){
					controller.bind('click', function(){
						var parent = $(this).parents('.vertical-sliding-box');
						if(!parent.hasClass('active')){
							parent.animate(
								{'top': 0},
								500,
								function(){
									parent.addClass('active');
								}
							)
						}else{
							parent.animate(
								{'top': originalGap + 'px'},
								500,
								function(){
									parent.removeClass('active');
								}
							)
						}
					})
				}
					
			});
		}
	});
})(jQuery);
$(window).load(function(){
	$('body').css('height', $('html').height() - 20 + 'px');
	$('.nd-slide-box-r').slidingPane({
		direction: 'right'
	});
	$('.nd-slide-box-l').slidingPane();
	$('.nd-slide-box-b').slidingPane({
		direction: 'bottom'
	});
});

(function($){
	//libs
	(function($){
		$.fn.extend({
			setCommunity : function(options){
				var defaults = {
					topDistance: '-790px'
				}
				var options = $.extend(defaults,options);
				return this.each(function(){
					var self = $(this);
					//self.css('top', options.topDistance);
					self.find('.indicator span').hover(
						function(){
							self.addClass('flash');
						},
						function(){
							self.removeClass('flash');
						}
					);
					self.find('.indicator span').bind('click', function(){
						self.toggleClass('active');
					})
				});
			}
		});
	})(jQuery);
	
	//load
	$(document).ready(function(){
		$('.community').setCommunity();
	});
})(jQuery);

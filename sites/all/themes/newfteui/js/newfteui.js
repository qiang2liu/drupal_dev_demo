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
					
					/*self.find('.indicator span').hover(
						function(){
							self.addClass('flash');
						},
						function(){
							self.removeClass('flash');
						}
					);*/
					self.find('.indicator span').bind('click', function(){
						
						$('div').not(self).not('.toolbar-handler').not('.toolbar-box').removeClass('active');
						self.toggleClass('active');
						$('.pane-handler').css('width','').removeClass('current');
						$('.pane').removeClass('show').css('right','-760px');
					})
				});
			},
			makePaneNormal: function(){
				$('.pane-handler').css('width','').removeClass('current');
				$('.pane').removeClass('show').css('right','-760px');
			},
			setPositionofElements : function(){
				var space = ($(window).width() - 760)/2;
				// set
				$('.main-content').css({
					'left': space + 'px'
				});
				
				//pane
				
				$('.pane-handler').bind('click',function(){
					$('.pane-handler').not($(this)).removeClass('current').css('width','');
					$(this).toggleClass('current')
					
					var id = $(this).attr('data-aim');
					$('.pane').not('#'+ id).removeClass('show').css('right','');
					
					if($('#'+ id).hasClass('show')){
						$('#'+ id).removeClass('show').css('right','');
					}else{
						$('#'+ id).css('right','').addClass('show').css('right', space + 'px' );
					}
				});
				$('.pane-handler').hover(
					function(){
						$(this).css('width',space+'px');
					},
					function(){
						if(!$(this).hasClass('active')){
							$(this).css('width','');
						}
						
					}
				);
			},
			toggleToolbar: function(){
				$('.toolbar-handler, .toolbar-box').toggleClass('active');
			},
			removeAllActive : function(){
				$('div').not('.toolbar-handler').not('.toolbar-box').not(this).removeClass('active');
				$(this).toggleClass('active');
				
			}
		});
	})(jQuery);
	
	//load
	$(document).ready(function(){
		//set position
		$.fn.setPositionofElements();
		$('.community').setCommunity();
		$('.toolbar-handler').bind('click', $.fn.toggleToolbar);
		
		$('.stage-selector-handler>em').bind('click', function(){
			$.fn.removeAllActive.call($('.stage-selector'));
			$.fn.makePaneNormal();
		});
		
		
		//user-profile
		$('.user-profile-inner').bind('click', function(){
			$.fn.removeAllActive.call($('.user-profile'));
			$.fn.makePaneNormal();
		});
		
		$('.pane-handler').bind('click',function(){
			$.fn.removeAllActive.call(this);
		});
		
	});
})(jQuery);

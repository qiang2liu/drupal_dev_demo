(function($){
	//libs
	(function($){
		$.fn.extend({
			setCommunity : function(options){
				var defaults = {
					topDistance: '-700px'
				}
				var options = $.extend(defaults,options);
				return this.each(function(){
					var self = $(this);
					self.find('.indicator span').bind('click', function(){
						$('div').not(self).not('.toolbar-handler').not('.toolbar-box').removeClass('active');
						self.toggleClass('active');
						$('.pane').removeClass('show');
					})
				});
			},
			setPositionofElements : function(){
				var space = ($(window).width() - $('.main-content').width())/2;
				// Desitination
				$('.main-content').css({
					'left': space + 'px'
				});	
			},
			makePaneNormal: function(){
				$('.pane-handler').removeClass('active');
				$('.pane').removeClass('show');
			},
			toggleToolbar: function(){
				$('.toolbar-handler, .toolbar-box').toggleClass('active');
			},
			removeAllActive : function(){
				$('div').not('.toolbar-handler').not('.toolbar-box').not(this).removeClass('active');
				$(this).toggleClass('active');
			}/*,
			navToggleList: function(){
				return this.each(function(){
					var self = $(this);
					var h = self.find('h4');
					if(h.hasClass('has-child')){
						
						h.find('em').bind('click', function(){
							self.find('.item-list').toggle();
						})
					}
				});
				
			}*/
		});
	})(jQuery);
	
	//load
	$(document).ready(function(){
		
		//set position
		$.fn.setPositionofElements();
		$('.community').setCommunity();
		
		//when window resize, we use this again
		$(window).resize(function(){
			$.fn.setPositionofElements();
		});
		
		//toolbar
		$('.toolbar-handler').bind('click', $.fn.toggleToolbar);
		//toolbar item expand/collapse
		//$('.mural').navToggleList();
		
		//stage selector
		$('.stage-selector-handler>em').bind('click', function(){
			$.fn.removeAllActive.call($('.stage-selector'));
			$.fn.makePaneNormal();
		});
		
		
		//user-profile
		$('.user-profile-inner').bind('click', function(){
			$.fn.removeAllActive.call($('.user-profile'));
			$.fn.makePaneNormal();
		});
		
		//pane
		$('.pane-handler').bind('click',function(){
			$.fn.removeAllActive.call(this);
			var id = $(this).attr('data-aim');
			$('.pane').not('#'+ id).removeClass('show');
			
			if($('#'+ id).hasClass('show')){
				$('#'+ id).removeClass('show');
			}else{
				$('#'+ id).css('right','').addClass('show');
			}
		});
		//pane switch
		$('.pane-tab').bind('click', function(){
			if(!$(this).hasClass('active')){
				$('.pane-tab').removeClass('active');
				$(this).addClass('active');
				var idx = $(this).index('.pane-tab');
				$('.pane-con').hide();
				$('.pane-con').eq(idx).show();
			}
		});
		
	});
})(jQuery);

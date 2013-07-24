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
						$('.pane').removeClass('show');
						$('div').not(self).not('.toolbar-handler').not('.toolbar-box').removeClass('active');
						self.toggleClass('active');
					})
				});
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
		$('.community').setCommunity();
		$('.toolbar-handler').bind('click', $.fn.toggleToolbar);
		$('.stage-selector-handler>em').hover(
			function(){
				$(this).addClass('flash');
				$('.stage-selector-handler>span').addClass('flash');
				$('.stage-box').addClass('flash');
			},
			function(){
				$(this).removeClass('flash');
				$('.stage-selector-handler>span').removeClass('flash');
				$('.stage-box').removeClass('flash');
			}
		);
		$('.stage-selector-handler>em').bind('click', function(){
			$('.pane').removeClass('show');
			$.fn.removeAllActive.call($('.stage-selector'));
			
		});
		$('.pane-handler').bind('click',function(){
			$.fn.removeAllActive.call(this);
			var id = $(this).attr('data-aim');
			$('.pane').not('#'+ id).removeClass('show');
			$('#'+ id).toggleClass('show');
		})
		//user-profile
		$('.user-profile-inner').bind('click', function(){
			$.fn.removeAllActive.call($('.user-profile'));
			$('.pane').removeClass('show');
		});
		
		
		//stage ajax
		/** Move to edgemarkers_stage module **/
		/*$.ajax({
			url: '?q=edgemakers/stage/api/list',
			dataType: 'json',
			type : 'GET',
			success : function(data){
				for(var i=0; i<data.length; i++){
					console.log(data[i]);
					$('.stage-box').append('<div class="stage-item"><a href="#x">'+ data[i].title + '</a></div>');
				}
			},
			error :function(){
				alert('An error occurs when getting the stage sets!')
			}
		});
		*/
	});
})(jQuery);

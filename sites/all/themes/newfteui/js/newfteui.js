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
				var space2 = ($(window).width() - 600)/2;
				$('.teacher-notes').css({
					'left' : space2 + 'px'
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
				var id = $(this).attr('data-aim');
				$('.pane').not('#'+ id).css('right','')
				$('.teacher-notes').css('top','835px');
				$(this).toggleClass('active');
			},
			numbering : function(){
				var defaults = {
					node: '.item-list:first li'
				}
				var options = $.extend(defaults,options);
				return this.each(function(){
					var self = $(this);
					self.find(options.node).each(function(i){
						//
					})
				});
			}
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
			jQuery('body').removeClass('no-scroll-bar');
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
			var self = $(this);
			var id = $(this).attr('data-aim');
			$('.pane').not('#'+ id).css('right','').removeClass('show');
			
			if($('#'+ id).hasClass('show')){
				$('#'+ id).css('right','').removeClass('show');
				
			}else{
				$('#'+ id).css('right',($(window).width()-760)/2 + 'px').addClass('show');
				
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
		
		//profile settings demo
		$('.demo-setting-wrapper').css({
			left : ($(window).width() - $('.demo-setting-wrapper').width())/2 + 'px',
			top  : ($(window).height() - $('.demo-setting-wrapper').height())/2 + 'px'
		});
		$('#secondary-menu ul.links li.first').bind('click', function(evt){
			evt.preventDefault();
			$('.demo-setting-wrapper').toggle();
		});
		//login
		$('.login-regisiter-newpassword-wrapper').css({
			'left': ($(window).width() - $('.login-regisiter-newpassword-wrapper').width())/2 + 'px'
		});
		$('.login-regisiter-newpassword-wrapper .lrn-tab li').bind('click', function(){
			if(!$(this).hasClass('active')){
			    $('.login-regisiter-newpassword-wrapper .lrn-tab li.active').removeClass('active');
			    $(this).addClass('active');
				var idx = $(this).index(); 
				$('.lrn-box.tab-active').removeClass('tab-active');
				$('.lrn-box').eq(idx).addClass('tab-active');
			}
		})
		
		//prevent mouse middle click
		$(window).bind('scroll', function(event){
			
			
			$(document).scrollLeft(0);
		})
		
		
		
	});
})(jQuery);

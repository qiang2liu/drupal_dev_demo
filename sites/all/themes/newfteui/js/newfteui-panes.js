(function($){
/* carrousel */
  $.fn.extend({
	carrousel: function(options){
		var defaults = {
			count      : 9,
			item       : '.d3-item',
			leftController: '.d3-left-arrow',
			rightController: '.d3-right-arrow',
			desBox : '.carousel-des',
			linkNode : '.carousel-viewmore'
		};
		var options = $.extend(defaults, options);
		return this.each(function(){
			var self = $(this);
			
			//the first show
			var idx = options.count % 2;
			var midNumber = parseInt(options.count/2,10);
			if(idx ==1){
				self.find(options.item).eq(midNumber).addClass('show');
			}else{
				self.find(options.item).eq(midNumber-1).addClass('show');
			}
			
			function d3Animate(){
				var activeIdx = self.find(options.item + '.show').index(options.item);
				//empty all except the 'show'
				self.find(options.item).not('.show').attr('class','d3-item');
				//check the first item
				if (activeIdx == 0){
					self.find(options.item).eq(0).addClass('show-is-first');
				}else{
					self.find(options.item).eq(0).addClass('show-left-fisrt')
				}
				//check the last item
				var ln = self.find(options.item).length -1;
				if(activeIdx == ln){
					self.find(options.item).eq(ln).addClass('show-is-last');
				}else{
					self.find(options.item).eq(ln).addClass('show-right');
				}
				//check the next item of the show
				self.find(options.item).eq(activeIdx+1).addClass('show-add-1');
				// //check others
				//left
				for(var i = 1; i < activeIdx; i++){
					self.find(options.item).eq(i).addClass('show-left');
				}
				//right
				for(var i = ln-1; i > activeIdx + 1; i--){
					self.find(options.item).eq(i).addClass('show-right');
				}
			}
			
			//set index
			function setIndex(){
				self.find(options.item).css('zIndex','0');
				var idx = self.find('.show').index(options.item);
				var itemLength = self.find(options.item).length-1;
				for(var i=itemLength; i>=idx; i--){
					self.find(options.item).eq(i).css('zIndex', itemLength - i);
				}
			}
			
			//initailize
			d3Animate();
			setIndex();
			
			//init animate
			function addAnimate(){
				self.find(options.item).addClass('reload');
				self.find(options.item).find('img').addClass('reload');
			}
			
			//the clicking of the left arrow
			self.find(options.leftController).bind('click', function(){
				var activeIdx = self.find(options.item + '.show').index(options.item);
				if(activeIdx > 0){
					self.find(options.item).eq(activeIdx).removeClass('show')
					self.find(options.item).eq(activeIdx -1).attr('class','d3-item').addClass('show');
				}
				d3Animate();
				setIndex();
				addAnimate();
			});
			
			//the clicking of the right arrow
			self.find(options.rightController).bind('click', function(){
				var activeIdx = self.find(options.item + '.show').index(options.item);
				if(activeIdx < options.count-1){
					self.find(options.item).eq(activeIdx).removeClass('show')
					self.find(options.item).eq(activeIdx +1).attr('class','d3-item').addClass('show');
				}
				d3Animate();
				setIndex();
				addAnimate();
			});
			
			//the img hover function
			self.find(options.item).bind('mouseover', function(){
				if(!$(this).hasClass('show')){
					var activeIdx = self.find(options.item + '.show').index(options.item);
					$(this).attr('class','d3-item').addClass('show');
					self.find(options.item).eq(activeIdx).removeClass('show');
					d3Animate();
					setIndex();
					addAnimate();
				}	
			});
			
		    //clcik anywhere to link to the topic page
		    self.find(options.desBox).bind('click', function(){
		    	var link = $(this).find('a',options.linkNode).attr('href');
		    	window.open(link);
		    })
		});
	}
 });
 
 
 $(document).ready(function(){
	//carrousel
	$('#d3').carrousel();
	
	//topic swithcer
	$('.topic-tab li').bind('click', function(){
		$('.topic-tab li.actived').removeClass('actived');
		$(this).addClass('actived');
		var idx=$(this).index('.topic-tab li');
		if(!$('.topic-content-box').eq(idx).hasClass('actived')){
			$('.topic-content-box.actived').removeClass('actived');
			$('.topic-content-box').eq(idx).addClass('actived')
		}
	})
	
	//Gallery
	$('#gallery-search-form').next().addClass('right-align');
	$('#gallery-search-form').wrapInner('<div class="new" />')
 });
})(jQuery);


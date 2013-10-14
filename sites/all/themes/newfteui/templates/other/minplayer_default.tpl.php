<div id="<?php print $settings['id']; ?>" class="media-player" style="width:<?php print $settings['width']; ?>; height:<?php print $settings['height']; ?>;">
  <div class="media-player-error"></div>
  <div class="media-player-controls">
    <div class="media-player-controls-left">
      <a class="media-player-play" title="Play"></a>
      <a class="media-player-pause" title="Pause"></a>
    </div>
    <div class="media-player-controls-right">
      <div class="media-player-timer">00:00</div>
      <div class="media-player-fullscreen">
        <div class="media-player-fullscreen-inner"></div>
      </div>
      <div class="media-player-volume">
        <div class="media-player-volume-slider"></div>
        <a class="media-player-volume-button" title="Mute/Unmute"></a>
      </div>
    </div>
    <div class="media-player-controls-mid">
      <div class="media-player-seek">
        <div class="media-player-progress"></div>
      </div>
    </div>
  </div>
  <div class="media-player-play-loader">
    <div class="media-player-big-play"><span></span></div>
    <div class="media-player-loader">&nbsp;</div>
    <div class="media-player-preview"></div>
  </div>
  <div class="media-player-display">
    <?php print $player; ?>
  </div>
</div>
<?php
  $modulePath = drupal_get_path('module', 'html5_media');
  $playerId = $settings['id'];
  $attributes = drupal_json_encode($element['#attributes']);
  require_once $modulePath.'/html5_media.module';
  $settings = array_intersect_key($settings, html5_media_player_settings());
  $settings = trim(drupal_json_encode($settings), '{}');
  $swfplayer = url($modulePath . '/player/flash/minplayer.swf');
?>
<script>
jQuery('#<?php echo $playerId; ?>').minplayer({
  id:'#<?php echo $playerId; ?>',
  attributes:<?php echo $attributes; ?>,
  <?php echo $settings; ?>,
  swfplayer:'<?php echo $swfplayer; ?>'
});
</script>
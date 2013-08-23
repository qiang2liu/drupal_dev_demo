<?php
// print('<pre>' . print_r($myideas, TRUE) . '</pre>');
?>

<h2 class="item-studio">Studio</h2>
<div class="pane-studio-box my-idea item-studio">
  <h4>my Ideas</h4>
  <div class="scroll-wrapper ">
    <ul id="mural-list">
      <?php
      if (is_array($myideas)) {
        foreach ($myideas as $item) {
          ?>
          <li>
            <span class="muralthumb <?php print $item['title']; ?>">
              <img src='<?php print $item['thumburl']; ?>'/>
            </span>

            <?php
            if (!empty($item['nid'])) {
              $edit_url = l('<span class ="muralsettingicon"></span>', 'mural/' . $item['nid'], array(
                'html' => true,
                'attributes' => array(
                  'class' => array('studio-mural-list-item-link'),
                  'id' => 'media-node-' . $item['nid'],
                ),
                      )
              );
              print $edit_url;
            }
            ?>

            <?php print_r($item['seturl']); ?>

          </li>

          <?php
        }
      }
      ?>
    </ul>
  </div>
</div>



<div class="pane-studio-box ideas-shared-with-me item-studio">
  <h4>Ideas Shared with me</h4>
  <div class="scroll-wrapper ">
    <ul>
      <?php
      foreach ($myshareideas as $item) {
        ?>
        <li>
          <span class="muralthumb">
            <img src='<?php print $item['thumburl']; ?>'/>
          </span>
        </li>

        <?php
      }
      ?>
    </ul>
  </div>
</div>
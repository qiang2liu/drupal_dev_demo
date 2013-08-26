<?php
// print('<pre>' . print_r($myideas, TRUE) . '</pre>');
?>

<h2 class="item-studio">Studio</h2>
<div class="pane-studio-box my-idea item-studio" id="studio-my-idea">
  <h4>my Ideas</h4>
  <div class="scroll-wrapper">
    <span class="prev"><a href="#" id="page-0"> > </a></span>
    <ul id="studio-mural-list">
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
    <span class="next"><a href="#" id="page-2"> > </a></span>
  </div>
</div>



<div class="pane-studio-box ideas-shared-with-me item-studio">
  <h4>Ideas Shared with me</h4>
  <div class="scroll-wrapper ">
    <ul id="pane-studio-shared-with-me-list">
      <?php
//       print('<pre>' . print_r($myshareideas, TRUE) . '</pre>');
      foreach ($myshareideas as $item) {
//         print('<pre>' . print_r($myshareideas, TRUE) . '</pre>');
        ?>
        <li>
          <span class="muralthumb">
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
      ?>
    </ul>
  </div>
</div>
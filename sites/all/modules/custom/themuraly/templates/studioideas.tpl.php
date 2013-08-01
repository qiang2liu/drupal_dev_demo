<h2 class="item-studio">Studio</h2>
<div class="pane-studio-box my-idea item-studio">
  <h4>my Ideas</h4>
  <div class="scroll-wrapper ">
    <ul>
      <?php
      foreach ($myideas as $item) {
        ?>
        <li>
          <span class="muralthumb">
            <img src='<?php print $item['thumburl']; ?>'/>
          </span>  

          <?php
          if (!empty($item['nid'])) {
            $edit_url = l('<span class ="muralsettingicon"></span>', 'modal/node/' . $item['nid'] . '/edit/nojs/0', array(
              'html' => true,
              'attributes' => array(
                'class' => array('ctools-use-modal'),
              ),
                    )
            );
            print $edit_url;
          }
          ?>

        </li>

        <?php
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
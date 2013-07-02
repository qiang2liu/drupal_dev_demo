<?php 
  global $base_url;
  
?>


<style>
  
  .table, tr, td, th{
    border: 0px;
    margin:0px;
    border: 1px solid #00000;
    
  }
  
  .infow tr td, .infow tr th {
     border: 1px solid #00000;
     text-align: center;
  }
  
</style>
<div class ="infow">

<table style="border:0">
  <tr>
    <td style=" border: 1px solid #00000;">
      <table style="border:0;">
        <tr>
          <td style=" border: 1px solid #00000;">
           <img src="<?php print $base_url;?>/images/mock_colla_2.jpg"/>
          </td> 
        </tr>
        <tr>
          <td style=" border: 1px solid #00000;">
            Devi
          </td> 
        </tr> 
      </table>
    </td>
    <td style=" border: 1px solid #00000;">
      <div>  <?php print $data['title']; ?> &nbsp;&nbsp; 2013/07/01  </div>
     
      <div>  <?php print $data['location']; ?>  </div>
         <div> 
           
           <table>
             <tr>
               <td style=" border: 1px solid #00000;">Collaborators</td>
                <td style=" border: 1px solid #00000;">
                   <table style="border:0;">
        <tr>
          <td style=" border: 1px solid #00000;">
           <img src="<?php print $base_url;?>/images/mock_colla_3.jpg"/>
          </td> 
        </tr>
        <tr>
          <td style=" border: 1px solid #00000;">
            Marc
          </td> 
        </tr> 
      </table>
                  
                </td>
                 <td style=" border: 1px solid #00000;">
                   
                   <table style="border:0;">
        <tr>
          <td style=" border: 1px solid #00000;">
           <img src="<?php print $base_url;?>/images/mock_colla_4.jpg"/>
          </td> 
        </tr>
        <tr>
          <td style=" border: 1px solid #00000;">
            Lisa
          </td> 
        </tr> 
      </table>
                   
                 </td>
                  <td style=" border: 1px solid #00000;">
                    
                    
                      <table style="border:0;">
        <tr>
          <td style=" border: 1px solid #00000;">
           <img src="<?php print $base_url;?>/images/mock_colla_1.jpg"/>
          </td> 
        </tr>
        <tr>
          <td style=" border: 1px solid #00000;">Tay
          </td> 
        </tr> 
      </table>
                    
                  </td>
               
             </tr>
             
             
           </table>
          
           
           
          
              
              
          
               
               
             
               
          
         
         </div>
    </td>
    
  </tr>
  
  
  
</table>


<table style="border:0">
  <tr>
    
    <td style=" border: 1px solid #00000;">
      <img src="<?php print $base_url;?>/images/mock_studio_1.jpg"/>
    </td>
    <td style=" border: 1px solid #00000;">
      <?php print $data['brief']; ?>
    </td>
    
  </tr>
</table>

<table style="border:0">
  <tr>
    
    
    <td style=" border: 1px solid #00000;">
      
    </td>
    
    
  </tr>
  
  <tr>
    
    
    <td style=" border: 1px solid #00000;">
      <a href="#"/>Send to Project</a>
    </td>
    
    
  </tr>
  
</table>
  
  
</div>
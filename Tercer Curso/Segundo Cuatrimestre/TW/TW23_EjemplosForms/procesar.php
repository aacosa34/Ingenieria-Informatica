<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <title id="titulo">Variables recibidas</title>
  </head>

  <body>
  	<?php
  	  function mostrar($var,$tit) {
  	  	echo "<h1>$tit</h1>";
        echo "<ul>";
	      foreach ($var as $c => $v) {
        	echo "<li>$c = ";
        	print_r($v);
					echo "</li>";
				}
    		echo "</ul>";
  	  }
  	  mostrar($_GET,"Variables GET");
  	  mostrar($_POST,"Variables POST");
		?>
  </body>
</html>
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>Conversor</title>
  <style>
    .error {
      color: red;
    }

    p:nth-child(3), p:nth-child(11) {
      margin: 0;
    }

    p:nth-child(4) {
      margin-bottom: 0;
    }

    label:not(:first-of-type):after {
      content: '';
      display: block;
    }

    [type="submit"] {
      margin-top: 15px;
    }
  </style>
</head>

<body>
  <h1>Conversor de temperaturas</h1>

<?php
if (isset($_GET["celsius"])) {
  /* Si se han recibido datos del formulario */
  $cel = $_GET["celsius"];
  $fah = $cel*9/5+32;
  echo "<p>Grados Celsius: $cel</p>";
  echo "<p>Grados Fahrenheit: $fah</p>";
  echo "<p><a href='".$_SERVER["SCRIPT_NAME"]."'>Calcule otra conversión</a></p>";
} else {
  /* Si no se han recibido datos del formulario */
  echo "<form action='".$_SERVER["SCRIPT_NAME"]."' method='get'>
          <label>Temperatura en Celsius: 
                 <input type='text' name='celsius'/>
                 </label>
          <input type='submit' value='Convertir'/>
        </form>";
} 
?>

</body>
</html>
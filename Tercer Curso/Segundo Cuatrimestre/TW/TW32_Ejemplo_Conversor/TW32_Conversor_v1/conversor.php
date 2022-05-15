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
/* Si se han recibido datos del formulario */
if (isset($_GET["celsius"])) {
  $cel = $_GET["celsius"];
  $fah = $cel*9/5+32;
  echo "<p>Grados Celsius: $cel</p>";
  echo "<p>Grados Fahrenheit: $fah</p>";
} else { /* Si no se han recibido datos del formulario */ 
  echo "<p>No ha enviado ningún dato</p>";
}
echo "<p><a href='conversor.html'>Calcule otra conversión</a></p>"; 
?>

</body>
</html>
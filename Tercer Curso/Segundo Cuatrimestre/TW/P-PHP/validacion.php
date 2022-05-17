<?php

function showVar($var,$msg) {
  echo "<h2>$msg</h2>";
  echo "<ul>";
  foreach ($var as $c => $v) {
    if (is_array($v)) {
      echo "<li>$c = <span class='valor'>"; 
      print_r($v); 
      echo "</span></li>";
    } else
      echo "<li>$c = <span class='valor'>$v</span></li>";
  }
  echo "</ul>";        
}

function getParametros($params){
  // Si se ha enviado el formulario
  if(isset($params["nombre"]) && isset($params["email"]) && 
     isset($params["email2"]) && isset($params["tarjeta"]) && 
     isset($params["mes"]) && isset($params["anyo"]) && 
     isset($params["cvc"]) && isset($params["recibir"]))
  {
    $resultado['enviado'] = true;

    // Comprobacion de los paramteros
    $resultado['errornombre'] = '';
   
    if(empty($params["nombre"]) || !preg_match('/^([A-ZÁÉÍÓÚ]{1}[a-zñáéíóú]+[\s]*)+$/', $params["nombre"])){
      $result['errornombre'] = 'Debe escribir su nombre (solo letras)';
    }
    else if(empty($params["email"]) || !filter_var($params["email"], FILTER_VALIDATE_EMAIL)){
      $result['erroremail'] = 'Formato de email no valido (formato aceptado: john@example.com)';
    }
    else if(empty($params["email2"]) || $params["email2"] != $params["email"]){
      $result['erroremail2'] = 'Emails no coincidentes. Por favor, revise ambos email';
    }
    else if(empty($params["tarjeta"])){

    }
    else if(empty($params["mes"]) || !is_numeric($params["mes"]) || $params["mes"] < 1 || $params["mes"] > 12){
      $result['errormes'] = 'El mes es incorrecto';
    }
    else if(empty($params["anyo"]) || !is_numeric($params["mes"]) || $params["anyo"] < 2000 || $params["anyo"] > 2100){
      $result['erroranyo'] = 'El año es incorrecto (válidos entre 2000 y 2100, use 4 dígitos)';
    }
    else if(empty($params["cvc"]) || !is_numeric($params["cvc"]) || !preg_match('/^[0-9]{3}$/', $params["cvc"])){
      $result['errorcvc'] = 'El CVC debe ser un número de 3 dígitos';
    }
    else if(empty($params["recibir"])){
      $result['errorrecibir'] = 'Debe seleccionar una opción obligatoriamente';
    }
  }
}

// Obtenemos los parámetros y los validamos
$parametros = getParametros($_GET);

if(isset($_GET["nombre"]) && isset($_GET["email"]) && isset($_GET["email2"]) && isset($_GET["tarjeta"]) && isset($_GET["mes"]) && isset($_GET["anyo"]) && isset($_GET["cvc"]) && isset($_GET["recibir"]))
{
  showVar($_GET, "Variables recibidas");
}
else{
    
}


?>
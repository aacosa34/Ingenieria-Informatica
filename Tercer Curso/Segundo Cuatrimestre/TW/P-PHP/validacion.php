<?php
require "plantillasHTML.php";

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

function mostrarFormulario($params){
  preambuloHTML("Validación de formularios", "formulario.css");
  echo "<header><h1>Datos de pago</h1></header>", PHP_EOL;
  echo "<main>";
  echo "<form action='" .$_SERVER['SCRIPT_NAME']. "' method=GET>";
  echo "<div>
            <label>Nombre: </label>
            <input type='text' name='nombre' value='".$params['nombre']."'/>";
  if($params['errornombre']!='')
    echo "<p class='error'>{$params['errornombre']}</p>"; 
  echo "</div>";
  echo "<div>
          <label>Email: </label>
          <input type='text' name='email' value='".$params['email']."'/>";
  if($params['erroremail']!='')
    echo "<p class='error'>{$params['erroremail']}</p>"; 
  echo "</div>";
  echo "<div>
          <label>Email (repetir): </label>
          <input type='text' name='email2' value='".$params['email2']."'/>";
  if($params['erroremail2']!='')
    echo "<p class='error'>{$params['erroremail2']}</p>"; 
  echo "</div>";
  echo "<div>
          <label>Numero de tarjeta: </label>
          <input type='text' name='tarjeta' value='".$params['nombre']."'/>";
  if($params['errortarjeta']!='')
    echo "<p class='error'>{$params['errortarjeta']}</p>"; 
  echo "</div>";
  echo "<div>
          <label>Mes caducidad: </label>
          <input type='text' name='mes' value='".$params['mes']."'/>";
  if($params['errormes']!='')
    echo "<p class='error'>{$params['errormes']}</p>"; 
  echo "</div>";
  echo "<div>
          <label>CVC: </label>
          <input type='text' name='cvc' value='".$params['cvc']."'/>";
  if($params['errorcvc']!='')
    echo "<p class='error'>{$params['errorcvc']}</p>"; 
  echo "</div>";
  echo "<div>      
          <label>Recibir información: </label>
          <input type='radio' name='recibir' value='Sí'";
          if(array_key_exists('Sí',$params)) echo ' checked';
          echo "/> Sí";
          echo "<input type='radio' name='recibir' value='No'";
          if(array_key_exists('No',$params)) echo ' checked';
          echo "/> No";
  echo "</div>";
  echo "<div>   
  <label>Temas de interés: </label>
  <input type='checkbox' name='intereses[]' value='aves'> Aves
  <input type='checkbox' name='intereses[]' value='casas'> Casas
  <input type='checkbox' name='intereses[]' value='coches'> Coches
</div> 
<input type='submit' name='boton' value='Enviar datos'/>

</form>";
echo "</main>";

  finHTML();

}

function getParametros(){
  // Si se ha enviado el formulario
  if(isset($_GET["nombre"]) && isset($_GET["email"]) && 
     isset($_GET["email2"]) && isset($_GET["tarjeta"]) && 
     isset($_GET["mes"]) && isset($_GET["anyo"]) && 
     isset($_GET["cvc"]) && isset($_GET["recibir"]))
  {
    $resultado['enviado'] = true;

    // Comprobacion de los paramteros
    $resultado['errornombre'] = $resultado['erroremail']   = 
    $resultado['erroremail2'] = $resultado['errortarjeta'] = 
    $resultado['errormes'] = $resultado['erroranyo']    = 
    $resultado['errorcvc'] = $resultado['errorrecibir'] = '';
    
   
    if(empty($_GET["nombre"]) || !preg_match('/^([A-ZÁÉÍÓÚ]{1}[a-zñáéíóú]+[\s]*)+$/', $_GET["nombre"])){
      $resultado['errornombre'] = 'Debe escribir su nombre (solo letras)';
    }
    else if(empty($_GET["email"]) || !filter_var($_GET["email"], FILTER_VALIDATE_EMAIL)){
      $resultado['erroremail'] = 'Formato de email no valido (formato aceptado: john@example.com)';
    }
    else if(empty($_GET["email2"]) || $_GET["email2"] != $_GET["email"]){
      $resultado['erroremail2'] = 'Emails no coincidentes. Por favor, revise ambos email';
    }
    else if(empty($_GET["tarjeta"])){

    }
    else if(empty($_GET["mes"]) || !is_numeric($_GET["mes"]) || $_GET["mes"] < 1 || $_GET["mes"] > 12){
      $resultado['errormes'] = 'El mes es incorrecto';
    }
    else if(empty($_GET["anyo"]) || !is_numeric($_GET["mes"]) || $_GET["anyo"] < 2000 || $_GET["anyo"] > 2100){
      $resultado['erroranyo'] = 'El año es incorrecto (válidos entre 2000 y 2100, use 4 dígitos)';
    }
    else if(empty($_GET["cvc"]) || !is_numeric($_GET["cvc"]) || !preg_match('/^[0-9]{3}$/', $_GET["cvc"])){
      $resultado['errorcvc'] = 'El CVC debe ser un número de 3 dígitos';
    }
    else if(empty($_GET["recibir"])){
      $resultado['errorrecibir'] = 'Debe seleccionar una opción obligatoriamente';
    }
  }else{
    $resultado['enviado'] = false;
  }

  return $resultado;
}

// Obtenemos los parámetros y los validamos
$parametros = getParametros();

// Si se han recibido parametros y son correctos
if($parametros['enviado']==true && ($parametros["errornombre"]=='' && $parametros["erroremail"]=='' && 
                                    $parametros["erroremail2"]=='' && $parametros["errortarjeta"]=='' &&
                                    $parametros["errormes"]=='' && $parametros["erroranyo"]=='' &&
                                    $parametros["errorcvc"]=='' && $parametros["errorrecibir"]== ''))
{
  showVar($parametros, "Variables recibidas");
}
else{
    echo "<h1>HOLA</h1>";
    mostrarFormulario($_GET);
}


?>
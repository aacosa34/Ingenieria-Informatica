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

function mostrarFormulario($parametros){
  preambuloHTML("Validación de formularios", "formulario.css");
  echo "<header><h1>Datos de pago</h1></header>", PHP_EOL;
  echo "<main>";
  echo "<form action='" .$_SERVER['SCRIPT_NAME']. "' method=GET>";
  echo "<div>
            <label>Nombre: </label>
            <input type='text' name='nombre' value='".$parametros['nombre']."'/>";
  if($parametros['errornombre']!='')
    echo "<p class='error'>{parametros['errornombre']}</p>"; 
  echo "</div>";
  echo "<div>
          <label>Email: </label>
          <input type='text' name='email' value='".$parametros['email']."'/>";
  if($parametros['erroremail']!='')
    echo "<p class='error'>{parametros['erroremail']}</p>"; 
  echo "</div>";
  echo "<div>
          <label>Email (repetir): </label>
          <input type='text' name='email2' value='".$parametros['email2']."'/>";
  if($parametros['erroremail2']!='')
    echo "<p class='error'>{parametros['erroremail2']}</p>"; 
  echo "</div>";
  echo "<div>
          <label>Numero de tarjeta: </label>
          <input type='text' name='tarjeta' value='".$parametros['nombre']."'/>";
  if($parametros['errortarjeta']!='')
    echo "<p class='error'>{parametros['errortarjeta']}</p>"; 
  echo "</div>";
  echo "<div>
          <label>Mes caducidad: </label>
          <input type='text' name='mes' value='".$parametros['mes']."'/>";
  if($parametros['errormes']!='')
    echo "<p class='error'>{parametros['errormes']}</p>"; 
  echo "</div>";
  echo "<div>
          <label>CVC: </label>
          <input type='text' name='cvc' value='".$parametros['cvc']."'/>";
  if($parametros['errorcvc']!='')
    echo "<p class='error'>{parametros['errorcvc']}</p>"; 
  echo "</div>";
  echo "<div>      
          <label>Recibir información: </label>
          <input type='radio' name='recibir' value='Sí'";
          if(array_key_exists('Sí',$parametros)) echo ' checked';
          echo "/> Sí";
          echo "<input type='radio' name='recibir' value='No'";
          if(array_key_exists('No',$parametros)) echo ' checked';
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

function getParametros($params){
  // Si se ha enviado el formulario
  if(isset($params["nombre"]) && isset($params["email"]) && 
     isset($params["email2"]) && isset($params["tarjeta"]) && 
     isset($params["mes"]) && isset($params["anyo"]) && 
     isset($params["cvc"]) && isset($params["recibir"]))
  {
    $resultado['enviado'] = true;

    // Comprobacion de los paramteros
    $resultado['errornombre']  = '';
    $resultado['erroremail']   = '';
    $resultado['erroremail2']  = '';
    $resultado['errortarjeta'] = '';
    $resultado['errormes']     = '';
    $resultado['erroranyo']    = '';
    $resultado['errorcvc']     = '';
    $resultado['errorrecibir'] = '';
    
   
    if(empty($params["nombre"]) || !preg_match('/^([A-ZÁÉÍÓÚ]{1}[a-zñáéíóú]+[\s]*)+$/', $params["nombre"])){
      $resultado['errornombre'] = 'Debe escribir su nombre (solo letras)';
    }
    else if(empty($params["email"]) || !filter_var($params["email"], FILTER_VALIDATE_EMAIL)){
      $resultado['erroremail'] = 'Formato de email no valido (formato aceptado: john@example.com)';
    }
    else if(empty($params["email2"]) || $params["email2"] != $params["email"]){
      $resultado['erroremail2'] = 'Emails no coincidentes. Por favor, revise ambos email';
    }
    else if(empty($params["tarjeta"])){

    }
    else if(empty($params["mes"]) || !is_numeric($params["mes"]) || $params["mes"] < 1 || $params["mes"] > 12){
      $resultado['errormes'] = 'El mes es incorrecto';
    }
    else if(empty($params["anyo"]) || !is_numeric($params["mes"]) || $params["anyo"] < 2000 || $params["anyo"] > 2100){
      $resultado['erroranyo'] = 'El año es incorrecto (válidos entre 2000 y 2100, use 4 dígitos)';
    }
    else if(empty($params["cvc"]) || !is_numeric($params["cvc"]) || !preg_match('/^[0-9]{3}$/', $params["cvc"])){
      $resultado['errorcvc'] = 'El CVC debe ser un número de 3 dígitos';
    }
    else if(empty($params["recibir"])){
      $resultado['errorrecibir'] = 'Debe seleccionar una opción obligatoriamente';
    }
  }else{
    $resultado['enviado'] = false;
  }

  return $resultado;
}

// Obtenemos los parámetros y los validamos
$parametros = getParametros($_GET);

// Si se han recibido parametros y son correctos
if($parametros['enviado']==true && ($parametros["errornombre"]=='' && $parametros["erroremail"]=='' && 
                                    $parametros["erroremail2"]=='' && $parametros["errortarjeta"]=='' &&
                                    $parametros["errormes"]=='' && $parametros["erroranyo"]=='' &&
                                    $parametros["errorcvc"]=='' && $parametros["errorrecibir"]== ''))
{
  showVar($_GET, "Variables recibidas");
}
else{
    echo "<h1>HOLA</h1>";
    mostrarFormulario($parametros);
}


?>
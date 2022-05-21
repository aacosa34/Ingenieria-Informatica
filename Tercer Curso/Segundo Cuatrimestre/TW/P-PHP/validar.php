<?php
$errornombre = $erroremail = $erroremail2 = $errortarjeta = $errormes = $erroranyo = $errorcvc = "";

$nombre = $email = $email2 = $tarjeta = $mes = $anyo = $cvc = "";

if($_SERVER["REQUEST_METHOD"] == "POST") {
    // Si el metodo es POST, validamos todos los campos
    if(empty($_POST["nombre"]) || !preg_match('/^([A-ZÁÉÍÓÚ]{1}[a-zñáéíóú]+[\s]*)+$/', $_POST["nombre"])){
        $errornombre = "Debe escribir su nombre (solo letras)";
    }else{
        $nombre = formatearVariable($nombre);
    }

    if(empty($_POST["email"]) || !filter_var($_POST["email"], FILTER_VALIDATE_EMAIL)){
        $erroremail = "Formato de email no valido (formato aceptado: john@example.com)";
    }
    else{
        $email = formatearVariable($email);
    }

    if(empty($_POST["email2"]) || $_POST["email2"] != $_POST["email"]){
        $erroremail2 = "Emails no coincidentes. Por favor, revise ambos email";
    }
    else{
        $email2 = formatearVariable($email2);
    }

    if(empty($_POST["mes"]) || !is_numeric($_POST["mes"]) || $_POST["mes"] < 1 || $_POST["mes"] > 12){
        $errormes = "El mes es incorrecto";
    }
    else{
        $mes = formatearVariable($mes);
    }

    if(empty($_POST["anyo"]) || !is_numeric($_POST["mes"]) || $_POST["anyo"] < 2000 || $_POST["anyo"] > 2100){
        $erroranyo = "El año es incorrecto (válidos entre 2000 y 2100, use 4 dígitos)";
    }
    else{
        $anyo = formatearVariable($anyo);
    }

    if(empty($_POST["cvc"]) || !is_numeric($_POST["cvc"]) || !preg_match('/^[0-9]{3}$/', $_POST["cvc"])){
        $errorcvc = "El CVC debe ser un número de 3 dígitos";
    }
    else{
        $cvc = formatearVariable($cvc);
    }
}

function formatearVariable($var){
    if(!is_numeric($var)){
       $var = trim($var); 
       $var = stripslashes($var);
       $var = htmlspecialchars($var);
    }
    
}
?>
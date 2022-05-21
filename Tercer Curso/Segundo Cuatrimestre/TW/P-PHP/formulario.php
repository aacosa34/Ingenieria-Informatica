<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="bootstrap.css">
    <title>Validación de formulario</title>
</head>
<body>
    
<?php

$errornombre = $erroremail = $erroremail2 = $errortarjeta = $errormes = $erroranyo = $errorcvc = $errorrecibir = "";

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

    if(empty($_POST["tarjeta"]) || !algoritmoDeLuhn($_POST["tarjeta"])){
        $errortarjeta = "El número de tarjeta no es válido";
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

    if(empty($_POST["recibir"])){
        $errorrecibir = "Debe seleccionar una opción obligatoriamente";
    }
}

function formatearVariable($var){
    $var = trim($var); 
    $var = stripslashes($var);
    $var = htmlspecialchars($var);
}

function algoritmoDeLuhn($numero){
    $impar = true;
    $suma = 0;

    foreach ( array_reverse(str_split($numero)) as $num){
        $suma += array_sum( str_split(($impar = !$impar) ? $num*2 : $num) );
    }

    return (($suma % 10 == 0) && ($suma != 0));
}

?>
    <main class="container">
        <div class="card bg-light">
            <header>
                <h1 class="card-header">Datos de pago</h1>
            </header>
            <div class="card-body">
                <form action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']) ?>" method="POST" novalidate>
                    <div class="form-group">
                        <label class="col-form-label">Nombre: </label>
                        <input class="form-control<?php if(!empty($errornombre)) {echo ' is-invalid"';} ?>" type="text" name="nombre" placeholder="Escriba su nombre" value="<?php if(!empty($_POST["nombre"])) {echo $_POST['nombre'];} else{echo "";}?>"/>
                        <p class="invalid-feedback"><?php echo $errornombre; ?></p>
                    </div> 

                    <div class="form-group">
                        <label class="col-form-label">Email:</label>
                        <input class="form-control<?php if(!empty($erroremail)) {echo ' is-invalid"';} ?>" type="text" name="email" placeholder="Escriba su email" value="<?php if(!empty($_POST["email"])) {echo $_POST['email'];} else{echo "";}?>"/>
                        <p class="invalid-feedback"><?php echo $erroremail; ?></p>
                    </div>
                    <div class="form-group">  
                        <label class="col-form-label">Email (repetir): </label>
                        <input class="form-control<?php if(!empty($erroremail2)) {echo ' is-invalid"';} ?>" type="text" name="email2" placeholder="Repita su email" value="<?php if(!empty($_POST["email2"])) {echo $_POST['email2'];} else{echo "";}?>"/>
                        <p class="invalid-feedback"><?php echo $erroremail2; ?></p>
                    </div>
                    <div class="form-group">
                        <label class="col-form-label">Numero de tarjeta: </label>
                        <input class="form-control<?php if(!empty($errortarjeta)) {echo ' is-invalid"';} ?>" type="text" name="tarjeta" value="<?php if(!empty($_POST["tarjeta"])) {echo $_POST['tarjeta'];} else{echo "";}?>"/>
                        <p class="invalid-feedback"><?php echo $errortarjeta; ?></p>
                    </div>
                    <div class="form-group">   
                        <label class="col-form-label">Mes caducidad: </label>
                        <input class="form-control <?php if(!empty($errormes)) {echo 'is-invalid"';} ?>" type="text" name="mes" value="<?php if(!empty($_POST["mes"])) {echo $_POST['mes'];} else{echo "";}?>"/>
                        <p class="invalid-feedback"><?php echo $errormes; ?></p>
                    </div>  
                    <div class="form-group">
                        <label class="col-form-label">Año caducidad: </label>
                        <input class="form-control<?php if(!empty($erroranyo)) {echo ' is-invalid"';} ?>" type="text" name="anyo" value="<?php if(!empty($_POST["anyo"])) {echo $_POST['anyo'];} else{echo "";}?>"/>
                        <p class="invalid-feedback"><?php echo $erroranyo; ?></p>
                    </div> 
                    <div class="form-group">  
                        <label class="col-form-label">CVC:</label>
                        <input class="form-control<?php if(!empty($errorcvc)) {echo ' is-invalid"';} ?>" type="text" name="cvc" value="<?php if(!empty($_POST["cvc"])) {echo $_POST['cvc'];} else{echo "";}?>"/>
                        <p class="invalid-feedback"><?php echo $errorcvc; ?></p>
                    </div>
                    <br>
                    <div class="form-check">
                        <input type="radio" class="form-check-input <?php if(!empty($errorrecibir)) {echo 'is-invalid"';}?>" id="validationFormCheck1" name="recibir" value="si" <?php if(!empty($_POST['recibir']) && $_POST['recibir']=="si") {echo "checked";} ?> required>
                        <label class="form-check-label" for="validationFormCheck1">Deseo recibir información</label>
                    </div>
                    
                    <div class="form-check mb-3">
                        <input type="radio" class="form-check-input <?php if(!empty($errorrecibir)) {echo 'is-invalid"';}?>" id="validationFormCheck2" name="recibir" value="no" <?php if(!empty($_POST['recibir']) && $_POST['recibir']=="no") {echo "checked";} ?> required>
                        <label class="form-check-label" for="validationFormCheck2">No deseo recibir información</label> 
                        <p class="invalid-feedback" id=><?php echo $errorrecibir; ?></p>
                    </div>
                    <div class="form-group">
                        <label class="col-form-label">Temas de interés: </label>
                        <div class="form-check">
                            <input class="form-check-input" id="check1" type="checkbox" name="intereses[]" value="aves" <?php if(!empty($_POST['intereses']) && in_array("aves", $_POST['intereses'])) {echo "checked";}?>>
                            <label class="form-check-label" for="check1">Aves</label>
                        </div>
                        <div class="form-check">
                            <input class="form-check-input" id="check2" type="checkbox" name="intereses[]" value="casas" <?php if(!empty($_POST['intereses']) && in_array("casas", $_POST['intereses'])) {echo "checked";}?>>
                            <label class="form-check-label" for="check2">Casas</label>
                        </div>
                        <div class="form-check">
                            <input class="form-check-input" id="check3" type="checkbox" name="intereses[]" value="coches" <?php if(!empty($_POST['intereses']) && in_array("coches", $_POST['intereses'])) {echo "checked";}?>>
                            <label class="form-check-label" for="check3">Coches</label>
                        </div>
                    </div>
                    <br>
                    <input class="btn btn-primary" type="submit" name="boton" value="Enviar datos"/>
                    
                </form>
            </div>

        </div>
    </main>


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

    if($_SERVER["REQUEST_METHOD"] == "POST") {
        if(empty($errornombre) && empty($erroremail) && empty($erroremail2) && empty($errortarjeta) &&
           empty($errormes)    && empty($erroranyo)  && empty($errorcvc)    && empty($errorrecibir)){
            $campos = Array("Nombre" => $_POST['nombre'],
                            "Email" => $_POST['email'],
                            "Email confirmado" => $_POST['email2'],
                            "Tarjeta" => $_POST['tarjeta'],
                            "Mes caducidad" => $_POST['mes'],
                            "Año caducidad" => $_POST['anyo'],
                            "CVC" => $_POST['cvc'],
                            "Recibir info" => $_POST['recibir'],
                            "Temas de interés" => (isset($_POST['intereses']) ? $_POST['intereses'] : ""));

            showVar($campos, "Variables recibidas");
        }
    }
?>
</body>
</html>


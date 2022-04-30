<!DOCTYPE html>
<html lang="es">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Document</title>
        
            
    </head>
    <body>
        <?php 
            $cadena = $_SERVER['HTTP_USER_AGENT'];
            $info = array(array("Chrome", "Google", "BSD", "Blink"),
                          array("Internet Explorer", "Microsoft", "Privativa", "Trident"),
                          array("Firefox", "Fundacion Mozilla", "GNU GPL", "Gecko"),
                          array("Opera", "Opera Software", "Privativa", "Blink"),
                          array("Safari", "Apple", "Privativa", "Webkit")
                        )
        ?>
        <p>La cadena del user agent es: <?php echo $cadena;?></p>
        <p>Sistema operativo: <?php  preg_match('/Linux|Windows|Mac OS/', $cadena, $patron); print_r($patron[0]); ?></p>
        <p>Navegador: <?php preg_match('/Chrome|Internet Explorer|Firefox|Opera|Safari/', $cadena, $patron); print_r($patron[0]); ?></p>
        <p>Version: <?php  ?></p>
        <p>Propietario: <?php  ?></p>
        <p>Licencia: <?php  ?></p>
        <p>Motor: <?php ?></p>
    </body>
</html>

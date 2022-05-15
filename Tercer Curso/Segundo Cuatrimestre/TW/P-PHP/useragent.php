<?php 
require "plantillasHTML.php";

preambuloHTML("User Agent");

echo "<p>La cadena del user agent es: <em>" . $_SERVER['HTTP_USER_AGENT'] . "</em></p>", PHP_EOL;

$useragent = $_SERVER['HTTP_USER_AGENT'];

$so = array("Linux", "Windows", "MacOS", "Otro");

$info = array("Chrome" => array("Google Chrome", "Google", "BSD", "Blink"),
              "Internet Explorer" => array("Internet Explorer", "Microsoft", "Privativa", "Trident"),
              "Firefox" => array("Mozilla Firefox", "Fundación Mozilla", "GNU GPL", "Gecko"),
              "Opera" => array("Opera", "Opera Software", "Privativa", "Blink"),
              "Safari" => array("Safari", "Apple", "Privativa", "Webkit")
);


if(preg_match('/Linux/', $useragent)){
    $so_index = 0;
}else if(preg_match('/Windows/', $useragent)){
    $so_index = 1;
}else if(preg_match('/Mac OS/', $useragent)){
    $so_index = 2;
}else{
    $so_index = 3;
}

preg_match('/Chrome|Internet Explorer|Firefox|Opera|Safari/', $useragent, $buscador);

preg_match('/(?:'. $buscador[0] .'| Version)\/([0-9.]+)/', $useragent, $version);

echo "<p>Sistema operativo: <em>" . $so[$so_index] . "</em></p>", PHP_EOL;
echo "<p>Navegador: <em>" . $info[$buscador[0]][0] . "</em></p>", PHP_EOL;
echo "<p>Version: <em>" . $version[1] . "</em></p>", PHP_EOL;
echo "<p>Propietario: <em>" . $info[$buscador[0]][1] . "</em></p>", PHP_EOL;
echo "<p>Licencia: <em>" . $info[$buscador[0]][2] . "</em></p>", PHP_EOL;
echo "<p>Motor: <em>" . $info[$buscador[0]][3] . "</em></p>", PHP_EOL;

finHTML();

?>
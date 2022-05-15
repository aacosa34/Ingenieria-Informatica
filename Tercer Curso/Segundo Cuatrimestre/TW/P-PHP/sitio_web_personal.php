<?php
require "plantillasHTML.php";

$opcion = 0;

if (isset($_GET["p"]) && ($_GET["p"]>=0 || $_GET["p"]<=3))
  $opcion = $_GET['p'];

preambuloHTML_titulos("Sitio Web Personal", "Sitio Web Personal", "Hecho por Adrián Acosa Sánchez");

navHTML($opcion);
switch($opcion) {
    case 0: paginaInicioHTML(); break;
    case 1: paginaPortafolio(); break;
    case 2: paginaCV(); break;
    case 3: paginaPersonal(); break;
    case 4: paginaContacto(); break;
}


footerHTML();
finHTML();

?>
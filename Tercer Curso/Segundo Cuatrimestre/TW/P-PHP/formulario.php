<?php
require "plantillasHTML.php";

preambuloHTML("Validación de formularios");

?>
        <header>
            <h1>Datos de pago</h1>
        </header>
        <main>
            <form action="validacion.php" method="GET">
                <label>
                    Nombre:
                    <input type="text" placeholder="Escriba su nombre"/>
                </label>
                <label>
                    Email:
                    <input type="text" placeholder="Escriba su email"/>
                </label>
                <label>
                    Email (repetir):
                    <input type="text" placeholder="Repita su email"/>
                </label>
                <label>
                    Numero de tarjeta:
                    <input type="text"/>
                </label>
                <label>
                    Mes caducidad:
                    <input type="text"/>
                </label>
                <label>
                    Año caducidad:
                    <input type="text"/>
                </label>
                <label>
                    CVC:
                    <input type="text" />
                </label>
                <label>
                    Recibir información:
                    <input type="text" placeholder="Escriba su nombre"/>
                </label>
                <label>
                    Nombre:
                    <input type="text" placeholder="Escriba su nombre"/>
                </label>
                <label>
                    Nombre:
                    <input type="text" placeholder="Escriba su nombre"/>
                </label>

            </form>
        </main>


<?php
    finHTML();
?>
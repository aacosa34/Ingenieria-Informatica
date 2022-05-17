<?php
require "plantillasHTML.php";

preambuloHTML("Validación de formularios", "formulario.css");

?>
        <header>
            <h1>Datos de pago</h1>
        </header>
        <main>
            <form action="validacion.php" method="GET">
                <div>
                    <label>Nombre: </label>
                    <input type="text" name="nombre" placeholder="Escriba su nombre"/>
                </div>  
                <div>
                    <label>Email:</label>
                    <input type="text" name="email" placeholder="Escriba su email"/>
                <div>  
                    <label>Email (repetir): </label>
                    <input type="text" name="email2" placeholder="Repita su email"/>
                </div>
                <div>
                    <label>Numero de tarjeta: </label>
                    <input type="text" name="tarjeta"/>
                <div>   
                    <label>Mes caducidad: </label>
                    <input type="text" name="mes"/>
                </div>  
                <div>
                    <label>Año caducidad: </label>
                    <input type="text" name="anyo"/>
                </div> 
                <div>  
                    <label>CVC:</label>
                    <input type="text" name="cvc" />
                </div>
                <div>      
                    <label>Recibir información: </label>
                    <input type="radio" name="recibir" value="Sí"/> Sí
                    <input type="radio" name="recibir" value="No"/> No
                </div>
                <div>   
                    <label>Temas de interés: </label>
                    <input type="checkbox" name="intereses[]" value="aves"> Aves
                    <input type="checkbox" name="intereses[]" value="casas"> Casas
                    <input type="checkbox" name="intereses[]" value="coches"> Coches
                </div> 
                <input type="submit" name="boton" value="Enviar datos"/>
                
            </form>
        </main>


<?php
    finHTML();
?>
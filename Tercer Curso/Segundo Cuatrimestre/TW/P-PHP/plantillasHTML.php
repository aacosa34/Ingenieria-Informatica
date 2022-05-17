<?php
# HEAD PARA TODO HTML
function preambuloHTML($title, $style) {
    echo <<< HTML
    <!DOCTYPE html>
    <html>
        <head>
            <meta charset="utf-8">
            <link rel="stylesheet" href=$style>
            <title>$title</title>
        </head>
        <body>
    HTML;
}

# HEAD CON H1 Y H3 
function preambuloHTML_titulos($titulo, $h1, $h3, $style) {
    preambuloHTML($titulo, $style);
    echo <<< HTML
            <header>
                <h1>$h1</h1>
                <h3>$h3</h3>
            </header>
    HTML;
}

function navHTML($opcion) { 
    echo <<< HTML
    <nav>
    <ul class="indice">
    HTML;
    $items = ["Inicio", "Portafolio", "CV", "Personal", "Contacto"];
    foreach ($items as $k => $v)
      echo "<li".($k==$opcion?" class='activo'":"").">".
           "<a href='sitio_web_personal.php?p=".($k)."'>".$v."</a></li>";
    echo <<< HTML
    </ul>
    </nav>
    HTML;
}

function footerHTML() {
    echo <<< HTML
    <footer>
        <small>(C) Adrián Acosa Sánchez</small>
    </footer>
    HTML; 
}

function paginaInicioHTML() {
    echo <<< HTML
    <main>
        <h2>INICIO</h2>
        <br>
        <p>Hola, me llamo Adrián Acosa. Soy estudiante de Ingeniería Informática en la mención de Tecnologías de la Información. Esta página
        ha sido desarrollada para la asignatura de Tecnologías Web. <br>
        <br>Te doy la bienvenida a la página de bienvenida de mi sitio web personal. Para cambiar entre las distintas páginas del sitio y
        obtener más información relacionada, use el índice situado más arriba.</p>
    </main>
    HTML;
}

function paginaPortafolio() {
    echo <<< HTML
    <main>
        <h2>PORTAFOLIO</h2>
        <br>
        <h4>Trabajos realizados:</h4>
        <br>
            <ul>
                <li>Administración de servidores web.</li>
                <li>Gestión de redes empresariales.</li>
                <li>Programación de videojuegos.</li>
            </ul>
    </main>
    HTML;
}

function paginaCV(){
    echo <<< HTML
    <main>
        <h2>CURRÍCULUM VITAE</h2>
        <br>
        <h4>Descripción general</h4>
        <p>Soy un estudiante universitario con mucha capacidad de adaptación a cualquier situación
            que se me ponga por delante. Aprendo rápido a realizar cualquier tipo de tarea, ya que me
            gusta que las cosas se hagan bien. Siempre intento buscar una solución a cualquier problema
            que se me presenta y es complicado que me venga abajo en una situación que me supere.</p>
        <br>
        <h4>Historial de trabajo</h4>
        <ul>
            <li>Clases particulares de programación básica.</li>
        </ul>
        <br>
        <h4>Formación</h4>
        <ul>
            <li>Actualmente me encuentro cursando mi tercer año en la ETSIIT en el grado de <em>Ingeniería Informática</em>.</li>
        </ul>

        <br>
        <h4>Soft Skills</h4>
        <ul>
            <li>Capacidad de trabajar en equipo</li>
            <li>Aprendizaje rápido</li>
            <li>Positividad</li>
            <li>Capacidad de escucha</li>
    </main>
    HTML;
}

function paginaPersonal() {
    echo <<< HTML
    <main>
        <h2>AFICIONES</h2>
        <br>
        <h4>Mis aficiones son:</h4>
        <br>
            <ul>
                <li>Deporte.</li>
                <li>Videojuegos.</li>
                <li>Informática.</li>
            </ul>
    </main>
    HTML;
}

function paginaContacto() {
    echo <<< HTML
    <main>
        <h2>CONTACTO</h2>
        <br>
        <h4>Puedes contactar conmigo a través de:</h4>
        <br>
            <ul>
                <li>email: adri110301@gmail.com</li>
                <li>Twitter: <a href="https://twitter.com/">@aacosa34</a></li>
                <li>LinkedIn: <a href="https://es.linkedin.com/">Adrián Acosa Sánchez</a></li>
            </ul>
    </main>
    HTML;
}

function finHTML() {
    echo <<< HTML
    </body>
    </html>
    HTML;
}


?>
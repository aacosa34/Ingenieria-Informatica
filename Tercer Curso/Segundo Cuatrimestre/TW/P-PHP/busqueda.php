<?php 
        // Inicializamos biblioteca
        $curl = curl_init();
        // Ponemos opciones para la petición HTTP
        $url = 'https://www.todostuslibros.com/busquedas?keyword=Asensi';
        curl_setopt_array($curl, [
        CURLOPT_RETURNTRANSFER => 1, // Para que devuelva el HTML de la página
        CURLOPT_URL => $url, // URL que vamos a solicitar
        CURLOPT_USERAGENT => 'cURL' // Cadena user-agent enviada al servidor
        ]);
        // Hacemos la petición de la página
        $resp = curl_exec($curl);
        // Procesamos el resultado ... en $resp
        echo $resp;

        preg_match('/\d+ títulos/', $resp, $num_resultados);
        // Liberamos recursos y finalizamos
        curl_close($curl);
    ?>
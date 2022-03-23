#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[]) {

    int fd;

    //creamos un buffer intermediario para la transmisión de datos
    char buffer[1024];

    //creamos un archivo temporal
    FILE *temporal = tmpfile();

    int leidos;
    int dbloqueo;

    //redirigimos la entrada estandar, q ahora es fd
    dup2(fd, STDIN_FILENO);

    umask(0);
    int fdArch = open("FicheroAlmacen", O_RDWR | O_CREAT | O_TRUNC, 0777);
    //leemos los datos de la entrada estándar
    while ((leidos = read(fd, buffer, sizeof(buffer))) > 0) {
        //lee de 0 y escribe en temporal
        if (fwrite(buffer, 1, leidos, temporal) < 0) {  // fwrite pq escribe en archivo tmpfile()
            perror("Error en fwrite en la escritura del proxy\n");
            exit(-1);
        }

        if ((leidos = read(fd, buffer, sizeof(buffer))) < 0) {
            perror("Error en la lectura del proxy2\n");
            exit(-1);
        }

        if (write(fdArch, buffer, sizeof(buffer)) < 0) {
            perror("Error al escribir en el archivo almacén\n");
            exit(-1);
        }
    }

    if (leidos == 0) {
        if ((leidos = fread(buffer, 1, sizeof(buffer), temporal)) < 0) {
            perror("Error en la lectura fread del proxy\n");
            exit(-1);
        }
        while (leidos > 0) {
            if ((dbloqueo = open("bloqueo", O_RDWR | O_CREAT)) < 0) {
                perror("Error en open del archivo");
                exit(-1);
            }

            //Ya tenemos la pantalla en exclusión mutua; lo mismo que un cerrojo con fcntl()
            flock(dbloqueo, F_WRLCK);

            fread(buffer, 1, sizeof(temporal), temporal);  //fread pq lee de archivo tmpfile()

            dup2(fd, 1);    //Ahora la salida estándar es fd, la pantalla

            //leemos de temporal y escribimos en 1 (STDOUT_FILENO)
            write(fd, temporal, sizeof(temporal));
        }

        if (leidos == 0) {
            flock(dbloqueo, F_UNLCK);
            fclose(temporal);
            exit(-1);
        }
    }




}
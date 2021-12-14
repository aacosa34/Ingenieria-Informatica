#include <stdio.h>

// Errores
#include <errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

#define tamanio 1024
#define names 100

void crear_proxy(int pid, int fd_fifosalida){
    printf ("Proxy-servidor: %d\n", pid);
    // En la ruta actual
    char nombre_fifo[names];
    int fd;
    // Nombre del fichero binario de proxy
	  sprintf(nombre_fifo, "/tmp/fifo.%d",pid);

    printf("Creamos el mkfifo\n");

    if(unlink(nombre_fifo) == 0){
        printf("%s borrado\n", nombre_fifo);
    }

    // Creamos el fichero fifo del proxy
    if(mkfifo(nombre_fifo, 0777) == -1){
        perror("Error al crear archivo fifo");
        exit(EXIT_FAILURE);
    }

    if ((write(fd_fifosalida, &pid, sizeof(int))) < 0){
        perror ("Servidor: Problema con la escritura del PID del fifo\n");
        exit(EXIT_FAILURE);
    }

    // Abrimos el FIFO en modo de lectura
    if(fd=open(nombre_fifo,O_RDWR) < 0){
        perror("Error al abrir el archivo fifo\n");
        exit(EXIT_FAILURE);
    }

    // Redirigimos la entrada estándar al archivo
    dup2(fd, STDIN_FILENO);

    //Ejecuto el proxy con el parametro del fifo creado
    //El  proxy tiene que abrir el FIFO con la concatenacion de su pid propio
	if (execlp("./proxy", "proxy", NULL)){
        perror("Error al crear el proceso proxy\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]){

    dup2(STDOUT_FILENO, STDERR_FILENO);

    setbuf(stdout, NULL);
    // Errores de argumentos
    if (argc > 2 || argc <= 1){
        printf ("Error: el numero de parametros no es correcto\n"
                 "Los parametros son: \n"
                 "%s <nombre_fifo>", argv[0]);
        exit(EXIT_FAILURE);
    }

    // El cliente hace la solicitud. La recibimos con un FIFO
    // Nombres de FIFO - Composicion fijada desde clientes.c
    // uno de entrada y otro de salida (desde el punto de vista del servidor).
    char fifoentrada[names];
    char fifosalida[names];
    char * buffer[tamanio];

    // descriptores de archivos fifo
    int fd_fifoentrada;
    int fd_fifosalida;

    sprintf(fifoentrada,"%se",argv[1]);
    sprintf(fifosalida,"%ss",argv[1]);

    // Borramos los fifos existentes anteriormente si los hubiese
    if(unlink(fifoentrada) == 0){
        printf("%s borrado\n", fifoentrada);
    }

    if(unlink(fifosalida) == 0){
        printf("%s borrado\n", fifosalida);
    }

    // Creacion de los FIFOS
    umask(0);
    if((mkfifo(fifoentrada, 0666)) == -1){
        perror("Error al crear archivo fifo de entrada");
        exit(EXIT_FAILURE);
    }


    if((mkfifo(fifosalida, 0666)) == -1){
        perror("Error al crear archivo fifo de salida");
        exit(EXIT_FAILURE);
    }

    // El fifo de entrada del servidor es de solo lectura para leer los datos convenientes
    // Es ignorada -- para ver si el cliente esta disponible
     if ((fd_fifoentrada = open (fifoentrada, O_RDWR)) < 0) {
        perror ("Servidor: Problema con el archivo fifo de entrada al servidor");
        exit(EXIT_FAILURE);
    }


    // El fifo de salida del servidor necesita permisos de lectura y escritura
    // Utilidad -- Informar del PID del proxy al cliente
    if ((fd_fifosalida = open (fifosalida, O_RDWR)) < 0) {
        perror ("Servidor: Problema con el archivo fifo de salida del servidor");
        exit(EXIT_FAILURE);
    }

    // Nos mantenemos a la espera de que el fifoentrada se llene y por lo tanto un tamanio
    // mayor a 0 bytes
    int pid, pid_real;
    int pid_cliente, resultado;
    int salida = 0;

    while (salida != -1){
        if ((resultado = read(fd_fifoentrada,&pid_cliente,sizeof(int))) > 0){
            // confirmando que tenemos el cliente
            pid = fork();
            if (pid == 0){
                pid_real = getpid();
                crear_proxy(pid_real, fd_fifosalida);
            }
            else if (pid == -1) {
                perror("fallo en fork\n");
                exit(EXIT_FAILURE);
            }
        }
        else {
            salida = -1;
        }
    }
}

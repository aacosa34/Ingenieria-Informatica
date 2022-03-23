#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>

void manejador(){
    int estado;
    pid_t pid;
    
    pid = wait(&estado);
}

int main(int argc, char **argv){
    int num_clientes = atoi(argv[1]);
    char pathname[512];
    DIR *dir;
    struct dirent *directorio;
    struct stat atributos;

    signal(SIGCHLD, manejador);

    if (dir = opendir(argv[2]) == NULL){
        perror("Error al abrir el directorio\n");
        exit(EXIT_FAILURE);
    }

    while(directorio = readdir(dir) != NULL && !S_ISREG(atributos.st_mode)){
        directorio = readdir(dir);
        sprintf(pathname, "%s/%s", argv[2], directorio->d_name);
        lstat(pathname, &atributos);
    }

    if(directorio == NULL){
        perror("No hay archivos regulares en el directorio\n");
        exit(EXIT_FAILURE);
    }

    int b = atributos.st_size;
    int a = directorio->d_ino;

    pid_t pid;

    umask(0);
    mkfifo("operacion", 0644);

    for(int i = 0; i < num_clientes; i++){
        pid = fork();
        if(pid == 0){
            srand((unsigned int) getpid());
            int op = rand() % 2 + 1;
            execlp("./calculadora", "calculadora", a, op, b);
        }
        else{
            int resultado;
            int fdfifo = open("operacion", O_RDONLY);
            while(read(fdfifo, &resultado, sizeof(int)) > 0)
                printf("El resultado de la operacion es: %d", resultado);
        }
    }

}
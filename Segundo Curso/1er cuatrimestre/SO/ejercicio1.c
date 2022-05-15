#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    struct stat atributos;

    lstat(argv[1], &atributos);

    if(S_ISDIR(atributos.st_mode)){
        printf("Última modificación del directorio: %s\n", ctime(atributos.st_mtime));
    }
    else{
        printf("El argumento no es un directorio\n");
    }

    return 0;

}
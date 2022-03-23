/* Ejercicio 2 Módulo 2 Sesión 2*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[]){
    
    if(argc != 3){
        printf("USO CORRECTO: ./ejercicio2 <pathname> <permisos>\n");
        exit(EXIT_FAILURE);
    }
    
    DIR *path;

    if( (path = opendir(argv[1])) == NULL ){
        printf("Error %d en opendir\n", errno);
        exit(EXIT_FAILURE);
    }

    struct dirent *archivo;
    struct stat atributos;
    char pathArchivo[512];
    int permisos = strtol(argv[2], NULL, 8);

    while( (archivo = readdir(path)) != NULL ){
        sprintf(pathArchivo, "%s/%s", argv[1], archivo->d_name);

        if(lstat(pathArchivo, &atributos) < 0){
            printf("Error %d en stat\n", errno);
            exit(EXIT_FAILURE);
        }

        int permisosAntiguos = atributos.st_mode & (S_IRWXU|S_IRWXG|S_IRWXO);

        if(strcmp(archivo->d_name, ".") && strcmp(archivo->d_name, "..")){
            if(chmod(pathArchivo, permisos) == 0)
                printf("%s : %o %o\n", archivo->d_name, permisosAntiguos, permisos);
            else
                printf("%s : %d %o\n", archivo->d_name, errno, permisosAntiguos);
        }
       
    }

    if(closedir(path) < 0){
        printf("Error %d en closedir\n", errno);
        exit(EXIT_FAILURE);
    }

}
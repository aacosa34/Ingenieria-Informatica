/* Ejercicio 3 Módulo 2 Sesión 2 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define IFXGRPOTH 011

int regulares = 0;
int tam = 0;

void buscar(DIR *dir, char* camino);

int main(int argc, char *argv[]){
    DIR *dir;
    
    printf("Los i-nodos son:\n\n");
    
    if(argc == 2){
        dir = opendir(argv[1]); // control de errores
        buscar(dir, argv[1]);
    }
    else{
        dir = opendir(".");
        buscar(dir, ".");
    }

    printf("Existen %d archivos regulares con permiso x para el grupo y otros\n", regulares);
    printf("El tamaño total ocupado por dichos archivos es %d bytes\n", tam);

    closedir(dir);
}

void buscar(DIR *dir, char* camino){
    
    struct dirent *entrada;    
    struct stat atributos;
    char pathname[512];
    DIR *subdir;
    
    while( (entrada = readdir(dir)) != NULL ){

        if(strcmp(entrada->d_name, ".") && strcmp(entrada->d_name, "..")){
            sprintf(pathname, "%s/%s", camino, entrada->d_name);

            if(lstat(pathname, &atributos) < 0){
                printf("Error %d en stat\n", errno);
                exit(EXIT_FAILURE);
            }

            if(S_ISREG(atributos.st_mode) && 
                (atributos.st_mode & S_IXGRP) && 
                (atributos.st_mode & S_IXOTH)){
                printf("%s %lu\n", pathname, atributos.st_ino);
                regulares++;
                tam += atributos.st_size;
            }
            else if (S_ISDIR(atributos.st_mode)) {
                subdir=opendir(pathname);
                buscar(subdir, pathname);
                closedir(subdir);
            }
            
        }
    }
    
}
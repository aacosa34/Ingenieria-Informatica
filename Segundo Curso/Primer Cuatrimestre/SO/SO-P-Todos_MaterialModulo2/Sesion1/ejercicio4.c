#include<unistd.h>  
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h> 
#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

#define ES_REGULAR(mode)    ((mode & S_IFMT) == S_IFREG)

int main (int argc, char* argv[]){
    struct stat atributos;

    if (argc != 2){
        // printf ();
        exit(-1);
    }

    if (lstat(argv[1], &atributos)<0){
        // printf()
        // perror()
        exit(-1);
    }

    if(ES_REGULAR(atributos.st_mode)){
        printf("Si es un archivo regular\n");
    }
    else{
        printf("No es un archivo regular\n");
    }

    return 1;
}
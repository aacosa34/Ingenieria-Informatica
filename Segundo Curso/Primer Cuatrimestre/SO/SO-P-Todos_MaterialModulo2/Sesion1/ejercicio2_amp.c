#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]){
    int fdin; // Entrada
    int fdout; // Salida
    const int TAM_BLOQUE = 20;
    char bloque[TAM_BLOQUE];
    const int TAM_BUFFER = 80;
    char buffer[TAM_BUFFER];
    int leidos;
    int cont = 1;
    char cadena[] = "El numero de bloques es %d\n";
    char salida[strlen(cadena)+2];

    if(argc == 2){
        if ((fdin = open(argv[1], O_RDONLY, S_IRUSR | S_IWUSR)) < 0){
            printf("\nError %d en open", errno);
            perror("\nError en open");
            exit(-1);
        }
    }
    else{
        fdin = STDIN_FILENO;
    }

    if ((fdout = open("salida.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR)) < 0){
        printf("\nError %d en open", errno);
        perror("\nError en open");
        exit(-1);
    }

    // Dejar espacio para la primera cadena
    lseek(fdout, strlen(cadena)+2, SEEK_SET);

    while ((leidos = read(fdin, buffer, TAM_BUFFER)) != 0) {
        sprintf(bloque, "\nBloque %d\n", cont); // Escritura del indice del bloque
        write(fdout, bloque, strlen(bloque));
        write(fdout, buffer, leidos);
        cont++;
    }

    // Volver al principio del archivo para escribir cadena al principio
    lseek(fdout, 0, SEEK_SET);
    sprintf(salida, cadena, cont-1);
    write(fdout, salida, strlen(salida));

    if(close(fdin) == -1){
        printf("\nError %d en close", errno);
        perror("\nError en close");
        exit(-1);
    }

    
    if(close(fdout) == -1){
        printf("\nError %d en close", errno);
        perror("\nError en close");
        exit(-1);
    }
    
    return 0;
}
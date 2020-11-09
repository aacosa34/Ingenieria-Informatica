#include ...

int main(int argc, char* argv[]){
    int fdin; // Entrada
    int fdout; // Salida
    const int TAM_BUFFER = 80;
    char buffer[TAM_BUFFER];
    int leidos;
    int cont = 1;

    if(argc == 2){
        if ((fdin = open(argv[1], O_RDONLY, S_IUSR|S_IWUSR)) < 0){
            printf("\nError %d en open", errno);
            perror("\nError en open");
            exit(-1);
        }
    }
    else{
        fdin = STDIN_FILENO;
    }

    if ((fdout = open("salida.txt", O_CREAT|O_TRUNC|O_WRONLY S_IUSR|S_IWUSR)) < 0){
        printf("\nError %d en open", errno);
        perror("\nError en open");
        exit(-1);
    }

    while ((leidos = read(fdin, buffer, TAM_BUFFER)) < 1) {
        write("Bloque %d", cont);
        cont+=1;
        write(fdout, buffer, leidos);
    }

    if(close(fdin) == -1){
        exit(-1);
    }

    
    if(close(fdout) == -1){
        exit(-1);
    }
    
    return 0;
}
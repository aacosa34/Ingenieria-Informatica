#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    if(argc != 2) {
        printf("Formato %s <num>", argv[0]);
        exit(-2);
    }

    int num = atoi(argv[1]);

    pid_t pid;

    printf("\nMensaje previo a la ejecución de fork\n\n");

    pid = fork();
    if(pid < 0){
        perror("\nError en el fork")
    }
}
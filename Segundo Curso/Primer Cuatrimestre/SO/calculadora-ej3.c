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
    int a = atoi(argv[1]);
    int op = atoi(argv[2]);
    int b = atoi(argv[3]);
    int res;
    char operator;
    char salida[11];

    int fd = open("operacion", O_WRONLY);

    int fdhistorico = open("historico.h", O_CREAT|O_TRUNC|O_RDWR, 0666);

    if(op == 1){
        printf("\nLa operacion es %d + %d, mi PID: %d", a, b, getpid());
        res = a + b;
        operator = '+'
    }
    else{
        printf("\nLa operacion es %d * %d, mi PID: %d", a, b, getpid());
        res = a * b;
        operator = '*';
    }

    sprintf(salida, "%d %s %d = %d\n", a, operator, b, res);

    flock(fdhistorico, F_WRLCK):

    write(fdhistorico, &salida, sizeof(salida)+2);

    flock(fdhistorico, F_UNLCK);
        
    write(fd, &res, sizeof(int));

    close(fdhistorico);

    return 0;
}
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
    int b = atoi(argv[3]);
    int res;

    int fd = open("operacion", O_WRONLY);

    if(atoi(argv[2]) == 1){
        printf("\nLa operacion es %d + %d, mi PID: %d", a, b, getpid());
        res = a + b;
    }
    else{
        printf("\nLa operacion es %d * %d, mi PID: %d", a, b, getpid());
        res = a * b;
    }
        
    write(fd, &res, sizeof(int));

    return 0;
}
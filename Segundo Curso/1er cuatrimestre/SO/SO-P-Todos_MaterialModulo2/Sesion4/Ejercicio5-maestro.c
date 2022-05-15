//Intentar que funcione para n hijos

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]){

    // ./maestro limite_inferior limite_superior
    // ./maestro 500 1000
    // [500, 1000] -> [500, 750] y [751, 1000]

    int minA, maxA;
    int minB, maxB;
    int fdEsclavo1[2], fdEsclavo2[2];
    int fdMaestro[2];
    int primo;

    pid_t PID1, PID2;

    if(argc != 3){
        printf("Error en el numero de argumentos\n");
        exit(-1);
    }

    //minA=strtol(argv[1], NULL, 10);
    //maxB=strtol(argv[2], NULL, 10);
    //Tambien podemos usar atoi():
    minA=atoi(argv[1]);
    maxB=atoi(argv[2]);
    //hace lo mismo el strtol y el atoi

    //Calculamos los extremos de los intervalos
    maxA=(minA+maxB)/2;
    minB=(maxA+1);

    pipe(fdEsclavo1);
    pipe(fdEsclavo2);
    pipe(fdMaestro);

    if((PID1=fork()) == 0){ //Primer hijo/esclavo
        //El esclavo 1 no tiene que comunicarse con el esclavo 2
        close(fdEsclavo2[0]);
        close(fdEsclavo2[1]);

        //En el cauce del maestro solo escribe, luego cierra el de lectura
        close(fdMaestro[0]);

        //En su cauce solo lee, luego cierra el de escritura
        close(fdEsclavo1[1]);
        //Cambiamos las salidas y entradas que recibirá el fichero esclavo
        dup2(fdEsclavo1[0], STDIN_FILENO);  //dup2 cierra la salida estándar y luego la redirecciona al primer argumento
        dup2(fdMaestro[1], STDOUT_FILENO);

        execl("./esclavo", "esclavo",NULL);
    } else if(PID2=fork() == 0){    //Segundo hijo/esclavo
        //El esclavo 2 no tiene que comunicarse con el esclavo 1
        close(fdEsclavo1[0]);
        close(fdEsclavo1[1]);

        //En el cauce del maestro solo escribe, luego cierra el de lectura
        close(fdMaestro[0]);

        //En su cauce solo lee, luego cierra el de escritura
        close(fdEsclavo2[1]);
        //Cambiamos las salidas y entradas que recibirá el fichero esclavo
        dup2(fdEsclavo2[0], STDIN_FILENO);
        dup2(fdMaestro[1], STDOUT_FILENO);

        execl("./esclavo", "esclavo", NULL);
    } else {
        //Si es el Maestro, cierra los descriptores de lectura, ya que solo va a escribir a los esclavos.
        close(fdEsclavo1[0]);
        close(fdEsclavo2[0]);
        close(fdMaestro[1]);    //No va a escribir en el cauce del Maestro, leerá de ahí

        //Escribe a los esclavos el minimo y el maximo del intervalo que le corresponde a cada uno
        write(fdEsclavo1[1], &minA, sizeof(int));
        write(fdEsclavo1[1], &maxA, sizeof(int));

        write(fdEsclavo2[1], &minB, sizeof(int));
        write(fdEsclavo2[1], &maxB, sizeof(int));

        while (read(fdMaestro[0], &primo, sizeof(int)))
        {
            printf("%d\n", primo);
        }
    }

    return 0;
}
#include <iostream>
#include "imagen.h"

using namespace std;

int main (){
    Imagen prueba1;

    prueba1.umbraliza("board.pgm", "pruebaumbraliza.pgm", 50, 250);

    Imagen prueba2;

    prueba2.zoom("saturno.pgm", "pruebazoom.pgm", 0, 0, 300, 300);

    Imagen prueba3;

    prueba3.contrasteTL("niveles.pgm", "pruebacontraste.pgm", 60, 200);

    Imagen prueba4;
 
    prueba4.morphing("vacas.pgm", "celulas.pgm", "vacascel");

    return 0;
}
#include <iostream>
#include "imagen.h"

using namespace std;

int main (){
    Imagen prueba1;

    prueba1.umbraliza("board.pgm", "pruebaumbraliza.pgm", 100, 200);

    Imagen prueba2;

    prueba2.zoom("saturno.pgm", "pruebazoom.pgm", 0, 0, 300, 300);

    return 0;
}
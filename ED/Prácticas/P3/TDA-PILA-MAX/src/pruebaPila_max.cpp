#include <iostream>
#include <iomanip>
#include "Pila_max.h"

using namespace std;

int main() {
    Pila_max<int> p, q;
    int dato;
    const int SALIDA = -1;

    cout << "Escriba una secuencia de números" << endl;
    cin >> dato;
    while(dato != SALIDA){
        p.poner(dato);
        cin >> dato;
    }
    cout << "Valor máximo contenido en la pila p: "<< p.maximo() << endl;

    Pila_max<int> r(p);

    cout << "Constructor de copia: pila r" << endl;
    cout << "Valor máximo contenido en la pila r(copia de p): "<< r.maximo() << endl;
    while(!r.vacia()){
        cout << r.tope_pila() << " ";
        r.quitar();
    }

    r = p;

    cout << endl << "Valor máximo contenido en la pila r (asignación de p): "<< r.maximo() << endl;

    cout << "La escribimos del revés" << endl;
    while(!p.vacia()){
        cout << p.tope_pila() << " ";
        q.poner(p.tope_pila());
        p.quitar();
    }

    cout << endl << "La frase original era" << endl;
    while(!q.vacia()){
        cout << q.tope_pila() << " ";
        q.quitar();
    }
    cout << endl;

     return 0;
}
#include <iostream>
#include "Pila_max_Cola.h"

using namespace std;

int main() {
    Pila_max<char> p, q;
    char dato;

    cout << "Escriba una frase" << endl;
    while((dato=cin.get())!='\n')
        p.poner(dato);

    cout << "La escribimos del revés" << endl;
    while(!p.vacia()){
        cout << p.tope_pila();
        q.poner(p.tope_pila());
        p.quitar();
    }

    cout << endl << "La frase original era" << endl;
    while(!q.vacia()){
        cout << q.tope_pila();
        q.quitar();
    }
    cout << endl;

    cout << "Valor máximo contenido en la pila p : "<< p.maximo() << endl;
    cout << "Valor máximo contenido en la pila q : "<< q.maximo() << endl;

 return 0;
}
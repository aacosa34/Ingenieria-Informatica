#include <iostream>
#include "calculadora.h"

using namespace std;

int main(int argc, char *argv[]) {
    int a,b;
    cout << "Introduce un numero: ";
    cin >> a;
    cout << "Introduce otro: ";
    cin >> b;

    Numero na(a);
    Numero nb(b);

    cout << "La suma es: " << suma(na, nb) << endl;
    cout << "El producto es: " << producto(na, nb) << endl;

    return 0;
}

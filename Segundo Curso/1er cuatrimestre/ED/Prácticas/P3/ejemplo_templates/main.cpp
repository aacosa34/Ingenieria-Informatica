#include "pareja.h"
#include <iostream>

/*
    ========================================
    Instanciación implícita 
    ========================================
    El programa se compila directamente
        g++ -o main main.cpp =I.
    
    ========================================
    Instanciación explícita 
    ========================================
    Se compila la template a objeto:
        g++ -c -o pareja.o -I.
        g++ -o main main.cpp pareja.o -I.
*/

int main() {
    Pareja<int, char> p(32, 'A');
    std::cout << p.first() << " " << p.second() << std::endl;
}
#include <cassert>
#include "pila_v.h"

Pila::Pila(){
    nelem = 0;
}

Pila::Pila(const Pila &p){
    copiar(p);
}

Pila & Pila::operator=(const Pila&p){
    copiar(p);

    return *this;
}

bool Pila::vacia() const{
    return nelem==0;
}

void Pila::poner(const Tbase & c){
    assert(nelem<TAM);
    pila[nelem++] = c;
}

void Pila::quitar(){
    assert(nelem>0);
    nelem--;
}

Tbase & Pila::tope(){
    assert(nelem>0);
    return pila[nelem-1];
}

const Tbase & Pila::tope() const{
    assert(nelem>0);
    return pila[nelem-1];
}

void Pila::copiar(const Pila &p){
    assert(p.nelem>0);
    for(int i = 0; i<nelem; i++){
        pila[i] = p.pila[i];
    }

    nelem = p.nelem;
}

Pila & Pila::operator--(){
    quitar();
    return *this;
}

Pila & operator+=(const Tbase & c){
    poner(c);
    return *this;
}
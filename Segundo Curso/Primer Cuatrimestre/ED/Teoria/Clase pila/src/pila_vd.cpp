#include <cassert>
#include "pila_vd.h"

Pila::Pila(int tam){
    reservar(reservados);
}

Pila::Pila(const Pila &p){
    copiar(p);
}

Pila::~Pila(){
    liberar();
}

Pila & Pila::operator=(const Pila&p){
    copiar(p);

    return *this;
}

bool Pila::vacia() const{
    return nelem==0;
}

void Pila::poner(const Tbase & c){
    if(nelem==reservados)
        resize(2*reservados);
    pila[nelem++] = c;
}

void Pila::quitar(){
    assert(nelem>0);
    nelem--;
    if(nelem<reservados/4)
        resize(reservados/2);
}

Tbase & Pila::tope(){
    assert(nelem>0);
    return pila[nelem-1];
}

const Tbase & Pila::tope() const{
    assert(nelem>0);
    return pila[nelem-1];
}

Pila & Pila::operator--(){
    quitar();
    return *this;
}

Pila & operator+=(const Tbase & c){
    poner(c);
    return *this;
}

void Pila::copiar(const Pila &p){
    nelem = p.nelem
    for(int i = 0; i<p.nelem; p++){
        pila[i] = p.pila[i];
    }
}

void Pila::resize(int n){
    assert(n>=nelem);

    int num_elementos = nelem;
    Tbase * aux = new Tbase [n];
    for(int i = 0; i<nelem; i++){
        aux[i] = pila[i];
    }
    liberar();
    
    reservados = n;
    nelem = num_elementos;
    pila = aux;
}

void Pila::reservar(int n){
    pila = new Tbase [n];
    reservados = n;
    nelem = 0;
}

void Pila::liberar(){
    delete [] pila;
    reservados = 0;
    nelem = 0;
}
/**
  * @file Pila_max_Cola.cpp
  * @brief Implementación del TDA Pila_max con vectores dinámicos
  */
#include <cassert>
#include "Pila_max_Cola.h"

// Constructor por defecto
template <class T>
Pila_max<T>::Pila_max(){
    tope = fondo = nullptr;
    num_elem = 0;
}

// Constructor de copia
template <class T>
Pila_max<T>::Pila_max(const Pila_max<T> & otra){
    copiar(otra);
}

// Destructor
template <class T>
Pila_max<T>::~Pila_max(){
    liberar();
}

// Operador de asignación
template <class T>
Pila_max<T> & Pila_max<T>::operator=(const Pila_max<T> & otra){
    liberar();
    copiar(otra);
    return *this;
}

// Esta vacía la pila
template <class T>
bool Pila_max<T>::vacia() const{
    return fondo == nullptr;
}

// Poner elemento en la pila
template <class T>
void Pila_max<T>::poner(const T & valor){
    T max = maximo();

    if (valor>maximo())
        max=valor;

    Celda nueva_celda(valor, max, nullptr);
    
    tope->siguiente = nueva_celda;

    tope = nueva_celda; 

    num_elem++;
}

// Quitar elemento de la pila
template <class T>
void Pila_max<T>::quitar(){
    Celda * aux = fondo;

    while(aux->siguiente->siguiente)
        aux = aux->siguiente;

    aux->siguiente = 0;

    delete tope;

    tope = aux;

    delete aux;

    num_elem--;    
}

// Elemento del tope de la pila
template <class T>
T& Pila_max<T>::tope_pila(){
    return tope->elemento;
}

// Consulta elemento del tope de la pila
template <class T>
const T& Pila_max<T>::tope_pila() const{
    return tope->elemento;
}

// Constulta del máximo elemento de la pila
template <class T>
const T& Pila_max<T>::maximo() const{
    return tope->max;
}

template <class T>
void Pila_max<T>::liberar(){
    Celda* aux;
    
    while(fondo!=0){
        aux = fondo;
        fondo = fondo->siguiente;
        delete aux;
    }
    fondo = 0;

    num_elem = 0;
}

// Copiar los datos de una pila a otra
template <class T>
void Pila_max<T>::copiar(const Pila_max<T> & otra){
    if (otra.fondo==0)
        fondo = 0;
    else{
        fondo = new Celda;
        fondo->elemento = otra.fondo->elemento;
        fondo->max = otra.fondo->max;
        Celda *orig = otra.fondo,
              *dest = fondo;

        while(orig->siguiente!=0){
            dest->siguiente = new Celda;
            orig = orig->siguiente;
            dest = dest->siguiente;
            dest->elemento = orig->elemento;
            dest->max = orig->max;
        }

    dest->siguiente = 0;
    num_elem = otra.num_elem;
    } 
}

template class Pila_max <char>;
template class Pila_max <int>;
template class Pila_max <double>;
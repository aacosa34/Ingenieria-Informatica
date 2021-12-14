/**
  * @file Pila_max_Cola.cpp
  * @brief Implementación del TDA Pila_max con vectores dinámicos
  */
#include <cassert>
#include "Pila_max_Cola.h"

using namespace std;

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
    T max;
    if(tope == nullptr)
        max = valor;
    else{
        max = maximo();
        if (valor>maximo())
            max=valor;
    }
    
    Celda *nueva_celda = new Celda(valor, max, tope);

    if(tope == nullptr){
        tope = fondo = nueva_celda;
        fondo->siguiente = nullptr;
    }
    else{
        tope = nueva_celda;
    }
    
    num_elem++;
}

// Quitar elemento de la pila
template <class T>
void Pila_max<T>::quitar(){
    assert(tope!=nullptr);

    Celda * aux = tope;
    tope = tope->siguiente;

    delete aux;

    if (tope == nullptr){
        fondo = nullptr;
    }

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
    if (otra.tope==nullptr)  // si está vacía
        fondo = tope = nullptr;
    else{                   // Caso general. Si no lo está
        tope = fondo = new Celda;   // Creamos la primera celda
        tope->elemento = otra.tope->elemento;
        tope->max = otra.tope->max;
        Celda *orig = otra.tope,
              *dest = tope;

        while(orig->siguiente!=nullptr){
            dest->siguiente = new Celda;
            orig = orig->siguiente;
            dest = dest->siguiente;
            dest->elemento = orig->elemento;
            dest->max = orig->max;
        }

    dest->siguiente = nullptr;
    num_elem = otra.num_elem;
    } 
}

template class Pila_max <int>;
template class Pila_max <double>;
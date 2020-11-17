/**
  * @file Pila_max_VD.cpp
  * @brief Implementación del TDA Pila_max con vectores dinámicos
  */
#include <cassert>
#include "Pila_max_VD.h"

// Constructor por defecto
template <class T>
Pila_max<T>::Pila_max(){
    datos = 0;
}

// Constructor de copia
template <class T>
Pila_max<T>::Pila_max(const Pila_max<T> & otra){
    datos = otra.datos;
}

// Destructor
template <class T>
Pila_max<T>::~Pila_max(){
    datos.swap(datos);
}

// Operador de asignación
template <class T>
Pila_max<T> & Pila_max<T>::operator=(const Pila_max<T> & otra){
    datos = otra.datos;
    return (*this);
}

// Esta vacía la pila
template <class T>
bool Pila_max<T>::vacia() const{
    return datos.empty();
}

// Poner elemento en la pila
template <class T>
void Pila_max<T>::poner(const T & valor){
    T max = maximo();

    if (valor>maximo())
        max=valor;

    Celda nueva_celda(valor,max);

    datos.push_back(nueva_celda);
}

// Quitar elemento de la pila
template <class T>
void Pila_max<T>::quitar(){
    datos.pop_back();
}

// Elemento del tope de la pila
template <class T>
T& Pila_max<T>::tope(){
    return datos.back();
}

// Consulta elemento del tope de la pila
template <class T>
const T& Pila_max<T>::tope() const{
    return datos.back();
}

// Constulta del máximo elemento de la pila
template <class T>
const T& Pila_max<T>::maximo() const{
    return datos.back().maximo;
}
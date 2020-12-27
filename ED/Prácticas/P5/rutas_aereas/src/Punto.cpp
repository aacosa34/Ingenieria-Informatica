#include "Punto.h"
#include<iostream>

using namespace std;

// Constructor por defecto
Punto::Punto(): longitud(0.0), latitud(0.0), nombre("") {}

// Constructor con dos parámetros
Punto::Punto(double lat, double lon, char* cad){
    latitud = lat;
    longitud = lon;
    nombre = cad;
}

// Consultor de la latitud de un punto
double Punto::GetLatitud(){
    return latitud;
}

// Consultor de la longitud de un punto
double Punto::GetLongitud(){
    return longitud;
}

// Operador ==
bool Punto::operator==(const Punto & otro) const{
    return (latitud == otro.latitud) && (longitud == otro.longitud);
}

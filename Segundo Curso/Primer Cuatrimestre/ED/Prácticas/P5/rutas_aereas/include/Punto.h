/**
 * @file Punto.h
 * @brief Fichero de cabecera del TDA Punto.
 */ 

#ifndef __PUNTO_H__
#define __PUNTO_H__

#include <iostream>

using namespace std;

/**
 * @brief T.D.A. Punto
 * 
 * Una instancia del tipo de dato Punto es un par de datos que representan
 * la longitud y la latitud de un punto sobre un mapa. Lo representamos:
 * 
 * (longitud, latitud)
 * 
 * @author Alejandro Rodger Marín y Adrián Acosa Sánchez
 * @date Diciembre 2020
 */

class Punto{
    private:
        double latitud;  ///< Coordenada con la latitud del punto
        double longitud;    ///< Coordenada con la longitud del punto       
        char* nombre;      ///< Nombre del punto
    
    public:
        /**
         * @brief Constructor por defecto de la clase Punto 
         */
        Punto();

        /**
         * @brief Constructor con las coordenadas de la latitud y longitud del punto
         * @param lat Latitud del punto
         * @param lon Longitud del punto
         * @param cad Nombre del punto
         */
        Punto(double lat, double lon, char* cad="");

        /**
         * @brief Consultor de la variable @e latitud
         * @return Latitud del punto
         */
        double GetLatitud();

        /**
         * @brief Consultor de la variable @e longitud
         * @return Longitud del punto
         */
        double GetLongitud();
        
        /**
         * @brief Operador relacional de igualdad
         * @param otro Punto a comparar
         * @return Devuelve true si los dos puntos son iguales.
         */
        bool operator==(const Punto & otro) const;

        /**
         * @brief Operador de entrada de datos
         * @param out variable de flujo de entrada
         * @param punto variable de la clase punto
         */
        friend istream & operator>>(istream & in, Punto & punto){
            double lat, lon;
            char basura;
            in >> basura >> lat >> basura >> lon >> basura;

            punto.latitud = lat;
            punto.longitud = lon;
    
            return in;
        }
        
        /**
         * @brief Operador de salida de datos
         * @param out variable de flujo de salida
         * @param punto variable de la clase punto
         */
        friend ostream & operator<<(ostream & out, const Punto & punto){
            out << "(" << punto.latitud << "," << punto.longitud << ")";

            return out;
        }
};

#endif
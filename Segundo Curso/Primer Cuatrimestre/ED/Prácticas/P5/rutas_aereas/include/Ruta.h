/**
 * @file Ruta.h
 * @brief Fichero de cabecera del TDA Ruta
 *
 */

#ifndef __RUTA_H__
#define __RUTA_H__

#include <iostream>
#include <vector>

#include "Punto.h"

/**
  *  @brief T.D.A. Ruta
  *
  * Una instancia del tipo de datos abstracto Ruta es un contenedor de 
  * todos los puntos de una ruta aérea. Lo representamos:
  * 
  * ruta[n]
  * 
  * donde n es el número de puntos de esa ruta.
  *
  * Un ejemplo de su uso:
  * @include pruebarutas.cpp
  *
  * @author Adrián Acosa Sánchez y Alejandro Rodger Marín
  * @date Diciembre 2020
  */

class Ruta{
    private:
        vector<Punto> ruta; ///< Vector de puntos de la ruta

    public:

        /**
         * @brief Constructor por defecto de la clase. Crea la Ruta vacía
         */
        Ruta();

        /**
         * @brief Método que añade un nuevo punto a la ruta.
         * @param p Punto a añadir
         */
        void aniade(const Punto & p);

        /**
         * @brief Método consultor del tamaño de la ruta
         */
        int size() const;

        /**
         * @brief Operador de asignación de la clase Ruta
         * @param otra Ruta
         * @return Una ruta con la misma información que la que se le pasa como parámetro
         */
        Ruta & operator=(const Ruta & otra);

        /**
         * @brief Operador de entrada de datos
         * @param in variable de flujo de entrada
         * @param ruta variable de la clase Ruta
         */
        friend istream & operator>>(istream & in, Ruta & rt);

        /**
         * @brief Operador de salida de datos
         * @param out variable de flujo de salida
         * @param ruta variable de la clase Ruta
         */
        friend ostream & operator<<(ostream & out, const Ruta & rt);

        // Iterador constante de la clase Ruta
        class iterator {
            private:
                vector<Punto>::iterator vit;
            public:
                iterator();

                iterator & operator++();
                Punto & operator*();
                bool operator!=(const iterator &it) const;

                friend class Ruta;
                friend class const_iterator;
        };

        /**
         * @brief Método que devuelve un iterador al principio de la ruta
         * @return Iterador al principio
         */
        iterator begin();

        /**
         * @brief Método que devuelve un iterador al final de la ruta
         * @return Iterador al final
         */
        iterator end();

        // Iterador constante de la clase Ruta
        class const_iterator {
            private:
                vector<Punto>::const_iterator vit;
            public:
                const_iterator();
                const_iterator(const Ruta::iterator & it);

                const_iterator & operator++();
                const Punto & operator*() const;
                bool operator!=(const const_iterator &it) const;

                friend class Ruta;
        };

        /**
         * @brief Método que devuelve un iterador constante al principio de la ruta
         * @return Iterador al principio
         */
        const_iterator begin() const;

         /**
         * @brief Método que devuelve un iterador constante al final de la ruta
         * @return Iterador al final
         */
        const_iterator end() const;

};

#endif
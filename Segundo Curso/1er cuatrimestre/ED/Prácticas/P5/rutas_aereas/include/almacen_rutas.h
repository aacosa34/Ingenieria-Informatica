/**
 * @file almacen_rutas.h
 * @brief Fichero de cabecera del TDA Almacen de rutas
 *
 */

#ifndef __ALMACEN_RUTAS_H__
#define __ALMACEN_RUTAS_H__

#include "Ruta.h"
#include<iostream>
#include<vector>
#include<string>

/**
  *  @brief T.D.A. Almacen de rutas
  *
  * Una instancia del tipo de datos abstracto Almacen de rutas
  * es un contenedor de todas las rutas aéreas que siguen
  * los aviones. Lo representamos:
  * 
  * almacen[n]
  * 
  * donde n es el número de rutas de ese almacen.
  *
  * @author Adrián Acosa Sánchez y Alejandro Rodger Marín
  * @date Diciembre 2020
  */

class Almacen_Rutas{
  private:
    vector<pair<string,Ruta>> almacen; ///< Almacen que contiene todas las rutas con sus códigos
  public:
    /**
     * @brief Constructor por defecto de la clase. Crea un almacen vacío
     */
    Almacen_Rutas();

    /**
     * @brief Método que añade una ruta al almacen de rutas
     * @param par Par con la nueva ruta y su código 
     */
    void aniade(pair<string, Ruta> par);

    /**
     * @brief Método que devuelve el tamaño del almacen de rutas
     * @return tamaño
     */
    int size() const;

    /**
     * @brief Operador de asignacion
     * @param otro Almacen de rutas a copiar
     * @return El almacen pasado como parámetro queda copiado en el almacen implícito
     */
    Almacen_Rutas & operator=(const Almacen_Rutas & otro);

    /**
     * @brief Operador de entrada de datos
     * @param in variable de flujo de entrada
     * @param almacen_ruta variable de la clase Almacen_Rutas
     */
    friend istream & operator>>(istream & in, Almacen_Rutas & almacen_rutas);

    /**
     * @brief Operador de salida de datos
     * @param out variable de flujo de salida
     * @param almacen_ruta variable de la clase Almacen_Rutas
     */
    friend ostream & operator<<(ostream & out, Almacen_Rutas & almacen_rutas);
    
    /**
     * @brief Devuelve una ruta dependiendo del código que se le pase 
     * como argumento
     * @param codigo string del código de la ruta
     */
    Ruta GetRuta(string codigo);

    /**
     * @brief Método que devuelve el código de la ruta indicada por su indice
     * @param indice Indice de la ruta
     */
    string GetCodigo(int indice);
};

#endif
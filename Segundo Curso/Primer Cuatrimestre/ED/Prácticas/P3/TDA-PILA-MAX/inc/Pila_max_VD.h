/**
  * @file Pila_max_VD.h
  * @brief Fichero cabecera del TDA Pila_max
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado en el mismo extremo.
  */

#ifndef __Pila_max_VD_H__
#define __Pila_max_VD_H__

#include <cassert>
#include <vector>

/**
 *  @brief T.D.A. Pila_max (Con vectores dinámicos)
 *
 *
 * Una instancia @e v del tipo de datos abstracto Pila_max sobre el tipo @c T es 
 * una lista de elementos del mismo con un funcionamiento @e LIFO (Last In, 
 * First Out). En esta implementación, cada casilla del vector tenemos almacenado
 * el propio elemento y el máximo de los elementos insertados. En una pila, las
 * operaciones de inserción y borrado de elementos tienen lugar en uno de los extremos
 * denominado @e Tope. Una pila de longitud @e n la denotamos

 * - [a1,a2,a3,..,an>

 * donde @e ai es el elemento de la posición i-ésima.

 * En esta pila, tendremos acceso únicamente al elemento del @e Tope, es decir, 
 * a @e an. El borrado o consulta de un elemento será sobre  @e an, y la
 * inserción de un nuevo elemento se hará sobre éste. Quedando el elemento
 * insertado como @e Tope de la pila.

 * Si @e n=0 diremos que la pila está vacía.

 * El espacio requerido para el almacenamiento es O(n). Donde n es el número de
 * elementos de la Pila.
 *
 * @author Alejandro Rodger Marín y Adrián Acosa Sánchez. 
 * @date Octubre 2020
 */

template<class T>
class Pila_max{
  private:
    struct Celda {
      T elemento;           ///< Elemento de información
      T max;                ///< Elemento máximo hasta esta celda

      /**
       * @brief Constructor con parámetros
       * @param elemem Elemento de información
       * @param max Elemento maximo hasta esa celda
       */
      Celda(const T & elem, const T & maximo) : 
        elemento(elem), max(maximo){}
    };

    std::vector<Celda> datos;   ///< Contenedor de datos de tipo Celda

  public:

    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    Pila_max();

    /**
     * @brief Constructor de copias
     * @param original La cola de la que se har� la copia.
     */
    Pila_max(const Pila_max<T> & original);
    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~Pila_max();
    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignación
     * @param otra La Pila_max_Cola que se va a asignar
     */
    Pila_max & operator=(const Pila_max<T> & otra);

    /**
     * @brief Devuelve si la pila está vacía o no
     */
    bool vacia() const;

    /**
     * @brief Añade un elemento al comienzo de la pila
     * @param valor Elemento a añadir
     */
    void poner(const T & valor);

    /**
     * @brief Elimina el primer elemento de la pila
     */
    void quitar();

    /**
     * @brief Devuelve el elemento del frente de la pila
     * @return El elemento del frente de la pila
     */
    T& tope_pila();

    /**
     * @brief Devuelve el elemento del frente de la pila de forma constante
     * @return El elemento del frente de la pila
     */
    const T& tope_pila() const;

    /**
     * @brief Devuelve el valor máximo de la pila
     * @return Valor máximo de la pila
     */
    const T& maximo() const;

};

#include <../src/Pila_max_VD.cpp>

#endif // __Pila_max_VD_H__
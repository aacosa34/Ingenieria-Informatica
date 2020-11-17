/**
  * @file Pila_max_Cola.h
  * @brief Fichero cabecera del TDA Pila_max (Partiendo de implementación de Colas)
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos por el mismo extremo.
  */

#ifndef __Pila_max_Cola_H__
#define __Pila_max_Cola_H__

#include <cassert>

/**
 *  @brief T.D.A. Pila_max (Partiendo de una cola)
 *
 *
 * Una instancia @e c del tipo de dato abstracto Pila_max_Cola sobre un dominio
 * @e T es una sucesión finita de elementos del mismo con un funcionamiento @e 
 * LIFO (Last In, First Out). Cada uno de los datos de esta pila tendrá dos datos:
 * el propio elemento y el valor máximo hasta ese elemento. En una pila, las 
 * operaciones de inserción, consulta y borrado tienen lugar en uno de los extremos, 
 * denominado @e tope de la pila, y el otro extremo se denomina @e fondo de la pila.
 * Una pila de longitud @e n la denotamos

 * - [a1|a_max_a1,a2|a_max_a2,a3|a_max_a3,...,an|a_max_an>

 * En esta pila, tendremos acceso únicamente al elemento del @e tope,
 * es decir, a @e a_max_an.
 * 
 * Si n=0 diremos que la pila está vacía.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el número 
 * de elementos de la pila.
 *
 * @author Alejandro Rodger Marín y Adrián Acosa Sánchez
 * @date Noviembre 2020
*/
template<class T>
class Pila_max{
  private:
    struct Celda {
      T elemento;           ///< Elemento de información
      T max;                ///< Elemento máximo hasta esta celda
      Celda * siguiente;    ///< Puntero al siguiente nodo

      /**
       * @brief Constructor por defecto
       */

      Celda() : siguiente(0){}

      /**
       * @brief Constructor con parámetros
       * @param elem Elemento de información
       * @param sig Puntero al siguiente nodo
       * @param maximo Elmento máximo hasta esa celda
       */
      Celda(const T & elem, const T & maximo, Celda * sig) : 
        elemento(elem), max(maximo), siguiente(sig){}

    };

    Celda * tope;  ///< Puntero al primer nodo de la lista
    Celda * fondo;   ///< Puntero al último nodo de la lista
    int num_elem;

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
    T& tope();

    /**
     * @brief Devuelve el elemento del frente de la pila de forma constante
     * @return El elemento del frente de la pila
     */
    const T& tope() const;

    /**
     * @brief Devuelve el valor máximo de la pila
     * @return Valor máximo de la pila
     */
    const T& maximo() const;

private:

    /**
     * @brief Libera la memoria utilizada por la pila.
     * @post La memoria queda liberada.
     */
    void liberar();

    /**
     * @brief Copia el contenido de una pila en otra.
     * @param otra Una pila con datos.
     * @pre La memoria ha sido reservada correctamente para el objeto implícito.
     * @post Los datos quedan copiados en la pila implícita.
     */
    void copiar(const Pila_max<T> & otra); 

};

#include <Pila_max_Cola.cpp>

#endif // __Pila_max_Cola_H__
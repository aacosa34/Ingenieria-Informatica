/**
 * @file pila_vd.h
 * @brief Fichero de cabecera del TDA pila
 */

#ifndef __PILA_VD_H__
#define __PILA_VD_H__

typedef char Tbase; /**< tipo de datos almacenados en las pilas */
const int TAM=10; /**< tamaño inicial que tendrá el vector dinámico de la pila */

/**
 * @brief T.D.A. Pila
 * Una instancia del tipo de dato abstracto pila es una colección de datos
 * de tipo Tbase para una gestión cómoda de estos.
 * 
 * Lo representamos como:
 * pila[TAM];
 * 
 * Un ejemplo de su uso:
 * @include uso_pila.cpp
 * 
 * @author Adrián Acosa Sánchez
 * @date Noviembre 2020
 */

class Pila{

private:

/** 
 * @page repConjunto Rep del TDA Pila
 * 
 * @section invConjunto Invariante de la representación
 * 
 * El invariante es \e rep.nelem<TAM
 * 
 * @section faConjunto Función de abstracción
 * 
 * Un objeto válido @e rep del TDA Pila representa el valor
 * 
 * pila[TAM]
 */

    Tbase pila[TAM]; /**< pila */
    int nelem;      /**< número de elementos usados */
    int reservados; /**< Número de celdas reservadas para la pila */

public:

    /**
     * @brief Constructor por defecto de la clase. Crea una pila vacía de tamaño n
     * @param tam Memoria reservada a la pila inicialmente
     */
    Pila(int tam=TAM);

    /**
     * @brief Constructor de copia de la clase. Crea una pila a partir de otra.
     * @param p Referencia a una pila
     * @pre \e p existe
     * @post \e e es copiado en el objeto implícito
     */
    Pila(const Pila & p);

    /**
     * @brief Destructor de la clase. Libera los recursos ocupados por la pila
     * @post La pila destruida no puede volver a usarse, salvo que se vuelva a 
     * hacer sobre ella una llamada a \e Pila()
     */
    ~Pila();

    /**
     * @brief Asignar una pila a otra. Realiza una copia profunda en el objeto 
     * implícito.
     * @param p Pila
     * @pre \e p existe
     * @return La pila copiada
     * @post La pila implícita se modifica. Cambia todos sus valores por
     * los de la pila \e p
     */
    Pila & operator=(const Pila &p);

    /**
     * @brief Comprobar si una pila está vacia.
     * @return \e true si la pila está vacia, \e false si no lo está
     */ 
    bool vacia() const;

    /**
     * @brief Añade un elemento en el tope de la pila
     * @param c constante del tipo Tbase
     */
    void poner(const Tbase & c);

    /**
     * @brief Elimina el elemento del tope de la pila
     */
    void quitar();

    /**
     * @brief Devuelve una referencia al elemento tope de la pila
     */
    Tbase & tope();

    /**
     * @brief Devuelve una referencia constante al elemento tope de la pila
     */
    const Tbase & tope() const;

private:

    /**
     * @brief Copia el contenido de una pila en otra
     * @param p una pila no vacía
     */
    void copiar(const Pila &p);

    /**
     * @brief Redimensiona una pila
     * @param n entero con el tamaño a redimensionar
     * @post la pila tiene un tamaño igual al parámetro @e n
     */
    void resize(int n);

    /**
     * @brief Libera la memoria ocupada por la pila
     * @post la memoria queda liberada
     */
    void liberar();

    /**
     * @brief Reserva memoria para la pila
     * @param n tamaño de la memoria a reservar para la pila
     * @post La memoria reservada es igual a la del parámetro @e n
     */
    void reservar(int n);
};

#endif /* pila_h */
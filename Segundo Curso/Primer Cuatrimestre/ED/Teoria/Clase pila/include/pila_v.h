/**
 * @file pila_v.h
 * @brief Fichero de cabecera del TDA pila
 */

#ifndef __PILA_V_H__
#define __PILA_V_H__

typedef char Tbase; /**< tipo de datos almacenados en las pilas */
const int TAM=500; /**< tamaño que tendrá el vector estático de la pila */

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

public:

    /**
     * @brief Constructor por defecto de la clase. Crea una pila vacía
     */
    Pila();

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
    ~Pila() = default;

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

    /**
     * @brief Sobrecarga del operador -- para quitar el elemento tope de la pila
     */
    Pila & operator--();

    /**
     * @brief Sobrecarga del operador += 
     * @param c referencia constante de tipo Tbase
     */
    Pila & operator+=(const Tbase & c);

private:

    /**
     * @brief Copia el contenido de una pila en otra
     * @param p una pila no vacía
     */
    void copiar(const Pila &p);
};

#endif /* pila_h */
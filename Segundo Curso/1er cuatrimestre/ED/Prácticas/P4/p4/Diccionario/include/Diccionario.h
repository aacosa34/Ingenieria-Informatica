/**
  * @file Diccionario.h
  * @brief Fichero cabecera del T.D.A. no lineal Diccionario
  *
  * Tipo de dato que gestiona datos con claves e informacion
  * asociada a esas claves.
  */

#ifndef DICCIONARIO
#define DICCIONARIO

#include <list> // Inclusion de list STL

using namespace std;

/** 
 * @brief Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que
 * no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave
 * de tipo T. El diccionario está ordenado de menor a mayor clave.
 */
template <class T, class U>
struct data{
  T clave;              ///< Clave de los diferentes elementos
  list<U> info_asoci;   ///< Elemento con la información asociada a la clave
};

/**
 * @brief Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T. Puede usarse como
 * un funtor.
 * @param d1 referencia a un dato de tipo @e data constante
 * @param d2 referencia a un dato de tipo @e data constante
 * @return Devuelve @e true si @e d1 es menor que @e d2, y 
 * @e false en caso contrario
 */
template <class T, class U>
bool operator< (const data<T,U> &d1,const data <T,U>&d2){
	if (d1.clave<d2.clave)
			return true;
	return false;
}	

/** 
 * @brief T.D.A. Diccionario
 * 
 * Un diccionario es una lista de datos de los definidos anteriormente. Cuidado porque se
 * manejan listas de listas. Se añaden 2 funciones privadas que hacen más facil la implementación
 * de algunos operadores o funciones de la parte pública. Copiar copia un diccioario en
 * otro y borrar elimina todos los elementos de un diccionario. La implementación de copiar
 * puede hacerse usando iteradores o directamente usando la función assign.
 * 
 * @author Pedro Antonio Mayorgas Parejo
 * @date Diciembre 2020
 */

template <class T, class U>
class Diccionario{
private:

  /**
	 * @brief Método de copia
	 * @param D Diccionario a copiar
	 * @post Los elementos del diccionario pasado como argumento quedan copiados en el implícito
	 */
	void Copiar(const Diccionario<T,U>& D);
	
	/**
	 * @brief Método de borrado de memoria
	 * @post El diccionario queda vacío
	 */
	void Borrar();

public:
	/**
	 * @brief Constructor por defecto
	 */
	Diccionario();
	
	/**
	 * @brief Constructor de copia
	 * @param D Diccionario a copiar
	 */
	Diccionario(const Diccionario &D);
	
	/**
	 * @brief Destructor
	 * @post La memoria almacenada en el diccionario queda liberada.
	 */
	~Diccionario();

/**
	 * @brief Operador de asignación
	 * @param D Diccionario a asignar
	 * @post El diccionario pasado como argumento queda copiado en el objeto implícito
	 */
	//Diccionario<T,U> & operator=(const Diccionario<T,U> &D);

	/**
	 * @brief Método de búsqueda de claves.
	 * 
	 * Busca la clave p en el diccionario. Si está devuelve un iterador a
	 * dónde está clave. Si no está, devuelve end() y deja el iterador de salida
	 * apuntando al sitio dónde debería estar la clave
	 * 
	 * @param p referencia a clave de tipo @e T
	 * @param it_out referencia al iterador del diccionario.
	 */
	//bool Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out);
	
	/**
	 * @brief Método de inserción de elementos.
	 * 
	 * Inserta un nuevo registro en el diccionario. Lo hace a través de la clave
	 * e inserta la lista con toda la información asociada a esa clave. Si el 
	 * diccionario no estuviera ordenado habría que usar la función sort() 
	 * 
	 * @param clave referencia constante a una clave de tipo @e T
	 * @param info referencia constante a la información
	 * @post Queda insertado un nuevo elemento en el diccionario
	 */
	//void Insertar(const T& clave,const list<U> &info);
	
	/**
	 * @brief Método para añadir significado a una clave
	 * 
	 * Añade una nueva informacion asocida a una clave que está en el diccionario.
	 * la nueva información se inserta al final de la lista de información.
	 * Si no esta la clave la inserta y añade la informacion asociada.
	 * 
	 * @param s referencia constante a la informacion
	 * @param p referencia constante a la clave de tipo @e T
	 * @post La información queda añadida en el diccionario
	*/
	//void AddSignificado_Palabra(const U & s ,const T &p);
	
	/**
	 * @brief Devuelve la información (una lista) asociada a una clave p. 
	 * 
	 * Podrían haberse definido operator[] como data<T,U> & operator[](int pos){ return datos.at(pos);}
	 * const data<T,U> & operator[](int pos)const { return datos.at(pos);}
	 * 
	 * @param p referencia a una clave
	 * @return Devuelve la información asociada a la clave p
	*/
	list<U>  getInfo_Asoc(const T & p);			   
	
	/**
	 * @brief Método de consulta del tamaño del diciconario
	 * @return Devuelve el tamaño del diccionario
	 */
	int size()const;
	
	/**
	 * @brief Funcion begin asociadas al diccionario
	 */
	typename list<data<T,U> >::iterator & begin();

	/**
	 * @brief Funcion end asociadas al diccionario
	 */
	typename list<data<T,U> >::iterator &end();
	
	/**
	 * @brief Funcion begin constante asociadas al diccionario
	 */
	typename list<data<T,U> >::const_iterator & begin()const;

	/**
	 * @brief Funcion end constante asociadas al diccionario
	 */
	typename list<data<T,U> >::const_iterator & end()const;

	// MÉTODOS A IMPLEMENTAR

	/**
	 * @brief Borra un elemento del diccionario por su clave.
	 * @param clave Referencia constante a una clave.
	 */
	void borra_elemento(const T &clave);
	
	/**
	 * @brief Une dos diccionarios. Si la misma clave se encuentra
	 * en ambos diccionarios, se fusionan las informaciones asociadas.
	 * @param otro Diccionario que se une.
	 */
	Diccionario<T,U> operator+(const Diccionario<T,U> & otro);

	/**
	 * @brief Devuelve los elementos dentro de un rango de claves
	 * @param ini clave inicial del rango.
	 * @param fin clave final del rango.
	 */
	list<U> getInfo_entreClaves(const T &ini, const T &fin);

	/**
	 * @brief Diferencia de diccionarios
	 * @param otro diccionario que se resta
	 */ 
	Diccionario<T,U> operator-(const Diccionario<T,U> &otro);

	// FIN MÉTODOS A IMPLEMENTAR



	/**
	 * @brief Clase iterador
	 * 
	 * Iterador de la clase Diccionario para gestionar los datos
	 * de los objetos de tipo Diccionario. 
	 */
  class iterator {
    private:
      typename list <data<T,U>>::iterator vit;
      friend class Diccionario<T, U>;

      iterator(typename list<data<T, U>>::iterator it); // Conversor del iterador que pasamos por argumento
    public:
      iterator();
      iterator(const iterator &it);

      iterator &operator=(const iterator &it);

      iterator &operator++();
      iterator &operator--();
      data<T, U> &operator*();

      bool operator==(const iterator &it) const;
      bool operator!=(const iterator &it) const;
    };
	
    /**
	 * @brief Clase iterador constante
	 * 
	 * Iterador de la clase Diccionario para gestionar los datos
	 * de los objetos de tipo Diccionario. 
	 */
	class const_iterator {
	private:
		typename list<data<T, U>>::const_iterator lit;			///< Iterador constante de la clase Diccionario
		friend class Diccionario<T, U>;

		const_iterator(typename list<data<T, U>>::const_iterator lit);	
	public:
		const_iterator();
		const_iterator(const const_iterator &it);

		const_iterator &operator=(const const_iterator &it);

		const_iterator &operator++();
		const_iterator &operator--();
		const data<T,U> &operator*() const;
		
		bool operator==(const const_iterator &it) const;
		bool operator!=(const const_iterator &it) const;
	};

};

#include "../src/Diccionario.cpp"
#endif

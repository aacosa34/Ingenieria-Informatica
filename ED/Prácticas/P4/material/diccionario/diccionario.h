/**
  * @file diccionario.h
  * @brief Fichero cabecera del T.D.A. no lineal Diccionario
  *
  * Tipo de dato que gestiona datos con claves e informacion
  * asociada a esas claves.
  */

#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>


using namespace std;

/** 
 * @brief Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que
 * no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave
 * de tipo T. El diccionario está ordenado de menor a mayor clave.
 */
template <class T,class U>
struct data{
T clave;			///< Clave de los diferentes elementos
list<U> info_asoci;	///< Elemento con la información asociada a la clave
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
 * @author Adrián Acosa Sánchez
 * @date Diciembre 2020
 */

template <class T,class U>
class Diccionario{
private:
	
	
	list<data<T,U> > datos; ///< Lista de datos del diccionario.
	
	/**
	 * @brief Método de copia
	 * @param D Diccionario a copiar
	 * @post Los elementos del diccionario pasado como argumento quedan copiados en el implícito
	 */
	void Copiar(const Diccionario<T,U>& D){
		//typename list<data<T,U> >::const_iterator it_d;
		//typename list<data<T,U> >::iterator it=this->datos.begin();
		
		datos.assign(D.datos.begin(),D.datos.end());
		/*for (it_d=D.datos.begin(); it_d!=D.datos.end();++it_d,++it){
				this->datos.insert(it,*it_d);
				
		}*/
	}
	
	/**
	 * @brief Método de borrado de memoria
	 * @post El diccionario queda vacío
	 */
	void Borrar(){
			
			this->datos.erase(datos.begin(),datos.end());
	}	      
		
			
public:
	/**
	 * @brief Constructor por defecto
	 */
	Diccionario():datos(list<data<T,U> >()){}
	
	/**
	 * @brief Constructor de copia
	 * @param D Diccionario a copiar
	 */
	Diccionario(const Diccionario &D){
		Copiar(D);
	}
	
	/**
	 * @brief Destructor
	 * @post La memoria almacenada en el diccionario queda liberada.
	 */
	~Diccionario(){}
	
	/**
	 * @brief Operador de asignación
	 * @param D Diccionario a asignar
	 * @post El diccionario pasado como argumento queda copiado en el objeto implícito
	 */
	Diccionario<T,U> & operator=(const Diccionario<T,U> &D){
		if (this!=&D){
				Borrar();
				Copiar(D);
		}
		return *this;
	}

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
	bool Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){
			
		if (datos.size()>0){
			
			typename list<data<T,U> >::iterator it;
			
			for (it=datos.begin(); it!=datos.end() ;++it){
			if ((*it).clave==p) {
					it_out=it;
					return true;
			}
			else if ((*it).clave>p){
					it_out=it;
					return false;
			}	  
				
			}
			
			it_out=it;
			return false;
		}
		else {	
			it_out=datos.end();
			return false;
		}	    
	}
	
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
	void Insertar(const T& clave,const list<U> &info){
		
		typename list<data<T,U> >::iterator it;
		
		if (!Esta_Clave(clave,it)){
			data<T,U> p;
			p.clave = clave;
			p.info_asoci=info;
		
			datos.insert(it,p);
				
		}
		
	}
	
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
	void AddSignificado_Palabra(const U & s ,const T &p){
		typename list<data<T,U> >::iterator it;
		
		if (!Esta_Clave(p,it)){
			datos.insert(it,p);
		}	    
		
		//Insertamos el siginificado al final
			(*it).info_asoci.insert((*it).info_asoci.end(),s);
	}
	
	/**
	 * @brief Devuelve la información (una lista) asociada a una clave p. 
	 * 
	 * Podrían haberse definido operator[] como data<T,U> & operator[](int pos){ return datos.at(pos);}
	 * const data<T,U> & operator[](int pos)const { return datos.at(pos);}
	 * 
	 * @param p referencia a una clave
	 * @return Devuelve la información asociada a la clave p
	*/
	list<U>  getInfo_Asoc(const T & p) {
		typename list<data<T,U> >::iterator it;
		
		if (!Esta_Clave(p,it)){
		return list<U>();
		}
		else{
		return (*it).info_asoci;
		}
	}			   
		
		
	
	/**
	 * @brief Método de consulta del tamaño del diciconario
	 * @return Devuelve el tamaño del diccionario
	 */
	int size()const{
		return datos.size();
	}

	
	/**
	 * @brief Funcion begin asociadas al diccionario
	 */
	typename list<data<T,U> >::iterator & begin(){
		datos.begin();
	}

	/**
	 * @brief Funcion end asociadas al diccionario
	 */
	typename list<data<T,U> >::iterator &end(){
		datos.end();
	}
	
	/**
	 * @brief Funcion begin constante asociadas al diccionario
	 */
	typename list<data<T,U> >::const_iterator & begin()const{
		datos.begin();
	}

	/**
	 * @brief Funcion end constante asociadas al diccionario
	 */
	typename list<data<T,U> >::const_iterator &end()const {
		datos.end();
	}
	

	/**
	 * @brief Clase iterador
	 * 
	 * Iterador de la clase Diccionario para gestionar los datos
	 * de los objetos de tipo Diccionario. 
	 */
	class iterator {
	private:
		typename list<data<T, U>>::iterator lit;			///< Iterador de la clase Diccionario 
		iterator(typename list<data<T, U>>::iterator lit){
			this.lit = lit;
		}

		friend class Diccionario<T, U>;

	public:
		iterator(){
			this.lit = NULL;
		}

		iterator(const iterator &it){
			this.lit = it.lit;
		}

		iterator &operator=(const iterator &it){
			if(this != &it)
				this.lit = it.lit;

			return *this;
		}

		iterator &operator++(){
			lit++;
			return *this;
		}

		bool operator!=(const iterator &it) const{
			return lit != it.lit;
		}
	};

	iterator begin(){
		return Diccionario<T,U>::iterator(datos.begin());
	}

	iterator end(){
		return Diccionario<T,U>::iterator(datos.end());
	}

	/**
	 * @brief Clase iterador constante
	 * 
	 * Iterador de la clase Diccionario para gestionar los datos
	 * de los objetos de tipo Diccionario. 
	 */
	class const_iterator {
	private:
		typename list<data<T, U>>::const_iterator lit;			///< Iterador constante de la clase Diccionario
		const_iterator(typename list<data<T, U>>::const_iterator lit){
			this.lit = lit;
		}		
		friend class Diccionario<T, U>;

	public:
		const_iterator(){
			this.lit = NULL;
		}
		const_iterator(const const_iterator &it){
			this.lit = it.lit;
		}

		const_iterator &operator=(const const_iterator &it){
			if(this != &it)
				this.lit = it.lit;

			return *this;
		}

		const_iterator &operator++(){
			lit++;
			
			return *this;
		}

		bool operator!=(const const_iterator &it) const{
			return lit != it.lit;
		}
	};

	const_iterator cbegin() const{

	}
	
	const_iterator cend() const{
		
	}	
		
};

#include "../src/diccionario.cpp"

#endif
	
	

	
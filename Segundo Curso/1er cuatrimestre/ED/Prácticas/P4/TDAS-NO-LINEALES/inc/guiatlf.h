/**
 * @file guiatlf.h
 * @brief Desarrollo del T.D.A no lineal Guía de telefonos
 * 
 * Tipo de dato que gestiona datos con una clave, y cada
 * una de las claves tienen sus datos asociados.
 */

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H

#include <map>
#include <iostream>
#include <string>

using namespace std;

istream & operator>>(istream &is,pair<string,string> &d){
	  
	  getline(is,d.first,'\t');
	  getline(is,d.second);
	  return is;
}	  

/**
 * @brief T.D.A Guía de teléfono
 * 
 * Una guía de teléfonos se encarga de gestionar datos
 * provenientes de archivos en los que tenemos un nombre de una
 * persona y su número de teléfono asociado.
 * 
 * @author Adrián Acosa Sánchez
 * @date Diciembre 2020
 */
class Guia_Tlf{
private:
	map<string,string> datos;			
public:
	Guia_Tlf();
	Guia_Tlf(const Guia_Tlf & gt);
	~Guia_Tlf();
	Guia_Tlf & operator=(const Guia_Tlf & gt);

	/**
		@brief Acceso a un elemento
		@param nombre: nombre del elemento  elemento acceder
		@return devuelve el valor asociado a un nombre, es decir el teléfono
	*/
	string & operator[](const string &nombre);
	
	string gettelefono(const string & nombre);
		
	/**
	 	@brief Insert un nuevo telefono 
		@param nombre: nombre clave del nuevo telefono
		@param tlf: numero de telefono
		@return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
	*/
	pair<map<string,string>::iterator,bool>  insert(string nombre, string tlf);
	
	/**
	 	@brief Insert un nuevo telefono 
		@param p: pair con el nombre y el telefono asociado
		@return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
	*/
	pair<map<string,string>::iterator,bool>  insert(pair<string,string> p);
	
	/**
		@brief Borrar un telefono
		@param nombre: nombre que se quiere borrar
		@note: en caso de que fuese un multimap borraria todos con ese nombre
	*/
	void borrar(const string &nombre);
	
	/**
		@brief Borrar un telefono
		@param nombre: nombre que se quiere borrar y telefono asociado
		@note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
	*/

	//con map siempre hay uno con multimap puede existir mas de uno
	void borrar(const string &nombre,const string &tlf);

	/**
		@brief  Numero de telefonos 
		@return el numero de telefonos asociados
	*/
	int size()const;

	/**
		@brief Contabiliza cuantos telefonos tenemos asociados a un nombre
		@param nombre: nombre sobre el que queremos consultar
		@return numero de telefonos asociados a un nombre	
	*/
	//al ser un map debe de ser 0 o 1. Si fuese un multimap podr�amos tener mas de uno
	unsigned int contabiliza(const string &nombre);
	
	/**
		@brief Limpia la guia
		*/
	void clear();

	/**
		@brief Union de guias de telefonos
		@param g: guia que se une
		@return: una nueva guia resultado de unir el objeto al que apunta this y g
	*/
	Guia_Tlf operator+(const Guia_Tlf & g);	   
				
	/**
		@brief Diferencia de guias de telefonos
		@param g: guia que se une
		@return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
	*/
	Guia_Tlf operator-(const Guia_Tlf & g);
	
	/**
		@brief Escritura de la guia de telefonos
		@param os: flujo de salida. Es MODIFICADO
		@param g: guia de telefonos que se escribe
		@return el flujo de salida
		*/ 
		
	
	friend ostream & operator<<(ostream & os, Guia_Tlf & g);
	
	/**
		@brief Lectura de  la guia de telefonos
		@param is: flujo de entrada. ES MODIFICADO
		@param g: guia de telefonos. ES MODIFICADO
		@return el flujo de entrada
	*/
	
	friend istream & operator>>(istream & is, Guia_Tlf & g);				    


	/**
	 * @brief Clase iterador
	 * 
	 * Iterador de la clase Guia_Tlf para gestionar los datos
	 * de los objetos de tipo Guia_Tlf. 
	 */
	class iterator {
	private:
		typename map<string, string>::iterator mit;			///< Iterador de la clase Guia_Tlf 
		iterator(typename map<string, string>::iterator mit);
		friend class Guia_Tlf;

	public:
		iterator();
		iterator(const iterator &it);
		iterator &operator=(const iterator &it);
		iterator &operator++();
		bool operator!=(const iterator &it) const;
	};

	/**
	 * @brief Clase iterador constante
	 * 
	 * Iterador de la clase Guia_Tlf para gestionar los datos
	 * de los objetos de tipo Guia_Tlf. 
	 */
	class const_iterator {
	private:
		typename map<string, string>::const_iterator mit;			///< Iterador constante de la clase Guia_Tlf
		const_iterator(typename map<string, string>::const_iterator mit);		
		friend class Guia_Tlf;

	public:
		const_iterator();
		const_iterator(const const_iterator &it);
		const_iterator &operator=(const const_iterator &it);
		const_iterator &operator++();
		bool operator!=(const const_iterator &it) const;
	};
};

#include "../src/guiatlf.cpp"

#endif


// Implementacion de Diccionario
#include "../include/Diccionario.h"

#ifndef DICCIONARIO_DEF
#define DICCIONARIO_DEF

// Método de copia de diccionarios
template <class T, class U>
void Diccionario<T,U>::Copiar(const Diccionario<T,U>& D){
  datos.assign(D.datos.begin(), D.datos.end());
}

// Método de borrado de diccionario
template <class T, class U>
void Diccionario<T,U>::Borrar(){
  this->datos.erase(datos.begin(),datos.end());
}

// Constructor por defecto
template <class T, class U>
Diccionario<T,U>::Diccionario(){
  datos.clear();
}

// Constructor de copia
template<class T, class U>
Diccionario<T,U>::Diccionario(const Diccionario &D){
    Copiar(D);
}

// Destructor
template<class T, class U>
Diccionario<T,U>::~Diccionario(){}

// Operador de asignación
template<class T, class U>
Diccionario<T,U> & Diccionario<T,U>::operator=(const Diccionario<T,U> &D){
    if (this!=&D){
        Borrar();
        Copiar(D);
    }
    return *this;
}

template<class T, class U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){		
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

// Método para insertar entradas en el diccionario
template<class T, class U>
void Diccionario<T,U>::Insertar(const T& clave,const list<U> &info){
    
  typename list<data<T,U> >::iterator it;

  if (!Esta_Clave(clave,it)){
      data<T,U> p;
      p.clave = clave;
      p.info_asoci=info;

      datos.insert(it,p);
          
  }
    
}

// Método para añadir significados a una palabra
template<class T, class U>
void Diccionario<T,U>::AddSignificado_Palabra(const U & s ,const T &p){
    typename list<data<T,U> >::iterator it;
    
    if (!Esta_Clave(p,it)){
        datos.insert(it,p);
    }	    
    
    //Insertamos el siginificado al final
        (*it).info_asoci.insert((*it).info_asoci.end(),s);
}

// Método para obtener los significados asociados a una palabra

template<class T, class U>
list<U> Diccionario<T,U>::getInfo_Asoc(const T & p) {
    typename list<data<T,U> >::iterator it;
    
    if (!Esta_Clave(p,it)){
    return list<U>();
    }
    else{
    return (*it).info_asoci;
    }
}
*/

// Método para obtener el tamaño del diccionario
template<class T, class U>
int Diccionario<T,U>::size()const{
    return datos.size();
}

template <class T, class U>
void Diccionario<T,U>::add(const data<T,U> d){
  datos.push_back(d);
}


// Iteradores no constantes

template <class T, class U>
typename Diccionario<T, U>::iterator Diccionario<T,U>::begin(){
  return Diccionario<T,U>::iterator(datos.begin());
}

template <class T, class U>
typename Diccionario<T, U>::iterator Diccionario<T,U>::end(){
  return Diccionario<T,U>::iterator(datos.end());
}


// Retorna iteradores constantes
/*
template<class T, class U>
typename Diccionario<T,U>::const_iterator & Diccionario<T,U>::begin()const{
  return Diccionario<T,U>::const_iterator(datos.begin());
}

template<class T, class U>
typename Diccionario<T,U>::const_iterator & Diccionario<T,U>::end()const {
	return Diccionario<T,U>::const_iterator(datos.end());
}
*/

/*
template <class T, class U>
bool Diccionario<T,U>
Esta_Clave (const T & p, list <data<T,U>> :: iterator & it_out) {
  bool status = false;

  list <data<T,U>> :: iterator pointer;

  if (!datos.empty){

    for (pointer = datos.begin(); pointer != datos.end() && !status; pointer++){

    }
  }

}
*/

// MÉTODOS A IMPLEMENTAR
/*
template<class T, class U>
void Diccionario<T,U>::borra_elemento(const T &clave){
  typename list<data<T,U> >::iterator it;

  if(Esta_Clave(clave, it)){
    datos.erase(it);
  }
}

template<class T, class U>
Diccionario<T,U> Diccionario<T,U>::operator+(const Diccionario<T,U> & otro){

}

template<class T, class U>
list<U> getInfo_entreClaves(const T &ini, const T &fin){

}

template<class T, class U>
Diccionario<T,U> operator-(const Diccionario<T,U> &otro){

}
*/

// FIN MÉTODOS A IMPLEMENTAR


//#############################################################################
// CLASE ITERATOR

template <class T, class U>
Diccionario<T,U>::iterator::iterator(){
  vit = 0;
}

template <class T, class U>
Diccionario<T, U>::iterator::iterator(typename list<data<T, U>>::iterator it) {
  vit = it;
}



template <class T, class U>
Diccionario<T, U>::iterator::iterator(const iterator &it) {
  vit = it.vit;
}


template <class T, class U>
typename Diccionario<T, U>::iterator &
Diccionario<T,U>::iterator::operator=(const iterator &it) {
  if (this != &it) {
    this -> vit = it.vit;
  }

  return *this;
}


template <class T, class U>
typename Diccionario<T,U>::iterator & Diccionario<T,U>::iterator::operator++(){
  vit++;

  return *this;
}


template <class T, class U>
typename Diccionario<T,U>::iterator & Diccionario<T,U>::iterator::operator--(){
  vit--;

  return *this;
}


template <class T, class U>
data<T, U> & Diccionario<T,U>::iterator::operator*(){
  return *vit;
}

template <class T, class U>
bool Diccionario<T,U>::iterator::operator==(const iterator &it) const{
  return this -> vit == it.vit;
}



template <class T, class U>
bool Diccionario<T,U>::iterator::operator!=(const iterator &it) const{
  return this->vit != it.vit;
}

//##################################################################################
// CLASE CONST_ITERATOR
/*
template<class T, class U>
Diccionario<T,U>::const_iterator::const_iterator(typename list<data<T, U>>::const_iterator lit){
	this.lit = lit;
}	

template<class T, class U>
Diccionario<T,U>::const_iterator::const_iterator(){
	this.lit = NULL;
}	

template<class T, class U>
Diccionario<T,U>::const_iterator::const_iterator(const const_iterator &it){
	this.lit = it.lit;
}

template<class T, class U>
typename Diccionario<T,U>::const_iterator 
&Diccionario<T,U>::const_iterator::operator=(const const_iterator &it){
	if(this != &it)
		this.lit = it.lit;
	return *this;
}

template<class T, class U>
typename Dicconario<T,U>::const_iterator & Dicconario<T,U>::const_iterator::operator++(){
  lit++;
			
	return *this;
}

template<class T, class U>
typename Diccionario<T,U>::const_iterator & Diccionario<T,U>::const_iterator::operator--(){
  lit--;

  return lit;
}

template<class T, class U>
const data<T, U> & Diccionario<T,U>::const_iterator::operator*() const{
  return *lit;
}

template <class T, class U>
bool Diccionario<T,U>::const_iterator::operator==(const const_iterator &it) const{
  return lit == it.lit;
}

template<class T, class U>
bool Dicconario<T,U>::const_iterator::operator!=(const const_iterator &it) const{
	return lit != it.lit;
}
*/

#endif

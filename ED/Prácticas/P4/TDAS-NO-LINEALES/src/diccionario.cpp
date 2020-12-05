// Métdo de copia
template <class T, class U>
void Diccionario<T,U>::Copiar(const Diccionario<T,U>& D){
	//typename list<data<T,U> >::const_iterator it_d;
    //typename list<data<T,U> >::iterator it=this->datos.begin();
    
    datos.assign(D.datos.begin(),D.datos.end());
    /*for (it_d=D.datos.begin(); it_d!=D.datos.end();++it_d,++it){
            this->datos.insert(it,*it_d);
            
    }*/
}

// Método de borrado de diccionario
template <class T, class U>
void Diccionario<T,U>::Borrar(){
	this->datos.erase(datos.begin(),datos.end());
}

// Constructor por defecto
template <class T, class U> 
Diccionario<T,U>::Diccionario():datos(list<data<T,U>>()) {};

// Constructor de copia
template<class T, class U>
Diccionario<T,U>::Diccionario(const Diccionario &D){
    Copiar(D);
}

template<class T, class U>
Diccionario<T,U>::~Diccionario(){}

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

template<class T, class U>
void Diccionario<T,U>::AddSignificado_Palabra(const U & s ,const T &p){
    typename list<data<T,U> >::iterator it;
    
    if (!Esta_Clave(p,it)){
        datos.insert(it,p);
    }	    
    
    //Insertamos el siginificado al final
        (*it).info_asoci.insert((*it).info_asoci.end(),s);
}

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

template<class T, class U>
int Diccionario<T,U>::size()const{
    return datos.size();
}

template<class T, class U>
typename list<data<T,U> >::iterator & Diccionario<T,U>::begin(){
    datos.begin();
}

template<class T, class U>
typename list<data<T,U> >::iterator & Diccionario<T,U>::end(){
	datos.end();
}

template<class T, class U>
typename list<data<T,U> >::const_iterator & Diccionario<T,U>::begin()const{
    datos.begin();
}

template<class T, class U>
typename list<data<T,U> >::const_iterator & Diccionario<T,U>::end()const {
	datos.end();
}

// MÉTODOS A IMPLEMENTAR

template<class T, class U>
void Diccionario<T,U>::borra_elemento(const T &clave){
    typename list<data<T,U> >::iterator it;
    if(Esta_Clave(clave, it)){
        datos.erase(it);
    }
}

template<class T, class U>
Diccionario<T,U> Diccionario<T,U>::operator+(const Diccionario<T,U> & otro){
    Diccionario<T,U> aux(*this);
    typename list<data<T,U>>::iterator it;

    for(it=otro.datos.begin(); it!=otro.datos.end();++it){
        if(it->first == )
    }
}

template<class T, class U>
list<U> getInfo_entreClaves(const T &ini, const T &fin){

}

template<class T, class U>
Diccionario<T,U> operator-(const Diccionario<T,U> &otro){

}

// FIN MÉTODOS A IMPLEMENTAR

// Diccionario::iterator

template<class T, class U>
Diccionario<T,U>::iterator::iterator(typename list<data<T, U>>::iterator lit){
    this.lit = lit;
}

template<class T, class U>
Diccionario<T,U>::iterator::iterator(){
    this.lit = NULL;
}

template<class T, class U>
Diccionario<T,U>::iterator::iterator(const iterator &it){
    this.lit = it.lit;
}

template<class T, class U>
typename Diccionario<T,U>::iterator &
Diccionario<T, U>::iterator::operator=(const iterator &it){
    if(this != &it)
        this.lit = it.lit;

    return *this;
}

template<class T, class U>
typename Diccionario<T,U>::iterator &Diccionario<T,U>::iterator::operator++(){
    lit++;
    return *this;
}

template<class T, class U>
bool Diccionario<T,U>::iterator::operator!=(const iterator &it) const{
    return lit != it.lit;
}

// Diccionario::const_iterator

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
bool Dicconario<T,U>::const_iterator::operator!=(const const_iterator &it) const{
	return lit != it.lit;
}
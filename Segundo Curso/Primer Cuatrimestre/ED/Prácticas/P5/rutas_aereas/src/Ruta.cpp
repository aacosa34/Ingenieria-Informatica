#include "Ruta.h"

using namespace std;

//Constructor por defecto
Ruta::Ruta(){}

//Operador de asignación
Ruta & Ruta::operator=(const Ruta & otra){
    ruta = otra.ruta;

    return *this;
}

void Ruta::aniade(const Punto & p){
    ruta.push_back(p);
}

int Ruta::size() const{
    return ruta.size();
}

// Operador de entrada de datos
istream & operator>>(istream & in, Ruta & rt){
    Ruta local;
    
    int tam;
    
    in >> tam;

    Punto nuevo_punto;
    for(int i = 0; i<tam; i++){
        in>>nuevo_punto;
        local.aniade(nuevo_punto);
    }

    rt = local;

    return in;
}

//Operador de salida de datos
ostream & operator<<(ostream & out, const Ruta & rt){
    Ruta::const_iterator puntero;

    int tam = rt.size();

    if(tam!=0){
        out << tam << " ";

        for(puntero = rt.begin(); puntero!=rt.end(); ++puntero){
            Punto punto = *puntero;
            out << "(" << punto.GetLatitud() << "," << punto.GetLongitud() << ") ";
        }
        
        out << "\n";
    }
    return out;
}

//##########################################################################################
// Clase iterator

//Constructor por defecto
Ruta::iterator::iterator(){}

//Operador ++
Ruta::iterator & Ruta::iterator::operator++(){
    ++vit;

    return *this;
}

//Operador *
Punto & Ruta::iterator::operator*(){
    return *vit;
}

//Operador !=
bool Ruta::iterator::operator!=(const iterator &it) const{
    return vit != it.vit;
}

//##########################################################################################

// Método que devuelve un iterador al principio de la ruta
Ruta::iterator Ruta::begin(){
    Ruta::iterator it;
    it.vit=ruta.begin();
    return it;
}

// Método que devuelve un iterador al final de la ruta
Ruta::iterator Ruta::end(){
    Ruta::iterator it;
    it.vit=ruta.end();
    return it;
}

//##########################################################################################
//Clase const_iterator

//Constructor por defecto
Ruta::const_iterator::const_iterator(){}

//Constructor de copia
Ruta::const_iterator::const_iterator(const Ruta::iterator & it){
    vit = it.vit;
}

//Operador ++
Ruta::const_iterator & Ruta::const_iterator::operator++(){
    ++vit;

    return *this;
}

//Operador *
const Punto & Ruta::const_iterator::operator*() const{
    return *vit;
}

//Operador !=
bool Ruta::const_iterator::operator!=(const const_iterator &it) const{
    return vit != it.vit;
}

//##########################################################################################

// Método que devuelve un iterador constante al principio de la ruta
Ruta::const_iterator Ruta::begin() const{
    Ruta::const_iterator it;
    it.vit=ruta.begin();
    return it;
}

// Método que devuelve un iterador constante al final de la ruta
Ruta::const_iterator Ruta::end() const{
    Ruta::const_iterator it;
    it.vit=ruta.end();
    return it;
}




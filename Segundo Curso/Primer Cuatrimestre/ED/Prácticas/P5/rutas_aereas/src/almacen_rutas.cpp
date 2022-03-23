#include "almacen_rutas.h"

using namespace std;

//Constructor por defecto
Almacen_Rutas::Almacen_Rutas(){}

// Añade una nueva ruta con su código
void Almacen_Rutas::aniade(pair<string, Ruta> par){
    almacen.push_back(par);
}

int Almacen_Rutas::size() const{
    return almacen.size();
}

Almacen_Rutas & Almacen_Rutas::operator=(const Almacen_Rutas & otro){
    almacen = otro.almacen;
    
    return *this;
}

//Operador de entrada de datos
istream & operator>>(istream & in, Almacen_Rutas & almacen_rutas){
    Almacen_Rutas local;

    if(in.peek()=='#'){
        string cadena;
        getline(in, cadena);
    }
    
    while (!in.eof()){
        Ruta nueva_ruta;
        string codigo;

        in >> codigo >> nueva_ruta;

        pair<string, Ruta> par;
        par.first = codigo;
        par.second = nueva_ruta;
        local.aniade(par);
    }

    almacen_rutas = local;
    
    return in;
}

//Operador de ssalida de datos
ostream & operator<<(ostream & out, Almacen_Rutas & almacen_rutas){
    string linea_clave = "#Rutas\n";
    out << linea_clave; 

    for (int i = 0; i<almacen_rutas.size(); i++){
        string codigo = almacen_rutas.GetCodigo(i);
        out << codigo << " ";
        out << almacen_rutas.GetRuta(codigo);
        out << "\n";
    }

    return out;
}

//Consultor del código de una ruta según su indice
string Almacen_Rutas::GetCodigo(int indice){
    return almacen[indice].first;
}

//Consultor de ruta según su código
Ruta Almacen_Rutas::GetRuta(string codigo){
    bool encontrado = false;
    Ruta buscada;
    
    for(int i = 0; i<size() && !encontrado; i++){
        if (almacen[i].first == codigo){
            buscada = almacen[i].second;
            encontrado = true;
        }
    }

    return buscada;
}
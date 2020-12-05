Guia_Tlf::Guia_Tlf():datos(map<string,string>()){}

Guia_Tlf::Guia_Tlf(const Guia_Tlf & gt){
    datos = gt.datos;
}

Guia_Tlf::~Guia_Tlf(){}

Guia_Tlf & Guia_Tlf::operator=(const Guia_Tlf & gt){
    if(this != &gt){
        clear();
        datos = gt.datos;
    }

    return *this;    
}

string & Guia_Tlf::operator[](const string &nombre) {
		return datos[nombre];
	}

string  Guia_Tlf::gettelefono(const string & nombre){
		map<string,string>::iterator it=datos.find(nombre);
		if (it==datos.end()) 
		return string("");
		else return it->second;
	}

pair<map<string,string>::iterator,bool>  Guia_Tlf::insert(string nombre, string tlf){
    pair<string,string> p (nombre,tlf);
    pair< map<string,string> ::iterator,bool> ret;

    ret=datos.insert(p); 
    return ret;     
        
}

pair<map<string,string>::iterator,bool>  Guia_Tlf::insert(pair<string,string> p){
    pair<map<string,string> ::iterator,bool> ret;

    ret=datos.insert(p); 
    return ret;     
        
}

void Guia_Tlf::borrar(const string &nombre){
    map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
    map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
    datos.erase(itlow,itupper);//borramos todos aquellos que tiene dicho nombre
}

void Guia_Tlf::borrar(const string &nombre,const string &tlf){
    map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
    map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
    map<string,string>::iterator it;
    bool salir =false;
    for (it=itlow; it!=itupper && !salir;++it){
        if (it->second==tlf){
            datos.erase(it);
            salir =true;
        }		
    }		
    
}

int Guia_Tlf::size()const{
	return datos.size();
}

unsigned int Guia_Tlf::contabiliza(const string &nombre){
	return datos.count(nombre);
}

void Guia_Tlf::clear(){
	datos.clear();
}

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf & g){
    Guia_Tlf aux(*this);
    map<string,string>::const_iterator it;

    for (it=g.datos.begin();it!=g.datos.end();++it){
        aux.insert(it->first,it->second);
    }	
        
    return aux;
}

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf & g){
    Guia_Tlf aux(*this);
    map<string,string>::const_iterator it;
    
    for (it=g.datos.begin();it!=g.datos.end();++it){
        aux.borrar(it->first,it->second);
    }
            
    return aux;
}

friend ostream & Guia_Tlf::operator<<(ostream & os, Guia_Tlf & g){
    map<string,string>::iterator it;

    for (it=g.datos.begin(); it!=g.datos.end();++it){
        os<<it->first<<"\t"<<it->second<<endl;
    }
    
    return os;
}

friend istream & Guia_Tlf::operator>>(istream & is, Guia_Tlf & g){
    pair<string,string> p;
    Guia_Tlf aux;
        
    while (is>>p){
        aux.insert(p);
    }

    g=aux;

    return is;
}

// Guia_Tlf::iterator

Guia_Tlf::iterator::iterator(typename map<string, string>::iterator mit){
    this.mit = mit;
}

Guia_Tlf::iterator::iterator(){
    this.mit = NULL;
}

Guia_Tlf::iterator::iterator(const iterator &it){
    this.mit = it.mit;
}
typename map<string, string>::iterator &Guia_Tlf::iterator::operator=(const iterator &it){
    if(this != &it){
        this.mit = it.mit;
    }
    return *this;
}

typename map<string, string>::iterator &Guia_Tlf::iterator::operator++(){
    mit++;
    return *this;    
}

bool Guia_Tlf::iterator::operator!=(const iterator &it) const{
    return mit != it.mit;
}

// Guia_Tlf::const_iterator

Guia_Tlf::const_iterator::const_iterator(typename map<string, string>::const_iterator mit){
    this.mit = mit;
}

Guia_Tlf::const_iterator::const_iterator(){
    this.mit = NULL;
}

Guia_Tlf::const_iterator::const_iterator(const const_iterator &it){
    this.mit = it.mit; 
}

typename map<string, string>::const_iterator &Guia_Tlf::const_iterator::operator=(const const_iterator &it){
    if(this != &it){
        this.mit = it.mit;
    }
    return *this;
}

typename map<string, string>::const_iterator &Guia_Tlf::const_iterator::operator++(){
    mit++;
    return *this;
}

bool Guia_Tlf::const_iterator::operator!=(const const_iterator &it) const{
    return mit != it.mit;
}
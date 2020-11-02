#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "imagenES.h"
#include "imagen.h"

using namespace std;

//Constructor por defecto
Imagen::Imagen(){
  filas = 0;
  cols = 0;
  img = 0;
}

//Constructor de copia
Imagen::Imagen(const Imagen & otra){
  reservar(otra.filas, otra.cols);
  copiar(otra);
} 

//Constructor con dos parametros
Imagen::Imagen(int f, int c){
  reservar(f,c);
} 

//Destructor
Imagen::~Imagen(){
  liberar();
} 

//Consultor de filas
int Imagen::num_filas() const{
  return filas;
} 

//Consultor de columnas
int Imagen::num_columnas() const{
  return cols;
} 

//Modificador de un valor
void Imagen::asigna_pixel (int f, int c, byte valor){
  img[f][c]=valor;
}

//Consultor de un valor
byte Imagen::valor_pixel (int f, int c) const{
	return img[f][c];
}

//Umbraliza una imagen
void Imagen :: umbraliza (const char * fichE, const char * fichS, byte T_1, byte T_2){
  if(T_1 > T_2){          // Reajuste del umbral
    byte aux = T_1;
    T_1 = T_2;
    T_2 = aux;
  }

  unsigned char* datos=0;
  if(LeerTipoImagen(fichE)==IMG_PGM){
    datos = LeerImagenPGM(fichE, filas, cols);
  }
  else{
    cerr << "La imagen es de un tipo no válido. Tipo de imagen admitido: PGM\n";
    exit(1);
  }

  for(int i=0; i<filas*cols; i++)             // Umbralizar 'datos'
    if(datos[i] < T_1 || datos[i] > T_2)
      datos[i] = byte(255);

  reservar(filas, cols);

  vector2matriz(datos);
 
  EscribirImagenPGM(fichS, datos, filas, cols);

  delete [] datos;                          // Liberar la memoria del vector auxiliar
    
}

// Hacer zoom a una imagen
void Imagen :: zoom (const char * fichE, const char * fichS, int x_1, int y_1, int x_2, int y_2){
    int alto = x_2-x_1;
    int ancho = y_2-y_1;

    if(ancho != alto){
      cerr << "El zoom ha de aplicarse a un trozo cuadrado\n";
      exit (2);
    }
    else{
      byte* datos=0;
      if(LeerTipoImagen(fichE)==IMG_PGM)
        datos = LeerImagenPGM(fichE, filas, cols);
      else{
        cerr << "La imagen es de un tipo no válido. Tipo de imagen admitido: PGM\n";
        exit(1);
      }

      reservar(filas,cols);

      vector2matriz(datos);
        
      Imagen aux(alto, ancho);

      for(int x = x_1, i = 0; x < x_2; x++, i++)
          for (int y = y_1, j = 0; y < y_2; y++, j++)
            aux.img[i][j] = img[x][y];

      Imagen inter(alto, 2*ancho-1);

      for(int f = 0; f < inter.filas; f++)
          for(int c = 0, j = 0; c < inter.cols; c+=2, j++){
            inter.img[f][c]=aux.img[f][j];
            if(c!=inter.cols-1)
              inter.img[f][c+1]=round((aux.img[f][j]+aux.img[f][j+1])/2.0);
          }

      Imagen zoom(2*alto-1, 2*ancho-1);

      for(int f = 0, i = 0; f < zoom.filas; f+=2, i++)
        for(int c = 0; c < zoom.cols; c++){
          zoom.img[f][c] = inter.img[i][c];
          if(f!=zoom.filas-1)
            zoom.img[f+1][c]=round((inter.img[i][c]+inter.img[i+1][c])/2.0);
        }
                
      (*this)=zoom;
        
      datos = matriz2vector();
      EscribirImagenPGM(fichS, datos, filas, cols);

      aux.liberar();
      inter.liberar();
      zoom.liberar();
      delete [] datos;
  }
  
}

void Imagen::contrasteTL(const char* fichE, const char* fichS, byte min, byte max){
  if(min > max){          // Reajuste del intervalo
    byte aux = min;
    min = max;
    max = aux;
  }

  byte* datos = 0;
  if(LeerTipoImagen(fichE)==IMG_PGM)
    datos = LeerImagenPGM(fichE, filas, cols);
  else{
    cerr << "La imagen es de un tipo no válido. Tipo de imagen admitido: PGM\n";
    exit(1);
  }

  int a=255, b=0;

  for(int i = 0; i < filas*cols; i++){
    if (datos[i] < a)
      a = datos[i];
        
    if (datos[i] > b)
      b = datos[i];
  }

  double operacion = double((max-min))/(b-a);

  for(int i = 0; i < filas*cols; i++){
      double pixel = min+(operacion*(datos[i]-a));
      datos[i] = round(pixel);
  }

  EscribirImagenPGM(fichS, datos, filas, cols);

  reservar(filas, cols);
  vector2matriz(datos);

  delete [] datos;
}

void Imagen::morphing(const char* fich_orig, const char* fich_rdo, const char* fich_intermedios){
  byte* datos_orig = 0;
  byte* datos_rdo = 0;
  int fils_rdo, cols_rdo;
  if(LeerTipoImagen(fich_orig)==IMG_PGM &&
     LeerTipoImagen(fich_rdo)==IMG_PGM){
    datos_orig = LeerImagenPGM(fich_orig, filas, cols);
    datos_rdo = LeerImagenPGM(fich_rdo, fils_rdo, cols_rdo);

    if(filas != fils_rdo || cols != cols_rdo){
      cerr << "Las imágenes origen y resultado no tienen el mismo tamaño\n";
      exit(3);
    }
  }
  else{
    cerr << "La/s imagen/es es/son de un tipo no válido. Tipo de imagen admitido: PGM\n";
    exit(1);
  }

  byte* intermedia = new byte[filas*cols];
  int cont = 1;
  // Bucle para 99 imagenes
  for(double alpha = 0.99; alpha > 0.0; alpha-=0.01){
    
    for(int i = 0; i < filas*cols; i++)
      intermedia[i] = alpha*datos_orig[i]+(1.0-alpha)*datos_rdo[i];

    ostringstream oss;
    oss << fich_intermedios << "_" << setw(3) << setfill('0') << cont <<  ".pgm"; 
    cont++;

    string cad = oss.str();
    char* nom_archivos = new char[cad.size()+1];
    strncpy(nom_archivos, cad.c_str(), cad.size());
  
    EscribirImagenPGM(nom_archivos, intermedia, filas, cols);

    delete [] nom_archivos;
  }
  
  delete [] intermedia;
  delete [] datos_orig;
  delete [] datos_rdo;
}

Imagen & Imagen :: operator = (const Imagen & otra){
	if (this != &otra){
		liberar ();
		reservar (otra.filas, otra.cols);
		copiar (otra);
	}

	return (*this);
}


//*************************************************************************//
//****************************MÉTODOS PRIVADOS*****************************//
//*************************************************************************//

//Liberar memoria
void Imagen::liberar(){

  for (int f=0; f<filas; f++)
  	delete [] img[f];

  delete [] img;

  filas = 0;
  cols = 0;
  img = 0;
}

//Reservar memoria
void Imagen::reservar(int nfils, int ncols){

  if (nfils>0 && ncols>0){
  	img = new byte*[nfils];

  	for (int f=0; f<nfils; f++)
  		img[f] = new byte [ncols];

  filas = nfils;
  cols = ncols;
  }
} 

//Copiar datos
void Imagen::copiar(const Imagen & otra){
  filas = otra.filas;
  cols = otra.cols;

  for (int f=0; f<filas; f++)
  	for (int c=0; c<cols; c++)
  		img[f][c]=otra.img[f][c];
} 

// Pasar una imagen de vector a una matriz
void Imagen::vector2matriz(byte* datos){
  int i = 0;
  for(int f = 0; f<filas; f++)                
    for(int c = 0; c<cols; c++){
      img[f][c] = datos[i];
      i++;
    }
}

// Pasar una imagen de matriz a vector
byte* Imagen::matriz2vector(){
    byte* datos = new byte[filas*cols];

    int i = 0;
    for(int f = 0; f<filas; f++)
      for(int c = 0; c < cols; c++){
        datos[i] = img[f][c];
        i++;
      }
    

    return datos;
}
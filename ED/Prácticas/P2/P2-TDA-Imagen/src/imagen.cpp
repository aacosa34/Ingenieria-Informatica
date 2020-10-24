#include<iostream>
#include<cmath>
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

  for(int f = 0; f<filas; f++)                // Guardar 'datos' en la matriz 'img'
    for(int c = 0; c<cols; c++)
      img[f][c] = datos[f+c];

 
  EscribirImagenPGM(fichS, datos, filas, cols);

  delete [] datos;                          // Liberar la memoria del vector auxiliar
    
}

// Hacer zoom a una imagen
void Imagen :: zoom (const char * fichE, const char * fichS, int x_1, int y_1, int x_2, int y_2){
  if(x_2-x_1 != y_2-y_1){
    cerr << "El zoom ha de aplicarse a un trozo cuadrado\n";
    exit (2);
  }
  else{
    unsigned char* datos=0;
    if(LeerTipoImagen(fichE)==IMG_PGM)
      datos = LeerImagenPGM(fichE, filas, cols);
    else{
      cerr << "La imagen es de un tipo no válido. Tipo de imagen admitido: PGM\n";
      exit(1);
    }

    int fd = 0;
    int cd = 0;

    Imagen aux(y_2-y_1, x_2-x_1);

    for(int f=0; f<aux.filas; f++)
        for(int c=0; c<aux.cols; c++)
            aux.img[f][c] = datos[f+(y_2-y_1)+c+(x_2-x_1)];

    delete [] datos;

    Imagen zoom(aux.filas, 2*aux.cols-1);
    
    int i = 0, j=0;
    for(int f=0; f<zoom.filas; f++)
      for(int c=0; c<zoom.cols; c++){
        if(c%2==1){
          i++;
          zoom.img[f][c] = round((aux.img[f][c-i] + aux.img[f][c-j]) / 2.0);
          j++;
        }
        else{
          zoom.img[f][c] = aux.img[f][cd];
          cd++;
        }
      }
    
    aux.liberar();

    reservar(2*zoom.filas-1, zoom.cols);
    
    i=j=0;
    for(int f=0; f<filas; f++){
      for(int c=0; c<cols; c++){
        if(f%2==1){
          img[f][c] = round((zoom.img[f-i][c]+zoom.img[f-j][c]) / 2.0);
        }
        else{
          img[f][c] = zoom.img[fd][c];
        }
      }
      if((f+1)%2==0)
        fd++;
      else
        i++; j++;
      
    }

    zoom.liberar();

    datos = new byte[filas*cols];

    for(int f=0; f<filas; f++)
      for(int c=0; c<cols; c++)
        datos[f+c] = img[f][c];

    
    EscribirImagenPGM(fichS, datos, filas, cols);
    

    
    delete [] datos;
  }
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
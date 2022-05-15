#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "imagenES.h"
#include "imagen.h"

using namespace std;

void morphing(const char* fich_orig, const char* fich_rdo, const char* fich_intermedios);

int main (){
  /*
    Imagen prueba1;

    prueba1.umbraliza("board.pgm", "pruebaumbraliza.pgm", 50, 250);

    Imagen prueba2;

    prueba2.zoom("saturno.pgm", "pruebazoom.pgm", 0, 0, 300, 300);*/

    Imagen prueba3;

    prueba3.contrasteTL("cameraman.pgm", "pruebacontraste.pgm", 20, 150);
 
    // morphing("vacas.pgm", "celulas.pgm", "vacascel");

    return 0;
}


// Función morphing
void morphing(const char* fich_orig, const char* fich_rdo, const char* fich_intermedios){
  byte* datos_orig = 0;
  byte* datos_rdo = 0;
  int fils_rdo, cols_rdo, fils_orig, cols_orig;
  if(LeerTipoImagen(fich_orig)==IMG_PGM &&
     LeerTipoImagen(fich_rdo)==IMG_PGM){
    datos_orig = LeerImagenPGM(fich_orig, fils_orig, cols_orig);
    datos_rdo = LeerImagenPGM(fich_rdo, fils_rdo, cols_rdo);

    if(fils_orig != fils_rdo || cols_orig != cols_rdo){
      cerr << "Las imágenes origen y resultado no tienen el mismo tamaño\n";
      exit(3);
    }
  }
  else{
    cerr << "La/s imagen/es es/son de un tipo no válido. Tipo de imagen admitido: PGM\n";
    exit(1);
  }

  byte* intermedia = new byte[fils_rdo*cols_rdo];
  int cont = 1;
  // Bucle para 99 imagenes
  for(double alpha = 0.999; alpha > 0.0; alpha-=0.001){
    
    for(int i = 0; i < fils_rdo*cols_rdo; i++)
      intermedia[i] = alpha*datos_orig[i]+(1.0-alpha)*datos_rdo[i];

    ostringstream oss;
    oss << fich_intermedios << "_" << setw(3) << setfill('0') << cont <<  ".pgm"; 
    cont++;

    string cad = oss.str();
    char* nom_archivos = new char[cad.size()+1];
    strncpy(nom_archivos, cad.c_str(), cad.size());
  
    EscribirImagenPGM(nom_archivos, intermedia, fils_rdo, cols_rdo);

    delete nom_archivos;
  }
  
  delete intermedia;
  delete datos_orig;
  delete datos_rdo;
}

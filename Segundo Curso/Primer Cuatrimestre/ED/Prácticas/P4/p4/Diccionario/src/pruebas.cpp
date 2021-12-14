#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main(){
  struct m {
    int v;
    char c;
  };

  list <m> l;
  list <m> :: iterator pointer;
  list <m> :: iterator encontrado;

  m d = {10, 'c'};
  m f = {30, 'd'};
  m g = {20, 'k'};

  // Insercion tipo FIFO
  l.push_back(d);
  l.push_back(f);
  l.push_back(g);

  bool salir = false;
  int iterations = 0;

  // Uso de iterator como puntero entre los datos no contiguos de una lista
  // en memoria
  for (pointer = l.begin(); pointer != l.end() && !salir; ++pointer){
    if (pointer -> v == 30){
      encontrado = pointer;
      cout << "Encontrado\n";
      salir = true;
    }

    iterations++;
  }

  cout << "Encontrado data: " << encontrado -> v << "\nEncontrado letra: " << encontrado -> c << endl;
  cout << "N iterations: " << iterations << endl;

  // Sort lambda
  l.sort( [] (const m & a, const m & b) {
    return a.v < b.v;
  } );

  cout << "Llega" << endl;
  for (pointer = l.begin(); pointer != l.end(); ++pointer){
      cout << "Valor data: " << pointer -> v << "\nValor letra: " << pointer -> c << endl;
  }

  list <m> * lp = *l;

    for (int i = 0; i < 4; i++){
      ++lp;
      cout << "Valor data: " << l.v << "\nValor letra: " << l.c << endl;
    }
}

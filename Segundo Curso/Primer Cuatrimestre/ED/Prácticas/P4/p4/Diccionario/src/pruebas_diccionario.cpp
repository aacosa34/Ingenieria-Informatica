#include <iostream>
#include "Diccionario.h"

using namespace std;

int main(){
  Diccionario<int, int> mi;
  data<int, int> s;

  s.clave=5;
  s.info_asoci=10;

  mi.add(s);


  s.clave=10;
  s.info_asoci=20;

  mi.add(s);

  // Pruebas de iterador

  Diccionario<int, int>::iterator it(mi.begin());


  while (it != mi.end()){
    s = *it;
    cout << s.clave << " Clave " << s.info_asoci << " Info asoci " << endl;

    ++it;
  }

  cout << endl;
}

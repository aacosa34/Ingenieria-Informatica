#include <iostream>

#include "Collection.h"

using namespace std;

int main(int argc, char *argv[]) {
  Collection<int, int> cInt;
  Collection<string, double> cString;

  for (int i = 1; i < 5; i++) {
    cInt.add(pair<int, int>(10 * (i * 2 + 1), 10 * (i * 2 + 1)));
    cString.add(
        pair<string, double>(to_string(10 * (i * 2 + 1)), 10 * (i * 2 + 1)));
  }

  for (int i = 1; i < 5; i++) {
    cInt.add(pair<int, int>(10 * i * 2, 10 * i * 2));
    cString.add(pair<string, double>(to_string(10 * i * 2), 10 * i * 2));
  }

  cout << "Recorremos las estructuras de forma lineal." << endl;
  cout << cInt << endl << cString << endl;

  cout << "Recorremos las estructuras por orden de clave." << endl;
  for (Collection<int, int>::ordered_iterator it = cInt.obegin();
       it != cInt.oend(); ++it)
    cout << '(' << (*it).first << ',' << (*it).second << ')' << endl;

  cout << endl;

  for (Collection<string, double>::ordered_iterator it = cString.obegin();
       it != cString.oend(); ++it)
    cout << '(' << (*it).first << ',' << (*it).second << ')' << endl;

  return 0;
}

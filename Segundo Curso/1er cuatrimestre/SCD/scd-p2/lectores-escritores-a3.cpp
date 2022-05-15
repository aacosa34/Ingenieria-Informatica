#include <iostream>
#include <iomanip>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "HoareMonitor.h"

using namespace std;
using namespace HM;

const int num_hebras_escritoras = 4;
const int num_hebras_lectoras = 2;

//**********************************************************************
// plantilla de función para generar un entero aleatorio uniformemente
// distribuido entre dos valores enteros, ambos incluidos
// (ambos tienen que ser dos constantes, conocidas en tiempo de compilación)
//----------------------------------------------------------------------

template< int min, int max > int aleatorio()
{
  static default_random_engine generador( (random_device())() );
  static uniform_int_distribution<int> distribucion_uniforme( min, max ) ;
  return distribucion_uniforme( generador );
}

class Lec_Esc : public HoareMonitor
{
private:
    int n_esc = 0;       // Número de escritores escribiendo
    bool leyendo = false; // True si hay algún lector leyendo
    CondVar lectura,
            escritura;

public:
    Lec_Esc();
    void iniLectura();
    void finLectura();
    void iniEscritura();
    void finEscritura();
};

Lec_Esc :: Lec_Esc(){
    lectura = newCondVar();
    escritura = newCondVar();
}

void Lec_Esc :: iniLectura(){
    if(leyendo || n_esc > 0)
        lectura.wait();

    leyendo = true;
}

void Lec_Esc :: finLectura(){
   leyendo = false;

   if(!escritura.empty())
        escritura.signal();
    else
        lectura.signal();
    
}

void Lec_Esc :: iniEscritura(){
    if(leyendo)
        escritura.wait();

    n_esc++;

    escritura.signal();
}

void Lec_Esc :: finEscritura(){
   n_esc--;

   if(n_esc == 0)
        lectura.signal(); 
}

void funcion_hebra_lectora( MRef<Lec_Esc> monitor, int num_lector){
    while (true){
        monitor->iniLectura();
        cout << "Lector " << num_lector << " empieza a leer" << endl;
        this_thread::sleep_for(chrono::milliseconds( aleatorio<20,100>() ));
        cout << "\t\tLector " << num_lector << " termina de leer" << endl;
        monitor->finLectura();
        this_thread::sleep_for(chrono::milliseconds( aleatorio<20,100>() ));
        
    }
}

void funcion_hebra_escritora ( MRef<Lec_Esc> monitor, int num_escritor ){
    while (true){
        monitor->iniEscritura();
        cout << "Escritor " << num_escritor << " empieza a escribir" << endl;
        this_thread::sleep_for(chrono::milliseconds( aleatorio<20,100>() ));
        cout << "\t\tEscritor " << num_escritor << " termina de escribir\n" << endl;
        monitor->finEscritura();
        this_thread::sleep_for(chrono::milliseconds( aleatorio<20,100>() ));
    }
} 

int main()
{
   cout << "--------------------------------------------------------" << endl
        << "   Problema de los lectores/escritores con monitor SU.  " << endl
        << "--------------------------------------------------------" << endl
        << flush;

    MRef<Lec_Esc> monitor = Create<Lec_Esc>();

    int num_escritores = num_hebras_escritoras;
    int num_lectores = num_hebras_lectoras;

    thread hebra_escritores[num_escritores];
    thread hebra_lectores[num_lectores];

    for(int i = 0; i < num_escritores; i++)
        hebra_escritores[i] = thread(funcion_hebra_escritora, monitor, i);

    for(int i = 0; i < num_lectores; i++)
        hebra_lectores[i] = thread(funcion_hebra_lectora, monitor, i);

    for(int i = 0; i < num_escritores; i++)
        hebra_escritores[i].join();
    for(int i = 0; i < num_lectores; i++)
        hebra_lectores[i].join();
      
}

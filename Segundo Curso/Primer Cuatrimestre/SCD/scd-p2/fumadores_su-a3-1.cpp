#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "HoareMonitor.h"

using namespace std ;
using namespace HM ;

const int num_fumadores = 5;

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

//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra

void fumar( int num_fumador )
{

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,200>() );

   // informa de que comienza a fumar

    cout << "Fumador " << num_fumador << "  :"
          << " empieza a fumar (" << duracion_fumar.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar

    cout << "Fumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente." << endl;

}

class Estanco : public HoareMonitor {
private:
    int ing_disp = -1;
    CondVar mostrador_vacio,
            ingrediente_producido[num_fumadores];
public:
    Estanco();
    void obtenerIngrediente(int num_fumador);
    void ponerIngrediente(int num_ingrediente);
    void esperarRecogidaIngrediente();
    void Esperar_mi_ingrediente(int num_fumador);
};

Estanco :: Estanco(){
    mostrador_vacio = newCondVar();
    for(int i = 0; i < num_fumadores; i++)
        ingrediente_producido[i] = newCondVar();
}

void Estanco :: obtenerIngrediente(int num_fumador){
    cout << "Retirado ingrediente " << num_fumador << endl;

    fumar( num_fumador );
    
    ing_disp = -1;
    mostrador_vacio.signal();
}

void Estanco :: ponerIngrediente(int num_ingrediente){
    ing_disp = num_ingrediente;
    cout << "Puesto ingrediente " << num_ingrediente << endl;
    ingrediente_producido[num_ingrediente].signal();
}

void Estanco :: esperarRecogidaIngrediente(){
    if(ing_disp != -1)
        mostrador_vacio.wait();
}

void Estanco :: Esperar_mi_ingrediente(int num_fumador){
    if(ing_disp != num_fumador)
        ingrediente_producido[num_fumador].wait();
    
    obtenerIngrediente(num_fumador);

}

//-------------------------------------------------------------------------
// Función que simula la acción de producir un ingrediente, como un retardo
// aleatorio de la hebra (devuelve número de ingrediente producido)

int producir_ingrediente()
{
   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_produ( aleatorio<10,100>() );

   // informa de que comienza a producir
   cout << "Estanquero : empieza a producir ingrediente (" << duracion_produ.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a 'duracion_produ' milisegundos
   this_thread::sleep_for( duracion_produ );

   const int num_ingrediente = aleatorio<0,num_fumadores-1>() ;

   // informa de que ha terminado de producir
   cout << "Estanquero : termina de producir ingrediente " << num_ingrediente << endl;

   return num_ingrediente ;
}

//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero( MRef<Estanco> monitor )
{  bool primera = true;
   while( true ){
      if (primera){
        int ingrediente = producir_ingrediente();

        monitor->ponerIngrediente(ingrediente);
        monitor->esperarRecogidaIngrediente();
      }
      else{
        
      }
   }
}


//----------------------------------------------------------------------
// función que ejecuta la hebra del fumador
void  funcion_hebra_fumador( MRef<Estanco> monitor, int num_fumador )
{
   while( true )
   {
      monitor->Esperar_mi_ingrediente(num_fumador);

   }
}

//----------------------------------------------------------------------

int main()
{
   cout << "--------------------------------------------------------" << endl
        << "       Problema de los fumadores con monitor SU.        " << endl
        << "--------------------------------------------------------" << endl
        << flush;

    MRef<Estanco> monitor = Create<Estanco>();

    thread hebra_estanquero(funcion_hebra_estanquero, monitor);
    thread hebra_fumadores[num_fumadores];

    for(int i = 0; i < num_fumadores; i++)
        hebra_fumadores[i] = thread(funcion_hebra_fumador, monitor, i);

    hebra_estanquero.join();

    for(int i = 0; i < num_fumadores; i++)
        hebra_fumadores[i].join();
      
}

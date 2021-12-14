#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "Semaphore.h"

using namespace std ;
using namespace SEM ;

const int num_fumadores = 3;
int num_cigarrillos[num_fumadores] = {0, 0, 0},
    num_ingredientes[num_fumadores] = {0, 0, 0};   

unsigned prox_fumador = 0;

Semaphore ing_disp[num_fumadores] = {0, 0, 0},
         fumadores_despierta[num_fumadores] = {0, 0, 0};

Semaphore excl_mutua = 1,          
          mostrador_vacio = 1;

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
// Función que simula la acción de producir un ingrediente, como un retardo
// aleatorio de la hebra (devuelve número de ingrediente producido)

int producir_ingrediente()
{
   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_produ( aleatorio<10,100>() );

   // informa de que comienza a producir
   cout << "Estanquero : empieza a producir ingrediente (" << duracion_produ.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_produ' milisegundos
   this_thread::sleep_for( duracion_produ );

   const int num_ingrediente = aleatorio<0,num_fumadores-1>() ;

   // informa de que ha terminado de producir
   cout << "Estanquero : termina de producir ingrediente " << num_ingrediente << endl;

   return num_ingrediente ;
}

//----------------------------------------------------------------------
// función que ejecuta la hebra del estanquero

void funcion_hebra_estanquero(  )
{
    int ingrediente = 0;
   while( true ){

      sem_wait( mostrador_vacio );
      
      ingrediente = producir_ingrediente();
      
      
      if(num_ingredientes[ingrediente] < 3){
        sem_signal( ing_disp[ingrediente] );
      }
      else{
        num_ingredientes[ingrediente] = 0;
        sem_signal( fumadores_despierta[ingrediente] );
      }
      
      num_ingredientes[ingrediente]++;
   }
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

//----------------------------------------------------------------------
// función que ejecuta la hebra del fumador
void  funcion_hebra_fumador( int num_fumador )
{
   while( true )
   {
      if(num_cigarrillos[num_fumador] < 3){
          sem_wait(ing_disp[num_fumador]);
      }
      else{
          sem_wait(fumadores_despierta[num_fumador]);
          num_cigarrillos[num_fumador] = 0;
      }

      sem_wait( excl_mutua );
      sem_signal( excl_mutua );

      cout << "El fumador " << num_fumador << " retira su ingrediente" << endl;

      sem_signal( mostrador_vacio );

      if(num_cigarrillos[num_fumador] < 3){

          num_cigarrillos[num_fumador]++; 
         fumar( num_fumador );
         
      }
      else{
         cout << "El fumador " << num_fumador << " no quiere más tabaco y duerme" << endl;
         this_thread::sleep_for( chrono::milliseconds(aleatorio<20,400>()));
         cout << "El fumador " << num_fumador << " se despierta" << endl;
      }
      

   }
}

//----------------------------------------------------------------------

int main()
{
   cout << "--------------------------------------------------------" << endl
        << "             Problema de los fumadores.                 " << endl
        << "--------------------------------------------------------" << endl
        << flush;

   thread hebra_estanquero(funcion_hebra_estanquero),
          fumadores[num_fumadores];

   for(int i = 0; i < num_fumadores; i++)
      fumadores[i] = thread(funcion_hebra_fumador, i);

   hebra_estanquero.join();

   for(int i = 0; i < num_fumadores; i++)
      fumadores[i].join();
      
}

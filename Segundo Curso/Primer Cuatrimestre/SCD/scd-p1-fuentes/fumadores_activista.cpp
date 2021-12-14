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

const int MAX_PROCLAMAS = 8;
int ingr_mangado;
int num_proclamas = 0;

unsigned prox_fumador = 0;

Semaphore ing_disp[num_fumadores] = {0, 0, 0};

Semaphore excl_mutua = 1,          
          mostrador_vacio = 1,
          manga_ingr = 0;

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
   while( true ){
      int ingrediente = producir_ingrediente();
      
      if(num_proclamas<MAX_PROCLAMAS){
        sem_wait( mostrador_vacio );
        sem_signal( ing_disp[ingrediente] );
      }
      else{
          sem_wait( mostrador_vacio );
          ingr_mangado = ingrediente;
          sem_signal( manga_ingr );
      }
   }
}

//-----------------------------------------------------------------------
// funcion que ejecuta la hebra del activista

void funcion_hebra_activista( ){
   int mangado;
   while (true){
      if(num_proclamas<MAX_PROCLAMAS){
      chrono::milliseconds espera_aleatoria( aleatorio<10,100>() );
      cout << "FUMAR MATA!!" << endl;
      this_thread::sleep_for(espera_aleatoria);
      num_proclamas++;
      }
      else{
        sem_wait( manga_ingr );
        sem_signal( mostrador_vacio );
        mangado = ingr_mangado;
        cout << "JA, JA, JA! Destruido ingrediente " << mangado;
        num_proclamas = 0;
      }
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
      sem_wait( excl_mutua );
      sem_signal( excl_mutua );

      sem_wait( ing_disp[num_fumador] );
      cout << "El fumador " << num_fumador << " retira su ingrediente" << endl;
      sem_signal( mostrador_vacio );

      fumar( num_fumador );

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
          hebra_activista(funcion_hebra_activista),
          fumadores[num_fumadores];

   for(int i = 0; i < num_fumadores; i++)
      fumadores[i] = thread(funcion_hebra_fumador, i);

   hebra_estanquero.join();
   hebra_activista.join();

   for(int i = 0; i < num_fumadores; i++)
      fumadores[i].join();
      
}

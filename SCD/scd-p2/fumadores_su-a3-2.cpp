#include <iostream>
#include <cassert>
#include <thread>
#include <mutex>
#include <random> // dispositivos, generadores y distribuciones aleatorias
#include <chrono> // duraciones (duration), unidades de tiempo
#include "HoareMonitor.h"

using namespace std ;
using namespace HM ;

// El numero de fumadores del problema son 3
const int num_fumadores = 3;

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

int producir_ingrediente() {
   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_produ( aleatorio<10,200>() );

   // informa de que comienza a producir
   cout << "Estanquero : empieza a producir ingrediente (" << duracion_produ.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_produ' milisegundos
   this_thread::sleep_for( duracion_produ );

   const int num_ingrediente = aleatorio<0,num_fumadores-1>() ;

   // informa de que ha terminado de producir
   cout << "Estanquero : termina de producir ingrediente " << num_ingrediente << endl;

   return num_ingrediente ;
}


//-------------------------------------------------------------------------
// Función que simula la acción de fumar, como un retardo aleatoria de la hebra

void fumar( int num_fumador ) {

   // calcular milisegundos aleatorios de duración de la acción de fumar)
   chrono::milliseconds duracion_fumar( aleatorio<20,400>() );

   // informa de que comienza a fumar

    cout << "Fumador " << num_fumador << "  :"
          << " empieza a fumar (" << duracion_fumar.count() << " milisegundos)" << endl;

   // espera bloqueada un tiempo igual a ''duracion_fumar' milisegundos
   this_thread::sleep_for( duracion_fumar );

   // informa de que ha terminado de fumar

    cout << "Fumador " << num_fumador << "  : termina de fumar, comienza espera de ingrediente." << endl;
}

// *****************************************************************************
// clase para monitor
class FumadorSU : public HoareMonitor  {
 private:
   CondVar mostrador;                       //  Variable de condicion de indicacion de que la produccion esta realizada
   CondVar fumadores[num_fumadores];         //  Variable de condicion de llamada al proceso o hilo del fumador

   // Ingrediente pasado al fumador, es el mostrador
   int ingrediente;
 public:
   FumadorSU() ;           // constructor

   // Funciones del suministrador
   void dar_suministro();

   // Funciones del estanquero
   void ponerIngrediente(int i);
   void esperarRecogidaIngrediente();

   //Funciones del fumador
   void obtenerIngrediente(int i);
};
// Implementacion
//----------------------------------------------------------------------

FumadorSU::FumadorSU (){
  mostrador = newCondVar();

  for (int i = 0; i < num_fumadores; i++){
    fumadores[i] = newCondVar();
  }

  ingrediente = -1;
}



// función que ejecuta la hebra del estanquero
void FumadorSU::ponerIngrediente(int i) {
    cout << "Ingrediente " << i << " llega" << endl;
    ingrediente = i;
    fumadores[i].signal();
}

void FumadorSU::esperarRecogidaIngrediente(){
    // Variable condition (cola de hebras) de espera del mostrador para que recoja el ingrediente
    // el fumador
    cout << "Esperando a la recogida del ingrediente\n";
    if (ingrediente != -1){
          mostrador.wait();
    }
    cout << "Mostrador libre, produciendo el siguiente ingrediente\n";
}

//----------------------------------------------------------------------
// función que ejecuta la hebra del fumador
// @args i es el numero de fumador que solicita el ingrediente
void  FumadorSU::obtenerIngrediente(int i){
     // Pasamos a la cola de hilos al fumador i que espera su sem_signal
     // del estanquero

     // Si el ingrediente es el fumador que se pasa por arg
     // Directamente no espera en la cola de hebras
     if (i != ingrediente){
        fumadores[i].wait();
     }

     cout << "Fumador: " << i
          << " Recoge el ingrediente del mostrador." << endl;
     ingrediente = -1;
     // Cuando el fumador recoge su ingrediente libera el mostrador
     mostrador.signal();
}

void fumador(MRef <FumadorSU> monitor, int i){
  while(true){
    monitor -> obtenerIngrediente(i);
    // Llamada a la funcion fumar que produce una espera aleatoria
    fumar(i);
  }
}

// Condiciones del suministro
static const int LIMIT_SUM = 5;
int suministro[LIMIT_SUM] = {0,0,0,0,0};

// Semaforos de sincronizacion
Semaphore ingredientes_suministrados(LIMIT_SUM);  // Puede suministrar hasta limit_sum
Semaphore ingredientes_recogidos(0);            // No hay ningun valor escrito inicialmente

// Control del almacen del suministrador Preparado para FIFO
int primera_ocupada = 0;
int primera_libre =  0;



//----------------------------------------------------------------------
// Funciones de hebra
void funcion_hebra_estanquero(MRef <FumadorSU> monitor) {
  while (true){
    int ingrediente;
    // Se realiza el reparto del trabajo de los items
    // Esperamos a que haya un ingrediente producido
    sem_wait(ingredientes_recogidos);
    // Ponemos en el mostrador el ingrediente para que esperemos al fumador que lo recoja
    ingrediente = suministro[primera_ocupada];
    cout << "Ingrediente " << ingrediente << " recogido\n" << endl;
    // Hacemos el vector circular
    primera_ocupada = (primera_ocupada+1)%LIMIT_SUM;
    // Le decimos al suministrador que un producto ha sido usado
    // Llevamos el ingrediente al estanco

    monitor->ponerIngrediente(ingrediente);
    monitor->esperarRecogidaIngrediente();

    sem_signal(ingredientes_suministrados);
  }
}

void funcion_hebra_suministrador() {
  while (true){
    // Se realiza el reparto del trabajo de los items
    // El primer ingrediente se produce fuera mientras los fumadores y el estanquero esperan a que exista algun ingrediente
    int ingre = producir_ingrediente();
    cout << "Ingrediente " << ingre << " producido almacenandolo en el suministro\n" << endl;
    // Hacemos que se decremente en 1 la capacidad de almacenamiento
    sem_wait(ingredientes_suministrados);
    suministro[primera_libre] = ingre;
    // Hacemos el vector circular para no tocar las variables mutuamente ya que el suministrador
    // puede suministrar 5 ingredientes seguidos por el semaforo
    primera_libre = (primera_libre+1)%LIMIT_SUM;
    // Llamamos al estanquero para que pase a recoger los ingredientes disponibles
    sem_signal(ingredientes_recogidos);
  }
}


//----------------------------------------------------------------------

int main() {
  // Creacion del monitor
  MRef <FumadorSU> monitor = Create<FumadorSU>();
  thread estanquero(funcion_hebra_estanquero, monitor);
  thread suministrador(funcion_hebra_suministrador);

  thread fumadores[num_fumadores];

  for (int i = 0; i < num_fumadores; i++){
    fumadores[i] = thread (fumador, monitor, i); // Creamos el hilo de cada fumador
  }

  // Como hay que esperar a que termine de inicializarse todas las hebras
  // iniciamos el trabajo de cada hebra
  suministrador.join();
  estanquero.join();

  for (int i = 0; i < num_fumadores; i++){
    fumadores[i].join();
  }
}

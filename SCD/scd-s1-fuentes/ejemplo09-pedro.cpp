// -----------------------------------------------------------------------------
// Sistemas concurrentes y Distribuidos.
// Seminario 1. Programación Multihebra y Semáforos.
//
// Ejemplo 9 (ejemplo9.cpp)
// Calculo concurrente de una integral. Plantilla para completar.
//
// Historial:
// Creado en Abril de 2017
// -----------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <chrono>  // incluye now, time\_point, duration
#include <future> // Ficheros de cabecera de los thread y future
#include <vector>
#include <cmath>

using namespace std ;
using namespace std::chrono;

const long m  = 1024l*1024l*1024l, // número de muestras (del orden de mil millones)
           n  = 4  ;               // número de hebras concurrentes (divisor de 'm')


// -----------------------------------------------------------------------------
// evalua la función $f$ a integrar ($f(x)=4/(1+x^2)$)
double f( double x )
{
  return 4.0/(1.0+x*x) ;
}
// -----------------------------------------------------------------------------
// calcula la integral de forma secuencial, devuelve resultado:
double calcular_integral_secuencial(  )
{
   double suma = 0.0 ;                        // inicializar suma
   for( long j = 0 ; j < m ; j++ ) {            // para cada $j$ entre $0$ y $m-1$:
      const double xj = double(j+0.5)/m;     //      calcular $x_j$
      suma += f( xj );                        //      añadir $f(x_j)$ a la suma actual
   }
   return suma/m ;                            // devolver valor promedio de $f$
}

// -----------------------------------------------------------------------------

// La hebra debe recibir el punto inicial del dominio
// PRE: i es la parte de la funcion inicial
double funcion_hebra( long i ){
   long final = i + (m / n);
   double suma = 0.0;

   if (final <= m){
     for (long j = i; j < final; j++){
       const double xj = double(j+0.5)/m;
       suma += f(xj);
     }
   }

   return suma;
}

// -----------------------------------------------------------------------------
// Calculo de la integral de forma concurrente
double calcular_integral_concurrente(void) {
  future <double> integral [n];
  double suma_integral = 0.0;
  // Calculamos una parte de la funcion
  // En el caso inicial se recoge part_func
  long part_func = m / n;
  // Indice de por donde va la funcion
  long pos_func = 0.0;
  // inicializamos los hilos.
  for (int i = 0; i < n; i++){
    integral[i] = async (launch::async, funcion_hebra, pos_func);
    pos_func += part_func;
  }
  // Obtenemos 4 valores future para obtener sus resultados para la sumatoria

  for (int i = 0; i < n; i++){
    suma_integral += integral[i].get();
  }
  // Devolvemos la media
  return suma_integral/m;
}
// -----------------------------------------------------------------------------

int main(){
  // Inicio de la integral secuencial
  time_point<steady_clock> inicio_sec  = steady_clock::now() ;
  const double             result_sec  = calcular_integral_secuencial(  );
  time_point<steady_clock> fin_sec     = steady_clock::now() ;
  duration<float,milli>    tiempo_sec  = fin_sec  - inicio_sec;
  double x = sin(0.4567);


  // Inicio de la integral por concurrencia
  time_point<steady_clock> inicio_conc = steady_clock::now() ;
  const double             result_conc = calcular_integral_concurrente(  );
  time_point<steady_clock> fin_conc    = steady_clock::now() ;

  duration<float,milli>    tiempo_conc = fin_conc - inicio_conc ;
  const float              porc        = 100.0*tiempo_conc.count()/tiempo_sec.count() ;

  constexpr double pi = 3.14159265358979323846l ;

  cout << "Número de muestras (m)   : " << m << endl
       << "Número de hebras (n)     : " << n << endl
       << setprecision(18)
       << "Valor de PI              : " << pi << endl
       << "Resultado secuencial     : " << result_sec  << endl
       << "Resultado concurrente    : " << result_conc << endl
       << setprecision(5)
       << "Tiempo secuencial        : " << tiempo_sec.count()  << " milisegundos. " << endl
       << "Tiempo concurrente       : " << tiempo_conc.count() << " milisegundos. " << endl
       << setprecision(4)
       << "Porcentaje t.conc/t.sec. : " << porc << "%" << endl;
}

// -----------------------------------------------------------------------------
//
// Sistemas concurrentes y Distribuidos.
// Práctica 4. Implementación de sistemas de tiempo real.
// Adrián Acosa Sánchez
// Archivo: ejecutivo1.cpp
// Implementación del primer ejemplo de ejecutivo cíclico:
//
//   Datos de las tareas:
//   ------------
//   Ta.  T    C
//   ------------
//   A  500   100
//   B  500   150
//   C  1000  200
//   D  2000  240
//  -------------
//
//
//  Planificación (con Ts == 500 ms)
//  *---------*----------*---------*--------*
//  | A B C   | A B   | A B C  | A B D  |
//  *---------*----------*---------*--------*
//
// RESPUESTA A LAS PREGUNTAS:
//
// PREGUNTA 1: el tiempo mínimo de espera que queda al final de las iteraciones
// del ciclo secundario con la planificación que he propuesto es de 10 ms, y se 
// produce en el último ciclo.
//
// PREGUNTA 2: No podría ser planificable, debido a que ocuparía el tiempo
// completo del ciclo secundario y no dejaría tiempo para los posibles retrasos
// que se pudieran dar.
//
//
// Historial:
// Creado en Diciembre de 2017
// -----------------------------------------------------------------------------

#include <string>
#include <iostream> // cout, cerr
#include <thread>
#include <chrono> // utilidades de tiempo
#include <ratio>  // std::ratio_divide

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

// tipo para duraciones en segundos y milisegundos, en coma flotante:
typedef duration<float, ratio<1, 1>> seconds_f;
typedef duration<float, ratio<1, 1000>> milliseconds_f;

// -----------------------------------------------------------------------------
// tarea genérica: duerme durante un intervalo de tiempo (de determinada duración)

void Tarea(const std::string &nombre, milliseconds tcomputo)
{
    cout << "   Comienza tarea " << nombre << " (C == " << tcomputo.count() << " ms.) ... ";
    sleep_for(tcomputo);
    cout << "fin." << endl;
}

// -----------------------------------------------------------------------------
// tareas concretas del problema:

void TareaA() { Tarea("A", milliseconds(100)); }
void TareaB() { Tarea("B", milliseconds(150)); }
void TareaC() { Tarea("C", milliseconds(200)); }
void TareaD() { Tarea("D", milliseconds(240)); }

// -----------------------------------------------------------------------------
// implementación del ejecutivo cíclico:

int main(int argc, char *argv[])
{
    // Ts = duración del ciclo secundario
    const milliseconds Ts(500);

    // ini_sec = instante de inicio de la iteración actual del ciclo secundario
    time_point<steady_clock> ini_sec = steady_clock::now();

    while (true) // ciclo principal
    {
        cout << endl
             << "---------------------------------------" << endl
             << "Comienza iteración del ciclo principal." << endl;

        for (int i = 1; i <= 4; i++) // ciclo secundario (4 iteraciones)
        {
            cout << endl
                 << "Comienza iteración " << i << " del ciclo secundario." << endl;

            switch (i)
            {
            case 1:
                TareaA();
                TareaB();
                TareaC(); /*450*/
                break;
            case 2:
                TareaA();
                TareaB(); /*250*/
                break;
            case 3:
                TareaA();
                TareaB();
                TareaC(); /*450*/
                break;
            case 4:
                TareaA();
                TareaB();
                TareaD(); /*490*/
                break;
            }

            // calcular el siguiente instante de inicio del ciclo secundario
            ini_sec += Ts;
            // esperar hasta el inicio de la siguiente iteración del ciclo secundario
            sleep_until(ini_sec);

            time_point<steady_clock> tiempo_perdida = steady_clock::now();
            milliseconds_f total = tiempo_perdida - ini_sec;
            cout << "Retraso: " << total.count() << endl;
            if (total > milliseconds(20))
            {
                cout << "Programa abortado" << endl;
                exit(1);
            }
        }
    }
}

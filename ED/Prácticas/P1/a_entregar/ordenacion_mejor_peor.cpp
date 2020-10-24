#include <iostream>
#include <ctime>
using namespace std;

void ordenar (int *v, int n) {
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(v[j]>v[j+1]) {
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
        }
}

void sintaxis() {
    cerr << "Sintaxis:" << endl;
    cerr << " TAM: Tamaño del vector (>0)" << endl;
    cerr << " VMAX: Valor máximo (>0)" << endl;
    cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
    exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]) {
    if (argc!=4) // Lectura de parámetros
        sintaxis();
    int tam=atoi(argv[1]); // Tamaño del vector
    int vmax=atoi(argv[2]); // Valor máximo
    if (tam<=0 || vmax<=0)
        sintaxis();

    int *v=new int[tam]; // Reserva de memoria

    /*
    // PEOR CASO   
    int contador = 0;
    for(int i=tam-1; i>0; i--){
        v[i] = contador;
        contador++;
    }
    */
    
    // MEJOR CASO
    for (int i=0; i<tam; i++) // Recorrer vector
        v[i] = i;    
    


    clock_t tini; // Anotamos el tiempo de inicio
    tini=clock();

    ordenar(v,tam); // Ordenamos el vector

    clock_t tfin; // Anotamos el tiempo de finalización 
    tfin=clock();

    // Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)
    cout << tam << "\t" << (tfin-tini)/(double)CLOCKS_PER_SEC << endl;
    delete [] v; //Liberamos memoria dinámica
}
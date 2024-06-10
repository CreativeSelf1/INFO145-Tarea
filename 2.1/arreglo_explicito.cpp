#include <iostream>
#include <random>
#include <iostream>
#include <algorithm>
 
using namespace std;

void imprimirArreglo(int* arreglo, int n){
    for (int i = 0; i < n; i++){
        cout << arreglo[i] << " ";
    }
    
}
void Busqueda_binaria(int* lineal, int tamano, int search){
    bool encontrado = binary_search(lineal, lineal + tamano, search);

    cout << encontrado << endl;
}

int* GeneradorLineal(int n) {
    int* lineal = new int[n];

    lineal[0] = rand() % 100;    // desde que rango?

    for (int i = 1; i < n; i++) {
        lineal[i] = lineal[i-1] + rand() % 10;   //epsilon que valor toma?
    }
    
    return lineal;
}

int* GeneradorNormal(int n){
    int* normal = new int[n];
    return normal;
}

int main(int argc, char *argv[]) {
    int n = 10;

    int* lineal = GeneradorLineal(n);
    int* normal = GeneradorNormal(n);

    //imprimirArreglo(lineal, n);
    Busqueda_binaria(lineal, n, 104);

}
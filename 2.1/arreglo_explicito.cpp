#include <iostream>
#include <random>
#include <iostream>
#include <algorithm>
#include <ctime> 
#include "BinarySearch/binarySearch.h"
 
using namespace std;

void imprimirArreglo(int* arreglo, int n){
    for (int i = 0; i < n; i++){
        cout << arreglo[i] << " ";
    }
    cout << endl;
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
    int n = 100000;
    unsigned t0, t1;


    int* lineal = GeneradorLineal(n);
    int* normal = GeneradorNormal(n);

    //imprimirArreglo(lineal, n);

    t0 = clock();
    for (int i = 0; i < 100000000; i++) {
        int key = rand() % (lineal[n-1] + 1); //generarar busquedas del rango del arreglo
        binary_search(lineal, n, key);
    }
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << time << " segundos";


    delete[] lineal;   //liberar memoria
    delete[] normal;

    return 0;
}
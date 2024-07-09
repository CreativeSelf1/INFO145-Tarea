#include "../Headers/searchMeasure.h"
#include "../Headers/binarySearch.h"


//Búsquedas binarias en el arreglo lineal/normal
void search_measure(vector<long int>& array, long int amount){
    unsigned t0, t1;
   
    t0 = clock();
    int key;
    for (long int i = 0; i < amount; i++) {
        key = array[rand() % array.size()]; // genera números aleatorios en el rango del arreglo
        binary_search(array, key);
    }
    t1 = clock();

    double timeInSeconds = (double(t1 - t0) / CLOCKS_PER_SEC);
    double timeInMilliseconds = timeInSeconds * 1000; 
     
    cout << " - Tiempo de ejecución: " << timeInMilliseconds << " ms" << endl;
}
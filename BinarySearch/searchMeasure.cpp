#include <iostream>
#include <chrono>

#include "searchMeasure.h"
#include "binarySearch.h"
using namespace std::chrono;

void search_measure(vector<int>& array, int amount){
    cout << "numeros buscados con busqueda binaria: " << endl;
    int key;
    int last = array.size()-1;
    int gap = array[last]-array[0];         // diferencia entre el primer y ultimo elemento

    for (int i = 0; i < amount; i++) {
        
        key = rand() % gap; // genera numeros aleatorios en el rango del arreglo
        
        auto t1 = high_resolution_clock::now();

        bool found = binary_search(array, key);
        
        auto t2 = high_resolution_clock::now();

        duration<double, std::milli> ms_double = t2 - t1;

        if (found) {
            cout << "'" << key << "' encontrada en: ";
            
        }
        else {
            cout << "'" << key << "' no encontrada en: ";
        }
        std::cout << ms_double.count() << endl;
    }
    cout << endl;
}
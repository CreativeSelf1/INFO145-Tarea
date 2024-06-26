#include <iostream>
#include <chrono>

#include "searchMeasure.h"
#include "binarySearch.h"
using namespace std::chrono;

void search_measure(vector<int>& array, int amount){
    cout << "numeros encontrados con busqueda binaria: ";
    int key;

    int last = array.size()-1;
    int gap = array[last]-array[0];         // diferencia entre el primer y ultimo elemento

    for (int i = 0; i < amount; i++) {;
        key = rand() % gap; // genera numeros aleatorios en el rango del arreglo
        bool found = binary_search(array, key);
        if (found) {
            cout << "'" << key << "' encontrada "<< endl;
        }
        else {
            cout << "'" << key << "' no encontrada" << endl;
        }
    }
    cout << endl;
}
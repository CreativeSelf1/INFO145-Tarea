#include <iostream>
#include <chrono>
#include <stdlib.h>

#include "searchMeasure.h"
#include "binarySearch.h"
using namespace std::chrono;

// void chronno_trigger(){
//     int cont = 0;
//     int diff = 0;
//     for (int i = 0; i< 10; i++){
//         auto t1 = high_resolution_clock::now();
//         _sleep(1000);
//         auto t2 = high_resolution_clock::now();
//         duration<double, std::milli> t3 = t2 - t1;
//         diff = t3.count()-1000;
//         cout << diff<<endl;
//         cont += diff;
//     }
//     cont = cont/10;
//     std::cout << "En promedio la estimacion de tiempo tiene una desviacion de " << cont << "ms." << endl;
// }
void search_measure(vector<int>& array, int amount, string name) {
    unsigned t0, t1;

    t0 = clock();
    int key;
    for (int i = 0; i < amount; i++) {
        key = array[rand() % array.size()]; // genera números aleatorios en el rango del arreglo
        binary_search(array, key);
    }
    t1 = clock();

    double timeInSeconds = (double(t1 - t0) / CLOCKS_PER_SEC);
    double timeInMilliseconds = timeInSeconds * 1000; 

    cout << "Arreglo distribución " << name << " - Tiempo de ejecución: " << timeInMilliseconds << " ms" << endl;
}


void gap_search_measure(vector<int>& arr, vector<int>& gapCodingArray, vector<int>&  sampleArray,int b, int amount){
    int key;
    int last = arr.size()-1;
    int gap = arr[last]-arr[0];         // diferencia entre el primer y ultimo elemento

    auto mainTimeStart= high_resolution_clock::now();
    for (int i = 0; i < amount; i++) {
        key = rand() % gap; // genera numeros aleatorios en el rango del arreglo
        //auto t1 = high_resolution_clock::now();
        bool found = gapCodingSearch(arr, gapCodingArray, sampleArray, b, key);
        // if (found) {
        //     cout << "'" << key << "' encontrada en: ";
        // }
        // else {
        //     cout << "'" << key << "' no encontrada en: ";
        // }

        // auto t2 = high_resolution_clock::now();

        // duration<double, std::milli> t3 = t2 - t1;
        // std::cout << t3.count() << endl;
    }
    // auto t2 = high_resolution_clock::now();
    // duration<double, std::milli> t3 = t2 - t1;
    // cout << t3.count() << endl;

    auto mainTimeStop= high_resolution_clock::now();
    duration<double, std::milli> mainTimeTotal = mainTimeStop - mainTimeStart;
    cout << "Tiempo de busqueda de gapCoding " << amount << " palabras: " << mainTimeTotal.count() << " ms"<<endl;
}

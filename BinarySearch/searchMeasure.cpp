#include <iostream>
#include <chrono>
#include <stdlib.h>

#include "searchMeasure.h"
#include "binarySearch.h"
using namespace std::chrono;

void chronno_trigger(){
    int cont = 0;
    int diff = 0;
    for (int i = 0; i< 10; i++){
        auto t1 = high_resolution_clock::now();
        _sleep(1000);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> t3 = t2 - t1;
        diff = t3.count()-1000;
        cout << diff<<endl;
        cont += diff;
    }
    cont = cont/10;
    std::cout << "En promedio la estimacion de tiempo tiene una desviacion de " << cont << "ms." << endl;
}
void search_measure(vector<int>& array, int amount){
    cout << "numeros buscados con busqueda binaria: " << endl;
    int key;
    int last = array.size()-1;
    int gap = array[last]-array[0];         // diferencia entre el primer y ultimo elemento

    auto mainTimeStart= high_resolution_clock::now();

    for (int i = 0; i < amount; i++) {
        
        key = rand() % gap; // genera numeros aleatorios en el rango del arreglo
        
        auto t1 = high_resolution_clock::now();

        bool found = binary_search(array, key);

        if (found) {
            cout << "'" << key << "' encontrada en: ";
        }
        else {
            cout << "'" << key << "' no encontrada en: ";
        }

        auto t2 = high_resolution_clock::now();

        duration<double, std::milli> t3 = t2 - t1;
        std::cout << t3.count() << endl;
    }

    auto mainTimeStop= high_resolution_clock::now();

    duration<double, std::milli> mainTimeTotal = mainTimeStop - mainTimeStart;
    auto elapsedTime = duration_cast<chrono::nanoseconds>(mainTimeStop - mainTimeStart); //alternativa para contar el tiempo
    std::cout << "Tiempo de busqueda de " << amount << " palabras: " << mainTimeTotal.count() << endl;

    auto mean = mainTimeTotal / amount;
    std::cout << "Tiempo de busqueda prmedio: " << mean.count() << endl;
}

void gap_search_measure(vector<int>& arr, vector<int>& gapCodingArray, vector<int>&  sampleArray,int b, int amount){
    cout << "numeros buscados con busqueda binaria gapCoding: " << endl;
    int key;
    int last = arr.size()-1;
    int gap = arr[last]-arr[0];         // diferencia entre el primer y ultimo elemento

    auto mainTimeStart= high_resolution_clock::now();

    for (int i = 0; i < amount; i++) {
        
        key = rand() % gap; // genera numeros aleatorios en el rango del arreglo
        
        auto t1 = high_resolution_clock::now();

        bool found = gapCodingSearch(arr, gapCodingArray, sampleArray, b, key);

        if (found) {
            cout << "'" << key << "' encontrada en: ";
        }
        else {
            cout << "'" << key << "' no encontrada en: ";
        }

        auto t2 = high_resolution_clock::now();

        duration<double, std::milli> t3 = t2 - t1;
        std::cout << t3.count() << endl;
    }

    auto mainTimeStop= high_resolution_clock::now();

    duration<double, std::milli> mainTimeTotal = mainTimeStop - mainTimeStart;
    std::cout << "Tiempo de busqueda de " << amount << " palabras: " << mainTimeTotal.count() << endl;

    auto mean = mainTimeTotal / amount;
    std::cout << "Tiempo de busqueda prmedio: " << mean.count() << endl;
}

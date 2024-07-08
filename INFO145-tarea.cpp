#include <iostream>
#include <random>
#include <vector>
#include <ctime> 

#include "BinarySearch/binarySearch.h"
#include "BinarySearch/searchMeasure.h"
#include "Array_operations_cases/case_2.1.h"
#include "Array_operations_cases/case_2.2.h"


using namespace std;

template <typename T>
void imprimirArray(const vector<T>& v) {
    for (const auto& elemento : v) {
        cout << elemento << " ";
    }
    cout << endl;
}

double calcularMedia(vector<long>& v) {
    double suma = 0.0;
    for (const auto& elemento : v) {
        suma += elemento;
    }
    return suma / v.size();
}


bool gapCodingSearch_prueba(vector<long>& arr, vector<long>& gapCodingArray, vector<int>&  sampleArray,int b, int key){
    //busqueda en sample
    int left = 0; 
    int right = sampleArray.size()-1;
    int mid;

    //guarda intervalos de busquedas del sample
    int valueLeft = -1; // int valueRight = -1;
    int interLeft = 0;  int interRight = sampleArray.size()-1;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (sampleArray[mid] == key) {
            valueLeft = sampleArray[mid];
            //valueRight = sampleArray[mid];
            return true;
        }
        if (sampleArray[mid] < key) {
            valueLeft = sampleArray[mid];  
            interLeft = mid;
            left = mid + 1;
        } else {
            //valueRight = sampleArray[mid];  
            interRight = mid;
            right = mid - 1;
        }
    }
    

    // cout << valueLeft << " " <<"posicion:"<<interLeft <<endl;
    // cout <<" posicion:"<<interRight<<endl ;


    //si no se encuenta en el sample buscar en el gapArray dentro del intervalo  
    //cout << "buscand en gapArray" << endl;
    long limit = interRight*b;  //
    
    if(interLeft == interRight){  //Si el numero no se encuentra entre los intervalos del sample, esta mas a la derecha 
        limit = gapCodingArray.size();
       // cout << "se cambio limit al valor " << limit << endl;
    }
    
    for(long i = interLeft*b; i <= limit; i++) {
        if(valueLeft == key)
            return true;
        
        if(valueLeft > key)
            return false;
        
        else{
            valueLeft = valueLeft + gapCodingArray[i+1]; 
        }
    }
    return false;
}

void gap_search_measure_prueba(vector<long>& arr, vector<long>& gapCodingArray, vector<int>&  sampleArray,int b, long amount){
    int key;
    int last = arr.size()-1;
    int gap = arr[last]-arr[0];         // diferencia entre el primer y ultimo elemento
    unsigned t0, t1;

    t0 = clock();
    for (long i = 0; i < amount; i++) {
        key = rand() % gap; // genera numeros aleatorios en el rango del arreglo
        //auto t1 = high_resolution_clock::now();
        
        //cout << "buscando " << key<< endl;
        bool found = gapCodingSearch_prueba(arr, gapCodingArray, sampleArray, b, key);
        // if (found)
        // {
        //    cout << "encontrado "<<key<<endl;
        // }
        // else cout << "no encontrado "<<key<<endl;
        
        
    }
    t1 = clock();
    double timeInSeconds = (double(t1 - t0) / CLOCKS_PER_SEC);
    double timeInMilliseconds = timeInSeconds * 1000; 

    cout << "Arreglo distribución linal gap coding - Tiempo de ejecución: " << timeInMilliseconds << " ms" << endl;
}

int main(int argc, char *argv[]) {
    //Definicion de variables
    long int n = 100000000;       //largo del arreglo
    double sigma = 10;  //desviacion estandar
    long int amount = 100000000;  //numero de busquedas 
    int epsilon = 15;
    int m = 10;        //numero de elementos del arreglo    2.2
    int b = n/m;        //intervalo para eleccion de elementos   2.2
    



    // CASO 2.1  -  Arreglo explicito

    vector<long int> lineal = GeneradorLineal(n, epsilon);
    vector<long int> normal = GeneradorNormal(n, calcularMedia(lineal), sigma); 
    //cout << "vector lineal: "; imprimirArray(lineal);
   // cout << "vector normal: "; imprimirArray(normal);

    cout << "Busquedas binarias - Array Explicito\n" << endl;

    search_measure(lineal, amount, "lineal");   //realizar "amount" cantidades de busquedas de busquedas binarias
    search_measure(normal, amount, "normal");



    // // CASO 2.2 GAP-CODING
    
    vector<long int> gapCodingArray_lineal = gapCoding(lineal, n);
    vector<long int> gapCodingArray_normal = gapCoding(normal, n);
    //cout << " gapCodingArray lineal: "; imprimirArray(gapCodingArray_lineal);
    // cout << " gapCodingArray normal: "; imprimirArray(gapCodingArray_normal);
    

    vector<int> sampleArray_lineal = sampleCoding(lineal, n, m, b);
    vector<int> sampleArray_normal = sampleCoding(normal, n, m, b);
    //cout << "sample lineal: "; imprimirArray(sampleArray_lineal);
    // cout << "sample normal: "; imprimirArray(sampleArray_normal);

    // cout <<"\nBusqueda gapCoding"<<endl;

    // gap_search_measure(lineal, gapCodingArray_lineal, sampleArray_lineal, b, amount);
    // gap_search_measure(normal, gapCodingArray_normal, sampleArray_normal, b, amount);

    cout << "\nBusquedas binarias - Array Gap-Coding\n" << endl;
    gap_search_measure_prueba(lineal, gapCodingArray_lineal, sampleArray_lineal, b, amount);
    gap_search_measure_prueba(normal, gapCodingArray_lineal, sampleArray_lineal, b, amount);



    



    // CASO 2.3 SHANON-FANO/HUFMANN



    return 0;
}

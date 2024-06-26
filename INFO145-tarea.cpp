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
        std::cout << elemento << " ";
    }
    std::cout << std::endl;
}

double calcularMedia(vector<int>& v) {
    double suma = 0.0;
    for (const auto& elemento : v) {
        suma += elemento;
    }
    return suma / v.size();
}

int main(int argc, char *argv[]) {
    //Definicion de variables
    int n = 10;     //largo del arreglo
    int amount = 10;  //numero de busquedas 
    if (argc == 2){
        n = strtol(argv[1], NULL, 10);
    }
    if (argc == 3){
        n = strtol(argv[1], NULL, 10);
        amount = strtol(argv[2], NULL, 10);
    }

    double sigma = 10;  //desviacion estandar
    int epsilon = 10;
    int m = n/4;        //numero de elementos del arreglo    2.2
    int b = n/m;        //intervalo para eleccion de elementos, con b=n/m   2.2


    chronno_trigger();      //prueba de presicion

    // CASO 2.1  -  Arreglo explicito
   
    vector<int> lineal = GeneradorLineal(n, epsilon);
    vector<int> normal = GeneradorNormal(n, calcularMedia(lineal), sigma);

    cout << "vector lineal: "; imprimirArray(lineal);
    //cout << "vector normal: "; imprimirArray(normal);

    search_measure(lineal, amount);   //realizar "amount" cantidades de busquedas de busquedas binarias
    //search_measure(normal, amount);



    // CASO 2.2 GAP-CODING
    vector<int> gapCodingArray_lineal = gapCoding(lineal, n);
    //vector<int> gapCodingArray_normal = gapCoding(normal, n);
    //std::cout << "gapCodingArray_lineal: "; imprimirArray(gapCodingArray_lineal);
    //std::cout << "gapCodingArray_normal: "; imprimirArray(gapCodingArray_normal);
    

    vector<int> sampleArray_lineal = sampleCoding(lineal, n, m, b);
    //vector<int> sampleArray_normal = sampleCoding(normal, n, m, b);
    //cout << "sample lineal: "; imprimirArray(sampleArray_lineal);
    //cout << "sample normal: "; imprimirArray(sampleArray_normal);

    gap_search_measure(lineal, gapCodingArray_lineal, sampleArray_lineal, b, amount);   //realizar "amount" cantidades de busquedas de busquedas binarias reducidas
    



    // CASO 2.3 SHANON-FANO/HUFMANN

    return 0;
}

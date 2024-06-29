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

double calcularMedia(vector<int>& v) {
    double suma = 0.0;
    for (const auto& elemento : v) {
        suma += elemento;
    }
    return suma / v.size();
}

int main(int argc, char *argv[]) {
    //Definicion de variables
    int n = 1000000;       //largo del arreglo
    double sigma = 10;  //desviacion estandar
    int amount = 100000;  //numero de busquedas 
    int epsilon = 15;
    int m = 4;        //numero de elementos del arreglo    2.2
    int b = n/m;        //intervalo para eleccion de elementos   2.2
    



    // CASO 2.1  -  Arreglo explicito

    vector<int> lineal = GeneradorLineal(n, epsilon);
    vector<int> normal = GeneradorNormal(n, calcularMedia(lineal), sigma); 
    // cout << "vector lineal: "; imprimirArray(lineal);
    // cout << "vector normal: "; imprimirArray(normal);

    cout << "Busqueda binarias" << endl;

    search_measure(lineal, amount, "lineal");   //realizar "amount" cantidades de busquedas de busquedas binarias
    search_measure(normal, amount, "normal");



    // // CASO 2.2 GAP-CODING
    
    vector<int> gapCodingArray_lineal = gapCoding(lineal, n);
    vector<int> gapCodingArray_normal = gapCoding(normal, n);
    // cout << " gapCodingArray lineal: "; imprimirArray(gapCodingArray_lineal);
    // cout << " gapCodingArray normal: "; imprimirArray(gapCodingArray_normal);
    

    vector<int> sampleArray_lineal = sampleCoding(lineal, n, m, b);
    vector<int> sampleArray_normal = sampleCoding(normal, n, m, b);
    // cout << "sample lineal: "; imprimirArray(sampleArray_lineal);
    // cout << "sample normal: "; imprimirArray(sampleArray_normal);

    cout <<"\nBusqueda gapCoding"<<endl;

    gap_search_measure(lineal, gapCodingArray_lineal, sampleArray_lineal, b, amount);
    gap_search_measure(normal, gapCodingArray_normal, sampleArray_normal, b, amount);



    // CASO 2.3 SHANON-FANO/HUFMANN



    return 0;
}

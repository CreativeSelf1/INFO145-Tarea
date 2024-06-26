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
    int n = 10;       //largo del arreglo
    double sigma = 2;  //desviacion estandar
    int amount = 10;  //numero de busquedas 
    int epsilon = 10;
    int m = 5;        //numero de elementos del arreglo    2.2
    int b = n/m;        //intervalo para eleccion de elementos, con b=n/m   2.2
    



    // CASO 2.1  -  Arreglo explicito
   
    vector<int> lineal = GeneradorLineal(n, epsilon);
    vector<double> normal = GeneradorNormal(n, calcularMedia(lineal), sigma);

    //cout << "vector lineal: "; imprimirArray(lineal);
    //cout << "vector normal: "; imprimirArray(normal);

    search_measure(lineal, amount);   //realizar "amount" cantidades de busquedas de busquedas binarias
    //search_measure(normal, amount);



    // CASO 2.2 GAP-CODING
    vector<int> gapCodingArray_lineal = gapCoding(lineal, n);
    //vector<int> gapCodingArray_normal = gapCoding(normal, n);
    //cout << " gapCodingArray_lineal: "; imprimirArreglo(gapCodingArray_lineal);
    

    vector<int> sampleArray_lineal = sampleCoding(lineal, n, m, b);
    //vector<int> sampleArray_normal = sampleCoding(lineal, n, m, b);
    //cout << "sample lineal: "; imprimirArreglo(sampleArray_lineal);


    bool found = gapCodingSearch(lineal, gapCodingArray_lineal, sampleArray_lineal, 74);  //prueba de busqueda con valor 74 en sample
    if(found)  cout << "El valor 74 fue encontrado" << endl;



    // CASO 2.3 SHANON-FANO/HUFMANN



    return 0;
}

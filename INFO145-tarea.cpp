#include <iostream>
#include <random>
#include <vector>
#include <ctime> 

#include "BinarySearch/binarySearch.h"
#include "Array_operations_cases/case_2.1.h"
#include "Array_operations_cases/case_2.2.h"

using namespace std;

void imprimirArreglo(vector<int>& vec){
    for (int num : vec){
        cout << num << " ";
    }
    cout << endl;
}



int main(int argc, char *argv[]) {
    int n = 50;       //largo del arreglo
    int amount = 10;  //numero de busquedas 
    int epsilon = 10;
    int m = 7;        //numero de elementos del arreglo    2.2
    int b = 4;        //intervalo para eleccion de elementos   2.2



    // CASO 2.1  -  Arreglo explicito
    vector<int> lineal = GeneradorLineal(n, epsilon);
    vector<int> normal = GeneradorNormal(n);

    cout << "vector lineal: "; imprimirArreglo(lineal);

    search_measure(lineal, amount);
    //search_measure(normal, amount);



    // CASO 2.2 GAP-CODING
    vector<int> gapCodingArray_lineal = gapCoding(lineal, n);
    vector<int> gapCodingArray_normal = gapCoding(normal, n);
    cout << " gapCodingArray_lineal: "; imprimirArreglo(gapCodingArray_lineal);
    

    vector<int> sampleArray_lineal = sampleCoding(lineal, n, m, b);
    vector<int> sampleArray_normal = sampleCoding(lineal, n, m, b);
    cout << "sample lineal: "; imprimirArreglo(sampleArray_lineal);


    bool found = gapCodingSearch(lineal, gapCodingArray_lineal, sampleArray_lineal, 74);  //prueba de busqueda con valor 74 en sample
    if(found)  cout << "El valor 74 fue encontrado" << endl;



    // CASO 2.3 SHANON-FANO/HUFMANN



    return 0;
}

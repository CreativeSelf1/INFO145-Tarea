#include <iostream>
#include <random>
#include <vector>
#include <ctime> 
#include <cstdlib>
#include <climits>
#include <math.h>       

#include "Headers/binarySearch.h"
#include "Headers/searchMeasure.h"
#include "Headers/case_2.1.h"
#include "Headers/case_2.2.h"
#include "Headers/case_2.3.h"

using namespace std;

template <typename T>
void imprimirArray(const vector<T>& v) {
    for (const auto& elemento : v) {
        cout << elemento << " ";
    }
    cout << endl;
}

bool gapCodingSearch(vector<long int>& arr, vector<long int>& gapCodingArray, vector<int>&  sampleArray,int b, int key){
    //primero busca en el sample el valor "key"
    int left = 0; 
    int right = sampleArray.size()-1;
    int mid;

    //guarda intervalos de busquedas del sample
    int valueLeft = gapCodingArray[0]; 
    int interLeft = 0;  int interRight = sampleArray.size()-1;

    //hacer busqueda binaria y guardar los intervalos del sample
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (sampleArray[mid] == key) {
            valueLeft = sampleArray[mid];
            return true;
        }
        if (sampleArray[mid] < key) {
            valueLeft = sampleArray[mid];  
            interLeft = mid;
            left = mid + 1;
        } else {
            interRight = mid;
            right = mid - 1;
        }
    }

    //si no se encuenta en el sample buscar en el gapArray dentro del intervalo  
    long int limit = interRight*b;  //

    if(interLeft == interRight){  //Si el numero no se encuentra entre los intervalos del sample, esta mas a la derecha  
        limit = gapCodingArray.size();
    }
   
    if(key < sampleArray[0]){  // quiere decir que no esta en el arreglo
        return false;
    }

    for(long int i = interLeft*b; i <= limit; i++) {
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

void gap_search_measure(vector<long int>& arr, vector<long int>& gapCodingArray, vector<int>&  sampleArray,int b, long int amount){
    int key;
    unsigned t0, t1;

    t0 = clock();
    for (long int i = 0; i < amount; i++) {
        key = arr[rand() % arr.size()]; // genera numeros aleatorios en el rango del arreglo
        gapCodingSearch(arr, gapCodingArray, sampleArray, b, key);
    }
    t1 = clock();
    double timeInSeconds = (double(t1 - t0) / CLOCKS_PER_SEC);
    double timeInMilliseconds = timeInSeconds * 1000; 

    cout<< " - Tiempo de ejecución: "<< timeInMilliseconds << "ms"<<endl;
}


int main(int argc, char *argv[]) {
    //Definición de variables
    if (argc != 5) {
        cout << "Usa: " << argv[0] << " <n> <amount> <sigma> <m>\n";
        return 1;
    }

    long int n = atol(argv[1]);          //largo del arreglo
    long int amount = atol(argv[2]);     //cantidad de búsquedas
    double sigma = atof(argv[3]);        //desviacion estandar
    int m = atoi(argv[4]);               //número de elemtos de arreglo Sample (m<n)
    int epsilon = 15;
    int b = n / m;                    // intervalo para eleccion de elementos

    //comprobaciones de entrada
    if (n < 1) {
        cout << "Ingrese un largo mayor que 0\n";
        return 1;
    }
    
    if (m >= n) {
        cout << "El valor m tiene ser menor que n\n";
        return 1;
    }
    
    // CASO 2.1  -  Arreglo explicito

    //generar arreglo distribucion lineal/normal
    vector<long int> lineal = GeneradorLineal(n, epsilon);
    vector<long int> normal = GeneradorNormal(n, calcularMedia(lineal), sigma); 
   
   //memoria ocupada por arreglo (long int = 8 bytes en sistemas de 64 bits y 4 bytes en sistemas de 32bits)
    size_t lineal_memory = lineal.size() * sizeof(long int);
    size_t normal_memory = normal.size() * sizeof(long int);
  
    cout << "Busquedas binarias - Array Explicito\n" << endl;
    cout<< "Arreglo distribución lineal - memoria ocupada " << lineal_memory <<" bytes";search_measure(lineal, amount);   //realizar "amount" cantidades de busquedas de busquedas binarias
    cout<< "Arreglo distribución normal - memoria ocupada " << normal_memory <<" bytes";search_measure(normal, amount);
    


    // // CASO 2.2 GAP-CODING
    
    //generar GapArray
    vector<long int> gapCodingArray_lineal = gapCoding(lineal, n);
    vector<long int> gapCodingArray_normal = gapCoding(normal, n);

    size_t gap_lineal_memory = gapCodingArray_lineal.size() * sizeof(long int);
    size_t gap_normal_memory = gapCodingArray_normal.size() * sizeof(long int);
    
    //generar SampleArray  
    vector<int> sampleArray_lineal = sampleCoding(lineal, n, m, b);
    vector<int> sampleArray_normal = sampleCoding(normal, n, m, b);

    size_t sample_lineal_memory = sampleArray_lineal.size() * sizeof(int);      
    size_t sample_normal_memory = sampleArray_normal.size() * sizeof(int);
    

    // gap_search_measure(lineal, gapCodingArray_lineal, sampleArray_lineal, b, amount);
    // gap_search_measure(normal, gapCodingArray_normal, sampleArray_normal, b, amount);

    cout << "\nBusquedas binarias - Array Gap-Coding\n" << endl;
    cout <<"Arreglo Gap-Coded lineal - memoria ocupada "<<gap_lineal_memory+sample_lineal_memory<<" bytes";
    gap_search_measure(lineal, gapCodingArray_lineal, sampleArray_lineal, b, amount);   
    cout <<"Arreglo Gap-Coded normal - memoria ocupada "<<gap_normal_memory+sample_normal_memory<<" bytes";
    gap_search_measure(normal, gapCodingArray_lineal, sampleArray_lineal, b, amount);



    // CASO 2.3 SHANON-FANO/HUFMANN

    vector<short int> shortGapCodingArray_lineal = shortGapCoding(lineal, n);
    vector<short int> shortGapCodingArray_normal = shortGapCoding(normal, n);

    size_t shortGap_lineal_memory = shortGapCodingArray_lineal.size() * sizeof(short int);      
    size_t ShortGap_normal_memory = shortGapCodingArray_normal.size() * sizeof(short int);
    
    
    cout << "\nBusquedas binarias - Array Gap-Coding con short\n" << endl;

    cout <<"Arreglo Gap-Coded lineal codificado de tipo short - memoria ocupada "<<shortGap_lineal_memory + sample_lineal_memory<<" bytes";
    short_gap_search_measure(lineal, shortGapCodingArray_lineal, sampleArray_lineal, b, amount);    //realizar "amount" cantidades de busquedas de busquedas binarias
    cout <<"Arreglo Gap-Coded normal codificado de tipo short - memoria ocupada "<<ShortGap_normal_memory + sample_lineal_memory<<" bytes";
    short_gap_search_measure(normal, shortGapCodingArray_normal, sampleArray_lineal, b, amount); //realizar

    return 0;
}

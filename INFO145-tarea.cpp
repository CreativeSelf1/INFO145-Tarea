#include <iostream>
#include <random>
#include <vector>
#include <ctime> 
#include <cstdlib>  

#include "Searches/binarySearch.h"
#include "Searches/searchMeasure.h"
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


bool gapCodingSearch(vector<long>& arr, vector<long>& gapCodingArray, vector<int>&  sampleArray,int b, int key){
    //primero busca en el sample el valor "key"
    int left = 0; 
    int right = sampleArray.size()-1;
    int mid;

    //guarda intervalos de busquedas del sample
    int valueLeft = -1; 
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

void gap_search_measure(vector<long int>& arr, vector<long int>& gapCodingArray, vector<int>&  sampleArray,int b, long int amount, string name){
    int key;
    int last = arr.size()-1;
    int gap = arr[last]-arr[0];         // diferencia entre el primer y ultimo elemento
    unsigned t0, t1;

    t0 = clock();
    for (long int i = 0; i < amount; i++) {
        key = rand() % gap; // genera numeros aleatorios en el rango del arreglo
        gapCodingSearch(arr, gapCodingArray, sampleArray, b, key);
    }
    t1 = clock();
    double timeInSeconds = (double(t1 - t0) / CLOCKS_PER_SEC);
    double timeInMilliseconds = timeInSeconds * 1000; 

    cout <<"Arreglo Gap-Coded "<<name<<" - Tiempo de ejecución: "<< timeInMilliseconds << "ms"<<endl;


}

int main(int argc, char *argv[]) {
    //Definicion de variables
    
    if (argc != 5) {
        cout << "Usa: " << argv[0] << " <n> <amount> <sigma> <m>\n";
        return 1;
    }

    long int n = atol(argv[1]);  
    long int amount = atol(argv[2]); 
    double sigma = atof(argv[3]); 
    int m = atoi(argv[4]);   
    int epsilon = 15;
    int b = n / m;                    // intervalo para eleccion de elementos

     if (m >= n) {
        cout << "El valor m tiene ser menor que n\n";
        return 1;
    }
    

    // CASO 2.1  -  Arreglo explicito

    //genrerar arreglo distribucion lineal/normal
    vector<long int> lineal = GeneradorLineal(n, epsilon);
    vector<long int> normal = GeneradorNormal(n, calcularMedia(lineal), sigma); 
  

    cout << "Busquedas binarias - Array Explicito\n" << endl;
    search_measure(lineal, amount, "lineal");   //realizar "amount" cantidades de busquedas de busquedas binarias
    search_measure(normal, amount, "normal");
    


    // // CASO 2.2 GAP-CODING
    
    //generar GapArray
    vector<long int> gapCodingArray_lineal = gapCoding(lineal, n);
    vector<long int> gapCodingArray_normal = gapCoding(normal, n);
  
    //generar SampleArray  
    vector<int> sampleArray_lineal = sampleCoding(lineal, n, m, b);
    vector<int> sampleArray_normal = sampleCoding(normal, n, m, b);
  

    cout << "\nBusquedas binarias - Array Gap-Coding\n" << endl;
    gap_search_measure(lineal, gapCodingArray_lineal, sampleArray_lineal, b, amount, "lineal");
    gap_search_measure(normal, gapCodingArray_lineal, sampleArray_lineal, b, amount, "normal");




    // CASO 2.3 SHANON-FANO/HUFMANN



    return 0;
}

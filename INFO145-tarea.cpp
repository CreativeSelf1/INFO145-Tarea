#include <iostream>
#include <random>
#include <vector>
#include <ctime> 
#include "BinarySearch/binarySearch.h"

using namespace std;

void imprimirVector(vector<int>& vec){
    for (int num : vec){
        cout << num << " ";
    }
    cout << endl;
}

void search_measure(vector<int>& array, int amount){
    cout << "numeros encontrados con busqueda binaria: ";
    int key;
    for (int i = 0; i < amount; i++) {
        key = array[rand() % array.size()]; // genera numeros aleatorios en el rango del arreglo
        bool found = binary_search(array, key);
        if (found) {
            cout << key << " ";
        }
    }
    cout << endl;
}

vector<int> GeneradorLineal(int n, int epsilon) {
    vector<int> lineal(n);

    lineal[0] = rand() % 10;
    for (int i = 1; i < n; i++) {
        lineal[i] = lineal[i-1] + rand() % epsilon;
    }
    return lineal;
}

vector<int> GeneradorNormal(int n){
    vector<int> normal(n);

    return normal;
}

vector<int> gapCoding(vector<int>& lineal, int n){
    vector<int> gapArray(n);

    gapArray[0] = lineal[0];
    for (int i = 1; i < n; i++){
        gapArray[i] = lineal[i] - lineal[i-1];
    }
    return gapArray;
}

vector<int> sampleCoding(vector<int>& array, int n, int m, int b){
    vector<int> sampleArray;

    for (int i = 0; i < n && int(sampleArray.size()) < m; i+=b){
        sampleArray.push_back(array[i]);
    }
    return sampleArray;
}

bool gapCodingSearch(vector<int>& lineal, vector<int>& gapCodingArray_lineal, vector<int>&  sampleArray_lineal, int key){
   //se busca el valor en el arreglo Sample
   if (binary_search(sampleArray_lineal, key)){
    return true;
   }

    // completar lo que falte

   return false;
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

    cout << "vector lineal: "; imprimirVector(lineal);

    search_measure(lineal, amount);
    //search_measure(normal, amount);




    // CASO 2.2 GAP-CODING
    vector<int> gapCodingArray_lineal = gapCoding(lineal, n);
    vector<int> gapCodingArray_normal = gapCoding(normal, n);
    

    vector<int> sampleArray_lineal = sampleCoding(lineal, n, m, b);
    vector<int> sampleArray_normal = sampleCoding(lineal, n, m, b);

    cout << "sample lineal: "; imprimirVector(sampleArray_lineal);

    bool found = gapCodingSearch(lineal, gapCodingArray_lineal, sampleArray_lineal, 74);  //prueba de busqueda con valor 74 en sample
    if(found)  cout << "El valor 74 fue encontrado" << endl;

    // CASO 2.3 SHANON-FANO/HUFMANN

    return 0;
}

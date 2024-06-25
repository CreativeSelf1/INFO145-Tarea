#include "case_2.2.h"

using namespace std;


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

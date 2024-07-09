#include "../Headers/case_2.3.h"
using namespace std;
vector<short int> shortGapCoding(vector<long int>& array, long int n){
    vector<short int> shortGapArray(n);

    shortGapArray[0] = array[0];
    for (long i = 1; i < n; i++){
        
        long diff = array[i] - array[i-1];
        
        if ( (diff > 32767) || (diff < -32768) ){
            cout << " wat " << endl;
            diff = -1;
        };
        short temp = diff;
        shortGapArray[i] = temp;
    }
    return shortGapArray;
}

bool shortGapCodingSearch(vector<long>& arr, vector<short>& gapCodingArray, vector<int>&  sampleArray,int b, int key){
    //busqueda en sample
    int left = 0; 
    int right = sampleArray.size()-1;
    int mid;

    //guarda intervalos de busquedas del sample
    int valueLeft = gapCodingArray[0]; 
    int interLeft = 0;  int interRight = sampleArray.size()-1;

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

    long limit = interRight*b;  //

    if(interLeft == interRight){  //Si el numero no se encuentra entre los intervalos del sample, esta mas a la derecha 
        limit = gapCodingArray.size();
    }

    if(key < sampleArray[0]){  // quiere decir que no esta en el arreglo
        return false;
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

void short_gap_search_measure(vector<long>& arr, vector<short>& gapCodingArray, vector<int>&  sampleArray,int b, long amount){
    int key;
    unsigned t0, t1;

    t0 = clock();
    for (long i = 0; i < amount; i++) {
        key = arr[rand() % arr.size()]; // genera numeros aleatorios en el rango del arreglo
        shortGapCodingSearch(arr, gapCodingArray, sampleArray, b, key);
    }
    t1 = clock();

    double timeInSeconds = (double(t1 - t0) / CLOCKS_PER_SEC);
    double timeInMilliseconds = timeInSeconds * 1000; 

    cout << " - Tiempo de ejecución: " << timeInMilliseconds << " ms" << endl;
}
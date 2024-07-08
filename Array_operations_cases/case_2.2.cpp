#include "case_2.2.h"

using namespace std;


vector<long int> gapCoding(vector<long int>& array, long int n){
    vector<long int> gapArray(n);

    gapArray[0] = array[0];
    for (long i = 1; i < n; i++){
        gapArray[i] = array[i] - array[i-1];
    }
    return gapArray;
}

vector<int> sampleCoding(vector<long int>& array, long n, int m, int b){
    vector<int> sampleArray;
    for (long i = 0; i < n; i+=b){
        if (int(sampleArray.size()) < m){
             sampleArray.push_back(array[i]);
        }
        else
            break;
        
    }
    return sampleArray;
}

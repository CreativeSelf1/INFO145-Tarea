#include "case_2.2.h"

using namespace std;


vector<int> gapCoding(vector<int>& array, int n){
    vector<int> gapArray(n);

    gapArray[0] = array[0];
    for (int i = 1; i < n; i++){
        gapArray[i] = array[i] - array[i-1];
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

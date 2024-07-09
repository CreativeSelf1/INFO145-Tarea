#include "../Headers/case_2.2.h"

using namespace std;


vector<long int> gapCoding(vector<long int>& array, long int n){
    vector<long int> gapArray(n);

    gapArray[0] = array[0];
    for (long i = 1; i < n; i++){
        gapArray[i] = array[i] - array[i-1];
    }
    // cout << "gapCodingArray_normal: " << ((sizeof(gapArray[0]))*n) * CHAR_BIT << endl;
    return gapArray;
}

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
    // cout << "shortGapCodingArray_normal: " << ((sizeof(shortGapArray[0]))*n) * CHAR_BIT << endl;
    return shortGapArray;
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

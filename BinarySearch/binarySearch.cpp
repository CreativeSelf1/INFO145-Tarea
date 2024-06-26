#include "binarySearch.h"
using namespace std;

bool binary_search(const vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return true;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}


bool gapCodingSearch(vector<int>& arr, vector<int>& gapCodingArray, vector<int>&  sampleArray,int b, int key){
    //se busca en el arreglo sample para conseguir cota izquierda y derecha
    int m = sampleArray.size();
    int left = 0;
    int right = 0;
    for (int i = 0; i<m; i++){
        if (sampleArray[i]<key){
            left = i;
        }
        else{
            right= i;
            break;
        }
    }
    left = left * b;
    if (right == 0){
        right= sampleArray.size()-1;
    }

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return true;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}
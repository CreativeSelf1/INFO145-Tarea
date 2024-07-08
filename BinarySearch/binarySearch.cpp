#include "binarySearch.h"
using namespace std;

bool binary_search(vector<long int>& arr, int key) {
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


// bool gapCodingSearch(vector<int>& arr, vector<int>& gapCodingArray, vector<int>&  sampleArray,int b, int key){
//     se busca en el arreglo sample para conseguir cota izquierda y derecha
//     int m = sampleArray.size();
//     int left = 0;
//     int right = 0;
//     int ct, cta = 0;
//     int mid;
//     for (int i = 0; i<m; i++){
//         if (sampleArray[i]<key){
//             left = i;
//             ct = sampleArray[i];
//         }
//         else{
//             right = i;
//             break;
//         }
//     }
//     if (right == 0){
//         right = gapCodingArray.size()-1;
//     }
//     else{
//         right = right * b;
//     }
//     left = left * b;
//     cta = ct;
    
//     while (left <= right) {
//         mid = (left + right) / 2;
//         for (int i = left; i< mid; i++){
//             cta += gapCodingArray[i];
//         }
//         if (cta == key) {
//             return true;
//         } else if (cta < key) {
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }
//     return false;
// }
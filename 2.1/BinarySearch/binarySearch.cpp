#include "binarySearch.h"
using namespace std;

int binary_search(int *arr, int tamano, int key){
    int left = 0; 
    int right = tamano -1 ;

    while (left <= right){
        int mid = (left + right) / 2;
        if (arr[mid] == key){
            return mid;
        }
        else if (arr[mid] < key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}
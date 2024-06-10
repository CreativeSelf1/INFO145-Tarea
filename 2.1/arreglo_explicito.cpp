#include <iostream>
 
using namespace std;

int* generadorLineal(int n){
    int* lineal = new int[n];
    
    return lineal;
}

int* generadorNormal(int n){
    int* normal = new int[n];
    
    return normal;
}

int main(int argc, char *argv[]) {
    int n = 10000;

    int* lineal = generadorLineal(n);
    int* normal = generadorNormal(n);

}
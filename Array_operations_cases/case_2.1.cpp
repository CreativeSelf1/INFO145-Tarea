#include "case_2.1.h"
using namespace std;

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

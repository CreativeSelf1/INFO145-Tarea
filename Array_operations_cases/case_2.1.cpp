#include "case_2.1.h"
using namespace std;


vector<int> GeneradorLineal(int n, int epsilon) {
    vector<int> lineal(n);
    srand(time(NULL));
    lineal[0] = rand() % 10;
    for (int i = 1; i < n; i++) {
        lineal[i] = lineal[i-1] + rand() % epsilon;
    }
    return lineal;
}

vector<double> GeneradorNormal(int n, double media, double sigma) {
    vector<double> normal(n);

    // Generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> d(media, sigma);

    for (int i = 0; i < n; ++i) {
        normal[i] = (int)d(gen);            // conversion de float a entero
    }

    sort(normal.begin(), normal.end());
    return normal;
}


#include "../Headers/case_2.1.h"
using namespace std;


vector<long int> GeneradorLineal(long int n, int epsilon) {
    vector<long int> lineal(n);
    srand(time(NULL));
    lineal[0] = rand() % epsilon;
    for (int i = 1; i < n; i++) {
        lineal[i] = lineal[i-1] + rand() % epsilon;
    }
    return lineal;
}

vector<long int> GeneradorNormal(long int n, double media, double sigma) {
    vector<long int> normal(n);

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


double calcularMedia(vector<long>& v) {
    double suma = 0.0;
    for (const auto& elemento : v) {
        suma += elemento;
    }
    return suma / v.size();
}
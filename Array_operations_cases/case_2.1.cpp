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

vector<double> GeneradorNormal(int n, double media, double sigma) {
    vector<double> normal(n);

    // Generador de números aleatorios
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> d(media, sigma);

    for (int i = 0; i < n; ++i) {
        normal[i] = d(gen);
    }

    sort(normal.begin(), normal.end());
    return normal;
}

void search_measure(vector<int>& array, int amount){
    cout << "numeros encontrados con busqueda binaria: ";
    int key;
    for (int i = 0; i < amount; i++) {
        key = array[rand() % array.size()]; // genera numeros aleatorios en el rango del arreglo
        bool found = binary_search(array, key);
        if (found) {
            cout << key << " ";
        }
    }
    cout << endl;
}


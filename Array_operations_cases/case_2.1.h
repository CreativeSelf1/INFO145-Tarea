#ifndef CASE_2_1
#define CASE_2_1

#include <vector>
#include <random>
#include <ostream>
#include <algorithm>
#include <iostream>
#include "../Searches/BinarySearch.h"

using namespace std;

vector<long int> GeneradorLineal(long int n, int epsilon);
vector<long int> GeneradorNormal(long int n, double media, double sigma);
double calcularMedia(vector<long>& v);

#endif 


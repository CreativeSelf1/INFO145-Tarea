#ifndef CASE_2_1
#define CASE_2_1

#include <vector>
#include <random>
#include <ostream>
#include <algorithm>
#include <iostream>
#include "../BinarySearch/BinarySearch.h"

using namespace std;

vector<int> GeneradorLineal(int n, int epsilon);
vector<double> GeneradorNormal(int n, double media, double sigma);
void search_measure(vector<int>& array, int amount);

#endif 


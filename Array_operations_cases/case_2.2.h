#ifndef CASE_2_2
#define CASE_2_2

#include <vector>
#include <random>
#include <iostream>
#include "../BinarySearch/BinarySearch.h"
using namespace std;

void search_measure(vector<int>& array, int amount);
vector<int> gapCoding(vector<int>& lineal, int n);
vector<int> sampleCoding(vector<int>& array, int n, int m, int b);
bool gapCodingSearch(vector<int>& lineal, vector<int>& gapCodingArray_lineal, vector<int>&  sampleArray_lineal, int key);

#endif 


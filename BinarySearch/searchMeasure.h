#ifndef SEARCH_MEASURE
#define SEARCH_MEASURE

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void chronno_trigger();
void search_measure(vector<long int>& array, long int amount, string name) ;
void gap_search_measure(vector<int>& arr, vector<int>& gapCodingArray, vector<int>&  sampleArray,int b, int amount);

#endif
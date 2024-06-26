#ifndef SEARCH_MEASURE
#define SEARCH_MEASURE

#include <vector>
using namespace std;

void chronno_trigger();
void search_measure(vector<int>& array, int amount);
void gap_search_measure(vector<int>& arr, vector<int>& gapCodingArray, vector<int>&  sampleArray,int b, int amount);

#endif
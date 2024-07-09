#ifndef CASE_2_3
#define CASE_2_3

#include <vector>
#include <ostream>
#include <iostream>

using namespace std;

vector<short int> shortGapCoding(vector<long int>& array, long int n);
bool shortGapCodingSearch(vector<long>& arr, vector<short>& gapCodingArray, vector<int>&  sampleArray,int b, int key);
void short_gap_search_measure(vector<long>& arr, vector<short>& gapCodingArray, vector<int>&  sampleArray,int b, long amount, string name);


#endif 
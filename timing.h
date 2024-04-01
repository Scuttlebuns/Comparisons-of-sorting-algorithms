//timing.h
//Includes Timing code, and Declarations of sorting functions
#pragma once
#include <vector>
#include <chrono>
using namespace std;

//the timing code is templated to allow multiple functions to be passed rather than repeating the timing code
//time sort will return the time taken in [milliseconds, or microseconds, or seconds] based on dataset, this will be decided at a later date 
//Currently returning a long long of microseconds 

template <typename Func>
long long timeSort(Func sortFunction, vector<int> data){
    auto start = chrono::high_resolution_clock::now();
    sortFunction(data); // This sorts the copy
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

//timing.h
//Includes Timing code, and Declarations of sorting functions
#pragma once
#include <vector>
#include <chrono>
using namespace std;

template <typename Func>
long long timeSort(Func sortFunction, vector<int> data){
    auto start = chrono::high_resolution_clock::now();
    sortFunction(data); // This sorts the copy
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}

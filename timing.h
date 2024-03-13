//Includes Timing code, and Declarations of sorting functions
#pragma once
#include <vector>
#include <chrono>
using namespace std;

/*
template <typename Func>
long long timeSort(Func sortFunction, const vector<int>& data) {
    vector<int> dataCopy = data;
    
    auto start = chrono::high_resolution_clock::now();
    sortFunction(dataCopy);  // Sort the copy
    auto end = chrono::high_resolution_clock::now();
    
    return chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
} 
*/
template <typename Func>
long long timeSort(Func sortFunction, vector<int> data){
    auto start = chrono::high_resolution_clock::now();
    sortFunction(data); // This sorts the copy
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}





// Declaration of the sort functions
void insertionSort(vector<int> &vec);
void selectionSort(vector<int> &vec);
void bubbleSort(vector<int> &vec);
void mergeSort(vector<int> &vec);
void quickSort(vector<int> &vec);
void heapSort(vector<int> &vec);
void countingSort(vector<int> &vec);
void radixSort(vector<int> &vec);


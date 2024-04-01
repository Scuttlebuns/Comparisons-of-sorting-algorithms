//Bubble Sort
//Best Case time of O(n) if list is sorted
//Average/worse case of O(n^2) if list is reversed

//Uses two double nested forloops to check each index of each vector starting at index 1 and 2
#pragma once
#include <iostream>
#include <vector>
using namespace std;

//Bubble sort function
inline void bubbleSort(vector<int>& vec) {
  for (size_t j = 0; j < vec.size(); j++) { //number of passes
    for (size_t i = 0; i < vec.size() - j - 1; i++) { //performs comparision and swaps 
      if (vec.at(i) > vec.at(i + 1)) {
        int temp = vec.at(i);
        vec.at(i) = vec.at(i + 1);
        vec.at(i + 1) = temp;
      }
    }
  }
}

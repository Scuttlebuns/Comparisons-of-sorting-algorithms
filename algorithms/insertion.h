//Insertion Sort
//Best Case O(n)
//Average Case O(n^2)
//Worse Case O(n^2)
#pragma once
#include <iostream>
#include <vector>
using namespace std;

//Insertion sort function
inline void insertionSort(vector<int> &vec) {
  //Start from index 1 (second element)
  for (size_t j = 1; j < vec.size(); j++) {
    int key = vec.at(j);
    int i = j - 1;
    //Move elements that are greater than the key
    while (i >= 0 and vec.at(i) > key) {
      vec.at(i + 1) = vec.at(i);
      i--;
    }
    //Insert key at its correct position
    vec.at(i + 1) = key;
  }
}

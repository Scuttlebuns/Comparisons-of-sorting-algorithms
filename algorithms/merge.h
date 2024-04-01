//Merge Sort
//Best Case O(n log n)
//Average Case O(n log n)
//Worse Case O(n log n)
#pragma once
#include <iostream>
#include <vector>
using namespace std;

//Performs the merging of the two sub vectors
inline void merge(vector<int>& vec, int left, int mid, int right) {
  vector<int> leftArr(vec.begin() + left, vec.begin() + mid + 1);
  vector<int> rightArr(vec.begin() + mid + 1, vec.begin() + right + 1);

  int i = 0, j = 0, k = left; //pointer initialization

  //Merge the temp vectors back into the main vec from left to right
  while (i < leftArr.size() && j < rightArr.size()) {
    if (leftArr.at(i) <= rightArr.at(j)) {
      vec.at(k++) = leftArr.at(i++);
    } else {
      vec.at(k++) = rightArr.at(j++);
    }
  }

  //Copy the elements from the left arr back to vec
  while (i < leftArr.size()) {
    vec.at(k++) = leftArr.at(i++);
  }

  //Copy the elements from the right arr back to vec
  while (j < rightArr.size()) {
    vec.at(k++) = rightArr.at(j++);
  }
}

//Implementation of merge sort
inline void mergeSortRecursive(vector<int>& vec, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2; //Finds midpoint
    mergeSortRecursive(vec, left, mid); //Sort the first half
    mergeSortRecursive(vec, mid + 1, right); //Sort the second half
    merge(vec, left, mid, right); //Merge them together
  }
}

// Wrapper function for mergeSort, this prevents linking errors 
inline void mergeSort(vector<int>& vec) {
  mergeSortRecursive(vec, 0, vec.size() - 1);
}

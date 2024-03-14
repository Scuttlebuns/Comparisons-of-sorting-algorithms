//Merge Sort
#pragma once
#include <iostream>
#include <vector>
using namespace std;

inline void merge(vector<int>& vec, int left, int mid, int right) {
  vector<int> leftArr(vec.begin() + left, vec.begin() + mid + 1);
  vector<int> rightArr(vec.begin() + mid + 1, vec.begin() + right + 1);

  int i = 0, j = 0, k = left;

  while (i < leftArr.size() && j < rightArr.size()) {
    if (leftArr.at(i) <= rightArr.at(j)) {
      vec.at(k++) = leftArr.at(i++);
    } else {
      vec.at(k++) = rightArr.at(j++);
    }
  }

  while (i < leftArr.size()) {
    vec.at(k++) = leftArr.at(i++);
  }

  while (j < rightArr.size()) {
    vec.at(k++) = rightArr.at(j++);
  }
}

inline void mergeSortRecursive(vector<int>& vec, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSortRecursive(vec, left, mid);
    mergeSortRecursive(vec, mid + 1, right);
    merge(vec, left, mid, right);
  }
}

// Wrapper function for mergeSort
inline void mergeSort(vector<int>& vec) {
  mergeSortRecursive(vec, 0, vec.size() - 1);
}

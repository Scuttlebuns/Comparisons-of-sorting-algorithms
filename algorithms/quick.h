//Quick Sort
#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Choose pivot according to the pivot choice
inline int choosePivot(vector<int>& vec, int start, int end, int pivotChoice) {
  if (pivotChoice == 1) { // First element
    return start;
  }
  else if (pivotChoice == 2) { // Random element
    return start + rand() % (end - start + 1);
  }
  else { // Median of first, middle, last
    int middle = start + (end - start) / 2;
    vector<int> median = {vec[start], vec[middle], vec[end]};
    sort(median.begin(), median.end());
    if (median[1] == vec[start]) {
      return start;
    } 
    else if (median[1] == vec[middle]) {
      return middle;
    } 
    else {
      return end;
    }
  }
}

inline int partition(vector<int>& vec, int start, int end, int pivotChoice) {
  int pivotIndex = choosePivot(vec, start, end, pivotChoice);
  swap(vec[pivotIndex], vec[start]);
  int pivotValue = vec[start];

  int left = start;
  for (int i = start + 1; i <= end; i++) {
    if (vec[i] < pivotValue) {
      left++;
      swap(vec[i], vec[left]);
    }
  }

  swap(vec[start], vec[left]);
  return left;
}

inline void quickSortRecursive(vector<int>& vec, int start, int end, int pivotChoice) {
  if (start < end) {
    int index = partition(vec, start, end, pivotChoice);
    quickSortRecursive(vec, start, index - 1, pivotChoice);
    quickSortRecursive(vec, index + 1, end, pivotChoice);
  }
}

// Wrapper function for quickSort
inline void quickSort(vector<int>& vec) {
  srand(time(0)); // Seed random number generator once
  quickSortRecursive(vec, 0, vec.size() - 1, 2); // Use pivot choice 2
}

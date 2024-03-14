//Heap Sort
//Max Heap
#pragma once
#include <vector>
#include <iostream>
using namespace std;


inline void heapify(vector<int> &vec, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && vec.at(left) > vec.at(largest))
    largest = left;

  if (right < n && vec.at(right) > vec.at(largest))
    largest = right;

  if (largest != i) {
    swap(vec.at(i), vec.at(largest));
    heapify(vec, n, largest);
  }
}

inline void heapSort(vector<int> &vec) {
  int n = vec.size();

  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(vec, n, i);

  for (int i = n - 1; i > 0; i--) {
    swap(vec.at(0), vec.at(i));
    heapify(vec, i, 0);
  }
}

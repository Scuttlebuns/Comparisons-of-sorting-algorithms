//Radix Sort
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline void radixCountingSort(vector<int>& vec, int exp) {
  int size = vec.size();
  vector<int> output(size);
  vector<int> count(10, 0);

  for (int i = 0; i < size; i++) {
    count.at((vec.at(i) / exp) % 10)++;
  }

  for (int i = 1; i < 10; i++) {
    count.at(i) += count.at(i - 1);
  }

  for (int i = size - 1; i >= 0; i--) {
    output.at(count.at((vec.at(i) / exp) % 10) - 1) = vec.at(i);
    count.at((vec.at(i) / exp) % 10)--;
  }

  for (int i = 0; i < size; i++) {
    vec.at(i) = output.at(i);
  }
}

inline void radixSort(vector<int>& vec) {
  int m = *max_element(vec.begin(), vec.end());

  for (int exp = 1; m / exp > 0; exp *= 10) {
    radixCountingSort(vec, exp);
  }
}

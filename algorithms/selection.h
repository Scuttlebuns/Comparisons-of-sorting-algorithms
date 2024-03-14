//Selection sort
#pragma once
#include <iostream>
#include <vector>
using namespace std;

inline void selectionSort(vector<int> &vec) {
  for (size_t i = 0; i < vec.size() - 1; i++) {
    size_t minIndex = i;
    for (size_t j = i + 1; j < vec.size(); j++) {
      if (vec.at(j) < vec.at(minIndex)) {
        minIndex = j;
      }
    }
    swap(vec.at(minIndex), vec.at(i));
  }
}

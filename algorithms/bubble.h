//Bubble Sort
#pragma once
#include <iostream>
#include <vector>
using namespace std;
inline void bubbleSort(vector<int>& vec) {
  for (size_t j = 0; j < vec.size(); j++) {
    for (size_t i = 0; i < vec.size() - j - 1; i++) {
      if (vec.at(i) > vec.at(i + 1)) {
        int temp = vec.at(i);
        vec.at(i) = vec.at(i + 1);
        vec.at(i + 1) = temp;
      }
    }
  }
}

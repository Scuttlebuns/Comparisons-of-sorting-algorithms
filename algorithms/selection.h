//Selection sort
//Best Case O(n ^ 2)
//Average Case O(n ^ 2)
//Worse Case O(n ^ 2)
#pragma once
#include <iostream>
#include <vector>
using namespace std;

inline void selectionSort(vector<int> &vec) {
  //Iterate over each element
  for (size_t i = 0; i < vec.size() - 1; i++) {
    size_t minIndex = i; //Assumes current index is current smallest
    for (size_t j = i + 1; j < vec.size(); j++) {
      if (vec.at(j) < vec.at(minIndex)) { //If a smaller index is found
        minIndex = j; //Update the small value
      }
    }
    swap(vec.at(minIndex), vec.at(i)); //Swap the smallest with the first element
  }
}

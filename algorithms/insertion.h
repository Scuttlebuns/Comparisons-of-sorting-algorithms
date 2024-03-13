//Insertion Sort
#pragma once
#include <iostream>
#include <vector>
using namespace std;

inline void insertionSort(vector<int> &vec) {
    for (size_t j = 1; j < vec.size(); j++) {
        int key = vec.at(j);
        int i = j - 1;
        while (i >= 0 and vec.at(i) > key) {
            vec.at(i + 1) = vec.at(i);
            i--;
        }
        vec.at(i + 1) = key;
    }
}

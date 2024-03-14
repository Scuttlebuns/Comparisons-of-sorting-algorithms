//Counting Sort
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline void countingSort(vector<int> &vec){
    int max = *max_element(vec.begin(), vec.end());
    int min = *min_element(vec.begin(), vec.end());
    int range = max - min + 1;
    
    vector<int> count(range);
    vector<int> output(vec.size());
    
    for (int i = 0; i < vec.size(); i++) {
        count.at(vec.at(i) - min)++;
    }
    
    for (int i = 1; i < count.size(); i++){
        count.at(i) += count.at(i-1);
    }
    
    for (int i = vec.size() - 1; i >= 0; i--){
        output.at(count.at(vec.at(i) - min) - 1) = vec.at(i);
        count.at(vec.at(i) - min)--;
    }
    
    for (int i = 0; i < vec.size(); i++){
        vec.at(i) = output.at(i);
    }
}

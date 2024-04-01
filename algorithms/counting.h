//Counting Sort
//Best Case O(n+k)
//Average Case O(n+k)
//Average Case O(n+k)
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Main function for countingSort
inline void countingSort(vector<int> &vec){
  int max = *max_element(vec.begin(), vec.end()); //Find max element
  int min = *min_element(vec.begin(), vec.end()); //Find minimum element
  int range = max - min + 1; //Range of the elements

  vector<int> count(range); 
  vector<int> output(vec.size());

  //Occurrence vector
  for (int i = 0; i < vec.size(); i++) {
    count.at(vec.at(i) - min)++;
  }

  //Cumulative counting
  for (int i = 1; i < count.size(); i++){
    count.at(i) += count.at(i-1);
  }

  //Generate the output vector by placing elements in the correct spot
  for (int i = vec.size() - 1; i >= 0; i--){
    output.at(count.at(vec.at(i) - min) - 1) = vec.at(i);
    count.at(vec.at(i) - min)--;
  }

  //Copy the sorted vector back to the original vector
  for (int i = 0; i < vec.size(); i++){
    vec.at(i) = output.at(i);
  }
}

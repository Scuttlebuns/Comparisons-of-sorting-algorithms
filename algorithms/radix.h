//Radix Sort
//Best O(n*k)
//Average O(n*k)
//Worse O (n*k)

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Function that performs the counting for on vec based on the digit value
inline void radixCountingSort(vector<int>& vec, int exp) {
  int size = vec.size();
  vector<int> output(size);
  vector<int> count(10, 0);

  //Occurrence vector
  for (int i = 0; i < size; i++) {
    count.at((vec.at(i) / exp) % 10)++;
  }

  //Update the count to be the position of the digit
  for (int i = 1; i < 10; i++) {
    count.at(i) += count.at(i - 1);
  }
  //Generate the output vector
  for (int i = size - 1; i >= 0; i--) {
    output.at(count.at((vec.at(i) / exp) % 10) - 1) = vec.at(i);
    count.at((vec.at(i) / exp) % 10)--;
  }
  //Copy the output vector into vec so the values are updated to the current digit
  for (int i = 0; i < size; i++) {
    vec.at(i) = output.at(i);
  }
}

//Radix sort functio
inline void radixSort(vector<int>& vec) {
  int m = *max_element(vec.begin(), vec.end()); //Finds the max element to know the number of digits needed

  //Start counting sort for every digit, not the exponent is passed in
  for (int exp = 1; m / exp > 0; exp *= 10) {
    radixCountingSort(vec, exp);
  }
}

//Heap Sort
//Max Heap
//Best Case of O(n log n)
//Average Case of O(n log n)
//Worse Case of O(n)
#pragma once
#include <vector>
#include <iostream>
using namespace std;

//Heapify function which maintains the heap property
inline void heapify(vector<int> &vec, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  //If left is larger than the root
  if (left < n && vec.at(left) > vec.at(largest))
    largest = left;

  //If right is the largest
  if (right < n && vec.at(right) > vec.at(largest))
    largest = right;

  //If the largest isn't the root
  if (largest != i) {
    swap(vec.at(i), vec.at(largest));
    heapify(vec, n, largest);
  }
}

//actual Heapsort function
inline void heapSort(vector<int> &vec) {
  int n = vec.size();

  //creates the heap 
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(vec, n, i);

  //Extracts an element from the heap and arranges it
  for (int i = n - 1; i > 0; i--) {
    swap(vec.at(0), vec.at(i));
    heapify(vec, i, 0);
  }
}

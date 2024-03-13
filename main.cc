#include <iostream>
#include "dataset.h"
using namespace std;
Dataset dataset;

int main(){
load_dataset();

int tempSize = dataset.get_inputSize();
vector<int> tempSorted = dataset.get_sorted();
vector<int> tempHalfSorted = dataset.get_halfSorted();
vector<int> tempReversed = dataset.get_reversed();

cout << "Input Size: " << tempSize << endl;
cout << "Sorted: ";
for (int x : tempSorted) {cout << x << " "; } cout << endl;
cout << "Half sorted: ";
for (int x : tempHalfSorted) {cout << x << " "; } cout << endl;
cout << "Reversed: ";
for (int x : tempReversed) {cout << x << " "; } cout << endl;



}

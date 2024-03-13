#include <iostream>
#include "dataset.h"
#include "timing.h"
#include "algorithms/insertion.h"
using namespace std;
Dataset dataset;

int main(){

//
string input; 
cout << "Which input file would you like?" << endl;
cout << "'input500.txt' or 'inputfile1.txt' " << endl;
cout << "Type '0' to use default" << endl;
cin >> input;
string folder = "inputfiles/";
if (input == "0") input = "inputfile1.txt";
folder += input;    
load_dataset(folder);

int tempSize = dataset.get_inputSize();
vector<int> tempSorted = dataset.get_sorted();
vector<int> tempHalfSorted = dataset.get_halfSorted();
vector<int> tempReversed = dataset.get_reversed();

/*
cout << "Input Size: " << tempSize << endl;
cout << "Sorted: ";
for (int x : tempSorted) {cout << x << " "; } cout << endl;
cout << "Half sorted: ";
for (int x : tempHalfSorted) {cout << x << " "; } cout << endl;
cout << "Reversed: ";
for (int x : tempReversed) {cout << x << " "; } cout << endl;
*/

cout << "Insertion (Sorted): " << timeSort(insertionSort, dataset.get_sorted()) << " microseconds" << endl;
cout << "Insertion (Half Sorted): " << timeSort(insertionSort, dataset.get_halfSorted()) << " microseconds" << endl;
cout << "Insertion (Reversed): " << timeSort(insertionSort, dataset.get_reversed()) << " microseconds" << endl;

}

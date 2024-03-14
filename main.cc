#include <iostream>
#include "dataset.h"
#include "timing.h"
#include "algorithms/insertion.h"
#include "algorithms/selection.h"
#include "algorithms/bubble.h"
#include "algorithms/merge.h"
#include "algorithms/quick.h"
#include "algorithms/heap.h"
#include "algorithms/counting.h"
#include "algorithms/radix.h"

using namespace std;
Dataset dataset;


// Declaration of the sort functions
void insertionSort(vector<int> &vec);
void selectionSort(vector<int> &vec);
void bubbleSort(vector<int> &vec);
void mergeSort(vector<int> &vec);
void quickSort(vector<int> &vec);
void heapSort(vector<int> &vec);
void countingSort(vector<int> &vec);
void radixSort(vector<int> &vec);

int main(){

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
  //FIXME - just used for testing
cout << "Input Size: " << tempSize << endl;
cout << "Sorted: ";
for (int x : tempSorted) {cout << x << " "; } cout << endl;
cout << "Half sorted: ";
for (int x : tempHalfSorted) {cout << x << " "; } cout << endl;
cout << "Reversed: ";
for (int x : tempReversed) {cout << x << " "; } cout << endl;
*/

  //Sorted functions:
  string timeType = " microseconds"; //microseconds or milliseconds
  cout << endl;
  cout << "============================" << endl;
  cout << "Timing results of Algorithms" << endl;
  cout << "Size: "<< dataset.get_inputSize() << " || Type: Sorted" << endl;
  cout << "Insertion: " << timeSort(insertionSort, dataset.get_sorted()) << timeType << endl;
  cout << "Selection: " << timeSort(selectionSort, dataset.get_sorted()) << timeType << endl;
  cout << "Bubble: " << timeSort(bubbleSort, dataset.get_sorted()) << timeType << endl;
  cout << "Merge: " << timeSort(mergeSort, dataset.get_sorted()) << timeType << endl;
  cout << "Quick: " << timeSort(quickSort, dataset.get_sorted()) << timeType << endl;
  cout << "Heap: " << timeSort(heapSort, dataset.get_sorted()) << timeType << endl;
  cout << "Counting: " << timeSort(countingSort, dataset.get_sorted()) << timeType << endl;
  cout << "Radix: " << timeSort(radixSort, dataset.get_sorted()) << timeType << endl;
  cout << "============================" << endl;



  /*
  cout << "Insertion (Half Sorted): " << timeSort(insertionSort, dataset.get_halfSorted()) << " microseconds" << endl;
  cout << "Insertion (Reversed): " << timeSort(insertionSort, dataset.get_reversed()) << " microseconds" << endl;
*/
}

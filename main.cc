//Use Make to build this project
#ifndef USE_MAKEFILE
#error "Please compile with 'make' instead of directly using 'g++'"
#endif

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

Dataset dataset; //Global dataset of all unsorted vectors

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
  cout << "Which input file would you like to use?" << endl;
  cout << "Input '1' for 10, 2 for '500'" << endl;
  cin >> input;
  string folder = "inputfiles/";
  if(input == "1") input = "inputfile1.txt";
  else if(input == "2") input = "input500.txt";
  else die("Input File not found!");
  folder += input;    
  load_dataset(folder);

  /*
  cout << "Input numer of times to run program" << endl;
  int numRuns = 0;
  cin >> numRuns;
  if(!cin or numRuns <= 0) die("Enter a number between 1 - N");
 // vector<int> numRunsVec(numRuns);
*/


  string timeType = " microseconds"; //FIXME microseconds or milliseconds (will pick later, once more input size)
  for(int i = 0; i < 3; i++){
    vector<int> dataVec;
    string label = "NO LABEL";
    if(i == 0){
      label = "Sorted";
      dataVec = dataset.get_sorted();
    }
    else if(i == 1){
      label = "Random";
      dataVec = dataset.get_random();
    }
    else{
      label = "Reversed";
      dataVec = dataset.get_reversed();
    }

    cout << endl;
    cout << "============================" << endl;
    cout << "Timing results of Algorithms" << endl;
    cout << "Size: "<< dataset.get_inputSize() << " || Type: " << label << endl;

    cout << "Insertion: " << timeSort(insertionSort, dataVec) << timeType << endl;
    cout << "Selection: " << timeSort(selectionSort, dataVec) << timeType << endl;
    cout << "Bubble: " << timeSort(bubbleSort, dataVec) << timeType << endl;
    cout << "Merge: " << timeSort(mergeSort, dataVec) << timeType << endl;
    cout << "Quick: " << timeSort(quickSort, dataVec) << timeType << endl;
    cout << "Heap: " << timeSort(heapSort, dataVec) << timeType << endl;
    cout << "Counting: " << timeSort(countingSort, dataVec) << timeType << endl;
    cout << "Radix: " << timeSort(radixSort, dataVec) << timeType << endl;
    cout << "============================" << endl;
  }
}

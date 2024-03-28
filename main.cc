//Use Make to build this project
#include <algorithm>
#ifndef USE_MAKEFILE
#error "Please compile with 'make' instead of directly using 'g++'"
#endif

#include <iostream>
#include "dataset.h"
#include "timing.h"
#include "testrun.h"
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

  cout << "Input numer of times to run program" << endl;
  int numRuns = 0.0;
  cin >> numRuns;
  if(!cin or numRuns <= 0) die("Enter a number between 1 - N");

  string timeType = " microseconds"; //FIXME microseconds or milliseconds (will pick later, once more input size)
  
  cout << endl;
  cout << "Average timing results" << endl;
  cout << "Size: "<< dataset.get_inputSize() << " || Runs: " << numRuns << endl;
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

    Testrun testrun;
    cout << "============================" << endl;
    cout << "Type: " << label << endl;
    for(int j = 0; j < numRuns; j++){

      testrun.set_insertion_time(timeSort(insertionSort, dataVec));
      testrun.set_selection_time(timeSort(selectionSort, dataVec));
      testrun.set_bubble_time(timeSort(bubbleSort, dataVec));
      testrun.set_merge_time(timeSort(mergeSort, dataVec));
      testrun.set_quick_time(timeSort(quickSort, dataVec));
      testrun.set_heap_time(timeSort(heapSort, dataVec));
      testrun.set_counting_time(timeSort(countingSort, dataVec));
      testrun.set_radix_time(timeSort(radixSort, dataVec));
    }
    cout << "Insertion: " << timeAverage(testrun.get_insertion_time(), numRuns) << endl;
    cout << "Selection: " << timeAverage(testrun.get_selection_time(), numRuns) << endl;
    cout << "Bubble: " << timeAverage(testrun.get_bubble_time(), numRuns) << endl;
    cout << "Merge: " << timeAverage(testrun.get_merge_time(), numRuns) << endl;
    cout << "Quick: " << timeAverage(testrun.get_quick_time(), numRuns) << endl;
    cout << "Heap: " << timeAverage(testrun.get_heap_time(), numRuns) << endl;
    cout << "Counting: " << timeAverage(testrun.get_counting_time(), numRuns) << endl;
    cout << "Radix: " << timeAverage(testrun.get_radix_time(), numRuns) << endl;
  }
}

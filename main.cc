//Use Make to build this project
#include <algorithm>
#ifndef USE_MAKEFILE
#error "Please compile with 'make' instead of directly using 'g++'"
#endif

//includes algoriths and headers for objects
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

  //File Selection
  string input; 
  cout << "Which input file would you like to use?" << endl;
  cout << "Input '1' for 500" << endl;
  cout << "Input '2' for 50k" << endl;
  cout << "Input '3' for 500k" << endl;

  //Input choices
  cin >> input;
  string folder = "inputfiles/";
  if(input == "1") input = "input500.txt";
  else if(input == "2") input = "input50k.txt";
  else if(input == "3") input = "input500k.txt";

  else die("Input File not found!"); //Die is a function inside of dataset.h that returns exit(1) and an error string
  folder += input;    
  load_dataset(folder);

  //Number of runs
  cout << "Input numer of times to run program" << endl;
  int numRuns = 0.0;
  cin >> numRuns;
  if(!cin or numRuns <= 0) die("Enter a number between 1 - N");

  string timeType = "Microseconds"; //Label for timing selection.
  
  cout << endl;
  cout << "Average timing results in " << timeType << endl;
  cout << "Size: "<< dataset.get_inputSize() << " || Runs: " << numRuns << endl;

  int vectorSortedType = 3; //How many different types of vectors are in a file "sorted, unsorted, random, etc...

  for(int i = 0; i < vectorSortedType; i++){ //Number of vector types, currently 3 ^
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
    for(int j = 0; j < numRuns; j++){ //For loop for number of times run, allows for averaging

      //populates the each algorithsm timing and pushes back into individual vectors for averaging.
      testrun.set_insertion_time(timeSort(insertionSort, dataVec));
      testrun.set_selection_time(timeSort(selectionSort, dataVec));
      testrun.set_bubble_time(timeSort(bubbleSort, dataVec));
      testrun.set_merge_time(timeSort(mergeSort, dataVec));
      testrun.set_quick_time(timeSort(quickSort, dataVec));
      testrun.set_heap_time(timeSort(heapSort, dataVec));
      testrun.set_counting_time(timeSort(countingSort, dataVec));
      testrun.set_radix_time(timeSort(radixSort, dataVec));
    }
    //timeAverage is a function that takes a testrun vector and returns the average based on numRuns. 
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

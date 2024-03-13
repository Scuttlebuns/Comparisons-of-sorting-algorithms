//dataset.h
//die() function in this file
//Reads into global vector
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

inline void die(string error = "Bad Input!"){
  cout << error << endl;
  exit(1);
}

class Dataset{
private:
  int inputSize;
  vector<int> sorted;
  vector<int> halfSorted;
  vector<int> reversed;

public:
  //Cstors:
  Dataset() {}
  Dataset(int new_inputSize, vector<int> new_sorted, vector<int> new_halfSorted, vector<int> new_reversed) : inputSize(new_inputSize), sorted(new_sorted), reversed(new_reversed) {} 

  //Getters
  int get_inputSize() const { return inputSize; }
  vector<int> get_sorted() const { return sorted; }
  vector<int> get_halfSorted() const { return halfSorted; }
  vector<int> get_reversed() const { return reversed; }

  //Setters
  void set_inputSize(int temp) { inputSize = temp; }
  void set_sorted(int temp) {sorted.push_back(temp); }
  void set_halfSorted(int temp) { halfSorted.push_back(temp); }
  void set_reversed(int temp) { reversed.push_back(temp); }

};

extern Dataset dataset;

inline void load_dataset(string fileName = "inputfiles/inputfile1.txt") {
  ifstream ins(fileName);
  if (!ins) die();

  string size;
  getline(ins, size); // First Line
  dataset.set_inputSize(stoi(size));
  int tempSize = stoi(size);

  for (int vectorChoice = 0; vectorChoice < 3; vectorChoice++) {
    string discard;
    getline(ins, discard); // Throws away label, ex: "sorted")

    string line;
    getline(ins, line); // Gets the data line
    stringstream dataval(line);

    for (int i = 0; i < tempSize; i++) {
      string data;
      getline(dataval, data, ' ');
      int temp = stoi(data);
      if (vectorChoice == 0) {
        dataset.set_sorted(temp);
      } 
      else if (vectorChoice == 1) {    
        dataset.set_halfSorted(temp);
      }
      else if (vectorChoice == 2) {
        dataset.set_reversed(temp);
        //cerr <<"temp" <<temp << endl;
      }
    }
  }
}


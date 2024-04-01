//dataset.h
//die() function in this file
//Reads into global vector
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//functions are marked inline in files to prevent linker errors

inline void die(string error = "Bad Input!"){ //die() is the 'BADINPUT' handling function, it will kill the program and return an error code.
  cout << error << endl;
  exit(1);
}

//Datat set is a class that takes stores the input files
//it holds the 3 types of vectors each input file contains
class Dataset{
private:
  int inputSize;
  vector<int> sorted; //sorted data vector
  vector<int> random; //random data vector
  vector<int> reversed; //reversed data vector

public:
  //Cstors:
  Dataset() {}
  Dataset(int new_inputSize, vector<int> new_sorted, vector<int> new_random, vector<int> new_reversed) : inputSize(new_inputSize), sorted(new_sorted), random(new_random) ,reversed(new_reversed) {} 

  //Getters:
  int get_inputSize() const { return inputSize; }
  vector<int> get_sorted() const { return sorted; }
  vector<int> get_random() const { return random; }
  vector<int> get_reversed() const { return reversed; }

  //Setters:
  void set_inputSize(int temp) { inputSize = temp; }
  void set_sorted(int temp) {sorted.push_back(temp); }
  void set_random(int temp) { random.push_back(temp); }
  void set_reversed(int temp) { reversed.push_back(temp); }

};

extern Dataset dataset; //dataset is a global inside of main.cc

//Load file function
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
    stringstream dataval(line); //using string stream to parse file 

    //dataset.set_[type] pushes back the values into a vector based on sorting type
    for (int i = 0; i < tempSize; i++) {
      string data;
      getline(dataval, data, ' ');
      int temp = stoi(data);
      if (vectorChoice == 0) {
        dataset.set_sorted(temp);
      } 
      else if (vectorChoice == 1) {    
        dataset.set_random(temp);
      }
      else if (vectorChoice == 2) {
        dataset.set_reversed(temp);
        //cerr <<"temp" <<temp << endl;
      }
    }
  }
}


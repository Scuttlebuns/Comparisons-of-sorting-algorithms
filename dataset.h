//dataset.h
//die() function in this file
//Reads into global vector
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void die(string error = "Bad Input!"){
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
/*
inline void load_dataset(string fileName = "inputfile1.txt"){
  ifstream ins(fileName);
  if(!ins) die();
  while(ins){
    string size;
    getline(ins, size); //First Line
    dataset.set_inputSize(stoi(size));
    int tempSize = stoi(size);

    for(int vectorChoice = 0; vectorChoice < 2; vectorChoice++){
      string line;
      getline(ins, line); //throws away "sorted"
      getline(ins, line);
      stringstream dataval(line);

      for (int i = 0; i < tempSize; i++){
        string data;
        getline(dataval, data, ' '); 
        int temp = stoi(data);
        if(vectorChoice == 0) dataset.set_sorted(temp);
        if(vectorChoice == 1) dataset.set_halfSorted(temp);
        if(vectorChoice == 2) dataset.set_reversed(temp);
      }
    }

  }
}
*/
inline void load_dataset(const string& fileName = "inputfile1.txt") {
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







/*
void load_dataset (string fileName = "inputfile1.txt"){
  ifstream ins (fileName);

  if(!ins) cerr << "Error opening file!\n";

  while (ins){
    string parser;
    int size = 0;
    ins >> size;
    dataset.set_inputSize(size);

    getline(ins, '\n'); //skips the 'sorted' line

    getline(ins, parser);
    istringstream sts(parser);
    int data;
    while(sts >> data) {
      dataset.set_sorted(data);  
    }



    if(!ins) break;
  }
}
*/
/*
  while (true) {


  }

} 





void load_questions (vector<Question> &question_db, string fileName = "questions.txt"){
  ifstream ins (fileName);
  if(!ins) cerr << "Error opening Questions file!\n";
  while(true){
    Question temp;
    vector<string> tempAnswers;
    string question = readline(ins);

    string answer1 = readline(ins);
    tempAnswers.push_back(answer1);

    string answer2 = readline(ins);
    tempAnswers.push_back(answer2);

    string answer3 = readline(ins);
    tempAnswers.push_back(answer3);

    string answer4 = readline(ins);
    tempAnswers.push_back(answer4);

    temp.set_question(question);
    temp.set_correctAnswer(answer1);
    temp.set_answer_db(tempAnswers);

    if(!ins) break;
    question_db.push_back(temp);
    test_db.push_back(temp);
  }
}
*/

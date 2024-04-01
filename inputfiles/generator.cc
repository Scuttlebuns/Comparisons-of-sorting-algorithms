//Not tied to main program, this is a separate program that populates the input files
//Might eventually add to main program, but not at this time
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

//Generates a sorted vector from 1 to n
void generateSortedVec(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        vec.at(i) = i + 1;
    }
}

//Uses std::shuffle to generate a random vector based on a random_device
void generateRandomVec(vector<int> &vec) {
    generateSortedVec(vec);
    random_device rd;
    default_random_engine rng(rd());
    shuffle(vec.begin(), vec.end(), rng);
}

//Generates a reversed sorted vector from n to 1
void generateReversedVec(vector<int>& vec) {
    generateSortedVec(vec);
    reverse(vec.begin(), vec.end());
}

//Function that uses ostream to write to a file
void writeVecToFile(ofstream &file, const string &title, const vector<int> &vec) {
    file << title << endl;
    for (int i = 0; i < vec.size(); i++) {
        file << vec.at(i) << " ";
    }
    file << endl; 
}

int main() {
    int size;
    string filename;

    //Enter input size of the vector
    cout << "Enter the size of the vector: ";
    cin >> size;
    //What the name of the new file is going to be
    cout << "Enter the filename: ";
    cin >> filename;

    //New ofstream for writing, also parses to make sure error handling.
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    file << size << endl;

    //Makes a new temp vector called vec initilized to the user entered size
    //Then calls all 3 vector functions to populate the data
    vector<int> vec(size);
    generateSortedVec(vec);
    writeVecToFile(file, "sorted", vec);

    generateRandomVec(vec);
    writeVecToFile(file, "random", vec);

    generateReversedVec(vec);
    writeVecToFile(file, "reversed", vec);

    //Close the file
    file.close();
    cout << "File Generated: " << filename << endl;

    //Successful exit of the program
    return 0;
}


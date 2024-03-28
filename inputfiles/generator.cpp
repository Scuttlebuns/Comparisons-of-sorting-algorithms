#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

void generateSortedVec(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        vec.at(i) = i + 1;
    }
}

void generateRandomVec(vector<int> &vec) {
    generateSortedVec(vec);
    random_device rd;
    default_random_engine rng(rd());
    shuffle(vec.begin(), vec.end(), rng);
}

void generateReversedVec(vector<int>& vec) {
    generateSortedVec(vec);
    reverse(vec.begin(), vec.end());
}

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

    cout << "Enter the size of the vector: ";
    cin >> size;
    cout << "Enter the filename: ";
    cin >> filename;

    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    file << size << endl;

    vector<int> vec(size);
    generateSortedVec(vec);
    writeVecToFile(file, "sorted", vec);

    generateRandomVec(vec);
    writeVecToFile(file, "random", vec);

    generateReversedVec(vec);
    writeVecToFile(file, "reversed", vec);

    file.close();
    cout << "File Generated: " << filename << endl;

    return 0;
}


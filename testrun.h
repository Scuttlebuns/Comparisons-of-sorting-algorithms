// testrun.h
// test run is used for averaging runs to produce an accurate result
#pragma once
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;


//Testrun class, contains a vector for all sorting algorithms
class Testrun {
private:
    vector<long long> insertion_time;
    vector<long long> selection_time;
    vector<long long> bubble_time;
    vector<long long> merge_time;
    vector<long long> quick_time;
    vector<long long> heap_time;
    vector<long long> counting_time;
    vector<long long> radix_time;

public:
  //Cstors:
    Testrun() {}
    Testrun(const vector<long long>& new_insertion_time,
            const vector<long long>& new_selection_time,
            const vector<long long>& new_bubble_time,
            const vector<long long>& new_merge_time,
            const vector<long long>& new_quick_time,
            const vector<long long>& new_heap_time,
            const vector<long long>& new_counting_time,
            const vector<long long>& new_radix_time)
        : insertion_time(new_insertion_time),
          selection_time(new_selection_time),
          bubble_time(new_bubble_time),
          merge_time(new_merge_time),
          quick_time(new_quick_time),
          heap_time(new_heap_time),
          counting_time(new_counting_time),
          radix_time(new_radix_time) {}

    // Getters:
    vector<long long> get_insertion_time() const { return insertion_time; }
    vector<long long> get_selection_time() const { return selection_time; }
    vector<long long> get_bubble_time() const { return bubble_time; }
    vector<long long> get_merge_time() const { return merge_time; }
    vector<long long> get_quick_time() const { return quick_time; }
    vector<long long> get_heap_time() const { return heap_time; }
    vector<long long> get_counting_time() const { return counting_time; }
    vector<long long> get_radix_time() const { return radix_time; }

    // Setters:
    void set_insertion_time(long long temp) { insertion_time.push_back(temp); }
    void set_selection_time(long long temp) { selection_time.push_back(temp); }
    void set_bubble_time(long long temp) { bubble_time.push_back(temp); }
    void set_merge_time(long long temp) { merge_time.push_back(temp); }
    void set_quick_time(long long temp) { quick_time.push_back(temp); }
    void set_heap_time(long long temp) { heap_time.push_back(temp); }
    void set_counting_time(long long temp) { counting_time.push_back(temp); }
    void set_radix_time(long long temp) { radix_time.push_back(temp); }
};

//Function called timeAverage, which returns the average of the vector of runs per algorithm, this is called for each algorithm in main
inline long long timeAverage(vector<long long> timeVec, int numRuns){
  double doubleNumRuns = static_cast<double>(numRuns);

 // if(timeVec.size() == 1) return timeVec.at(1); 
  double sum = accumulate(timeVec.begin(), timeVec.end(), 0.0);
  return sum / doubleNumRuns; 
}

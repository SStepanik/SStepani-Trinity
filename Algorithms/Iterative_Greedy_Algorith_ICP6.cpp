//Sean Stepanik
#include<limits> 
#include<cmath>  
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Interval {
    int start;
    int finish;
    
    Interval(int s, int f) : start(s), finish(f) {}
};

bool compareIntervals(const Interval& a, const Interval& b) {
    return a.finish < b.finish;
}

vector<Interval> intervalScheduling(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), compareIntervals);
    
    vector<Interval> schedule;
    int lastEndTime = -1;
    
    for (const Interval& interval : intervals) {
        if (lastEndTime == -1 || interval.start >= lastEndTime) {
            schedule.push_back(interval);
            lastEndTime = interval.finish;
        }
    }
    
    return schedule;
}

int main() {
    vector<Interval> intervals = {Interval(1, 3), Interval(2, 4), Interval(3, 5), Interval(5, 7), Interval(6, 8)};

    vector<Interval> schedule = intervalScheduling(intervals);
    
    cout << "The max number of jobs can be scheduled is " << schedule.size() << "\n";
    cout << "They are jobs: ";
    
    for (const Interval& interval : schedule) {
        cout << "(" << interval.start << ", " << interval.finish << ") ";
    }
    cout << endl;

    return 0;
}

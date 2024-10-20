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

vector<Interval> intervalScheduling(vector<Interval>& intervals, vector<Interval>&result, int k, int n){
    int m = k + 1;

    while ((m <= n) && (intervals[m].start < intervals[k].finish))
        m += 1;
    if (m < n){
        result.push_back(intervals[m]);
        return intervalScheduling(intervals, result, m, n);
    }
    return result;
}

int main() {
    vector<Interval> intervals = {Interval(1, 3), Interval(2, 4), Interval(3, 5), Interval(5, 7), Interval(6, 8)};
    vector<Interval> result = {Interval(1, 3)};

    vector<Interval> schedule = intervalScheduling(intervals, result, 0, intervals.size());

    cout << "The max number of jobs can be scheduled is " << schedule.size() << "\n";
    cout << "They are jobs: ";
    
    for (const Interval& interval : schedule) {
        cout << "(" << interval.start << ", " << interval.finish << ") ";
    }
    cout << endl;

    return 0;
}

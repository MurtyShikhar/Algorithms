/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <vector>
#include <algorithm>

using namespace std;
 
bool cmp(Interval& i1, Interval& i2) {
      return i1.start < i2.start;
}  

bool intersect(Interval& i1, Interval& i2) {
    return !(i1.start > i2.end || i2.start > i1.end);
}

Interval merged(Interval& i1, Interval& i2) {
    return Interval(min(i1.start, i2.end), max(i1.end, i2.end));
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        vector<Interval> mergedIntervals;
        if (n==0) return mergedIntervals;
        Interval currInterval = intervals[0];
        
        int i = 1;
        while (i < n) {
            // merge them!
            if (intersect(currInterval, intervals[i])) {
                currInterval = merged(currInterval, intervals[i]);
            }
            
            else {
                mergedIntervals.push_back(currInterval);
                currInterval = intervals[i];
            }
            
            i++;
        }
        
        mergedIntervals.push_back(currInterval);
        
        return mergedIntervals;
        
    }
};
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (Interval a, Interval b) {
            return a.start < b.start;
        });
        
        vector<Interval> result;
        size_t index = 0;
        
        if(intervals.size() > 0) 
            result.push_back(intervals[0]);
        
        for(size_t i = 1; i < intervals.size(); i++) {
            if(intervals[i].start <= result[index].end){
                if(result[index].end < intervals[i].end)
                    result[index].end = intervals[i].end;
            } else {
                result.push_back(intervals[i]);
                index++;
            }
            
        }   
        return result;
    }
};
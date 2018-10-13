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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto comp = [](const Interval& i1, const Interval& i2){
            if(i1.start != i2.start)
                return i1.start < i2.start;
            return i1.end < i2.end;
        };
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0, pre = 0;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i].start < intervals[pre].end)
            {
                res++;
                if(intervals[i].end < intervals[pre].end)
                    pre = i;
            }
            else
                pre = i;
        }
        return res;
    }
};

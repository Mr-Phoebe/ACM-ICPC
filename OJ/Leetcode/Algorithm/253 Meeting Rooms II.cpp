/*
* @Author: Haonan Wu
* @Date:   2017-09-25 09:18:02
* @Last Modified by:   Haonan Wu
* @Last Modified time: 2017-09-25 09:20:08
*/

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;
        for(auto a : intervals) 
        {
            ++m[a.start];
            --m[a.end];
        }
        int rooms = 0, res = 0;
        for(auto it : m) 
            res = max(res, rooms += it.second);
        return res;
    }
};
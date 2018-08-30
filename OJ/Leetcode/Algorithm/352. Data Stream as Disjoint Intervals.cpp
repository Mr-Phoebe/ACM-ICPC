/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        int index = search(val);

        if(index != -1 && inter[index].end >= val)
            return;

        if(index != -1 && val - 1 == inter[index].end)
            inter[index].end = val;
        else if(index != inter.size()-1 && val + 1 == inter[index+1].start)
            inter[index+1].start = val;
        else
            inter.insert(inter.begin() + index + 1, Interval(val, val));

        if(index < inter.size() - 1 && inter[index].end + 1 == inter[index+1].start)
        {
            inter[index].end = inter[index+1].end;
            inter.erase(inter.begin()+index+1);
        }

    }

    vector<Interval> getIntervals() {
        return inter;
    }
private:
    vector<Interval> inter;
    int search(int val)
    {
        int l = -1, r = inter.size();
        while(l+1 < r)
        {
            int mid = (l+r)>>1;
            if(inter[mid].start <= val)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

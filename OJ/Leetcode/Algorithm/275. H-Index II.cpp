class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n+1;
        while(l+1 < r)
        {
            int mid = (l + r) >> 1;
            if(citations[n-mid] >= mid)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};

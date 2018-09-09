class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = INT_MAX;
        int ans = 0;
        for(auto p : prices)
        {
            if(p < minn)
                minn = p;
            ans = max(ans, p - minn);
        }
        return ans;
    }
};

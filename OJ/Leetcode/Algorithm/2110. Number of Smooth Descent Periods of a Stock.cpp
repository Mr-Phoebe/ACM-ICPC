class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res = 0;
        long long conti = 1;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i-1] == prices[i]+1) {
                ++conti;
            } else {
                res += (conti+1)*conti/2;
                conti = 1;
            }
        }
        res += (conti+1)*conti/2;
        return res;
    }
};
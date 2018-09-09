class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int sell1 = 0, sell2 = 0;
        for(auto p : prices)
        {
            hold1 = max(hold1, -p);
            sell1 = max(sell1, hold1 + p);
            hold2 = max(hold2, sell1 - p);
            sell2 = max(sell2, hold2 + p);
        }
        return sell2;
    }
};

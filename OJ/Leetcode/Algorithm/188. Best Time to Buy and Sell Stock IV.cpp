class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2)   return 0;
        if(k > n/2)
        {
            int maxn = 0;
            for(int i = 1; i < n; i++)
                maxn += max(0, prices[i] - prices[i-1]);
            return maxn;
        }
        else
        {
            int dp[k+1][n];
            memset(dp, 0, sizeof(dp));
            for(int i = 1; i <= k; i++)
            {
                int premaxn = -prices[0];
                for(int j = 1; j < n; j++)
                {
                    dp[i][j] = max(dp[i][j-1], prices[j] + premaxn);
                    premaxn = max(dp[i-1][j-1] - prices[j], premaxn);
                }
            }
            return dp[k][n-1];
        }
    }
};

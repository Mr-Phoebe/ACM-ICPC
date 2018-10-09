class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int> > dp(n+1, vector<int>(m+1, INT_MAX));

        dp[n-1][m] = dp[n][m-1] = 1;
        for(int i = n-1; i >= 0; i--)
            for(int j = m-1; j >= 0; j--)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) - dungeon[i][j];
                dp[i][j] = max(1, dp[i][j]);
            }
        return dp[0][0];
    }
};

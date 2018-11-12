class Solution {
public:
    /*
        Interesting DP problem, using dp[x][y] = the mininum cost to guarantee a win of section [x, y]
        dp[x][y] = min(dp[x][y], max(dp[x][k-1], dp[k+1][y]) + k)
        Pay attention that the loop must solve the sub section with 1 length and then 2, 3 ~~~ n-1,
        so the 1st dimension is the length of the section and the 2cd is the start index and then the break point.
    */
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2);
        for (int i = 0; i < n+2; i++)
            dp[i].resize(n+2);
        for (int len = 1; len < n; len++){
            for (int i = 1; i + len<= n; i++){
                int j = i + len;
                int &cost = dp[i][j];
                if (j - i > 1) {
                    for (int k = i+1; k < j; k++){
                        if (cost == 0)
                            cost = max(dp[i][k-1], dp[k+1][j]) + k;
                        else
                            cost = min(cost, max(dp[i][k-1], dp[k+1][j]) + k);
                    }
                }
                else cost = i;
                //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            }
        }
        return dp[1][n];
    }
};

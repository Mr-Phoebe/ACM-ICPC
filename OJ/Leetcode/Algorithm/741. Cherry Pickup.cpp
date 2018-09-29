
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size(), M = (N<<1)-1;
        vector<vector<int> > dp(N, vector<int>(N, 0));
        dp[0][0] = grid[0][0];
        for(int n = 1; n < M; ++n)
        {
            for(int i = N-1; i >= 0; --i)
                for(int p = N-1; p >= 0; --p)
                {
                    int j = n - i, q = n - p;
                    if(j < 0 || j >= N || q < 0 || q >= N || grid[i][j] < 0 || grid[p][q] < 0)
                    {
                        dp[i][p] = -1;
                        continue;
                    }
                    if(i > 0)
                        dp[i][p] = max(dp[i][p], dp[i-1][p]);
                    if(p > 0)
                        dp[i][p] = max(dp[i][p], dp[i][p-1]);
                    if(i > 0 && p > 0)
                        dp[i][p] = max(dp[i][p], dp[i-1][p-1]);

                    if(dp[i][p] >= 0)
                        dp[i][p] += grid[i][j] + (i != p ? grid[p][q] : 0);
                }
        }
        return max(dp[N-1][N-1], 0);
    }
};

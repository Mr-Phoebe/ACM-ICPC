class Solution {
    int N, M;
    const long mod=1e9+7;
    int dp[55][55][12];
    int sum[55][55];
    vector<vector<int>> a;
    int subSum(int i, int j, int x, int y)
    {
        return (sum[x][y]-sum[x][j-1]-sum[i-1][y]+sum[i-1][j-1]);
    }
    int solve(int i, int j, int k) {
        if (k == 1) {
            return subSum(i, j, N, M) > 0;
        }
        long ans = dp[i][j][k];
        if (ans != -1) 
            return ans;
        ans = 0;
        for(int ii = i; ii < N; ++ii) {
            if(subSum(i, j, ii, M))
                ans += solve(ii+1, j, k-1);
            ans %= mod;
        }
        for(int jj = j; jj < M; ++jj) {
            if(subSum(i, j, N, jj))
                ans += solve(i, jj+1, k-1);
            ans %= mod;
        }
        return dp[i][j][k] = ans;
    }
public:
    int ways(vector<string>& pizza, int k) {
        N = pizza.size();
        M = pizza[0].size();
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= M; ++j) {
                if(pizza[i-1][j-1] == 'A') {
                    sum[i][j] = 1;
                }
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
        memset(dp, -1, sizeof(dp));
        int res = solve(1, 1, k);
        return res%mod;
    }
};
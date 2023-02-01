class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long> sumpre(n+1, 0);
        vector<long> sumsuf(n+1, 0);
        sumpre[0] = grid[0][0];
        for(int i = 1; i < n; i++) {
            sumpre[i] = sumpre[i-1] + grid[0][i];
        }
        sumsuf[n-1] = grid[1][n-1];
        for(int i = n-2; i >= 0; i--) {
            sumsuf[i] = sumsuf[i+1] + grid[1][i];
        }
        long ans = LONG_MAX;
        for(int i = 0; i < n; i++) {
            ans = min(ans, max(sumpre[n-1] - sumpre[i], sumsuf[0] - sumsuf[i]));
        }
        return ans;
    }
};
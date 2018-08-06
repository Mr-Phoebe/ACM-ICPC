class Solution {
private:
    int dp[101][101];
    map<char, vector<int> > node;
    int m = -1, n = -1;
    string key;
    int dfs(int i, int j)
    {
        if(j == m)
            return 0;
        if(~dp[i][j])
            return dp[i][j];
        dp[i][j] = INT_MAX;
        for(int k : node[key[j]])
        {
            int diff = abs(k - i);
            int step = min(diff, n - diff);
            dp[i][j] = min(dp[i][j], step + dfs(k, j+1));
        }
        return dp[i][j];
    }
public:
    int findRotateSteps(string ring, string key) {
        memset(dp, -1, sizeof(dp));
        m = key.length();
        n = ring.length();
        this->key = key;
        for(int i = 0; i < n; i++)
        {
            node[ring[i]].push_back(i);
        }
        return dfs(0, 0)+m;
    }
};

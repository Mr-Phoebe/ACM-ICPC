class Solution {
public:
    bool canCross(vector<int>& stones) {
        return dfs(stones, 0, 0);
    }
private:
    unordered_map<long long, bool> dp;
    bool dfs(const vector<int>& stones, const long long& k, const int& pos)
    {
        long long key = pos | k << 11L;
        if(dp.find(key) != dp.end())
            return dp[key];
        if(pos+1 == stones.size())
            return dp[key] = true;
        for(int i = pos+1; i < stones.size(); i++)
        {
            if(stones[i] - stones[pos] < k-1)
                continue;
            if(stones[i] - stones[pos] > k+1)
                break;
            if(dfs(stones, stones[i]-stones[pos], i))
                return dp[key] = true;
        }
        return dp[key] = false;
    }
};
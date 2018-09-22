class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int cnt = 0;
        int low_len = low.length(), high_len = high.length();
        if(low_len > high_len || (low_len == high_len && low > high))
            return 0;
        long long dp[2] = {1, 3};
        for(int i = 2; i < high_len; i++)
        {
            if(i > low_len)
                cnt += dp[i&1] << 2;
            dp[i&1] *= 5;
        }
        if(low_len == high_len)
        {
            string tmp = string(low_len, '0');
            dfs(cnt, tmp, low, high, 0, low_len-1);
        }
        else
        {
            string tmp = string(low_len, '0');
            dfs(cnt, tmp, low, high, 0, low_len-1);
            tmp = string(high_len, '0');
            dfs(cnt, tmp, low, high, 0, high_len-1);
        }
        return cnt;
    }
private:
    const pair<char, char> d[5] = {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'},};
    void dfs(int& cnt, string& cur, const std::string& low, const std::string& high, int l, int r)
    {
        if(l > r)
        {
            if((cur.length() > low.length() || low <= cur) &&
               (cur.length() < high.length() || high >= cur))
                cnt++;
            return;
        }
        int begin = l == 0 && r != 0 ? 1 : 0;
        int end = l == r ? 3 : 5;
        for(int i = begin; i < end; ++i)
        {
            cur[l] = d[i].first;
            cur[r] = d[i].second;
            if((cur.size() > low.size() || string(low, 0, l+1) <= string(cur, 0, l+1)) &&
               (cur.size() < high.size() || string(cur, 0, l+1) <= string(high, 0, l+1)))
                dfs(cnt, cur, low, high, l+1, r-1);
        }
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> mp(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+5,false);
        dp[0] = true;
        for(int i = 0 ; i < n; i++)
        {
            if(!dp[i])  continue;
            string subs = "";
            for(int j = i+1; j <= n; j++)
            {
                subs += s[j-1];
                if(mp.find(subs) != mp.end())
                    dp[j] = true;
            }
        }
        return dp[n];
    }
};
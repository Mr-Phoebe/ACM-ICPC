class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        
        int** dp = new int*[len2+2];
        for(int i = 0; i < len2+2; i++)
        {
            dp[i] = new int[len1+2];
            memset(dp[i], 0, sizeof(int)*(len1+2));
        }
        for(int i = 0; i < len1; i++)
            dp[0][i] = 1;
        for(int i = 0; i < len2; i++)
        {
            for(int j = 0; j < len1; j++)
            {
                if(t[i] == s[j])
                    dp[i+1][j+1] = dp[i][j] + dp[i+1][j];
                else
                    dp[i+1][j+1] = dp[i+1][j];
            }
        }
        return dp[len2][len1];
    }
};

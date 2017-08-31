class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(s3.length() != len1 + len2)
            return false;
    
        bool dp[len1+5][len2+5] = {true};
        
        for(int i = 0 ; i <= len1; i++)
            for(int j = (!i); j <= len2; j++)
                if(!i)
                    dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[j-1]);
                else if(!j)
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i-1]);
                else
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
        return dp[len1][len2];
    }
};
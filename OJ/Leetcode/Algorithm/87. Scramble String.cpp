class Solution {
public:
    
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        bool dp[len+5][len+5][len+5] = {false};    

        int count[26] = {0};
        for(int i = 0; i < len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }

        for(int i=0; i<26; i++)
            if(count[i]!=0)
                return false;  

        for(int i = 0; i < len; i++)
            for(int j = 0; j < len; j++)
                dp[1][i][j] = s1[i] == s2[j];

        for(int n = 2; n <= len; n++)
            for(int i = 0; i <= len - n; i++)
                for(int j = 0; j <= len - n; j++)
                    //if(test(s1, s2, i, j, n))
                        for(int l = 1; l < n; l++) 
                            if(dp[l][i][j] && dp[n-l][i+l][j+l] || dp[l][i][j+n-l] && dp[n-l][i+l][j])
                            {
                                dp[n][i][j] = true;
                                break;
                            }
        return dp[len][0][0];
                    
    }
};
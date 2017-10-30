class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int res = 0;
        bool dp[n][n] = {false};
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[i][j] = s.at(i) == s.at(j) && (j - i < 3 || dp[i + 1][j - 1]);
                if(dp[i][j]) ++res;
            }
        }
        return res;
    }
};

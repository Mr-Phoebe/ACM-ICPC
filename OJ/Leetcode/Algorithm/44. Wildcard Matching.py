class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        s = ' ' + s;p = ' ' + p;
        ls = len(s);lp = len(p)
        
        dp = [[False for _ in range(lp+1)] for _ in range(ls+1)]
        dp[0][0] = True
        
        
        for j in range(1, lp):
            dp[0][j] = dp[0][j-1] & (p[j] == '*')
            for i in range(1, ls):
                if p[j] == '?' or s[i] == p[j]:
                    dp[i][j] = dp[i-1][j-1]
                elif p[j] == '*':
                    dp[i][j] = dp[i][j-1] | dp[i-1][j]
                    
        return dp[ls-1][lp-1]
        
        
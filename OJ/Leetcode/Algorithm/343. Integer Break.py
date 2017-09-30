class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [1 for i in range(n+10)]
        for i in range(2, n+1):
            for j in range(1, i):
               dp[i] = max(dp[i], max(j,dp[j]) * max(i-j, dp[i-j]))
        return dp[n]

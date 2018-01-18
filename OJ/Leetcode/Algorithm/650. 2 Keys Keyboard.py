class Solution(object):
    def minSteps(self, n):
        """
        :type n: int
        :rtype: int
        """
        def dfs(k):
            if dp[k]!= 0:  return dp[k]
            dp[k] = k
            for i in range(2, int(math.sqrt(k))+1):
                if k%i == 0:
                    dp[k] = min(dfs(k/i)+i, dp[k])
                    dp[k] = min(dfs(i)+k/i, dp[k])
            return dp[k]
        dp = [0 for i in range(n+10)]
        dp[0] = 0; dp[1] = 0;
        if n == 1:  return 0
        return dfs(n)
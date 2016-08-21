class Solution(object):
    

    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [[0] * (n+1) for _ in range(n+1)]
        
        def solve(lo, hi):
            if lo < hi and dp[lo][hi] == 0:
                dp[lo][hi] = min(x + 
                                    max(solve(lo,x-1), solve(x+1,hi)) for x in range(lo, hi))
            return dp[lo][hi]
        
        return solve(1, n)
        
        
            
        
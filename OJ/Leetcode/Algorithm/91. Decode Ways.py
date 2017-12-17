class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        def zero(s):
            return s == '0'
        def valid(s1, s2):
            return s1 == '1' or (s1 == '2' and s2 <= '6')
        n = len(s)
        if(n == 0 or s[0] == '0'):
            return 0
        if(n == 1):
            return 1
            
        dp = [0 for i in range(n+5)]
        dp[-1] = 1
        dp[0] = 1
        for i in range(1, n):
            if(not zero(s[i]) and valid(s[i-1], s[i])):
                dp[i] += dp[i-2] + dp[i-1]
            elif(zero(s[i]) and valid(s[i-1], s[i])):
                dp[i] += dp[i-2]
                print "ha"
            elif(not zero(s[i]) and not valid(s[i-1], s[i])):
                dp[i] += dp[i-1]
            else:
                return 0
        return dp[n-1]
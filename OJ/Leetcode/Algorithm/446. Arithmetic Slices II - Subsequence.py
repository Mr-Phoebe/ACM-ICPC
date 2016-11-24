class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        ans, n = 0, len(A)
        dp = [{} for i in xrange(n)]
        for i in xrange(1, n):
            for j in range(i):
                dist = A[i] - A[j]
                s = dp[j].get(dist, 0) + 1
                dp[i][dist] = dp[i].get(dist, 0) + s
                res += (s-1)
        return ans
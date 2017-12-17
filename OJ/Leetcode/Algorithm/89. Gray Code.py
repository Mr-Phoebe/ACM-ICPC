class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        ans = [0]
        for i in range(n):
            ans += map(lambda x,m=i : x + pow(2, m), reversed(ans))
        return ans
        
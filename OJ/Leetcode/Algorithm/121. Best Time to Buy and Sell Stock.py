class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if prices == []:
            return 0
        maxn = prices[-1]
        ans = 0
        for num in reversed(prices):
            maxn = max(num, maxn)
            ans = max(ans, maxn-num)
        return ans

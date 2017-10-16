class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        last, now = 0, 0
        l =len(nums)
        if l == 1:
            return nums[0]
        for i in range(l-1): 
            last, now = now, max(last + nums[i], now)
        ans = now
        last, now = 0, 0
        for i in range(1, l): 
            last, now = now, max(last + nums[i], now)
        return max(ans, now)

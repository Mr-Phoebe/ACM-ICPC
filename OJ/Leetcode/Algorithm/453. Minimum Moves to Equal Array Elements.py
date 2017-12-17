class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        minn = min(nums)
        ans = 0
        for i in nums:
            ans += i-minn
        return ans


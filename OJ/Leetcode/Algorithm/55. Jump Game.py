class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        reach = 0
        n = len(nums)
        for i in range(n+1):
            if i > reach or i >= n:
                break
            reach = max(reach, i+nums[i])
        return i == n
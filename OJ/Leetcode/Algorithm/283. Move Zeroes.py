class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        begin = 0
        end = n-1
        for i in range(n):
            if(nums[i] == 0):
                continue
            else:
                nums[begin], nums[i] = nums[i], nums[begin]
                begin += 1
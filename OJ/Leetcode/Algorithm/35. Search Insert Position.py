class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l = -1
        r = len(nums)
        
        while l+1 < r:
        	mid = l + (r - l >> 1)
        	if nums[mid] < target:
        		l = mid
        	else:
        		r = mid
        
        return r

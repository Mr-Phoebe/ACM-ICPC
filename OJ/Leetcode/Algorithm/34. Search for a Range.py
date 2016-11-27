class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l = -1
        r = len(nums) - 1
        ans = [0, 0]
        while l+1 < r:
            mid = l + (r - l >> 1)
            if nums[mid] >= target:
                r = mid
            else:
                l = mid
        if nums[r]!= target:
            ans[0] = -1
        else:
            ans[0] = r
        
        l = 0
        r = len(nums)
        while l+1 < r:
            mid = l + (r - l >> 1)
            if nums[mid] <= target:
                l = mid
            else:
                r = mid
        
        if nums[l]!= target:
            ans[1] = -1
        else:
            ans[1] = l
        return ans
            
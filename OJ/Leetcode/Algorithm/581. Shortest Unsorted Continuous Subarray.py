class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        l = 0
        r = n-1
        ans = 0
        while l < n-1 and nums[l] <= nums[l+1]:
            l += 1
        while r >= 1 and nums[r-1] <= nums[r]:
            r -= 1
        
        if l < r:
            mi = min(nums[l:r+1])
            ma = max(nums[l:r+1])
            while l >= 1 and nums[l-1] > mi:
                l -= 1
            while r < n-1 and nums[r+1] < ma:
                r += 1
            ans = r-l+1
        return ans
        

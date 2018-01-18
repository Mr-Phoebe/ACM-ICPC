class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n = len(nums)
        l = -1
        r = n - 1
        
        while l + 1 < r:
        	mid = l + (r - l >> 1)
        	if nums[mid] > nums[r]:
        		l = mid
        	else:
        		r = mid
        
        half = r
        
        l = 0
        r = n
        while l + 1 < r:
        	mid = l + (r - l >> 1)
        	realmid = (mid + half) % n
        	if nums[realmid] > target:
        		r = mid
        	else:
        		l = mid
        
        if nums[(l+half)%n] == target:
        	return (l+half)%n
        else:
        	return -1
/*
* @Author: Haonan Wu
* @Date:   2017-08-25 04:26:08
* @Last Modified by:   lenovo
* @Last Modified time: 2017-08-25 04:26:17
*/
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        i = 0
        while i<l:
            if nums[i]>0 and nums[i]<=l and nums[i] != i+1 and nums[i] != nums[nums[i]-1]:
                temp = nums[i]
                nums[i] = nums[nums[i] - 1]
                nums[temp - 1] = temp
            else:
                i += 1
        
        for i in range(l):
            if nums[i] != i+1:
                return i+1
        return l+1
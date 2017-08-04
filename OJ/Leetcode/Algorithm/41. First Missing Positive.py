# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-07-21 12:43:56
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-07-21 13:04:56

# python的for循环 range(l)，最后得到的是l-1

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
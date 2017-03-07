# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-06 20:56:21
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-06 21:14:30

class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        if k == 0:
            for i in range(0, len(nums) - 1):
                if nums[i] == 0 and nums[i+1] == 0:
                    return True
            return False
        
        k = abs(k)
        if len(nums) >= k * 2:
            return True
            
        P = [0]
        for x in nums:
            v = (P[-1] + x)%k
            P.append(v)
        
        seen = set()
        for i in xrange(len(P) - 3, -1, -1):
            seen.add(P[i+2])
            if P[i] in seen:
                return True
        return False
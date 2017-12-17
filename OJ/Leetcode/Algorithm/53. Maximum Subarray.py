# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-10 16:29:40
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-10 16:37:56

class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        maxx = nums[0]
        tmp = 0
        for num in nums:
            tmp = max(tmp + num, num)
            maxx = max(maxx, tmp)
        return maxx


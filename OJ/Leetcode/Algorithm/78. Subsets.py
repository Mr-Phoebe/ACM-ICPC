# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-07 21:29:04
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-07 21:29:15

class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = [[]]
        for num in sorted(nums):
            res += [item+[num] for item in res]
        return res
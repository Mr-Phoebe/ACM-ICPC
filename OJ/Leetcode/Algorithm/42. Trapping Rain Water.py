# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-07-23 23:15:51
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-07-23 23:16:03

class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        le = len(height)
        leftmax = [0 for i in range(le)]
        rightmax = [0 for i in range(le)]
        
        maxn = 0
        for i in range(le):
            leftmax[i] = maxn
            maxn = max(maxn,height[i])
            
        maxn = 0
        for i in range(le-1, -1, -1):
            rightmax[i] = maxn
            maxn = max(maxn,height[i])
            
        ans = 0
        for i in range(le):
            if leftmax[i] != 0 and rightmax[i] != 0:
                h = min(leftmax[i], rightmax[i]) - height[i]
                if h > 0:
                    ans += h
        return ans
        
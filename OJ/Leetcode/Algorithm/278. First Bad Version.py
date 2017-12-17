# -*- coding: utf-8 -*-
# @Author: Haonan Wu
# @Date:   2017-09-24 18:58:20
# @Last Modified by:   Haonan Wu
# @Last Modified time: 2017-09-24 18:58:30

# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        l = 0; r = n;
        while l+1 < r:
            mid = (l+r)>>1
            if(isBadVersion(mid)):
                r = mid
            else:
                l = mid
        return r
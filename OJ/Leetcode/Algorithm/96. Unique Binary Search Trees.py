# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-17 08:41:06
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-17 08:41:16

class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = [0] * (n+1)
        res[0] = 1
        for i in xrange(1, n+1):
            for j in xrange(i):
                res[i] += res[j] * res[i-1-j]
        return res[n]
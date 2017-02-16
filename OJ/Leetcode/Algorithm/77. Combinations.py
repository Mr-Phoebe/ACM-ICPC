# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-16 16:21:34
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-16 16:34:20


class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        l = []
        num = n
        def dfs(i, k, cur):
            if k == 0:
                tmp = cur[0:]
                l.append(tmp)
                return
            for ii in range(i, num):
                if ii+k <= num:
                    cur.append(ii+1)
                    dfs(ii+1, k-1, cur)
                    cur.remove(ii+1)

        dfs(0, k, [])

        return l

'''
from itertools import combinations

class Solution:
    def combine(self, n, k):
        return list(combinations(range(1, n+1), k))
'''
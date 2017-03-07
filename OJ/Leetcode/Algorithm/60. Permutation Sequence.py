# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-07 11:26:51
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-07 11:30:18

from itertools import permutations

class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        now = ''
        for i in range(1, n+1):
            now += str(i)
        i = 0
        for j in permutations(now, n):
            i+=1
            if i == k:
                temp = ""
                for s in j:
                    temp+=s
                return temp
        


if __name__ == '__main__':
    sol = Solution()
    print sol.getPermutation(3, 2)
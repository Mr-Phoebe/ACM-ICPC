# -*- coding: utf-8 -*-
# @Author: Haonan Wu
# @Date:   2017-09-27 23:49:26
# @Last Modified by:   Haonan Wu
# @Last Modified time: 2017-09-27 23:54:52

class Solution(object):
    def dfs(self, num, target, pos, negate, prod):
        ans = []
        l = len(num)
        for i in xrange(pos, l):
            if i > pos and num[pos] == "0":
                break

            if i == l-1:
                if negate * prod * long(num[pos:i+1]) == target:
                    ans.extend([num[pos:i+1]])
                break
            
            aa = self.dfs(num, target - prod * negate * long(num[pos:i+1]), i+1, 1, 1)
            ans.extend([num[pos:i+1] + "+" + s for s in aa])

            ss = self.dfs(num, target - prod * negate * long(num[pos:i+1]), i+1, -1, 1)     
            ans.extend([num[pos:i+1] + "-" + s for s in ss])

            mm = self.dfs(num, target, i+1, 1, prod * negate * long(num[pos:i+1]))
            ans.extend([num[pos:i+1] + "*" + s for s in mm])

        return ans
        
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        return self.dfs(num, target, 0, 1, 1)
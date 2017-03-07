# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-07 20:47:21
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-07 20:55:14
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        l1, l2 = len(word1)+1, len(word2)+1
        dp = [[0 for _ in xrange(l2)] for _ in xrange(l1)]
        for i in xrange(l1):
            dp[i][0] = i
        for j in xrange(l2):
            dp[0][j] = j
        for i in xrange(1, l1):
            for j in xrange(1, l2):
                dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+(word1[i-1]!=word2[j-1]))
        return dp[-1][-1]
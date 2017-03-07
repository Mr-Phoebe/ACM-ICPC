# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-06 20:11:45
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-06 20:19:58

class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        dp = [[1 for x in range(n)] for x in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i][j-1]+dp[i-1][j]
        return dp[-1][-1]


if __name__ == '__main__':
    sol = Solution()
    print sol.uniquePaths(5, 9)
# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-11 20:57:43
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-11 21:34:21

class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        def isin(x, y):
            return x>=0 and y>=0 and x<n and y<n and ma[x][y] == -1
        if n == 0:
            return []
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        ma = [([-1] * n) for i in range(n)]
        space = n*n
        num = 1
        x = 0;y = 0;dire = 0;
        cnt = 0
        ma[x][y] = num
        while space!=num:
            xx = x + dx[dire%4]
            yy = y + dy[dire%4]
            if isin(xx, yy):
                num += 1
                ma[xx][yy] = num
                x = xx
                y = yy
            else:
                dire += 1
        return ma




if __name__ == '__main__':
    n = input()
    sol = Solution()
    print sol.generateMatrix(n)
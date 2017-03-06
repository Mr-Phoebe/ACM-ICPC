# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-03-03 10:57:26
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-03-03 11:01:34

class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        ret = []
        while matrix:
            ret += matrix.pop(0)
            if matrix and matrix[0]:
                for row in matrix:
                    ret.append(row.pop())
            if matrix:
                ret += matrix.pop()[::-1]
            if matrix and matrix[0]:
                for row in matrix[::-1]:
                    ret.append(row.pop(0))
        return ret
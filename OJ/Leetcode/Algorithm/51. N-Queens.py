# -*- coding: utf-8 -*-
# @Author: HaonanWu
# @Date:   2017-02-10 19:09:00
# @Last Modified by:   HaonanWu
# @Last Modified time: 2017-02-10 19:46:55

import math
import copy

class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        def change(index):
            l = ['.'] * n
            l[index] = 'Q'
            return ''.join(l)
        def NQueens(res, ld, rd, k, vec):
            if res != limit:
                pos = limit & ~(res | ld | rd)
                while pos!=0:
                    p = pos & -pos # find the last one
                    pos -= p
                    vec[k] = change(int(math.log(p, 2)))
                    NQueens(res + p, (ld + p) << 1, (rd + p) >> 1, k + 1, vec)
                    vec[k] = space
            else:
                l = copy.deepcopy(vec)
                result.append(l)
        limit = (1 << n) - 1
        space = '.' * n
        vec = [space]*n
        result = []
        NQueens(0, 0, 0, 0, vec)
        return result

    


if __name__ == '__main__':
    sl = Solution()

    sl.solveNQueens(4)
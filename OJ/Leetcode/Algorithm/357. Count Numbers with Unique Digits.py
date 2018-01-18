class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 1
        res = 10
        tmp = 9
        for i in range(1, n):
            tmp *= (10 - i)
            res += tmp
#            if n >= 10:        # it is rediculous that the N is below 10
#                return res
        return res
class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        import math
        n = int(math.log(num, 2))
        m = (1<<n)-1
        return ~num & m

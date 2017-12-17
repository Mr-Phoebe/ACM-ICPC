class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0 or x == 1:
            return x
        l,r = 0, x/2 + 1
        while l+1<r:
            mid = l + ((r - l) >> 1)
            if mid**2 > x:
                r = mid - 1
            else:
                l = mid
        return r
        
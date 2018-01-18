class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        root = 0
        bit = 1 << 15
        while bit > 0:
            root |= bit
            if root**2 > num:
                root ^= bit
            bit >>= 1
        return root * root == num

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        tmp = x
        y = 0
        while tmp:
            y = y*10 + tmp%10
            tmp = tmp/10
        return y == x
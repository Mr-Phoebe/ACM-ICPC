class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        flag = (dividend > 0) ^ (divisor > 0)
        dividend, divisor = abs(dividend), abs(divisor)
        ans = 0
        for i in range(31, -1, -1):
        	if (dividend>>i) >= divisor:
        		ans <<= 1
        		ans |= 1
        		dividend -= (divisor << i)
        	else:
        		ans <<= 1
        if flag:
        	ans = -ans
        return min(max(-2147483648, ans), 2147483647)
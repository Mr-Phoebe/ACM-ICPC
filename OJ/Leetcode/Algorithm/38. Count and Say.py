class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return '1'
        else:
            s = self.countAndSay(n-1) # recursion
            digit, count = s[0], 1
            res = ''
            for c in s[1:]:
                if c == digit:
                    count += 1
                else: # change of current digit
                    res += str(count) + str(digit)
                    digit, count = c, 1
            res += str(count) + str(digit)
            return res
        
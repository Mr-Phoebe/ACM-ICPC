class Solution(object):
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        s = [c for c in str(n)]
        for i in range(len(s) - 2, -1, -1):
            l = i
            r = len(s) - 1
            while l != r and s[r] <= s[l]:
                r -= 1
            if l != r:
                s[l], s[r] = s[r], s[l]
                s[l+1:] = sorted(s[l+1:])
                num = int("".join(s))
                return num if -2 ** 31 <= num <= 2 ** 31 - 1 else -1
        return -1

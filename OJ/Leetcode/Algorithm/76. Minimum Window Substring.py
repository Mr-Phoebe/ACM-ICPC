import collections

class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        num, length = collections.Counter(t), len(t)
        i = st = en = 0
        for j, c in enumerate(s, 1):
            length -= num[c] > 0
            num[c] -= 1
            if not length:
                while i < j and num[s[i]] < 0:
                    num[s[i]] += 1
                    i += 1
                if not en or j - i <= en - st:
                    st, en = i, j
        return s[st:en]


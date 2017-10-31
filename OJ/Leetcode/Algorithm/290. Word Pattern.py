class Solution(object):
    def wordPattern(self, pattern, st):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        s = st.split()
        return map(pattern.find, pattern) == map(s.index, s)

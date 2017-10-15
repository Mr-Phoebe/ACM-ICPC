class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        return len(s.split('A'))<=2 and s.find('LLL')==-1

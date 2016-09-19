class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if strs == []:  
            return ''  
        for i in range(len(strs[0])):  
            for str in strs:  
                if len(str) <= i or str[i] != strs[0][i]:  
                    return strs[0][:i]  
        return strs[0]  
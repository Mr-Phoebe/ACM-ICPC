class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows==1:
            return s  
        res=["" for i in range(numRows)]  
        i=0
        gap=numRows-2  
        while i<len(s):  
            j=0  
            while i<len(s) and j<numRows:
                res[j]+=s[i]
                i+=1
                j+=1  
            j=gap  
            while i<len(s) and j>0:
                res[j]+=s[i]
                i+=1
                j-=1  
        chs=''  
        for i in range(numRows):  
            chs+=res[i]  
        return chs  
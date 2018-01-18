class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        mincut = [i-1 for i in range(n+5)]
        
        for i in range(1, n):
            for j  in range(min(i+1, n-i)):
                if s[i-j] != s[i+j]:
                    break
                mincut[i+j+1] = min(mincut[i+j+1], mincut[i-j]+1)
            for j  in range(min(i, n-i)):
                if s[i-j-1] != s[i+j]:
                    break
                mincut[i+j+1] = min(mincut[i+j+1], mincut[i-j-1]+1)
                '''
            for j in range(n+1):
                print mincut[j],
            print ""    
                '''
            
        return mincut[n]
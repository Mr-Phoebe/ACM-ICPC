class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        le = len(height)
        leftmax = [0 for i in range(le)]
        rightmax = [0 for i in range(le)]
        
        maxn = 0
        for i in range(le):
            leftmax[i] = maxn
            maxn = max(maxn,height[i])
            
        maxn = 0
        for i in range(le-1, -1, -1):
            rightmax[i] = maxn
            maxn = max(maxn,height[i])
        
        print height
        print rightmax
        print leftmax
            
        ans = 0
        for i in range(le):
            if leftmax[i] != 0 and rightmax[i] != 0:
                h = min(leftmax[i], rightmax[i]) - height[i]
                if h > 0:
                    ans += h
        return ans
        
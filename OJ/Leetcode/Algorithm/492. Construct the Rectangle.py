import math
class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        num = int(math.sqrt(area))+1
        while num >= 1:
            if area%num == 0:
                ans = area/num
                break
            num -= 1
            
        return [max(num,ans), min(num,ans)]

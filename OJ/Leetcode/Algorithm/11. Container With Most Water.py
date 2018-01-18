class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        le = 0
        ri = len(height) - 1
        ans = 0
        while le < ri:
            ans = max(ans, min(height[le], height[ri]) * (ri - le))
            if height[le] > height[ri]:
                ri = ri - 1
            else:
                le = le + 1
        return ans
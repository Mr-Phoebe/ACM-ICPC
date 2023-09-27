import math
class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        sum = func = 0
        ans = -math.inf;
        for i in range(len(nums)):
            sum += nums[i]
            func += nums[i] * i
        
        ans = max(ans, func)
        for i in range(len(nums)-1, -1, -1):
            func += sum - len(nums) * nums[i]                    
            ans = max(ans, func)
        
        return ans

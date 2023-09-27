import math

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        if len(nums) >= 3:
            min_num1 = min_num2 = math.inf
            for n in nums:
                if min_num1 >= n:
                    min_num1 = n
                elif min_num2 >= n:
                    min_num2 = n
                else:
                    return True
        return False
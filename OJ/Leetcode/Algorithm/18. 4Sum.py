class Solution(object):
    def dfs(self, nums, target, count, res, result):
            length = len(nums)
            if length < count or count < 2  or target < nums[0] * count or target > nums[-1] * count:
                return []
            if count == 2: 
                left = 0
                right = length - 1
                while left < right:
                    sum = nums[left] + nums[right]
                    if sum == target:
                        result.append(res + [nums[left], nums[right]])
                        left += 1
                        right -= 1
                        while left < right and nums[right] == nums[right+1]:
                            right -= 1
                        while left < right and nums[left] == nums[left-1]:
                            left += 1
                    elif sum > target:
                        right -= 1
                    else:
                        left += 1
            else:		
                for i in range(0, len(nums) - count + 1):
                    if i != 0 and nums[i] == nums[i-1]:
                        continue
                    self.dfs(nums[i + 1:], target - nums[i], count - 1, res + [nums[i]], result)

    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        self.dfs(nums, target, 4, [], result)

        return result
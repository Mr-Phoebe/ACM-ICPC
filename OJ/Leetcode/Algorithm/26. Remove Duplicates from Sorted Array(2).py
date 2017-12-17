class Solution:
    def removeDuplicates(self, nums):
        size=0;length=len(nums)
        for i in range(length):
            if i==0 or nums[i]!=nums[i-1]:
                nums[size]=nums[i]
                size+=1
        return size


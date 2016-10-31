from collections import OrderedDict
class Solution(object):
    def removeDuplicates(self, nums):
        nums[:] =  OrderedDict.fromkeys(nums).keys()
        return len(nums)
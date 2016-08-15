import random
class Solution(object):

    def __init__(self, nums):
        """

        :type nums: List[int]
        :type size: int
        """
        self.origin = nums[:]
        self.output = nums

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.origin

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        n = len(self.output)
        for i in range(n):
            j = random.randint(i,n-1)
            self.output[i], self.output[j] = self.output[j], self.output[i]
        return self.output


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
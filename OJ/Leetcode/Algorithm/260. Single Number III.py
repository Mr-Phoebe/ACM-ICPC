class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = reduce(lambda x, y : x ^ y, nums)
        diff_bit = res & (-res)
        a = []
        b = []
        for i in nums:
            if diff_bit & i != 0:
                a.append(i)
            else:
                b.append(i)

        return [reduce(lambda x, y : x ^ y, a), reduce(lambda x, y : x ^ y, b)]

class Solution:
    def findLHS(self, nums: List[int]) -> int:
        cnt = defaultdict(int)
        for i in nums:
            cnt[i] = cnt[i] + 1
        
        ans = 0
        for num in cnt.keys():
            if num + 1 in cnt:
                ans = max(ans, cnt[num] + cnt[num+1])

        return ans
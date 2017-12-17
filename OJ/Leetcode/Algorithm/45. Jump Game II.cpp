class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, ans = 0, j = 1;
        int len = nums.size();
        while(j<len)
        {
            int end = min(nums[i]+i, len-1);
            while(j<=end)
            {
                if(nums[j]+j>nums[i]+i)
                    i = j;
                j++;
            }
            ans++;
        }
        return ans;
    }
};
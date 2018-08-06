class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        vector<int> ans;
        long long sum = 0;
        int i = 0;
        while(sum < n)
        {
            while(i < nums.size() && sum+1 >= nums[i])
            {
                sum += nums[i++];
            }
            if(sum < n)
            {
                ans.push_back(sum+1);
                sum += sum+1;
            }
        }
        return ans.size();
    }
};

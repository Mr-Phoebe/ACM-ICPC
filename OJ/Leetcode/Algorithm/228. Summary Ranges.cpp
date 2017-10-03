class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n == 0)  return ans;
        int pre = nums[0] - 2, now = nums[0] - 2;
        nums.push_back(nums[nums.size()-1]+2);
        string tmp = "";
        for(int i = 0; i <= n; i++)
        {
            if(now+1 != nums[i])
            {
                if(now == pre)
                    ans.push_back(to_string(now));
                else
                    ans.push_back(to_string(pre) + string("->") + to_string(now));
                pre = now = nums[i];
            }
            else
            {
                now = nums[i];
            }
        }

        ans.erase(ans.begin());
        return ans;
    }
};

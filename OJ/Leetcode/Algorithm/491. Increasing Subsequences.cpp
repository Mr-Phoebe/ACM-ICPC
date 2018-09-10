class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> tmpans;
        dfs(0, ans, tmpans, nums);
        return ans;
    }

    void dfs(int pos, vector<vector<int> >& ans, vector<int>& tmp, const vector<int>& nums)
    {
        if(tmp.size() > 1)
        {
            ans.push_back(tmp);
        }
        unordered_set<int> vis;
        for(int i = pos; i < nums.size(); i++)
        {
            if((tmp.size() == 0 || nums[i] >= tmp.back()) && vis.find(nums[i]) == vis.end())
            {
                vis.insert(nums[i]);
                tmp.push_back(nums[i]);
                dfs(i+1, ans, tmp, nums);
                tmp.pop_back();
            }
        }
    }
};

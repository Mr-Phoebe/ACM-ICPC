class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ret;

        if (nums.empty())
            return ret;

        sort(nums.begin(), nums.end());
        ret.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()))
            ret.push_back(nums);

        return ret;
    }
};
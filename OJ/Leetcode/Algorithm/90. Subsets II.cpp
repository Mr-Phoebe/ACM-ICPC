class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        int N = (1<<n);
        set<vector<int> > s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < N; i++)
        {
            vector<int> tmp;
            for(int j = 0; j < n; j++)
            {
                if(i & (1<<j))
                    tmp.push_back(nums[j]);
            }
            s.insert(tmp);
        }
        vector<vector<int> > ans(s.begin(), s.end());
        return ans;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size(), need = n;
        vector<pair<int, int> > ve;
        vector<int> cnt(n, 0);
        for(int i = 0; i < n; i++)
            for(auto num : nums[i])
                ve.emplace_back(make_pair(num, i));
        sort(ve.begin(), ve.end(), [](auto a, auto b){return a.first < b.first;});
        vector<int> ans = {ve[0].first, ve[ve.size()-1].first};
        int start = 0, end = 0;
        for(; end < ve.size(); end++)
        {
            if(cnt[ve[end].second]++ == 0)
                need--;
            while(need == 0)
            {
                if(ve[end].first - ve[start].first < ans[1] - ans[0])
                    ans[0] = ve[start].first, ans[1] = ve[end].first;
                if(--cnt[ve[start++].second] == 0)
                    need++;
            }
        }
        return ans;
    }
};

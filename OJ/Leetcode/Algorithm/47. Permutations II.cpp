class Solution {
public:
    void dfs(int pos, int N, vector<vector<int>> &ans, vector<int> cur)
    {
        if(pos == N-1)
        {
            ans.push_back(cur);
            for(int i = 0; i < cur.size(); i++)
                printf("%d ", cur[i]);
            printf("\n");
            return;
        }
        for(int i = pos; i < N; i++)
        {
            if(i != pos && cur[i] == cur[pos])  continue;
            swap(cur[i], cur[pos]);
            dfs(pos+1, N, ans, cur);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        dfs(0, nums.size(), ans, nums);
        return ans;
    }
};
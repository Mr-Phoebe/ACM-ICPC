class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
            {
                int tmp = 0;
                for(int k = 0; k < m; k++)
                    tmp += grid[i][k] & grid[j][k];
                ans += tmp*(tmp-1)/2;
            }
        return ans;
    }
};

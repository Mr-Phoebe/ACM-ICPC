class Solution {
    int dx[2] = {-1,1};
    int dy[2] = {1,-1};
    int n, m;
    vector<vector<int> > mat;
    vector<int> ans;
    inline bool in(int x, int y)
    {
        return x>=0 && x<n && y>=0 && y<m;
    }
    void dfs(int x, int y)
    {
        //printf("%d ", mat[x][y]);
        ans.push_back(mat[x][y]);
        int flag = (x+y)&1;
        int xx = x+dx[flag];
        int yy = y+dy[flag];
        if(in(xx, yy))
            dfs(xx, yy);
        else if(flag)   // odd
        {
            if(x < n-1)     dfs(x+1, y);
            else if(y < m-1)dfs(x, y+1);
        }
        else
        {
            if(y < m-1)      dfs(x, y+1);
            else if(x < n-1) dfs(x+1, y);
        }
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        mat = matrix;
        n = matrix.size();
        if(n)   m = matrix[0].size();
        else    return ans;
        dfs(0, 0);
        return ans;
    }
};

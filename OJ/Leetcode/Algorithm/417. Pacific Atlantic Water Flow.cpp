class Solution {
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
    vector<pair<int, int>> res;
    vector<vector<int>> vis;
    int n,m;
    bool in(int x, int y)
    {
        return x>=0 && y>=0 && x<n && y<m;
    }
    void dfs(const vector<vector<int> >& matrix, int x, int y, int pre, int mask)
    {
        if(!in(x,y) || (vis[x][y]&mask) || pre > matrix[x][y])
            return;            
        vis[x][y] |= mask;
        if(vis[x][y] == 3)  res.push_back(make_pair(x, y));
        for(int i = 0, xx, yy; i < 4; i++)
        {
            xx = x + dx[i];
            yy = y + dy[i];
            dfs(matrix, xx, yy, matrix[x][y], mask);
        }
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(n == 0)  return res;
        m = matrix[0].size();
        if(m == 0)  return res;
        vis.resize(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) 
        {
            dfs(matrix, i, 0, INT_MIN, 1);
            dfs(matrix, i, m - 1, INT_MIN, 2);
        }
        for(int i = 0; i < m; i++) 
        {
            dfs(matrix, 0, i, INT_MIN, 1);
            dfs(matrix, n - 1, i, INT_MIN, 2);
        }
        return res;
    }
};

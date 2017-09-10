class Solution {
public:
    int cutOffTree(vector<vector<int>>& mp) {
        /*
        n = mp.size();
        if(!n)  return -1;
        m = mp[0].size();
        if(!m)  return -1;

        vector<pair<int, int> > tt(2750, make_pair(-1, -1));
        for(int i = 0 ; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mp[i][j] > 1)
                    tt[mp[i][j]] = make_pair(i, j);

        int x = 0, y = 0, ans = 0;
        for(int k = 0; k < 2750; k++)
        {
            if(tt[k].first == -1) continue;
            int i = tt[k].first, j = tt[k].second;
            memset(vis, 0, sizeof(vis));
            int step = dfs(x, y, i, j, 0, mp);
            if(step == n*m*2)   return -1;
            ans += step;
            x = i, y = j;
        }
        return ans;
        */
    }
private:
    int n, m;
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
    bool vis[55][55];
    int dfs(int x, int y, const int& i, const int& j, int step, const vector<vector<int>>& mp)
    {
        vis[x][y] = true;
        if(i == x && j == y)
            return step;
        int ans = n*m*2;
        for(int k = 0; k < 4; k++)
        {
            int xx = x+dx[k];
            int yy = y+dy[k];
            if(in(xx, yy) && mp[xx][yy])
                ans = min(ans, dfs(xx, yy, i, j, step+1, mp));
        }
        return ans;
    }
    inline bool in(int x, int y)
    {
        return x>=0 && y>=0 && x<n && y<m && !vis[x][y];
    }
};

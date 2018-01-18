class Solution {
public:
    int trapRainWater(vector<vector<int>>& a) {
        if(a.size() == 0 || a[0].size() == 0) return 0;
        n = a.size();
        m = a[0].size();
        const int begin = n*m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || j == 0 || i == n-1 || j == m-1)    addedge(begin, make_pair(idx(i, j), 0));
                for(int k = 0; k < 4; k++)
                {
                    int x = i+dx[k], y = j+dy[k];
                    if(x >= 0 && x < n && y >= 0 && y < m) addedge(idx(i, j), make_pair(idx(x, y), a[i][j]));
                }
            }
        int ans = 0;
        dij(begin);
        for (int i = 0; i < n; i++, puts(""))
            for (int j = 0; j < m; j++) {
                int w = dist[idx(i, j)];
                if(w > a[i][j]) ans += w - a[i][j];
            }

        return ans;
    } 
private:
    const static int MAXN = 110*110+5;
    vector<pair<int, int> > edge[MAXN];
    int dist[MAXN], vis[MAXN];
    int n, m;
    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};
    inline int idx(int x, int y)
    {
        return x*m+y;
    }
    inline void addedge(int i, pair<int, int> j)
    {
        edge[i].push_back(j);
    }
    void dij(const int& begin)
    {
        memset(dist, 0x3f, sizeof(dist));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        dist[begin] = 0;
        que.push(make_pair(dist[begin], begin));
        while(!que.empty())
        {
            int d = que.top().first, u = que.top().second; que.pop();
            if(vis[u])  continue;
            vis[u] = 1;
            for(auto e : edge[u])
            {
                int v = e.first, w = e.second;
                if(max(d, w) < dist[v])
                {
                    dist[v] = max(d, e.second);
                    que.push(make_pair(dist[v], v));
                }
            }
        }
    }
};
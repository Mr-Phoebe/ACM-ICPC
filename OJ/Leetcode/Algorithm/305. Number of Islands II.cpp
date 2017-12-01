class Solution {
    vector<int> fa;
    int m, n;
    int find_fa(int id) 
    {
        if(fa[id] != id)
            return fa[id] = find_fa(fa[id]);
        return id;
    }
    inline int idx(int x, int y)
    {
        return x * n + y;
    }
    inline bool in(int x, int y)
    {
        return x >= 0 && y >= 0 && x < m && y < n && fa[idx(x, y)] != -1;
    }
    const int dx[4] = {0,0,1,-1};
    const int dy[4] = {1,-1,0,0};
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        fa = vector<int>(m * n, -1);
        this->m = m;
        this->n = n;
        int island = 0;
        for (auto pos : positions) 
        {
            int x = pos.first, y = pos.second, idx_p = idx(x, y);
            fa[idx_p] = idx_p;
            island++;
            for(int i = 0; i < 4; i++) 
            {
                int xx = x + dx[i], yy = y + dy[i], idx_new = idx(xx, yy);
                if(in(xx, yy))
                {
                    int rootNew = find_fa(idx_new), rootPos = find_fa(idx_p);
                    if(rootPos != rootNew)
                    {
                        fa[rootPos] = rootNew;
                        --island;
                    }
                }
            }
            res.push_back(island);
        }
        return res;
    }
};

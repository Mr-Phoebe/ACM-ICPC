class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int a[n + 1];
        memset(a, 0, sizeof(a));
        vector<int> g[n + 1];
        for (auto& p : dislikes)
        {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != 0) continue;
            a[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int y = q.front(); q.pop();
                for (int x : g[y])
                {
                    if (a[y] * a[x] > 0) return false;
                    if (a[x] == 0) {
                        a[x] = -a[y];
                        q.push(x);
                    }
                }
            }
        }
        return true;
    }
};

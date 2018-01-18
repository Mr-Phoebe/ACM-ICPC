
#define ls first
#define rs second
#define pb(x) push_back(x)
class Solution {
private:
    vector<int>* edge;
public:
    vector<int> findOrder(int n, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        int* dir = new int[n+2];
        edge = new vector<int> [n+2];
        queue<int> que;

        memset(dir, 0, sizeof(int)*(n+2));
        for(int i = 0; i < n; i++)
            edge[i].clear();
        while(!que.empty()) que.pop();

        for(auto i : prerequisites)
        {
            edge[i.rs].pb(i.ls);
            dir[i.ls]++;
        }
        for(int i = 0; i < n; i++)
            if(!dir[i])
                que.push(i);


        while(!que.empty())
        {
            int u = que.front();que.pop();
            if(~dir[u])
                res.push_back(u);
            dir[u] = -1;
            for(auto e : edge[u])
                if(!--dir[e])
                    que.push(e);
        }
        if(res.size() != n) return {};
        return res;
    }
};


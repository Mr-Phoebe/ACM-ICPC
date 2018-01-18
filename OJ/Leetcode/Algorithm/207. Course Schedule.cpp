class Solution {
    vector<int> vis;
    vector<int>* edge;
    int dfs(int u)
    {
        //cout<<u<<" "<<vis[u]<<endl;
        vis[u] = -1;
        for(auto v : edge[u])
        {
            if(!vis[v])
            {
                if(dfs(v))
                    return true;
            }
            if(vis[v] == -1)
            {
                return true;
            }
        }
        vis[u] = 1;
        return false;
    }
public:
    bool canFinish(int n, vector<pair<int, int>>& prerequisites) {
        vis.resize(n,0);
        edge = new vector<int>[n];
        
        for(auto p:prerequisites)
        {
            edge[p.second].push_back(p.first);
        }
        for(int i = 0; i < n; i++)
            if(vis[i]!=-1 && dfs(i))
                return false;
        return true;
    }
};

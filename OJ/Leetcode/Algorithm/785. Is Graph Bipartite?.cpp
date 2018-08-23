class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        memset(color, -1, sizeof(color));
        int n = graph.size();
        for(int i = 0; i < n; i++)
        {
            if(~color[i])
                continue;
            color[i] = 0;
            if(!dfs(-1, i, graph))
                return false;
        }
        return true;
    }
private:
    int color[105];

    bool dfs(int pre, int n, const vector<vector<int> >& graph)
    {
        for(auto node : graph[n])
        {
            if(node == pre)
                continue;
            if(~color[node])
            {
                if(color[node] == color[n])
                    return false;
            }
            else
            {
                color[node] = color[n] ^ 1;
                if(!dfs(n, node, graph))
                    return false;
            }
        }
        return true;
    }
};

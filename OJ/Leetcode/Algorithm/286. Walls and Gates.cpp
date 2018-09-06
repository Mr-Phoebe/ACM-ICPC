class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        n = rooms.size();
        if(n == 0)
            return ;
        m = rooms[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(rooms[i][j] == 0)
                    dfs(i, j, 0, rooms);
    }
private:
    int n, m;
    void dfs(int x, int y, int dep, vector<vector<int>>& rooms)
    {
        if(x < 0 || y < 0 || x >= n || y >= m || rooms[x][y] == -1 || rooms[x][y] < dep)
            return;
        rooms[x][y] = min(rooms[x][y], dep);
        dfs(x+1, y, dep+1, rooms);
        dfs(x-1, y, dep+1, rooms);
        dfs(x, y+1, dep+1, rooms);
        dfs(x, y-1, dep+1, rooms);
    }
};

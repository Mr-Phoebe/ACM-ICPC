class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return -1;
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> total(m, vector<int>(n, 0));
        int walk = 0, ret = -1;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] != 1) continue;
                ret = -1;
                queue<pair<int, int>> que;
                que.emplace(i, j);
                while(!que.empty()){
                    int x = que.front().first;
                    int y = que.front().second;
                    que.pop();
                    for (int i = 0; i < 4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                            continue;
                        if (grid[nx][ny] == walk){
                            grid[nx][ny]--;
                            // here no need to refresh dp, because dp is assigned instead of using min
                            dp[nx][ny] = dp[x][y] + 1;
                            total[nx][ny] += dp[nx][ny];
                            que.emplace(nx, ny);
                            if (ret < 0 || total[nx][ny] < ret)
                                ret = total[nx][ny];
                        }
                    }
                }
                walk--;
            }
        }
        return ret;
    }
};

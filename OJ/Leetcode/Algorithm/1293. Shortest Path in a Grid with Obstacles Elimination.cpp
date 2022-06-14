class Solution {
    struct Node {
        int i, j;
        int k;
        int step;
        Node(int i, int j, int k, int step) {
            this->i = i;
            this->j = j;
            this->k = k;
            this->step = step;
        }
    };
    
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    int N, M, K;

    
    bool in(int i, int j) {
        if (i < 0 || j < 0 || i >= N || j >= M) {
            return false;
        }
        return true;
    }
public:
    int shortestPath(vector<vector<int>>& grid, int KK) {
        N = grid.size();
        M = grid[0].size();
        K = KK;
        
        if(N + M - 2 <= KK) {
            return N + M - 2;
        }
        
        vector<vector<int>> vis(N+1, vector<int>(M+1, -1));

        queue<Node> q;
        
        q.push(Node(0,0,K,0));
        vis[0][0] = K;
        while(!q.empty())
        {
            auto cur = q.front();
            int x = cur.i;
            int y = cur.j;
            q.pop();
            
		    if(cur.i == N-1 && cur.j == M-1) {
                return cur.step;
            }
            
            for(int t = 0; t < 4; ++t) {
                int newI = cur.i + dir[t][0];
                int newJ = cur.j + dir[t][1];
                if(!in(newI, newJ)) {
                    continue;
                }
                int newK = grid[newI][newJ] == 1? cur.k - 1:cur.k;
                if(newK < 0 || (vis[newI][newJ] != -1 && vis[newI][newJ] >= newK)) {
                    continue;
                }
                vis[newI][newJ] = newK;
                Node newNode(newI, newJ, newK, cur.step+1);
                q.push(newNode);
            }
            
        }
        return -1;
    }
};
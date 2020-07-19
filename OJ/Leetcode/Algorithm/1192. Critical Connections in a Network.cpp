class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n);
        vector<int> dnf(n, INT_MAX);
        vector<int> low(n, INT_MAX);
        vector<vector<int>> ans;
        int t = 0;   
        
        function<void(int, int)> tarjan = [&](int r, int p) {
            low[r] = dnf[r] = t++;
            for (int c : g[r]) {
                if (dnf[c] == INT_MAX) {
                    tarjan(c, r);
                    low[r] = min(low[r], low[c]);
                    if (low[c] > dnf[r]) {
                        ans.push_back({c, r});
                    }
                } else if (c != p) {
                    low[r] = min(dnf[c], low[r]);
                }
            }
        };
        
        for(const auto& edge :connections) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        tarjan(0, -1);
        return ans;
    }  
};
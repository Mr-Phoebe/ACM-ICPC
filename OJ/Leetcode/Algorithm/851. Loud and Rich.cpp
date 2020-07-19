class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        const int n = quiet.size();
        vector<vector<int>> g(n);
        vector<int> ans(n, -1);
        
        for(const auto& e : richer) {
            g[e[1]].push_back(e[0]);
        }
        
        for(int i = 0; i < n; i++) {
            dfs(i, g, quiet, ans);
        }
        return ans;
    }
    
    pair<int, int> dfs(int node, const vector<vector<int>>& g, const vector<int>& quiet, vector<int>& ans) {
        if (ans[node] > 0)
            return make_pair(quiet[ans[node]], ans[node]);
        ans[node] = node;
        int minNode = quiet[node];
        for(auto& next : g[node]) {
            auto [minNext, ansNext] = dfs(next, g, quiet, ans);
            if (minNode > minNext) {
                minNode = minNext;
                ans[node] = ans[next];
            }
        }
        return make_pair(minNode, quiet[ans[node]]);
    }
};
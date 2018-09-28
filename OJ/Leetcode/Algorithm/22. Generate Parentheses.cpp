class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string cur = "";
        vector<string> ans;
        dfs(cur, ans, 0, 0, n);
        return ans;
    }
private:
    void dfs(string& cur, vector<string>& ans, int left, int right, const int n)
    {
        if(right == n)
        {
            ans.push_back(cur);
            return;
        }
        if(left > right)
        {
            string tmp = cur + ")";
            dfs(tmp, ans, left, right+1, n);
        }
        if(left < n)
        {
            string tmp = cur + "(";
            dfs(tmp, ans, left+1, right, n);
        }
    }
};

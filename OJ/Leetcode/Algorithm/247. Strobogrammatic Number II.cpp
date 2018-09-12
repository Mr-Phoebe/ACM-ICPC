class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans;
        if(n <= 0)  return ans;
        string solution;
        for(int i = 0; i < n; i++) solution += "0";
        int l = 0, r = n-1;
        dfs(l,r,solution,ans);
        return ans;
    }

    void dfs(int l, int r, string solution, vector<string>& ans){
        if(l == r)
        {
            solution[l] = '0';
            ans.push_back(solution);
            solution[l] = '1';
            ans.push_back(solution);
            solution[l] = '8';
            ans.push_back(solution);
            return;
        }
        else if(l > r)
        {
            ans.push_back(solution);
            return;
        }

        solution[l] = solution[r] = '1';
        dfs(l+1,r-1,solution,ans);
        solution[l] = solution[r] = '8';
        dfs(l+1,r-1,solution,ans);
        solution[l] = '6', solution[r] = '9';
        dfs(l+1,r-1,solution,ans);
        solution[l] = '9', solution[r] = '6';
        dfs(l+1,r-1,solution,ans);
        if(l != 0){
            solution[l] = solution[r] = '0';
            dfs(l+1,r-1,solution,ans);
        }
    }
};

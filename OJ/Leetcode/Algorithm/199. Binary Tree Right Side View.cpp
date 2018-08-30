/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
private:
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root, vector<int>& ans, int dep=0)
    {
        if(root == NULL)
            return;
        if(vis.find(dep) == vis.end())
        {
            vis[dep] = true;
            ans.push_back(root->val);
        }
        dfs(root->right, ans, dep+1);
        dfs(root->left, ans, dep+1);
        return;
    }
};

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
    int ret = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        dfs(root, 0);
        return ret;
    }
    void dfs(TreeNode* root, int a) {
        if (!root) return ;
        if (!root->left && !root->right && a== 0) ret += root->val;
        else if (!root->left && root->right) dfs(root->right,1);
        else if (!root->right && root->left) dfs(root->left, 0);
        else {
            dfs(root->right,1);
            dfs(root->left, 0);
        }
    }
};

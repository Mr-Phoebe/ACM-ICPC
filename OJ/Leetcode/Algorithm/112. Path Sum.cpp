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
    int sum;
    bool dfs(TreeNode* root, int sum)
    {
        if(!root)   return false;
        if(!root->right && !root->left)
        {
            return sum + root->val == this->sum;
        }
        return dfs(root->left, sum+root->val) || dfs(root->right, sum+root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        this->sum = sum;
        return dfs(root, 0);
    }
};

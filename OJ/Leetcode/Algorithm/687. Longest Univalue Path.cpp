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
    int dfs(TreeNode* root, int& res)
    {
        if(!root)
            return 0;
        int rl = dfs(root->left, res);
        int rr = dfs(root->right, res);
        int sum = 0;
        int ret = 0;
        if(root->left && root->left->val == root->val)
        {
            sum += rl;
            ret = rl;
        }
        if(root->right && root->right->val == root->val)
        {
            sum += rr;
            ret = max(ret, rr);
        }
        res = max(res, sum);
        return ret+1;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};
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
    int maxn;
    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        maxn = max(maxn, l+r+1);
        return max(l, r) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        maxn = -1;
        dfs(root);
        return max(maxn-1, 0);
    }
};

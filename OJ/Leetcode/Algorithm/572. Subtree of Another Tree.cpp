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
    bool dfs(TreeNode* root, TreeNode* t)
    {
        if(!t && !root)
            return true;
        if(!root || !t)
            return false;
        bool ans = root->val == t->val & dfs(root->left, t->left) & dfs(root->right, t->right);
        return ans;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s)   return false;
        bool ans = dfs(s, t) | isSubtree(s->left, t) | isSubtree(s->right, t);        
        return ans;
    }
};

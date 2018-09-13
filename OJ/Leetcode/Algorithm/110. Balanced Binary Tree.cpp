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
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    bool ans = true;
    int dfs(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(abs(right - left) > 1)
            ans = false;
        return max(left, right)+1;
    }
};

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<TreeNode*, int> ans = dfs(root);
        return ans.first;
    }
private:
    pair<TreeNode*, int> dfs(TreeNode* root)
    {
        if(root == NULL)
            return make_pair(root, 0);
        pair<TreeNode*, int> left = dfs(root->left);
        pair<TreeNode*, int> right = dfs(root->right);
        if(left.second > right.second)
        {
            left.second++;
            return left;
        }
        if(left.second < right.second)
        {
            right.second++;
            return right;
        }
        if(left.second == right.second)
        {
            right.first = root;
            right.second++;
            return right;
        }
    }
};

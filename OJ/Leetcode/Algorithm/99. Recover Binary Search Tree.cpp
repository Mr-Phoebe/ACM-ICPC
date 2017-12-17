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
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(node1->val, node2->val);
    }
private:
    TreeNode* node1 = nullptr;
    TreeNode* node2 = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);
    void dfs(TreeNode* root)
    {
        if(!root)  return;
        dfs(root->left);
        if(!node1 && prev->val >= root->val)   node1 = prev;
        if( node1 && prev->val >= root->val)   node2 = root;
        prev = root;
        dfs(root->right);
    }
};
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
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int, vector<int> > que;
        function<int(TreeNode*, int, int)> dfs = [&](TreeNode* root, int id, int deep){ return root ? que[deep].push_back(id), max({id+1-que[deep][0], dfs(root->left, id*2, deep+1), dfs(root->right, id*2+1, deep+1)}) : 0; };
        return dfs(root, 1, 0);
    }
};
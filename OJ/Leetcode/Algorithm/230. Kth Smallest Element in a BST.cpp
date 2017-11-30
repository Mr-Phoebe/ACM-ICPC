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
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
    int find(TreeNode* root, int& k) {
        if (root) {
            int x = find(root->left, k);
            return !k ? x : !--k ? root->val : find(root->right, k);
        }
        return -1;
    }
};

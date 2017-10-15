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
private:
    int maxToRoot(TreeNode *root, int &re) {
        if(!root) return 0;
        int l = maxToRoot(root->left, re);
        int r = maxToRoot(root->right, re);
        if(l < 0) l = 0;
        if(r < 0) r = 0;
        re = max(re, l + r + root->val);
        return root->val += max(l, r);
    }
public:
    int maxPathSum(TreeNode *root) {
        int max = INT_MIN;
        maxToRoot(root, max);
        return max;
    }
};

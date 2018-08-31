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
    /*
        Simple dfs question, using dfs can make sure from left to right but can't make sure from top to bottom.
    */
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<pair<TreeNode*, int>> que;
        unordered_map<int, vector<int>> mp;
        que.push(make_pair(root, 0));
        int mmax = 0x80000000;
        int mmin = 0x7fffffff;
        while(!que.empty()){
            TreeNode* cur_root = que.front().first;
            int cur_col = que.front().second;
            que.pop();

            mp[cur_col].push_back(cur_root->val);
            mmax = max(mmax, cur_col);
            mmin = min(mmin, cur_col);
            if (cur_root->left != NULL){
                que.push(make_pair(cur_root->left, cur_col -1));
            }
            if (cur_root->right != NULL){
                que.push(make_pair(cur_root->right, cur_col + 1));
            }
        }
        for (int i = mmin; i <= mmax; i++)
            res.push_back(mp[i]);
        return res;
    }
};

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int> > ans;
        int flag = 0;
        if(root)
            que.push(root);
        while(!que.empty())
        {
            vector<int> res(que.size());
            for(int i = 0; i < res.size(); i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                int index = flag ? res.size() - 1 - i : i;
                res[index] = cur->val;

                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            flag ^= 1;
            ans.push_back(res);
        }
        return ans;
    }
};

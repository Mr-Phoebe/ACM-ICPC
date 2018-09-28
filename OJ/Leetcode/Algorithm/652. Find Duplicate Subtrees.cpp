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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        vector<TreeNode*> ans;
        for(auto& item : mp)
        {
            if(item.second.size() > 1)
                ans.push_back(item.second[0]);
        }
        return ans;
    }
private:
    unordered_map<string, vector<TreeNode*> > mp;
    string dfs(TreeNode* root)
    {
        if(root == nullptr)
            return "#";
        string left = dfs(root->left);
        string right = dfs(root->right);
        string cur = to_string(root->val) + "," + left + "," + right;
        mp[cur].push_back(root);
        return cur;
    }
};

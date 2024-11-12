/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void reverseodd(TreeNode*root){
    queue<TreeNode*>q;
    if(!root){
        return ;
    }
    int level=0;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<TreeNode*> ans;
        ans.reserve(n<<1);
        for(int i=0;i<n;i++){
            TreeNode*temp=q.front();
            q.pop();
            ans.push_back(temp);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        if(level%2==1){
            int left=0 ,right=ans.size()-1;
            while(left<right){
                swap(ans[left]->val,ans[right]->val);
                left++;
                right--;
            }
        }
        level++;
    }
}
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*>ans;
        reverseodd(root);
        return root;
    }
};
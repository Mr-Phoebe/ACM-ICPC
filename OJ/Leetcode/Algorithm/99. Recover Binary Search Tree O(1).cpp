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
        TreeNode* cur = root,* pre = nullptr;
        while(cur)
        {
            if(cur->left == nullptr)
            {
                iserror(cur);
                last = cur;
                //printf("%d\n", last->val);
                cur = cur->right;
            }
            else
            {
                pre = cur->left;
                while(pre->right != nullptr && pre->right != cur)
                    pre = pre->right;

                if(pre->right == nullptr)
                {
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    pre->right = NULL;
                    iserror(cur);
                    last = cur;
                    //printf("%d\n", last->val);
                    cur = cur->right;
                }
            }
        }
        swap(node1->val, node2->val);
    }
private:
    TreeNode* node1 = nullptr;
    TreeNode* node2 = nullptr;
    TreeNode* last = new TreeNode(INT_MIN);
    void iserror(TreeNode* cur)
    {
        //printf("%d %d\n", last->val, cur->val);
        if(!node1 && last->val > cur->val)   node1 = last;
        if( node1 && last->val > cur->val)   node2 = cur;
    }
};
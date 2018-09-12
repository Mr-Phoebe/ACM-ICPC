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
    int closestValue(TreeNode* root, double target) {

        int ans;
        double diff = std::numeric_limits<double>::max();
        TreeNode* curr = root;

        while(curr!=NULL)
        {
            double currdiff = target - curr->val;

            if(abs(currdiff) < abs(diff)){
                diff = currdiff;
                ans = curr->val;
            }

            if(diff==0) return target;

            curr = currdiff>0 ? curr->right : curr->left;

        }

        return ans;
    }
};

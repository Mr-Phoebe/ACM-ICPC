/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* l;
    TreeNode* dfs(int n)
    {
        if(n == 0)  return nullptr;
        TreeNode* cur = new TreeNode(0);
        cur->left = dfs(n/2);
        cur->val = l->val;
        l = l->next;
        cur->right = dfs(n - n/2 -1);
        return cur;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int cnt = 0;
        l = head;
        ListNode* cur = head;
        while(cur)
        {
            cnt++;
            cur = cur->next;
        }
        return dfs(cnt);
    }
};

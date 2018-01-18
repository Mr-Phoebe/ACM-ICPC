/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)  return head;
        ListNode* nhead = new ListNode(INT_MIN);
        nhead->next = head;
        ListNode* pre = nhead;
        ListNode* last = nullptr;
        for(int i = 0; i < m; i++)
        {
            last = pre;
            pre = pre->next;
        }
        ListNode* cur = pre;
        pre = last;
        for(int i = 0; i < n-m+1; i++)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        last->next->next = cur;
        last->next = pre;
        return nhead->next;
    }
};
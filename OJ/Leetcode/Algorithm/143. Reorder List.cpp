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
    void reorderList(ListNode* head) {
        if(!head || !head->next)   return;
        ListNode* p1 = head, *p2 = head->next;
        
        while(p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        ListNode* tail = p1->next;
        p2 = tail->next;
        tail->next = p1->next = nullptr;
        
        while(p2)
        {
            p1 = p2->next;
            p2->next = tail;
            tail = p2;
            p2 = p1;
        }
        
        p1 = head;
        p2 = tail;
        while(p1)
        {
            ListNode* tmp = p1->next;
            p1 = p1->next = p2;
            p2 = tmp;
        }
        
    }
};

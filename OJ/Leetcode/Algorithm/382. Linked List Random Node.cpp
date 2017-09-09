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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = head->val, i = 2;  
        ListNode* cur = head->next;  
        while(cur)
        {  
            int j = rand() % i;  
            if(!j)
                res = cur->val;  
            i++;  
            cur = cur->next;  
        }  
        return res;  
        
    }
private:
    ListNode* head = nullptr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if(lists.empty())
            return NULL;

        int n = lists.size();
        while(n > 1)
        {
            int k = (n + 1) / 2;
            for(int i = 0; i < n / 2; i++)
            {
                lists[i] = merge2List(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }

    ListNode* merge2List(ListNode* n1, ListNode* n2)
    {
        ListNode dummy(0);
        ListNode* p = &dummy;
        while(n1 && n2)
        {
            if(n1->val < n2->val)
            {
                p->next = n1;
                n1 = n1->next;
            }
            else
            {
                p->next = n2;
                n2 = n2->next;
            }
            p = p->next;
        }

        if(n1)
            p->next = n1;
        else if(n2)
            p->next = n2;

        return dummy.next;
    }
};

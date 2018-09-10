/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* pre = head;
        if(pre == NULL)
        {
            Node* insert = new Node(insertVal, NULL);
            insert->next = insert;
            return insert;
        }
        Node* next = head->next;
        while(next != head)
        {
            if(pre->val <= insertVal && next->val >= insertVal)
                break;
            if(pre->val > next->val)
            {
                if(insertVal >= pre->val || insertVal <= next->val)
                    break;
            }
            pre = next;
            next = next->next;
        }
        Node* insert = new Node(insertVal, next);
        pre->next = insert;
        return head;
    }
};

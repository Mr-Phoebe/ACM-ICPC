/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *new_head, *l1, *l2;
        if (head == NULL) return NULL;
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l1->next = l2;
        }
        new_head = head->next;
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            if (l1->random != NULL) l1->next->random = l1->random->next;
        }
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next != NULL) l2->next = l2->next->next;
        }
        return new_head;
    }
};


/*
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> mp;
        // 创建一个新的链表头
        RandomListNode *new_head = new RandomListNode(head->label);
        // node1负责指向原链表，node2负责指向新链表
        RandomListNode *node1 = head, *node2 = new_head;
        // 按照原链表的结构不断创建新的节点，并维护好next指针，将node1与node2的对应关系保存到hash_map中，
        // 以备后面维护random指针的时候，可以通过node1找到对应的node2。
        while (node1->next != NULL) {
            mp[node1] = node2;
            node1 = node1->next;
            node2->next = new RandomListNode(node1->label);
            node2 = node2->next;
        }
        // 将两个链表的尾巴的对应关系也保存好
        mp[node1] = node2;
        
        // 继续从头开始处理random指针
        node1 = head;
        node2 = new_head;
        while (node1->next != NULL) {
            node2->random = mp[node1->random];
            node1 = node1->next;
            node2 = node2->next;
        }
        // 把尾巴的random指针也处理好
        node2->random = mp[node1->random];
        return new_head;
    }
};

*/

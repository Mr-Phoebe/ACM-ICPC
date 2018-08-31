/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        Node *prev = NULL, *head = NULL;
        dfs(root, prev, head);
        head->left = prev;
        prev->right = head;
        return head;
    }
private:
    void dfs(Node* root, Node*& prev, Node*& head)
    {
        if(!head && !root->left)
        {
            head = prev = root;
        }
        Node* left = root->left;
        Node* right = root->right;
        if(left)
            dfs(left, prev, head);
        if(prev)
        {
            prev->right = root;
            root->left = prev;
            prev = root;
        }
        if(right)
            dfs(right, prev, head);
    }
};

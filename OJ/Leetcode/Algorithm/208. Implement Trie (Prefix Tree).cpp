typedef struct Node{
    bool isend;
    Node* kids[26];
    Node()
    {
        isend = false;
        memset(kids, 0, sizeof(kids));
    }
}Node;
class Trie {
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(char c : word)
        {
            int key = c - 'a';
            if(!node->kids[key])
                node->kids[key] = new Node();
            node = node->kids[key];
        }
        node->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(char c : word)
        {
            int key = c - 'a';
            if(!node->kids[key])
                return false;
            node = node->kids[key];
        }
        return node->isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(char c : prefix)
        {
            int key = c - 'a';
            if(!node->kids[key])
                return false;
            node = node->kids[key];
        }
        for(int i = 0; i < 26; i++)
            if(node->kids[i])
                return true;
        return false | node->isend;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */


class TrieNode
{
public:
    bool isKey;
    TrieNode* children[26];
    TrieNode(): isKey(false)
    {
        memset(children, NULL, sizeof(TrieNode*) * 26);
    }
};

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word)
    {
        TrieNode* node = root;
        for(char c : word)
        {
            char key = c - 'a';
            if(!(node->children[key]))
                node->children[key] = new TrieNode();
            node = node->children[key];
        }
        node->isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word)
    {
        return query(word.c_str(), root);
    }

private:
    TrieNode* root;

    bool query(const char* word,TrieNode* root)
    {
        TrieNode* node = root;
        for(int i = 0; word[i]; i++)
        {
            if(node && word[i] != '.')
                node = node->children[word[i] - 'a'];
            else if(node && word[i] == '.')
            {
                TrieNode* tmp = node;
                for(int j = 0; j < 26; j++)
                {
                    node = tmp->children[j];
                    if(query(word+i+1, node))
                        return true;
                }
                return false;
            }
            else break;
        }
        
        return node && node->isKey;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


/*
class WordDictionary
{
public:
    // Initialize your data structure here. 
    WordDictionary()
    {

    }

    // Adds a word into the data structure. 
    void addWord(string word)
    {
        map[(int)word.length()].insert(word);
    }

    // Returns if the word is in the data structure. 
    //A word could contain the dot character '.' to represent any one letter. 
    bool search(string word)
    {
        int len = word.length();

        for(auto& s: map[len])
        {
            bool flag = true;
            for(int i = 0; i < s.length(); i++)
            {
                if(word[i] == '.')
                    continue;
                if(word[i] != s[i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                return true;
        }

        return false;
    }

private:
    unordered_map<int, unordered_set<string>> map;
};
*/
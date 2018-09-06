#define ALPHABET_SIZE 27
#define NUM_OF_TOPWORDS 3

class TrieNode {
public:
    TrieNode* child[ALPHABET_SIZE];
    int freq;
    vector<pair<int, string>> words;

    TrieNode() : freq(0)
    {
        for(auto& p: child) p = NULL;
    }
};

class Trie{
private:
    TrieNode* root;

    void updateTop3(TrieNode* p, string& word, int freq)
    {
        if(p == NULL) return;
        int i = 0, n = p->words.size();
        while(i < n && p->words[i].second != word) i++;
        if(i < n)
            p->words[i].first = freq;
        else
            p->words.push_back({freq, word});
        sort(p->words.begin(), p->words.end(), [](const auto& p1, const auto& p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        });
        if(p->words.size() > NUM_OF_TOPWORDS) p->words.pop_back();
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    int getChildIndex(char& c)
    {
        return (c == ' ') ? 0 : (c - 'a' + 1);
    }

    void insert(string& word, int freq)
    {
        TrieNode *p = root;
        for(char& c: word) {
            int idx = getChildIndex(c);
            if(p->child[idx] == NULL)
                p->child[idx] = new TrieNode();
            p = p->child[idx];
            updateTop3(p, word, freq);
        }
        p->freq = freq;
    }

    TrieNode* isPrefix(string& word)
    {
        TrieNode *p = root;
        for(char& c: word)
        {
            int idx = getChildIndex(c);
            if(p->child[idx] == NULL) return NULL;
            p = p->child[idx];
        }
        return p;
    }
};

class AutocompleteSystem {
private:
    Trie* trie;
    string path;

public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        trie = new Trie();
        for(int i = 0; i < sentences.size(); ++i)
            trie->insert(sentences[i], times[i]);
    }

    vector<string> input(char c) {
        vector<string> ans;
        auto p = trie->isPrefix(path);
        if(c == '#')
        {
            trie->insert(path, p == NULL ? 1 : p->freq + 1);
            path = "";
        }
        else
        {
            path += c;
            int idx = trie->getChildIndex(c);
            if(p != NULL && p->child[idx] != NULL)
                for(auto& v: p->child[idx]->words)
                    ans.push_back(v.second);
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */

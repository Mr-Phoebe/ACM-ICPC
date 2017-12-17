class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        mp.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto s : dict)
            mp.insert(s);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int n = word.length();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 26; j++)
            {
                string tmp = word;
                if(tmp[i] == j+'a') continue;
                tmp[i] = j+'a';
                if(mp.find(tmp) != mp.end())
                    return true;
            }
        return false;
    }
private:
    unordered_set<string> mp;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
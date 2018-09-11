class Solution {
public:
    unordered_map<string, vector<string>> m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(m.count(s))
            return m[s];
        if(s.empty())
            return {""};
        vector<string> res;
        for(string word : wordDict)
        {
            if(s.substr(0, word.size()) != word)
                continue;
            vector<string> rem = wordBreak(s.substr(word.size()), wordDict);
            for(string str : rem)
                res.push_back(word + (str.empty() ? "" : " ") + str);
        }
        return m[s] = res;
    }
};

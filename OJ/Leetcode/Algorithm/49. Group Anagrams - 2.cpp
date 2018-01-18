class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
        vector<vector<string>> anagrams;
        unordered_map<long long, multiset<string>> mp;
        for(string s : strs)
        {
            long long flag = 1;
            for(auto c : s)
                flag *= p[c-'a'];
            mp[flag].insert(s);
        }
        for(auto m : mp) 
        { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};
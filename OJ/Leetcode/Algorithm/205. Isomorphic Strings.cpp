class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;
        int n = s.length();
        if(n != t.length()) return false;
        for(int i = 0; i < n; i++)
        {
            if(mp1.count(s[i]) != 0 && mp1[s[i]] != t[i])
                return false;
            if(mp2.count(t[i]) != 0 && mp2[t[i]] != s[i])
                return false;
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};

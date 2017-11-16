class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ls = s.length();
        int lt = t.length();
        for (int i = 0; i < min(ls, lt); i++){
            if (s[i] != t[i]){
                if (s.substr(i+1) == t.substr(i+1))
                    return true;
                if (s.substr(i+1) == t.substr(i))
                    return true;
                if (s.substr(i) == t.substr(i+1))
                    return true;
                return false;
            }
        }
        return abs(ls - lt) == 1;
    }
};

class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        while(s.length()<n)
        {
            s += string(s[i++]-'0', s[s.length()-1]^3);
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};

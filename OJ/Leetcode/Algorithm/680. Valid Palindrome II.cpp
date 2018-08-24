class Solution {
public:
    bool validPalindrome(string s) {
        for(int i = 0, j = s.length()-1; i <= j; i++, j--)
        {
            if(s[i] != s[j])
            {
                int l = i+1, r = j;
                while(l <= r && s[l] == s[r])
                    l++, r--;
                if(l > r)
                    return true;
                l = i, r = j-1;
                while(l <= r && s[l] == s[r])
                    l++, r--;
                if(l > r)
                    return true;
                else
                    return false;
            }
        }
        return true;
    }
};

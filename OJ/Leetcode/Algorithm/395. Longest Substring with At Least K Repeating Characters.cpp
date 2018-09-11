class Solution {
public:
    int longestSubstring(string s, int k) {
        return divide(0, s.length()-1, s, k);
    }
private:
    int divide(int l, int r, const string& s, const int& k)
    {
        if(r < l || r - l + 1 < k)
            return 0;
        vector<int> cnt(26, 0);
        for(int i = l; i <= r; i++)
            cnt[s[i]-'a']++;

        for(int i = l; i <= r; i++)
        {
            if(cnt[s[i]-'a'] < k)
            {
                return max(divide(l, i-1, s, k), divide(i+1, r, s, k));
            }
        }
        return r-l+1;
    }
};

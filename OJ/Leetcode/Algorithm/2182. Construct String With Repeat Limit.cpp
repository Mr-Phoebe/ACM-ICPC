class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int cnt[33] = {};
        string ans;
        for(auto c : s)  {
            cnt[c - 'a']++;
        }
        while (true) {
            int i = 25;
            bool useOne = false;
            for (; i >= 0; i--) {
                if (ans.size() && i == ans.back() - 'a' && cnt[i]) {
                    useOne = true;
                    continue;
                }
                if (cnt[i] > 0)
                    break;
            }
            if (i == -1)
                break;
            int fill = useOne ? 1 : min(cnt[i], repeatLimit);
            cnt[i] -= fill;
            while (fill--) 
                ans += 'a' + i;
        }
        return ans;
    }
};
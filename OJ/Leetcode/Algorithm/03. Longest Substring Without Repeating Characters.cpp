class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, len = 0;
        if(!s.size())
            return ans;
        vector<bool> vis(300, false);
        for(int i = 0, j = 0; j < s.size(); ){
            if(!vis[s[j]]){
                vis[s[j++] ] = 1;
                len++;
            }else{
                vis[s[i++]] = 0;
                len--;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};
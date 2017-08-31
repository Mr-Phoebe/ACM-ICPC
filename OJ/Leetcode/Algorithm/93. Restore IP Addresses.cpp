class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        string res = "";
        dfs(s, 0, 0, res);
        return ans;
        /*
        categorized discussion method will be the fastest.
        */
    }
private:
    vector<string> ans;
    int n;
    void dfs(const string& s, int idx, int cnt, string res)
    {
        if(cnt == 4 && idx == n)
        {
            ans.push_back(res.substr(0, res.length()-1));
            return;
        }
        if(idx >= n || cnt >= 4)  return;
        if(cnt == 3 && s.length()-idx > 3) return;
        if(cnt == 2 && s.length()-idx > 6) return;
        
        for(int i = 1 ; i < 4; i++)
        {
            if(idx+i > s.length()) return;
            string tmp = s.substr(idx,i);
            if(isvalid(tmp))
                dfs(s, idx+i, cnt+1, res+tmp+".");
        }
        
    }
    bool isvalid(string s)
    {
        if(atoi(s.c_str()) >= 256 || (s[0] == '0' && s.length()>1))   return false;
        return true;
    }
};
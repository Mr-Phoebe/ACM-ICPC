class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, set<char> > suf, pre;
        set<char> st;
        string last = "";
        for(auto s : words)
        {
            st.insert(s.begin(), s.end());
            for(int j = 0; j < min(s.length(), last.length()); j++)
            {
                if(s[j] == last[j]) continue;
                suf[last[j]].insert(s[j]);
                pre[s[j]].insert(last[j]);
                break;
            }
            last = s;
        }
        set<char> em = st;
        for(auto item : pre)
            em.erase(item.first);
        string ans;
        while(!em.empty())
        {
            char a = *em.begin();
            em.erase(em.begin());
            for(auto b : suf[a])
            {
                pre[b].erase(a);
                if(pre[b].empty())
                    em.insert(b);
            }
            ans += a;
        }
        return ans.size() == st.size() ? ans : "";
    }
};

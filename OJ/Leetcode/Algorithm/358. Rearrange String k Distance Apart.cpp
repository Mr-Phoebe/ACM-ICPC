class Solution {
public:
    string rearrangeString(string s, int k) {
        int len = s.length();
        if(k == 0 || len == 0)  return s;
        unordered_map<char, int> mp;
        priority_queue<pair<int, char> > que;
        string ans = "";
        
        for(auto c : s) mp[c]++;
        for(auto it = mp.begin(); it != mp.end(); it++)
            que.push(make_pair(it->second, it->first));
        while(!que.empty())
        {
            vector<pair<int, char> > vis;
            int num = min(k, len);
            while(num--)
            {
                if(que.empty())
                {
                    if(ans.size() != s.size())
                        return string("");
                    else
                        return ans;
                }
                auto cur = que.top();que.pop();
                ans += cur.second;
                if(cur.first > 1)
                    vis.push_back(make_pair(cur.first-1, cur.second));
            }
            for(auto a : vis)
                que.push(a);
        }
        return ans;
    }
};

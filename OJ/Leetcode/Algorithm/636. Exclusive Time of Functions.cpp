class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int len = logs.size(), id, time, last;
        vector<int> ans(n);
        vector<int> fun;
        for(int i = 0; i < len; i++)
        {
            if(logs[i].find("start") != std::string::npos)
            {
                sscanf(logs[i].c_str(), "%d:start:%d", &id, &time);
                if(!fun.empty())
                    ans[fun[fun.size()-1]] += time-last;
                fun.push_back(id);
                last = time;
            }
            else
            {
                sscanf(logs[i].c_str(), "%d:end:%d", &id, &time);
                ans[fun[fun.size()-1]] += time-last+1;
                last = time+1;
                fun.pop_back();
            }
        }
        return ans;
    }
};
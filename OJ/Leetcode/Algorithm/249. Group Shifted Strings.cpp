class Solution {
    unordered_map<string, vector<string> > dic;
    string hash(string& s)
    {
        int minn = 'z';
        string ans = "";
        for(int i = 1; i < s.length(); i++)
            ans += char((s[i] - s[i-1] + 26)%26);
            
        return ans;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        for(auto s : strings)
        {
            string key = hash(s);
            dic[key].push_back(s);
        }
        for(auto vs : dic)
        {
            vector<string> ss = vs.second;
            sort(ss.begin(), ss.end());
            ans.push_back(ss);
        }
        return ans;
    }
};

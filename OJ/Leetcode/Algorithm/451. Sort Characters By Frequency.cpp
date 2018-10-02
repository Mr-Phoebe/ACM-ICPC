class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto ch : s)
            mp[ch]++;
        vector<pair<int, char> > ve;
        for(auto& item : mp)
            ve.push_back(make_pair(item.second, item.first));
        sort(ve.begin(), ve.end());
        string ans = "";
        for(int i = ve.size()-1; i >= 0; i--)
        {
            ans += string(ve[i].first, ve[i].second);
        }
        return ans;
    }
};

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> cnt;
        for(auto s : arr) {
            cnt[s]++;
        }
        for(auto s : arr) {
            if(cnt[s] == 1) {
                k--;
                if (k == 0) {
                    return s;
                } 
            }
        }
        return "";
    }
};
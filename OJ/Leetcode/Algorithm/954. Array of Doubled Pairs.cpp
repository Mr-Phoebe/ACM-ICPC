class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt;
        sort(arr.begin(), arr.end());
        for(auto a : arr) {
            // cout<<a<<" ";
            cnt[a]++;
        }
        // cout<<endl;
        int pos = lower_bound(arr.begin(), arr.end(), 0) - arr.begin();
        int negLength = pos;
        int posLength = n - pos;
        // cout<<negLength<<" "<<posLength<<endl;
        if((negLength&1) || (posLength&1)) {
            // One of the part are odd
            if(negLength > 2) {
                return false;
            }
        }
        // cout<<pos-1 << " "<<pos/2<<endl;
        for(int i = pos-1; i >= 0; i--) {
            // cout<<arr[i]<<endl;
            if(cnt[arr[i]] > 0) {
                if(cnt[arr[i]*2] == 0) {
                    return false;
                } else {
                    cnt[arr[i]]--;
                    cnt[arr[i]*2]--;
                }
            }
        }
        for(int i = pos; i < n; i++) {
            // cout<<arr[i]<<endl;
            if(cnt[arr[i]] > 0) {
                if(cnt[arr[i]*2] == 0) {
                    return false;
                } else {
                    cnt[arr[i]]--;
                    cnt[arr[i]*2]--;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int n = arr.size();
        list<int> ans;
        int l = pos-1, r = pos;
        while(k)
        {
            if(l < 0)
            {
                ans.push_back(arr[r]);r++;k--;
                continue;
            }
            if(r >= n)
            {
                ans.push_front(arr[l]);l--;k--;
                continue;
            }
            if(x-arr[l] <= arr[r]-x)
            {
                ans.push_front(arr[l]);l--;k--;
            }
            else
            {
                ans.push_back(arr[r]);r++;k--;
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};

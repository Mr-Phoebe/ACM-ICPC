class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n/2+1;
        vector<int> ans(n, 0);
        for(int pos = 0; i < n/2+1 || j < n; i++, j++) {
            if(i < n/2+1) {
                ans[pos++] = nums[i];
            }
            if(j < n) {
                ans[pos++] = nums[j];
            }
        }
        return ans;
    }
};
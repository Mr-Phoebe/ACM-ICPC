class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long> sumpre(n+1, 0);
        vector<long> sumsuf(n+1, 0);
        sumpre[0] = nums[0];
        for(int i = 1; i < n; i++) {
            sumpre[i] = sumpre[i-1] + nums[i];
        }
        sumsuf[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            sumsuf[i] = sumsuf[i+1] + nums[i];
        }
        int ans = 0;
        for(int i = 0; i < n-1; i++) {
            if(sumpre[i] >= sumsuf[i+1]) {
                ans++;
            }
        }
        return ans;
    }
};
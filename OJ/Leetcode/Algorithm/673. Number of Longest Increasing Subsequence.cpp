class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        vector<int> dp(nums.size());
        vector<int> cnt(nums.size());
        dp[0] = cnt[0] = 1;
        int res = 1, res_cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            int mmax = 0, ccnt = 0;
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i])
                    mmax = max(mmax, dp[j]);
            }
            for (int j = 0; j < i; j++){
                if ((nums[j] < nums[i]) && (dp[j] == mmax))
                    ccnt += cnt[j];
            }
            dp[i] = mmax + 1;
            ccnt == 0? (cnt[i] = 1):(cnt[i] = ccnt);
            cout<<cnt[i]<<endl;
        }
        for (int i = 0; i < nums.size(); i++)
            res = max(res, dp[i]);
        for (int i = 0; i < nums.size(); i++)
            if (dp[i] == res)
                res_cnt += cnt[i];
        cout<<res<<endl;
        return res_cnt;
    }
};
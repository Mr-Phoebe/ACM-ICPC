class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bool dp[20010] = {true};
        int sum = 0;
        for(auto num : nums)
            sum += num;
        if(sum&1)   return false;
        sum /= 2;
        for(auto num : nums)
            for(int j = sum; j >= num; j--)
                dp[j] |= dp[j-num];
        return dp[sum];
    }
};

/*
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<20000> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 0x1)
            return false;
        for (auto n : nums)
            bits |= bits<<n;
        return bits[sum>>1];
    }
};
*/

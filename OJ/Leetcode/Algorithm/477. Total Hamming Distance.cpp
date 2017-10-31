class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ones = 0, sum = 0;
        const int len = nums.size();
        for(int i = 0; i < 32; ++i)
        {
            ones = 0;
            for(int val: nums)
                ones += (val >> i) & 1;
            sum += (len - ones) * ones;
        }
        return sum;
    }
};

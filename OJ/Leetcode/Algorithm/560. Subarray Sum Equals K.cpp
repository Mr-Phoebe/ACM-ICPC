class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        map<int,int> rec; 
        int cnt = 0; 
        rec[sum]++; 
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            cnt += rec[sum-k];
            rec[sum]++;
        }
        return cnt;
    }
};

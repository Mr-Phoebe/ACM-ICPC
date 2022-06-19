class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        // if(n == 1) {
        //     return 1;
        // }
        int pos1, pos2;
        int val1 = INT_MAX, val2 = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(nums[i] < val1) {
                val1 = nums[i];
                pos1 = i;
            }
            if(nums[i] > val2) {
                val2 = nums[i];
                pos2 = i;
            }
        }
        int f1 = min(pos1, pos2);
        int f2 = max(pos1, pos2);
        int res1 = f1 + 1 + n - f2;
        int res2 = f2 + 1;
        int res3 = n - f1;
        return min(res1, min(res2, res3));
    }
};
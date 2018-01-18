/*
* @Author: Haonan Wu
* @Date:   2017-09-09 21:36:52
* @Last Modified by:   lenovo
* @Last Modified time: 2017-09-09 21:36:56
*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)  return n;
        int ans = 1, cur = 1;
        for(int i = 1; i < n; i++)
            if(nums[i] > nums[i-1])
                cur++, ans = max(ans, cur);
            else
                cur = 1;
        return ans;
    }
};
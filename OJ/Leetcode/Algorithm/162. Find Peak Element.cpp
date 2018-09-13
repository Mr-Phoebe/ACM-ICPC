class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = nums.size();
        while(l+1 < r)
        {
            int mid = (l+r)>>1;
            int left = mid == 0 ? INT_MIN : nums[mid-1];
            int right = mid == n ? INT_MIN : nums[mid+1];
            int cur = nums[mid];
            if(cur > right && cur > left || (l == r))
                return mid;
            if(right > cur && cur > left)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};

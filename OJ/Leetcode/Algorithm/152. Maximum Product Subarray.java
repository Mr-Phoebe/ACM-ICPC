class Solution {
    public int maxProduct(int[] nums) {
        int ans = nums[0];
        int p = nums[0];
        int previous = 0;
        for(int i = 1; i < nums.length; i++)
        {
            if(p < 0 && previous == 0)
                previous = p;       // If the last item is negative, record the product

            if(nums[i-1] == 0 && nums[i] != 0)
            {
                p = nums[i];
                previous = 0;
            }
            else
                p *= nums[i];

            if(p < 0 && previous < 0)
                ans = Math.max(ans, p / previous);
            else
                ans = Math.max(ans, p);
        }
        return ans;
    }
}

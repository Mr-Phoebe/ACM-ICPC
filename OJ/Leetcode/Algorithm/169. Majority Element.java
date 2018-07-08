class Solution {
    public int majorityElement(int[] nums) {
        int ans = nums[0];
        int cnt = 0;
        for(int i : nums) {
            if(cnt == 0)
                ans = i;
            if(ans == i)
                cnt++;
            else
                cnt--;
        }
        return ans;
    }
}

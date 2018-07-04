class Solution {
    private int divideAndConquer(long[] sum, int l, int r, int low, int upp)
    {
        if(r - l <= 1)
            return 0;
        int mid = (r-l>>1) + l;
        int cnt = divideAndConquer(sum, l, mid, low, upp) + divideAndConquer(sum, mid, r, low, upp);
        for(int i = l, n = mid, m = mid; i < mid; i++)
        {
            while(n < r && sum[n] - sum[i] <= upp) n++;
            while(m < r && sum[m] - sum[i] <  low) m++;
            cnt += n - m;
        }
        Arrays.sort(sum, l, r);
        return cnt;
    }
    public int countRangeSum(int[] nums, int lower, int upper) {
        long[] sum = new long[nums.length+1];
        for(int i = 1; i <= nums.length; i++)
            sum[i] = sum[i-1] + nums[i-1];
        return divideAndConquer(sum, 0, nums.length+1, lower, upper);
    }

}

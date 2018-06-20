class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length, maxx = -1, maxi = 0;
        List<Integer> res = new ArrayList<Integer>();

        if(n == 0)
            return res;

        int[] cnt = new int[n];
        int[] pre = new int[n];
        Arrays.fill(pre, -1);
        Arrays.fill(cnt, 0);
        Arrays.sort(nums);

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] % nums[j] == 0)
                {
                    if(cnt[j] + 1 > cnt[i])
                    {
                        cnt[i] = cnt[j] + 1;
                        pre[i] = j;
                    }
                    if(cnt[i] > maxx)
                    {
                        maxx = cnt[i];
                        maxi = i;
                    }
                }
            }
        }
        do
        {
            res.add(nums[maxi]);
            maxi = pre[maxi];
        }while(maxi != -1);
        return res;
    }
}

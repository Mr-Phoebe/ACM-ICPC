class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] ugly = new int[n];
        ugly[0] = 1;
        int[] cnt = new int[primes.length];
        for(int i = 1; i < n; i++)
        {
            int min = Integer.MAX_VALUE;
            int index = -1;
            for(int j = 0; j < primes.length; j++)
            {
                if(min > ugly[cnt[j]] * primes[j] && ugly[cnt[j]] * primes[j] > 0)
                {
                    min = ugly[cnt[j]] * primes[j];
                    index = j;
                }
                else if(min == ugly[cnt[j]] * primes[j])
                {
                    cnt[j] += 1;
                }
            }
            ugly[i] = min;
            cnt[index] += 1;
        }
        return ugly[n-1];
    }
}

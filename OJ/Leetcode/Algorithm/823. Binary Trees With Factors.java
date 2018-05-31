class Solution {
    public int numFactoredBinaryTrees(int[] A) {
        long ans = 0;
        final long MOD = (long)1e9+7;
        Arrays.sort(A);
        HashMap<Integer, Long> dp = new HashMap<>();
        for(int i = 0 ; i < A.length; i++)
        {
            dp.put(A[i], 1L);
            for(int j = 0; j < i; j++)
            {
                if(A[i] % A[j] == 0 && dp.containsKey(A[i] / A[j]))
                {
                    dp.put(A[i], (dp.get(A[i]) + dp.get(A[j]) * dp.get(A[i] / A[j]) )% MOD);
                }
            }
        }
        for(long i : dp.values())
            ans = (ans + i) % MOD;
        return (int)ans;
    }
}

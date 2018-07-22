class Solution {
    public int primePalindrome(int N) {
        while (N < Integer.MAX_VALUE)
        {
            N = nextPalin("" + N);
            if (isPrime(N))
                return N;
            N++;
        }
        return -1;
    }
    private int nextPalin(String n)
    {
        int l = n.length();
        List<Integer> cands = new LinkedList<>();
        int half = Integer.valueOf(n.substring(0, (l + 1) / 2));
        for(int i = half; i <= half + 1; i++)
        {
            String halfString = "" + i;
            if(l % 2 == 1)
                halfString = halfString.substring(0, halfString.length() - 1);
            String newString = "" + i + new StringBuilder(halfString).reverse().toString();
            System.out.println(newString);
            cands.add(Integer.valueOf(newString));
        }
        int ori = Integer.valueOf(n), result = Integer.MAX_VALUE;
        for(int cand : cands)
            if(cand >= ori && cand < result)
                result = cand;

        return result;
    }
    private boolean isPrime(int n)
    {
        if(n <= 1)
            return false;
        long l = (long)n;
        for(long i = 2; i * i <= l; i++)
            if(l % i == 0)
                return false;
        return true;
    }
}

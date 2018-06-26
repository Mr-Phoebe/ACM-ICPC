class Solution {
    private Map<String, Integer> map = new HashMap<>();
    public int kSimilarity(String A, String B) {
        map.put(B, 0);
        return dp(A.toCharArray(), B, 0);
    }

    private int dp(char[] a, String b, int i)
    {
        String sa = new String(a);
        if(map.containsKey(sa))
            return map.get(sa);
        int minn = Integer.MAX_VALUE;
        while(i < a.length && a[i] == b.charAt(i)) i++;
        for(int j = i+1; j < a.length; j++)
        {
            if(a[j] == b.charAt(i))
            {
                swap(a, i, j);
                int step = dp(a, b, i+1);
                if(step < Integer.MAX_VALUE)
                    minn = Math.min(minn, step + 1);
                swap(a, i, j);
            }
        }
        map.put(sa, minn);
        return minn;
    }
    private void swap(char[] a, int i, int j) {
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

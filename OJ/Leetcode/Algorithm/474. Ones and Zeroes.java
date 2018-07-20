class Solution {
    public int findMaxForm(String[] strs, int m, int n) {

        int[][][] dp = new int[strs.length+1][m+1][n+1];
        for(int i = 1; i <= strs.length; i++)
        {
            int[] cnt = w(strs[i-1]);
            for(int mi = 0; mi <= m; mi++)
            {
                for(int ni = 0; ni <= n; ni++)
                {
                    if(mi == 0 && ni == 0)
                        dp[i][mi][ni] = 0;
                    else if(cnt[0] <= mi && cnt[1] <= ni)
                        dp[i][mi][ni] = Math.max(1 + dp[i-1][mi-cnt[0]][ni-cnt[1]], dp[i-1][mi][ni]);
                    else
                        dp[i][mi][ni] = dp[i-1][mi][ni];
                }
            }
        }

        return dp[strs.length][m][n];
    }

    int[] w(String s)
    {
        int[] i = new int[2];
        for(char c: s.toCharArray())
            i[(c == '0' ? 0 : 1)]++;
        return i;
    }
}

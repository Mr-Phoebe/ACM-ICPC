class Solution {
    private int[] fa = new int[2001];
    public int[] findRedundantConnection(int[][] edges) {
        for(int i = 0; i < 2001; i++)
            fa[i] = i;
        int[] ans = new int[2];
        for(int i = 0; i < edges.length; i++)
        {
            int a = find(edges[i][0]), b = find(edges[i][1]);
            if(a == b)
            {
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
            }
            else
            {
                fa[a] = b;
            }
        }
        return ans;
    }
    private int find(int x) {
        if(x != fa[x])
            fa[x] = find(fa[x]);
        return fa[x];
    }
}

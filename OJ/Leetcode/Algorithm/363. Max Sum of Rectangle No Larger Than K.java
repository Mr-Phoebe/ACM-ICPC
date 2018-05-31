
class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        if(matrix.length == 0 || matrix[0].length == 0)
            return 0;
        int row = matrix.length;
        int col = matrix[0].length;
        int m = Math.min(row, col);
        int n = Math.max(row, col);
        boolean colIsBig = col > row;

        int ans= Integer.MIN_VALUE;
        for(int i = 0; i < m; i++)
        {
            int[] sum = new int[n];
            for(int j = i; j >= 0; j--)
            {
                int val = 0;
                TreeSet<Integer> set = new TreeSet<Integer>();
                set.add(0);
                for(int q = 0; q < n; q++)
                {
                    sum[q] = sum[q] + (colIsBig ? matrix[j][q] : matrix[q][j]);
                    val += sum[q];
                    Integer subres = set.ceiling(val - k);
                    if(subres != null)
                        ans = Math.max(ans, val - subres);
                    set.add(val);
                }
            }
        }
        return ans;
    }
}

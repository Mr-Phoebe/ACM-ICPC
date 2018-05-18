class Solution {
    static int[][] tmpIndex;
    public int longestIncreasingPath(int[][] matrix) {
        if(matrix==null || matrix.length==0) return 0;
        int tmp=0;
        tmpIndex=new int[matrix.length][matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if(tmpIndex[i][j]==0) {
                    int tmpNum=longestIncreasingPath(matrix,i,j,-1);
                    if(tmpNum > tmp) tmp=tmpNum;
                }
            }
        }

        return tmp;
    }
      private static int longestIncreasingPath(int[][] matrix,int row,int team,int num) {
        if(row < 0 || row ==matrix.length || team < 0 || team == matrix[row].length) return 0;
        if(matrix[row][team] <= num) return 0;
        if(tmpIndex[row][team] > 0) return tmpIndex[row][team];

        int goUp= longestIncreasingPath(matrix,row-1,team,matrix[row][team])+1;
        int goRight= longestIncreasingPath(matrix,row,team+1,matrix[row][team])+1;
        int goDown= longestIncreasingPath(matrix,row+1,team,matrix[row][team])+1;
        int goLeft= longestIncreasingPath(matrix,row,team-1,matrix[row][team])+1;

        tmpIndex[row][team]=Math.max(goUp, Math.max(goRight, Math.max(goDown, goLeft)));

        return tmpIndex[row][team];
    }
}

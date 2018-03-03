public int maxCount(int m, int n, int[][] ops) {  
    // 初始化为m,n可以省略if，否则不可省  
    int row = m;  
    int col = n;  
    for (int[] op : ops) {  
        // op[0]是横坐标  
        row = Math.min(row, op[0]);  
        // op[1]是纵坐标  
        col = Math.min(col, op[1]);  
    }  
    // row * col是左上角的元素个数  
    return row * col;  
}  

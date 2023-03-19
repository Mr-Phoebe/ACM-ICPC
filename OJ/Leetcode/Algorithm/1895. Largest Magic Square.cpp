class Solution {
public:
    int m, n;
    vector<vector<int>> preSumRow, preSumCol;
    int largestMagicSquare(vector<vector<int>> &grid) {
        m = grid.size(); 
        n = grid[0].size();
        preSumRow = vector(m, vector<int>(n + 1, 0)); 
        preSumCol = vector(n, vector<int>(m + 1, 0));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                preSumRow[r][c + 1] = preSumRow[r][c] + grid[r][c];
                preSumCol[c][r + 1] = preSumCol[c][r] + grid[r][c];
            }
        }
        for (int k = min(m, n); k >= 2; k--) 
            if (test(grid, k)) 
                return k;
        return 1;
    }
    bool test(vector<vector<int>> &grid, int k) {
        for (int r = 0; r + k - 1 < m; ++r) {
            for (int c = 0; c + k - 1 < n; ++c) {
                int sum = getSumRow(r, c, c + k - 1);
                int sum2 = getSumCol(c, r, r + k - 1);
                bool match = sum == sum2;
                for (int nr = r + 1; nr < r + k && match; ++nr) {
                    match = sum == getSumRow(nr, c, c + k - 1);
                }
                for (int nc = c + 1; nc < c + k && match; ++nc) {
                    match = sum == getSumCol(nc, r, r + k - 1);
                }
                int diag = 0, antiDiag = 0;
                for (int d = 0; d < k && match; ++d) {
                    diag += grid[r + d][c + d];
                    antiDiag += grid[r + d][c + k - 1 - d];
                }
                match = match && (diag == sum && diag == antiDiag);
                if (match) 
                    return true;
            }
        }
        return false;
    }
    int getSumRow(int row, int l, int r) {
        return preSumRow[row][r + 1] - preSumRow[row][l];
    }
    int getSumCol(int col, int l, int r) {
        return preSumCol[col][r + 1] - preSumCol[col][l];
    }
};
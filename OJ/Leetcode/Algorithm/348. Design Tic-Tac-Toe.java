public class TicTacToe {
    int n;
    int[] rows;
    int[] cols;
    int diagonal;
    int anti_diagonal;
    int wins;
    /** Initialize your data structure here. */
    public TicTacToe(int n) {
        this.n = n;
        rows = new int[n];
        cols = new int[n];
        diagonal = 0;
        anti_diagonal = 0;
        wins = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    public int move(int row, int col, int player) {
        if (player == 1) {
            rows[row]++;
            cols[col]++;
            if (row == col)
                diagonal++;
            if (row + col == n - 1)
                anti_diagonal++;
        }
        else if (player == 2) {
            rows[row]--;
            cols[col]--;
            if (row == col)
                diagonal--;
            if (row + col == n - 1)
                anti_diagonal--;
        }
        if (rows[row] == n || cols[col] == n || diagonal == n || anti_diagonal == n)
            wins = 1;
        else if (rows[row] == -n || cols[col] == -n || diagonal == -n || anti_diagonal == -n)
            wins = 2;
        return wins;
    }
}

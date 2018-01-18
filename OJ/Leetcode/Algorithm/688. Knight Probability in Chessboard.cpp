class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        double dp[2][30][30];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[0][i][j] = 0.0;
            }
        }
        dp[0][r][c] = 1.0;
        int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
        for (int i = 1; i <= K; i++) {
            int a = i % 2;
            int b = a ^ 1;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dp[a][i][j] = 0;
                    for (int d = 0; d < 8; d++) {
                        int x = i + dx[d];
                        int y = j + dy[d];
                        if (x >= 0 && x < N && y >= 0 && y < N)
                            dp[a][i][j] += dp[b][x][y] / 8;
                    }
                }
            }
        }
        double result = 0.0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result += dp[K % 2][i][j];
            }
        }
        return result;
    }
};
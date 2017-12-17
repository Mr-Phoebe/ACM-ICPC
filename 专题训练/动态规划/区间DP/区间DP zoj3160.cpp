#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
    
int main()
{
    int n, m, i, j, k, l, a[512], dp[303][303];
    char g[512][512];
    
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(g, 0, sizeof(g)), memset(dp, 0, sizeof(dp));
        while (m--)
            scanf("%d %d", &i, &j), g[i][j] = g[j][i] = 1;
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (l = 1; l < n; l++)
            for (i = 0, j = i + l; i + l < n; i++, j = i + l) {
                if (g[a[i]][a[j]] && (j == i + 1 || dp[i + 1][j - 1] == j - i - 1))
                    dp[i][j] = j - i + 1;
                if (!dp[i][j])
                    for (k = i; k < j; k++)
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        printf("%d\n", dp[0][n - 1]);
    }
    return 0;
}
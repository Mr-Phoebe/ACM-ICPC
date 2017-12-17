//By Lh
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int MOD = 10000007;

typedef long long LL;

int n, m;
LL a[15][15], c[15][15], f[15][15];

int main()
{
    int i, j, k;

    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(a, 0, sizeof(a));
        for (i = 1; i <= n; i++) scanf("%d", &a[i][1]);
        a[n+1][1] = 23; a[n+2][1] = 3;
        memset(f, 0, sizeof(f));
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= i; j++) f[i][j] = 1;
            f[i][n+1] = 10; f[i][n+2] = 1;
        }
        f[n+1][n+1] = 10; f[n+1][n+2] = 1; f[n+2][n+2] = 1;
        while (m > 0)
        {
            if ((m&1) == 1)
            {
                memset(c, 0, sizeof(c));
                for (i = 1; i <= n+2; i++)
                for (j = 1; j <= n+2; j++)
                for (k = 1; k <= n+2; k++) c[i][j] = (c[i][j] + f[i][k]*a[k][j])%MOD;
                for (i = 1; i <= n+2; i++)
                for (j = 1; j <= n+2; j++) a[i][j] = c[i][j];
            }
            m >>= 1;
            memset(c, 0, sizeof(c));
            for (i = 1; i <= n+2; i++)
            for (j = 1; j <= n+2; j++)
            for (k = 1; k <= n+2; k++) c[i][j] = (c[i][j] + f[i][k]*f[k][j])%MOD;
            for (i = 1; i <= n+2; i++)
            for (j = 1; j <= n+2; j++) f[i][j] = c[i][j];
        }
        printf("%I64d\n", a[n][1]);
    }
    return 0;
}

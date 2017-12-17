//By LH
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

LL dp[2][1 << 22];
int num[44];

int main()
{
    int t, n, m, icase = 1;
    LL ans;
    scanf("%d", &t);
    while (t--)
    {
        memset (dp, 0, sizeof(dp));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= (1 << 20); j++)
                dp[i % 2][j] = dp[1 - (i % 2)][j] + dp[1 - (i % 2)][j ^ num[i]];
        ans = 0;
        for (int i = m; i <= (1 << 20); i++)
            ans += dp[n % 2][i];
        printf("Case #%d: %I64d\n", icase++, ans);
    }
    return 0;
}

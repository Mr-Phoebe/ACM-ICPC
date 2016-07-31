//By LH
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

int n, a[205], b[205];
LL f[205][205];

LL dp(int x, int y)
{
    int i;
    LL tmp, now;

    if (f[x][y] != -1) return f[x][y];
    if (x+1 == y) return 0;
    tmp = 1000000000;
    for (i = x+1; i < y; i++)
    {
        now = dp(x, i) + dp(i, y) + a[i]+b[x]+b[y];
        tmp = min(now, tmp);
    }
    f[x][y] = tmp;
    return f[x][y];
}

int main()
{
    int i, T, cnt;

    scanf("%d", &T);
    cnt = 0;
    while (T--)
    {
        cnt++;
        scanf("%d", &n);
        for (i = 1; i <= n; i++) scanf("%d", &a[i]);
        a[0] = 0; a[n+1] = 0;
        for (i = 1; i <= n; i++) scanf("%d", &b[i]);
        b[0] = 0; b[n+1] = 0;
        memset(f, -1, sizeof(f));
        printf("Case #%d: %I64d\n", cnt, dp(0, n+1));
    }
    return 0;
}

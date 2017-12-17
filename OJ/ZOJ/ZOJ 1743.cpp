#include <bits/stdc++.h>

using namespace std;

struct node
{
    int l, r, c;
    friend bool operator < (node a, node b)
    {
        return a.r < b.r;
    }
};

node a[1010];
int dp[400][400];

int main()
{
    int n;
    a[0].l = a[0].r = a[0].c = 0;
    while(scanf("%d", &n) && n)
    {
        ++n;
        for(int i = 1; i < n; ++i)
            scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].c);
        sort(a, a+n);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i < n; ++i)
        {
            for(int j = a[i-1].r+1; j <= a[i].r; ++j)
                for(int k = 0; k <= a[i].r; ++k)
                    dp[j][k] = dp[j-1][k], dp[k][j] = dp[k][j-1];
            for(int j = a[i].r; j >= 0; --j)
            {
                dp[j][a[i].r] = max(dp[j][a[i].r], dp[j][a[i].l-1] + a[i].c);
                dp[a[i].r][j] = max(dp[a[i].r][j], dp[a[i].l-1][j] + a[i].c);
            }
        }
        printf("%d\n", dp[a[n-1].r][a[n-1].r]);
    }
    return 0;
}

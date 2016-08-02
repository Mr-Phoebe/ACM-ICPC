#include <bits/stdc++.h>

using namespace std;

double dp[100010];

int main()
{
    int n, m;
    scanf("%d%d", &n,&m);
    dp[1] = 1;
    for(int i = 2; i <= m; ++i)
        dp[i] = (1-dp[i-1]) * dp[i-1] + dp[i-1] * (dp[i-1] - 1.0/n);
    double ans = 0;
    for(int i = 1; i <= m; ++i)
        ans += dp[i];
    printf("%.17f\n", ans);
    return 0;
}

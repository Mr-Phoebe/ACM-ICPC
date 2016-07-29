#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[100005];
ll ans, f[100005][205];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%x", &a[i]);
    for (int i = 1; i <= n; i++)
    for (int j = 0; j<= min(i, 200); j++)
    {
        if (j > 0) f[i][j] = f[i-1][j-1];
        f[i][j] = max(f[i][j], f[i-1][j]+(a[i]^(i-j-1)));
        ans = max(f[i][j], ans);
    }
    printf("%lld\n", ans);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long a[4][4010], b[4010*4010];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int j = 0; j < n; ++j)
            for(int i = 0; i < 4; ++i)
                scanf("%lld", &a[i][j]);
        int len = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                b[len++] = a[0][i]+a[1][j];
        sort(b, b+n*n);
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
            {
                long long sum = a[2][i]+a[3][j];
                ans += upper_bound(b, b+len, -sum) - lower_bound(b, b+len, -sum);
            }
        printf("%d\n", ans);
        if(T != 0)
            puts("");
    }
    return 0;
}

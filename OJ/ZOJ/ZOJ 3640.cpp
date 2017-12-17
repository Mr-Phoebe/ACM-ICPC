#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

double dp[10010*2];
int c[10010], f[10010];

int main()
{
    int n, init;
    while(scanf("%d%d", &n, &init) > 0)
    {
        int max_c = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &c[i]);
            max_c = max(max_c, c[i]);
            f[i] = (1.0+sqrt(5))/2.0 * c[i] * c[i] + eps;
        }
        if(init > max_c)
        {
            int sum = 0;
            for(int i = 0; i < n; i++)
                sum += f[i];
            printf("%.3f\n", sum*1.0/n);
        }
        else
        {
            for(int i = max_c*2; i >= init; i--)
            {
                dp[i] = 0;
                for(int j = 0; j < n; j++)
                    if(i > c[j])
                        dp[i] += f[j];
                    else
                        dp[i] += dp[i+c[j]] + 1;
                dp[i]/=n;
            }
            printf("%.3f\n", dp[init]);
        }
    }
    return 0;
}

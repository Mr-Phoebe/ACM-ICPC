#include <bits/stdc++.h>

using namespace std;

double dp[55][55];
double power[110], npower[110];
long long c[55][55];
int n, m;

double dfs(int i, int j)
{
    if(i >= m && j >= m)
        return 0;
    double &ret = dp[i][j];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int k = i; k <= n; k++)
        for(int l = j; l <= n; l++)
            if(k != i || l != j)
                ret += dfs(l, k) * power[k+l-i-j] * npower[2*n-k-l+i+j] * c[n-i][k-i] * c[n-j][l-j];
    return ret = (ret + 1) / (1 - npower[2*n-i-j]);
}

int main()
{
    for(int i = 0; i <= 50; i++)
    {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; ++j)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
    power[0] = npower[0] = 1;
    double p;
    while(scanf("%d%d%lf", &n, &m, &p) && n)
    {
        for(int i = 1; i <= 2*n; i++)
            power[i] = power[i-1] * p, npower[i] = npower[i-1] * (1-p);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                dp[i][j] = -1;
        printf("%.6f\n", dfs(0, 0));
    }
    return 0;
}

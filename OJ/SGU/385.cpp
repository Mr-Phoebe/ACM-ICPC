#include <bits/stdc++.h>

using namespace std;

double dp[110][110][110], a[110][110], sum[110][110];
int n;

void init()
{
    for(int i = 1; i <= 100; ++i)
    {
        a[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            a[i][j] = a[i][j-1]*(i-j+1);
    }
}

double getdp(int i, int j, int k);

double getsum(int i, int j)
{
    double &ret = sum[i][j];
    if(ret >= 0)
        return ret;
    ret = 0;
    if(j > i)
        return ret;
    for(int k = 1; k*j <= i; ++k)
        ret += getdp(i, j, k);
    return ret;
}

double getdp(int i, int j, int k)
{
    double &ret = dp[i][j][k];
    if(ret >= 0)
        return ret;
    if(i <= 1 || j <= 1 || k <= 0 || k*j > i || j > i)
        return ret = 0;
    if(i == j && k == 1)
        return ret = a[n][i] / i;
    ret = getdp(i-j, j, k-1) * a[n-i+j][j] / j / k;
    if(k == 1)
    {
        double p = a[n-i+j][j] / j;
        for(int l = 2; l <= i-j && l <= j-1; ++l)
            ret += getsum(i-j, l) * p;
    }
    return ret;
}

int main()
{
    init();
    scanf("%d", &n);
    memset(dp, -1, sizeof dp);
    memset(sum, -1, sizeof sum);
    double p = 0, pp = 0;
    for(int i = 2; i <= n; ++i)
        for(int j = 1; j*i <= n; ++j)
            p += i*j*getdp(n, i, j), pp += getdp(n, i, j);
    printf("%.11f\n", p/pp);
    return 0;
}

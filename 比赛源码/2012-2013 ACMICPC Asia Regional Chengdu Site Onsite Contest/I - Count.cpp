#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000000007

using namespace std;

int n,cas = 0;

long long dp[1005];

void make()
{
    memset(dp,0,sizeof(dp));
    dp[1] = 1;
    for(int i=2;i<=1000;i++)
        for(int j=1;j<=1000;j++)
        if((i-1) % j == 0)
        dp[i] = (dp[i]+dp[(i-1)/j])%MOD;
}

int main()
{
    make();

    while(~scanf("%d",&n))
    {
        printf("Case %d: %I64d\n",++cas,dp[n]);
    }
    return 0;
}
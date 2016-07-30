#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MOD=1000000007;
int dp[2002][2002];
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        memset(dp,0,sizeof(dp));
        for (int i = 1; i <= n; i++)
            dp[1][i] = 1;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int z = j; z <= n; z+=j)
                {
                    dp[i][z] = (dp[i][z]+dp[i-1][j])%MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans+=dp[k][i];
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
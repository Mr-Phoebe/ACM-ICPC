#include<cstdio>
#include<cstring>

typedef __int64 LL;
#define mod 1000000007
const int MAXN = 1002;
const int MAXA = 1025;
int dp1[MAXN][MAXA], dp2[MAXN][MAXA], dp3[MAXN][MAXA];
int a[MAXN];

int main()
{
    int T, n, i, j, t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i = 0; i < n; i++)
            scanf("%d",&a[i]);
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        memset(dp3, 0, sizeof(dp3));
        dp1[0][a[0]] = 1;
        for(i = 1; i < n - 1; i++)
        {
            dp1[i][a[i]]++; //单独一个元素构成一个集合
            for(j = 0; j < MAXA; j++)
            {
                if(dp1[i-1][j])
                {
                    dp1[i][j] += dp1[i-1][j]; //不添加第i个元素进行异或,继承之前算好的
                    dp1[i][j] %= mod;

                    t = j ^ a[i];  //添加第i个元素进行异或
                    dp1[i][t] += dp1[i-1][j];
                    dp1[i][t] %= mod;
                }
            }
        }
        dp2[n-1][a[n-1]] = 1;
        dp3[n-1][a[n-1]] = 1;
        for(i = n-2; i > 0; i--)
        {
            dp2[i][a[i]]++;
            dp3[i][a[i]]++;   //单独一个元素构成一个集合
            for(j = 0; j < MAXA; j++)
            {
                if(dp2[i+1][j])
                {
                    dp2[i][j] += dp2[i+1][j];  //不添加第i个元素进行按位与
                    dp2[i][j] %= mod;

                    t = j & a[i]; //添加第i个元素进行按位与
                    dp2[i][t] += dp2[i+1][j];
                    dp2[i][t] %= mod;

                    dp3[i][t] += dp2[i+1][j]; //添加第i个元素进行按位与
                    dp3[i][t] %= mod;
                }
            }
        }
        int ans = 0;
        for(i = 0; i < n - 1; i++)
        {
            for(j = 0; j < MAXA; j++)
            {
                if(dp1[i][j] && dp3[i+1][j])
                {
                    ans += (LL(dp1[i][j]) * dp3[i+1][j] % mod);
                    ans %= mod;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

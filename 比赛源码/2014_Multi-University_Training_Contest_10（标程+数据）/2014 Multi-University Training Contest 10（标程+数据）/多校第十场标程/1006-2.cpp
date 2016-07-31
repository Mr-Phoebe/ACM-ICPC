#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int v[1005],a[1005];
int dp[1005][2005];
int main()
{
    int T,n;
    scanf("%d",&T);
    rep(cas,T)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int maxn = a[n-1];
        memset(v,0,sizeof(v));
        for(int i=0; i<n; i++)
        {
            int val = 1;
            int to = a[i];
            while(v[to] && to>=1)
            {
                to--;
                val++;
            }
            if(to!=0)
                v[to] = val;
        }
        memset(dp,-1,sizeof(dp));
        dp[0][0] = 0;
        for(int i=1;i<=maxn;i++)
        {
            for(int j=0;j<=maxn;j++)
            {
                if((v[i]>=0) && (j-1>=0) && (dp[i-1][j-1]!=-1))//≤ª ’
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
                if((v[i]>0) && (j+v[i]-1>=0) && (dp[i-1][j+v[i]-1]!=-1))// ’
                    dp[i][j] = max(dp[i][j],dp[i-1][j+v[i]-1]+1);
            }
        }
        int ret = 0;
        for(int i=0;i<=maxn;i++)
            ret = max(ret,dp[maxn][i]);
        printf("Case #%d: %d\n",cas+1,ret);
    }
}

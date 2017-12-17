#include <cstdio>
#define MAXN 500005
#define For(i,m,n) for(int i=(m);i<(n);i++)
#define LL long long
#define UI unsigned int

/*author birdstorm*/
using namespace std;
UI dp[MAXN];

void solve()
{
    for(LL i=1; i<MAXN; ++i)
    {
        dp[i]+=dp[i-1];
        for(LL j=i; j<MAXN; j+=i)
            dp[j]+=(UI)j*(UI)((j/i+1LL)*(j/i)/2LL);
    }
}

int main()
{
    solve();
    int t, n, cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case #%d: %u\n",cs++,dp[n]);
    }
    return 0;
}


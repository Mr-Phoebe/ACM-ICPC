#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>

#define MAXN 500005
#define ll unsigned int
using namespace std;

ll dp[MAXN], f[MAXN], sum[MAXN];
vector<ll> dx[MAXN];
void get_div()
{
    for(ll i=1; i<MAXN; i++)
        for(ll j=i; j<MAXN; j+=i)
        {
            dx[j].push_back(i);     // 约数
            sum[j]+=i;              // 约数和
        }
    for(ll i=1; i<MAXN; i++)
    {
        int sz=dx[i].size();
        f[i]=(ll)((long long)i*(long long)(i+1)/(long long)2);
        for(int j=1; j<sz; j++)
        {
            ll tmp2=i/dx[i][j];
            f[i]-=f[tmp2]*dx[i][j];
        }
    }
    //for(ll i=1; i<10; i++) printf("%u--\n",dx[i].size());
}
void solve()
{
    dp[1]=1;
    f[1]=1;
    for(ll i=2; i<MAXN; i++)
    {
        dp[i]=dp[i-1];
        ll sz=dx[i].size();
        for(ll j=0; j<sz; j++)
        {
            ll tmp2=i/dx[i][j];
            dp[i]+=i*f[tmp2]*sum[dx[i][j]];
        }
    }
}
int main()
{
    int t;
    int n;
    get_div();
    solve();
    int cs=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case #%d: ",cs++);
        cout<<dp[n]<<'\n';
    }
    return 0;
}

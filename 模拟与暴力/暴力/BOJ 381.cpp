#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

#define MAXN 5005
#define N 65
#define inf 1.0e20
#define eps 1.0e-8
#define MOD 1000000007

#define For(i,m,n) for(int i=(m);i<(n);i++)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define rep(i,m,n) for(int i=(m);i<=(n);i++)
#define repd(i,m,n) for(int i=(m);i>=(n);i--)
#define LL long long
#define test

using namespace std;
int a[MAXN], d[MAXN], dp[MAXN];
int n;

void solve()//LIS（nlogn）
{
    int tot=1;
    rep(i,1,n)
	{
        if(i==1)
			d[tot++]=a[i], dp[i]=1;
        else
		{
            if(a[i]>d[tot-1])
				d[tot]=a[i], dp[i]=tot++;
            else
			{
                int tmp=lower_bound(d+1,d+tot,a[i])-d;
                d[tmp]=a[i], dp[i]=tmp;
            }
        }
    }for(int i=0;i<tot;i++)cout<<d[i]<<" ";
}
int g[MAXN], gg[MAXN], sta[MAXN];

bool judge()
{
    int ans=0, ret;
    rep(i,1,n)
		if(ans<=dp[i]) ans=dp[i],ret=i;         //LIS的长度和最后一项
    int top=1;
    sta[top++]=a[ret];
    //rep(i,1,n) printf("%d\n",dp[i]);
    for(int i=ret-1;i>=1;i--)
        if(ans-1==dp[i]&&a[i]<a[ret])
			sta[top++]=a[i], ans--, ret=i;
    sort(sta+1,sta+top);                        //LIS的确定项
    int m=1;
    rep(i,1,n)
        if(!binary_search(sta+1,sta+top,a[i]))  //剩余项
			g[m++]=a[i];
    rep(i,1,m)
		gg[i]=g[i];
    sort(gg+1,gg+m);
    rep(i,1,m)
		if(gg[i]!=g[i]&&gg[i]!=g[m-i])          //剩余项是否递增或者递减
			return false;
    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
	{
        scanf("%d",&n);
        rep(i,1,n)
			scanf("%d",&a[i]);
        solve();
        if(!judge())
		{
            rep(i,1,n/2+1)
				swap(a[i],a[n-i+1]);
            solve();
            printf(judge()?"Yes\n":"No\n");
        }
        else printf("Yes\n");
    }
    return 0;
}

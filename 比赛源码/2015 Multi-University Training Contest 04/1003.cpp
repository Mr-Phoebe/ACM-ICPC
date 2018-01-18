#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c)
{
    int ret=1;
    for(; b; b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;
    return ret;
}
const int N=1e5+10;
int a[N],tot=1,cir[N],n,f[N],on[N],h[N],p[N*2],n1[N*2],ee,cnt[N],sz[N],b[N],cc[N];
int gf(int x)
{
    return (f[x]==x)?x:(f[x]=gf(f[x]));
}
int un(int x,int y)
{
    if(gf(x)==gf(y))return 0;
    f[gf(x)]=gf(y);
    return 1;
}
void ae(int x,int y)
{
    p[ee]=y;
    n1[ee]=h[x];
    h[x]=ee++;
}
void dfs(int u)
{
    sz[u]=1;
    for(int i=h[u]; ~i; i=n1[i])if(!on[p[i]])
        {
            dfs(p[i]);
            sz[u]+=sz[p[i]];
        }
}
int check(int m)
{
    for(int i=0; i<m; i++)
        cc[i]=0;
    for(int i=1; i<=tot; i++)
        cc[b[i]=(b[i-1]+sz[cir[i]])%m]++;
    int ret=cc[0],la=tot;
    for(int i=1; i<tot; i++)
    {
        cc[b[i]]--;
        int t=b[i];
        cc[b[i]=(b[la]+sz[cir[i]])%m]++;
        ret=max(ret,cc[t]);
        la=i;
    }
    return ret;
}
int main()
{
    int x;
    int S=0;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)h[i]=-1;
        ee=0;
        for(int i=1; i<=n; i++)scanf("%d",&a[i]),f[i]=i,ae(a[i],i),on[i]=cnt[i]=0;
        for(int i=1; i<=n; i++)if(!un(a[i],i))
            {
                cir[1]=i;
                break;
            }
        on[cir[1]]=1;
        x=a[cir[1]];
        tot=1;
        while(x!=cir[1])on[cir[++tot]=x]=1,x=a[x];
        for(int i=1; i<=tot; i++)dfs(cir[i]);
        for(int i=1; i<=n; i++)if(!on[i])cnt[sz[i]]++;
        for(int i=1; i<=n; i++)
            for(int j=i+i; j<=n; j+=i)
                cnt[i]+=cnt[j];
        int ans=0;
        for(int i=1; i<=n; i++)if(n%i==0)if(check(i)+cnt[i]==n/i)ans++;
        printf("%d\n",ans);
    }
    return 0;
}


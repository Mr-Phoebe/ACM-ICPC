#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;
int n;
long long sum[maxn];
long long ans,dans;
long long a[maxn];
struct Convex_Hull
{
    int sz;
    pair<long long,long long> line[maxn];
    void init()
    {
        memset(line,0,sizeof(line));
        sz=0;
    }
    long long get(int p,long long x)
    {
        return line[p].first*x+line[p].second;
    }
    bool is_bad(long long x,long long y,long long z)
    {
        long long fi = (line[x].second-line[z].second)*(line[x].first-line[y].first);
        long long se = (line[y].second-line[x].second)*(line[z].first-line[x].first);
        return fi<=se;
    }
    void add(long long x,long long y)
    {
        line[sz++]=make_pair(x,y);
        while(sz>2&&is_bad(sz-2,sz-3,sz-1))
            line[sz-2]=line[sz-1],sz--;
    }
    long long query(long long x)
    {
        int l = -1 ,r = sz-1;
        while(r-l>1)
        {
            int mid = (l+r)/2;
            if(get(mid,x)<=get(mid+1,x))l=mid;
            else r=mid;
        }
        return get(r,x);
    }
}H;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
        ans=ans+a[i]*i;
    }
    H.init();
    for(int i=2;i<=n;i++)
    {
        H.add(i-1,-sum[i-2]);
        dans=max(dans,H.query(a[i])+sum[i-1]-a[i]*i);
    }
    H.init();
    for(int i=n-1;i>=1;i--)
    {
        H.add(-(i+1),-sum[i+1]);
        dans=max(dans,H.query(-a[i])+sum[i]-a[i]*i);
    }
    cout<<ans+dans<<endl;
}

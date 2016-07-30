//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;

#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<50
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int N=111,M=100010;

struct MaxCostMaxFlow
{
    int e,ev[M],nxt[M],head[M];
    ll cost[M],dis[M],cap[M];
    int pnt[N],road[N],q[N],bg,ed;
    bool vis[N];
    void init()
    {
        e=0;
        memset(head,-1,sizeof(head));
    }
    void addedge(int u,int v,ll f,ll c)
    {
        ev[e]=v;
        cap[e]=f;
        cost[e]= c;
        nxt[e]=head[u];
        head[u]=e++;
        ev[e]=u;
        cap[e]=0;
        cost[e]=-c;
        nxt[e]=head[v];
        head[v]=e++;
    }
    bool spfa(int s,int t,int n)
    {
        for(int i=0; i<n; i++) dis[i]=-1,vis[i]=0;
        bg=ed=dis[s]=0;
        pnt[s]=s;
        q[ed++]=s;
        while(bg!=ed)
        {
            int u=q[bg++];
            vis[u]=0;
            if(bg==n) bg=0;
            for(int i=head[u]; ~i; i=nxt[i])
            {
                if(cap[i]<=0)continue;
                ll v=ev[i];
                if(dis[v]<dis[u]+cost[i])
                {
                    dis[v]=dis[u]+cost[i];
                    pnt[v]=u;
                    road[v]=i;
                    if(!vis[v]) q[ed++]=v;
                    vis[v]=1;
                    if(ed==n) ed=0;
                }
            }
        }
        return dis[t]!=-1;
    }
    ll f=0,c=0;
    ll maxcost(int s,int t,int n)
    {
        c=f=0;
        while(spfa(s,t,n))
        {
            ll minf=LLINF;
            for(int u=t; u!=s; u=pnt[u]) minf=min(minf,cap[road[u]]);
            for(int u=t; u!=s; u=pnt[u]) cap[road[u]]-=minf,cap[road[u]^1]+=minf;
            f+=minf;
            c+=minf*dis[t];
        }
        return c;
    }
} g;

ll w[22],sc[22];
int ma[55][55];
int s,ss,n,m,k;

inline ll p(ll x)
{
    return 6400-3*(100-x)*(100-x);
}

int main()
{
    while(read(n)&&read(k)&&read(m)&&(n+m+k))
    {
        ll sum=0,cnt=0,ans=0;
        g.init();
        s=0;
        ss=n+m+1;
        for(int i=1; i<=m; sum+=w[i],i++)
            read(w[i]);
        for(int i=1; i<=m; i++)
            read(sc[i]);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                read(ma[i][j]);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(ma[i][j])
                    g.addedge(j,i+m,k,0);
        for(int i=1; i<=n; i++)
            g.addedge(i+m,n+m+1,k,0);
        for(int i=1; i<=m; i++)
        {
            if(sc[i]<60)  cnt+=60-sc[i],g.addedge(0,i,60-sc[i],INF),sc[i]=60;
            ans+=w[i]*p(sc[i]);
            for(int j=sc[i]; j<100; j++) g.addedge(0,i,1,w[i]*(p(j+1)-p(j)));
        }
        ans+=g.maxcost(s,ss,n+m+2)-INF*cnt;
        printf("%.6f\n",ans>0?ans/1600.0/sum:0);
    }
    return 0;
}

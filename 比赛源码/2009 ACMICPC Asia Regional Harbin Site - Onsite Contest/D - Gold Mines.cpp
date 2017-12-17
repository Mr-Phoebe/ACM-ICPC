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
#define getidx(l,r) (l+r | l!=r)
#define ls getidx(l,mid)
#define rs getidx(mid+1,r)
#define lson l,mid
#define rson mid+1,r

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

const int N=1010;
const int M=500*501;

int n,m,nn;
int a[M],b[M];
int pos[15];
int price[N];

struct Graph
{
    struct node
    {
        int v,next,w,flow;
        node() {};
        node(int a,int b,int c,int d)
        {
            next=a;
            v=b;
            w=c;
            flow=d;
        }
    } E[2*M];

    int head[N],pre[N],dis[N];
    int beg,end,flow,cost;
    bool h[N];
    int path[N];
    int NE,NV;

    void resize(int n)
    {
        this->NV=n;
    }
    void init(int n)
    {
        NE=0;
        NV=n;
        memset(head,-1,sizeof(int)*(n+10));
    }
    void addedge(int u,int v,int flow,int w)
    {
        E[NE]=node(head[u],v,w,flow);
        head[u]=NE++;
        E[NE]=node(head[v],u,-w,0);
        head[v]=NE++;
    }


    queue<int> q;
    bool spfa()
    {
        CLR(h,0);
        CLR(pre,-1);
        while(!q.empty())   q.pop();
        for(int i=0; i<=NV; i++)
            dis[i]=INF;
        dis[beg]=0;
        q.push(beg);
        h[beg]=true;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            h[u]=false;
            for(int i=head[u]; ~i; i=E[i].next)
            {
                if(E[i].flow>0 && dis[E[i].v]>dis[u]+E[i].w)
                {
                    dis[E[i].v]=dis[u]+E[i].w;
                    pre[E[i].v]=u;path[E[i].v]=i;
                    if(h[E[i].v] == false)
                    {
                        h[E[i].v]=true;
                        q.push(E[i].v);
                    }
                }
            }
        }
        return dis[end]<INF;
    }

    int mincost_maxflow(int s,int t)
    {
        this->beg=s;
        this->end=t;
        flow=0,cost=0;
        while(spfa())
        {
            int Min=INT_MAX;
            for(int i=end; i!=beg; i=pre[i])
                if(Min>E[path[i]].flow)
                    Min=E[path[i]].flow;
            for(int i=end; i!=beg; i=pre[i])
            {
                E[path[i]].flow-=Min;
                E[path[i]^1].flow+=Min;
                cost+=Min*E[path[i]].w;
            }
            flow+=Min;
        }
        if(flow==nn)
            return cost;
        return -1;
    }
} g;

int build(int st)
{
    g.init(2*n+2);
    int ss=0,tt=2*n+1;
    for(int i=0; i<2*nn; i++)
    {
        if((1<<i)&st)
            g.addedge(ss,pos[i],1,0);
        else
            g.addedge(pos[i]+n,tt,1,0);
    }
    for (int i=1; i<=n; i++)
    {
        g.addedge(i,i+n,1,price[i]);
    }
    for (int i=1; i<=m; i++)
    {
        g.addedge(a[i]+n,b[i],INF,0);
        g.addedge(b[i]+n,a[i],INF,0);
    }
    return g.mincost_maxflow(ss,tt);
}

int main()
{
    //freopen("data.txt","r",stdin);
    int T;
    read(T);
    while(T--)
    {
        read(n),read(m);
        for(int i=1; i<=m; i++)
        {
            read(a[i]),read(b[i]);
            a[i]++;
            b[i]++;
        }
        scanf("%d",&nn);
        for(int i=0; i<2*nn; i++)
        {
            read(pos[i]);
            pos[i]++;
        }
        int sum=0;
        for(int i=1; i<=n; i++)
        {
            read(price[i]);
            sum += price[i];
        }
        int ans=INF;
        for(int st=0; st<(1<<(2*nn)); st++)
        {
            if(__builtin_popcount(st) != nn)  continue;
            int ret=build(st);
            if(ret>=0)
                ans=min(ans,ret);
        }
        if(ans<=sum)
            ans=sum-ans;
        else
            ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
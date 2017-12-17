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
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
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

const int MAXN=1010;

struct nedge
{
    int c,f,v,next;
}e[2*MAXN*MAXN];
int head[MAXN],tot;
int cost,flow;
int s,t,n,m;

void init()
{
    tot=1;CLR(head,0);
}

void addedge(int u,int v,int cc,int ff)
{
    e[++tot].v=v;
    e[tot].c=cc;
    e[tot].f=ff;
    e[tot].next=head[u];
    head[u]=tot;
    e[++tot].v=u;
    e[tot].c=0;
    e[tot].f=-ff;
    e[tot].next=head[v];
    head[v]=tot;
}

int dist[MAXN],res[MAXN],last[MAXN],minx[MAXN];
struct sf
{
    bool operator()(const int& a, const int& b) const
    {
        return dist[a] > dist[b];
    }
};

int spfa()
{
    for(int i=s; i<=t; i++)
        dist[i]=INF,res[i]=0;
    priority_queue<int, vector<int>, sf> Q;
    dist[s]=0;
    res[s]=INF;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.top();Q.pop();
        if(u==t)
            return res[t];
        for(int i=head[u]; i; i=e[i].next)
        {
            if(e[i].c>0 && (dist[u]+e[i].f < dist[e[i].v]))
            {
                dist[e[i].v]=dist[u]+e[i].f;
                res[e[i].v]=min(e[i].c,res[u]),last[e[i].v]=u,minx[e[i].v]=i;
                Q.push(e[i].v);
            }
        }
    }
    return dist[t]==INF ? INF:res[t];
}

void change(int mi)
{
    flow+=mi;
    for(int i=t; i-s; i=last[i])
    {
        e[minx[i]].c-=mi;
        e[minx[i]^1].c+=mi;
        cost+=e[minx[i]].f*mi;
    }
}

int Mincost_flow()
{
    cost=0;
    flow=0;
    int mi;
    while((mi=spfa())!=INF)
        change(mi);
    return cost;
}

int main()
{
//    freopen("data.txt","r",stdin);
	while(read(n)&&read(m))
    {
        init();
        int u,v,w;
        addedge(0,1,2,0);
        addedge(n,n+1,2,0);
        for(int i=1;i<=m;i++)
        {
            read(u),read(v),read(w);
            addedge(u,v,1,w);addedge(v,u,1,w);
        }
        s=0,t=n+1;
        write(Mincost_flow()),putchar('\n');
    }
    return 0;
}

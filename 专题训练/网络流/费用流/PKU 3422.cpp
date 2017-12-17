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

const int MAXN=5010;
int n,k;
int c[55][55];



struct nedge
{
    int c,f,v,next;				// c为容量，f为费用
} e[4*MAXN];
int head[MAXN],tot;
int ss,tt;
int cost,flow;

void init()
{
    tot=1;
    CLR(head,0);
}

void addedge(int u,int v,int cc,int ff)		// f费用加边有正负
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

int dui[MAXN],tou,wei,d[MAXN],hs[MAXN],last[MAXN],minx[MAXN];

int spfa()
{
    CLR(d,INF);CLR(hs,0);CLR(last,0);CLR(dui,0);
    d[ss]=1;
    hs[ss]=1;
    tou=wei=0;
    dui[wei++]=ss;
    while(tou-wei)
    {
        int now=dui[tou];
        tou=(tou+1)%MAXN;
        hs[now]=0;
        for(int i=head[now]; i; i=e[i].next)
            if(e[i].c>0 && d[e[i].v]>d[now]+e[i].f)
            {
                last[e[i].v]=now;
                minx[e[i].v]=i;
                d[e[i].v]=d[now]+e[i].f;
                if(hs[e[i].v]==0)
                {
                    hs[e[i].v]=1;
                    dui[wei]=e[i].v;
                    wei=(wei+1)%MAXN;
                }
            }
    }
    return d[tt]-INF;
}

void change()
{
    int mi=INF;
    for(int i=tt; i-ss; i=last[i])
        mi=min(mi,e[minx[i]].c);
    flow+=mi;
    for(int i=tt; i-ss; i=last[i])
    {
        e[minx[i]].c-=mi;
        e[minx[i]^1].c+=mi;
        cost+=e[minx[i]].f*mi;
    }
}

int Mincost_flow()		//最大费用流则加负值费用，返回 -cost
{
    cost=flow=0;
    while(spfa())
        change();
    return -cost;
}


int main()
{
    while(read(n)&&read(k))
    {
        init();
        const int base=n*n;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                read(c[i][j]);
        ss=0,tt=n*n+base;
        int x;
        addedge(ss,1,k,0);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                x=(i-1)*n+j;
                addedge(x,x+base,1,-c[i][j]);
                addedge(x,x+base,INF,0);
                if(i+1<=n)
                    addedge(x+base,x+n,INF,0);
                if(j+1<=n)
                    addedge(x+base,x+1,INF,0);
            }
        write(Mincost_flow()),putchar('\n');
    }
    return 0;
}

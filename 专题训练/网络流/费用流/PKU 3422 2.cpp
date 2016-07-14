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

const int MAXN=200001;
int n,k;
int c[55][55];

struct nedge
{
    int c,f,v,next;				// c为容量，f为费用
} e[MAXN];
int head[MAXN],tot;
int ss,tt;
int cost,flow;

void init(int n)
{
    tot=1;
    for(int i=0; i<=3*n*n+2; i++)
        head[i]=0;
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

int visit[MAXN],pre[MAXN],dis[MAXN],que[MAXN],pos[MAXN];
int spfa()
{
    int i,u,v,k;
    for(i=0; i<=3*n*n+2; i++)
        pre[i]=-1,visit[i]=0,dis[i]=INF;
    int top=0,low=0;
    que[low++]=ss,pre[ss]=ss,dis[ss]=0,visit[ss]=1;
    while(top!=low)
    {
        int u=que[top++];
        visit[u]=0;
        for(k=head[u]; k; k=e[k].next)
        {
            v=e[k].v;
            if(e[k].c>0 && dis[u]+e[k].f < dis[v])//最大费用，求最小费用时这里的改符号
            {
                dis[v]=dis[u]+e[k].f;
                pre[v]=u;
                pos[v]=k;
                if(!visit[v])
                {
                    visit[v]=1;
                    que[low++]=v;
                }
            }
        }
    }
    if(pre[tt]!=-1 && dis[tt]<INF)//求最小费用时这里改成dit[t] < 正无穷
        return 1;
    return 0;
}


int Mincost_flow()		//最大费用流则加负值费用，返回 -cost
{
    cost=flow=0;
    while(spfa())
    {
        int u,mi=INF;
        for(u=tt; u!=ss; u=pre[u])
            mi=min(mi,e[pos[u]].c);
        flow+=mi;
        cost+=dis[tt]*mi;
        for(u=tt; u!=ss; u=pre[u])
        {
            e[pos[u]].c-=mi;
            e[pos[u]^1].c+=mi;
        }
    }
    return -cost;
}


int main()
{
    while(read(n)&&read(k))
    {
        init(n);
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

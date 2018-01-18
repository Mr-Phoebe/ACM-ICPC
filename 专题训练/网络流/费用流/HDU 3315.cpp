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

const int MAXN=1000;
int n;

struct nedge
{
    int c,f,v,next;				// c为容量，f为费用
} e[MAXN*MAXN];
int head[MAXN],tot;
int ss,tt;
int cost,flow;

void init()
{
	CLR(head,-1);
	tot=1;
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

int que[MAXN],tou,wei,d[MAXN],vis[MAXN],last[MAXN];

int spfa()
{
    CLR(d,INF);CLR(vis,0);CLR(last,-1);CLR(que,0);
    d[ss]=0;last[ss]=last[tt]=-1;vis[ss]=1;
    tou=wei=0;
    que[wei++]=ss;
    while(wei-tou)
    {
        int now=que[tou];
        tou=(tou+1)%MAXN;
        vis[now]=0;
        for(int i=head[now]; ~i; i=e[i].next)
            if(e[i].c && d[e[i].v]>d[now]+e[i].f)
            {
                last[e[i].v]=i;
                d[e[i].v]=d[now]+e[i].f;
                if(vis[e[i].v]==0)
                {
                    vis[e[i].v]=1;
                    que[wei]=e[i].v;
                    wei=(wei+1)%MAXN;
                }
            }
    }
    return d[tt]!=INF;
}

void change()
{
    int mi=INF,i;
    for(i=last[tt]; ~i ;i=last[e[i^1].v])
        if(e[i].c<mi)
            mi=e[i].c;
    flow+=mi;
   	cost+=d[tt]*mi;
    for(i=last[tt]; ~i ;i=last[e[i^1].v])
    {
        e[i].c-=mi;
        e[i^1].c+=mi;
    }
}

int Mincost_flow()		//最大费用流则加负值费用，返回 -cost
{
    cost=flow=0;
    while(spfa())
        change();
    return -cost;
}


void print()
{
    int i,j;
    cout<<"Graph"<<endl;
    for(i=1;i<=n;i++)
        {
            cout<<i<<":";
            for(j=head[i];~j;j=e[j].next)
                cout<<e[j].v<<"("<<e[j].f<<") ";
            cout<<endl;
        }
}

bool judge(int x1, int x2, int y1, int y2)
{
    while(1)
    {
        x2-=y1;
        if(x2<=0)
            return 1;
        x1-=y2;
        if(x1<=0)
            return 0;
    }
}

int main()
{
    int i, j, V[100], H[100], P[100], A[100], B[100];
    while(read(n)&&n)
    {
        for(i=1;i<=n;i++)
            read(V[i]);
        for(i=1;i<=n;i++)
            read(H[i]);
        for(i=1;i<=n;i++)
            read(P[i]);
        for(i=1;i<=n;i++)
            read(A[i]);
        for(i=1;i<=n;i++)
            read(B[i]);
        init();
        ss=0,tt=2*n+1;
        for(i=1;i<=n;i++)
        {
            addedge(ss,i,1,0);
            addedge(i+n,tt,1,0);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(judge(H[i],P[j],A[i],B[j]))
                    if(i==j)							//ʤ
                        addedge(i,j+n,1,-V[i]*1000-1);
                    else
                        addedge(i,j+n,1,-V[i]*1000);
                else
                    if(i==j)
                        addedge(i,j+n,1,V[i]*1000-1);
                    else
                        addedge(i,j+n,1,V[i]*1000);
            }
        }
        int ans=Mincost_flow();
        if(ans/1000<=0)
        	puts("Oh, I lose my dear seaco!");
        else
	        printf("%d %.3f%%\n",ans/1000,(ans%1000)*100.0/n);
    }
    return 0;
}

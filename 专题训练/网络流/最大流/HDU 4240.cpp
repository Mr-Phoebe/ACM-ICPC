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

const int MAXN=1000+10;
const int MAXM=100000+10;

struct Edge
{
	int v,f,next;
}e[MAXM];
int n,src,sink,maxx,cas;
int head[MAXN];
int tot;

void add_edge(int u,int v,int c)
{
	e[++tot].v=v;
	e[tot].f=c;
	e[tot].next=head[u];
	head[u]=tot;
	e[++tot].v=u;
	e[tot].f=0;
	e[tot].next=head[v];
	head[v]=tot;
}

void init()
{
	CLR(head,-1);
	tot=1;maxx=-INF;
	int m,u,v,w;
	read(cas);read(n);read(m);read(src);read(sink);
	for(int i=0;i<m;i++)
	{
		read(u),read(v),read(w);
		add_edge(u,v,w);
	}
}

bool vis[MAXN];
int dist[MAXN];

void bfs()
{
	CLR(dist,0);
	queue<int> que;
	vis[src]=true;
	que.push(src);
	while(!que.empty())
	{
		int u=que.front();
		que.pop();
		for(int i=head[u];~i;i=e[i].next)
		{
			if(e[i].f && !vis[e[i].v])
			{
				que.push(e[i].v);
				dist[e[i].v]=dist[u]+1;
				vis[e[i].v]=true;
			}
		}
	}
}

int dfs(int u,int v,int delta)
{
	if(u==sink || delta==0)
	{
		maxx=max(maxx,v);
		return delta;
	}
	else
	{
		int ret=0;
		for(int i=head[u];~i;i=e[i].next)
			if(e[i].f && dist[e[i].v]==dist[u]+1)
			{
				int dd=dfs(e[i].v,min(v,e[i].f+e[i^1].f),min(e[i].f,delta));
				e[i].f-=dd;
				e[i^1].f+=dd;
				delta-=dd;
				ret+=dd;
			}
		return ret;
	}
}

int maxflow()
{
	int ret=0;
	while(1)
	{
		CLR(vis,0);
		bfs();
		if(!vis[sink])
			return ret;
		ret+=dfs(src,INF,INF);
	}
}

int main()
{
	int T;
	read(T);
	while(T--)
	{
		init();
		double ans=(double)maxflow();
		printf("%d %.3lf\n",cas,ans/maxx);
	}
	return 0;
}

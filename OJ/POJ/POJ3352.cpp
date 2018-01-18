//      whn6325689
//		Mr.Phoebe
//		http://blog.csdn.net/u013007900
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

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

const int MAXN=1111;

int dfn[MAXN],low[MAXN],head[MAXN];
int stack[MAXN],belong[MAXN],in[MAXN];
bool vis[MAXN];
int n,m,cnt,scnt,be,tot;
int g[MAXN][MAXN];

struct Edge
{
	int v,next;	
}e[MAXN*MAXN];

void init()
{
	CLR(head,-1);CLR(dfn,0);
	CLR(low,0);CLR(in,0);
	cnt=scnt=tot=be=0;
}

void addedge(int u,int v)
{
	e[tot].v=v;
	e[tot].next=head[u];
	head[u]=tot++;
}

void tarjan(int u,int fa)
{
	int v;
	dfn[u]=low[u]=++cnt;
	for(int i=head[u];~i;i=e[i].next)
	{
		v=e[i].v;
		if(v==fa)
			continue;
		if(!dfn[v])
			tarjan(v,u);
		low[u]=min(low[u],low[v]);
	}
}

int main()
{
	init();
	read(n),read(m);
	int u,v;
	for(int i=0;i<m;i++)
	{
		read(u),read(v);
		addedge(u,v);addedge(v,u);
	}
	
	tarjan(1,1);
	for(int u=1;u<=n;u++)
		for(int j=head[u];~j;j=e[j].next)
		{
			int v=e[j].v;
			if(low[u]!=low[v])
				in[low[u]]++;
		}
	int ans=1;
	for(int i=1;i<=n;i++)
		if(in[i]==1)
			ans++;
	write(ans/2),putchar('\n');
	return 0;
}

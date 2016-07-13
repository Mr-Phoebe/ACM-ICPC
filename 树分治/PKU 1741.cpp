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
#define speed std::ios::sync_with_stdio(false);
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

const int MAXN=10010;

struct Edge
{
	int v,nex,w;
} e[MAXN<<1];
int h[MAXN],tot;
int vis[MAXN],n,k;

int sz[MAXN],num[MAXN],dep[MAXN];
int root,N;
int st[MAXN],top,ans;

void init()
{
	CLR(h,-1);CLR(vis,0);
	root=0;num[0]=N=n;ans=0;tot=0;
}

void addedge(int u,int v,int w)
{
	e[tot].v=v;
	e[tot].w=w;
	e[tot].nex=h[u];
	h[u]=tot++;
}

int dfs_root(int u,int fa=-1)
{
	sz[u]=1;num[u]=0;
	for(int i=h[u];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(fa==v || vis[v])	continue;
		sz[u]+=dfs_root(v,u);
		num[u]=max(num[u],sz[v]);
	}
	num[u]=max(num[u],N-sz[u]);
	if(num[u]<num[root])
		root=u;
	return sz[u];
}

int dfs_dep(int u,int fa=-1)
{
	if(dep[u]<=k)	st[top++]=dep[u];
	sz[u]=1;
	for(int i=h[u];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(fa==v || vis[v])	continue;
		dep[v]=dep[u]+e[i].w;
		sz[u]+=dfs_dep(v,u);;
	}
	return sz[u];
}


int get_num(int u,int len)
{
	top=0;
	dep[u]=len;
	dfs_dep(u);
	sort(st,st+top);
	int ans=0,r=top-1;
	for(int l=0;l<r;l++)
	{
		while(r>l && st[l]+st[r]>k)
			r--;
		ans+=r-l;
	}
	return ans;
}

void dfs(int u)
{
	vis[u]=1;
	ans+=get_num(u,0);
	for(int i=h[u];~i;i=e[i].nex)
	{
		int v=e[i].v;
		if(vis[v])	continue;
		ans-=get_num(v,e[i].w);
		root=0;N=sz[v];
		dfs_root(v);
		dfs(root);
	}
}

int main()
{
	while(read(n)&&read(k)&&(n+k))
	{
		init();
		for(int i=1,u,v,w;i<n;i++)
		{
			read(u),read(v),read(w);
			addedge(u,v,w);addedge(v,u,w);
		}
		dfs_root(1);
		dfs(root);
		write(ans),putchar('\n');
	}
	return 0;
}
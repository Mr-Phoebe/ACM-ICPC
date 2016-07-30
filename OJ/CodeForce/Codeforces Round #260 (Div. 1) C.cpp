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

const int MAXN=300010;

vector<int> g[MAXN];

struct DisjointSet
{
	vector<int> father,rank,path;
	DisjointSet(int n): father(n),rank(n),path(n){}
	
	int find(int v)
	{
		return father[v] = father[v]==v ? v:find(father[v]);
	}
	
	void merge(int x,int y)
	{
		int a=find(x),b=find(y);
		if(a==b)
			return;
		if(rank[a]<rank[b])
		{
			father[a]=b;
			path[b]=max((path[a]+1)/2+(path[b]+1)/2+1,max(path[a],path[b]));
		}
		else
		{
			father[b]=a;
			path[a]=max((path[a]+1)/2+(path[b]+1)/2+1,max(path[a],path[b]));
			if(rank[b]==rank[a])
				rank[a]++;
		}
	}
	
	void clear(int n)
	{
		for(int i=0;i<=n;i++)
			father[i]=i,rank[i]=0,path[i]=0;
	}
	
};

bool vis[MAXN];
int maxx,maxxnode;

void dfs(int u,int f,int s)
{
	if(s>maxx){maxx=s;maxxnode=u;}
	vis[u]=true;
	int len=g[u].size();
	for(int i=0;i<len;i++)
		if(g[u][i]!=f)
			dfs(g[u][i],u,s+1);
}

DisjointSet d(MAXN);
int n,m,q;

int main()
{
	freopen("data.txt","r",stdin);
	read(n),read(m),read(q);
	int u,v,t;
	d.clear(n+1);
	for(int i=0;i<m;i++)
	{
		read(u),read(v);
		g[u].push_back(v);
		g[v].push_back(u);
		d.merge(u,v);
	}
	for(int i=1;i<=n;i++)
	{
		int fa=d.find(i);
		if(!vis[fa])
		{
			maxx=-INF;dfs(fa,-1,0);
			maxx=-INF;dfs(maxxnode,-1,0);
			d.path[fa]=maxx;
		}
	}
	while(q--)
	{
		read(t);
		if(t==1)
		{
			read(u);
			write(d.path[d.find(u)]);putchar('\n');
		}
		else
		{
			read(u),read(v);
			d.merge(u,v);
		}
	}
	return 0;
}
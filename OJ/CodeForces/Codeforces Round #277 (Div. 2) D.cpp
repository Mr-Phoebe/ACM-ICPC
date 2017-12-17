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

const int MAXN=2010;
const ll MOD=1000000007;

struct Edge
{
	int v,next;
}e[MAXN*2];

int head[MAXN],val[MAXN];
int d,n,tot;

void addedge(int u,int v)
{
	e[tot].v=v;
	e[tot].next=head[u];
	head[u]=tot++;	
}

ll dfs(int u,int fa,int root)
{
	ll ret=1;
	for(int i=head[u];~i;i=e[i].next)
	{
		int v=e[i].v;
		if(v==fa)
			continue;
		if(val[v]<val[root] || val[v]>val[root]+d)
			continue;
		if(val[root]==val[v] && v>root)
			continue;
		ret*=(dfs(v,u,root)+1);
		ret%=MOD;
	}
	return ret;
}

int main()
{
	CLR(head,-1);
	read(d),read(n);
	for(int i=1;i<=n;i++)
		read(val[i]);
	for(int i=1,u,v;i<n;i++)
	{
		read(u),read(v);
		addedge(u,v);
		addedge(v,u);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll temp=dfs(i,-1,i);
		ans+=temp;
		ans%=MOD;
	}
	write(ans),putchar('\n');
	return 0;
}
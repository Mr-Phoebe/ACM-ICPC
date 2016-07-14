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

const int MAXN=1000010;
const int MOD=1e9+7;

ll exGcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
	{
        x=1,y=0;
        return a;
    }
    ll gcd;
    gcd=exGcd(b,a%b,y,x);
    y-=a/b*x;
    return gcd;
}

ll ff[MAXN],rev[MAXN];

inline ll Rev(int a)
{
    ll x,y;
    exGcd(a,MOD,x,y);
    x=(x%MOD+MOD)%MOD;
    return x;
}

inline void init()
{
    ff[0]=1;
    for(int i=1; i<=1000000; i++)
        ff[i]=ff[i-1]*i%MOD, rev[i]=Rev(ff[i]);
}

struct Edge
{
	int to,next;
}e[MAXN<<1];

int head[MAXN],tot,n;
ll ans;

void addedge(int u,int v)
{
	e[tot].to=v;
	e[tot].next=head[u];
	head[u]=tot++;
}

ll dp[MAXN];
int num[MAXN];

void dfs(int u,int fa=-1)
{
	dp[u]=1;num[u]=0;
	for(int i=head[u],v;~i;i=e[i].next)
	{
		v=e[i].to;
		if(v==fa)	continue;
		dfs(v,u);
		num[u]+=num[v];
		dp[u]=dp[u]*dp[v]%MOD*rev[num[v]]%MOD;
	}
	dp[u]=dp[u]*ff[num[u]]%MOD;
	num[u]++;
}

void dfs2(int u,int fa=-1)
{
	ans=(ans+dp[u]*dp[u]%MOD)%MOD;
	for(int i=head[u],v;~i;i=e[i].next)
	{
		v=e[i].to;
		if(v==fa)	continue;
		dp[v]=dp[u]*num[v]%MOD*Rev(n-num[v])%MOD;
		/*
		ll temp=dp[u]*rev(dp[v] * C(n-1,num[v])%MOD)%MOD;       除了v子树以外的所有的信息汇入u节点的方案数，组合数是为了消除v子树对全局的影响
		dp[v]=dp[v]*temp%MOD*C(n-1,n-num[v])%MOD;               从父亲汇入v节点的方案数
		*/
		dfs2(v,u);
	}
}

int main()
{
	init();
	int T;
	read(T);
	while(T--)
	{
 		CLR(head,-1);tot=0;ans=0;
		read(n);
		for(int i=0,x,y;i<n-1;i++)
		{
			read(x),read(y);
			addedge(x,y);
			addedge(y,x);
		}
		dfs(1);
		dfs2(1);
	 	write(ans),putchar('\n');
	}
	return 0;
}

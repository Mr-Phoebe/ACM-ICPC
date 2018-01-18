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
#define LLINF 1LL<<62

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

const int MAXM=20010;
const int MAXN=2010;
const int MOD=1000000007;

struct Edge
{
	int v,next;
}e[MAXM];

int head[MAXN],tot,cnt;
int n,m,k;
int dp[MAXN][MAXN],val[MAXN];
map<ll,int> fac;

ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}

void addedge(int u,int v)
{
	e[tot].v=v;
	e[tot].next=head[u];
	head[u]=tot++;
}

int dfs(int u,int x)
{
	if(dp[u][fac[x]]!=-1)
		return dp[u][fac[x]];
	if(u==n)
		return x==k;
	dp[u][fac[x]]=0;
	int v;
	for(int i=head[u];~i;i=e[i].next)
	{
		v=e[i].v;
		if(k%val[v])
			continue;
		int temp=lcm(x,val[v]);
		if(temp>k || temp==x)
			continue;
		dp[u][fac[x]]=(dp[u][fac[x]]+dfs(v,temp))%MOD;
	}
	return dp[u][fac[x]];
}

int main()
{
	while(read(n)&&read(m)&&read(k))
	{
		fac.clear();
		tot=0;cnt=0;
		CLR(head,-1);
		for(int i=1;i<=(int)(sqrt(k)+0.5);i++)
		{
			if(k%i==0)
				fac[(ll)i]=++cnt;
			if(k!=i*i)
				fac[(ll)(k/i)]=++cnt;
		}
		int u,v;
		for(int i=1;i<=m;i++)
		{
			read(u),read(v);
			addedge(u,v);
		}
		for(int i=1;i<=n;i++)
			read(val[i]);
		CLR(dp,-1);
		int temp=dfs(1,val[1]);
		if(temp==-1)
			temp=0;
		write(temp);
		putchar('\n');
	}
	return 0;
}

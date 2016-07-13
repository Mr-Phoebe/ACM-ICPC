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

const int MAXN=100010;

int prime[MAXN],vis[MAXN],top=0;
int num[MAXN],fac[MAXN],f[MAXN],v[MAXN];
ll n,ans=0;
vi g[MAXN];


void getprime()
{
	top=0;	
	for(int i=2;i<1000;i++)
	{
		if(!vis[i])
		{
			prime[top++]=i;
			for(int j=i<<1;j<1000;j+=i)
				vis[j]=1;
		} 
	}
}

void dfs(int u,int d,int idx)
{
	if(d>=v[idx])
	{
		if(u!=1)
			g[idx].pb(u);
		return;
	}
	dfs(u,d+1,idx);
	dfs(u*fac[d],d+1,idx);
}

void getfac(int u,int &cnt)
{
	cnt=0;
	for(int i=0;i<top && prime[i]*prime[i]<=u;i++)
	{
		if(u%prime[i]==0)
		{
			fac[cnt++]=prime[i];
			while(u%prime[i]==0)
				u/=prime[i];
		}
	}
	if(u!=1)
		fac[cnt++]=u;
}

void init()
{
	getprime();
	for(int i=2;i<MAXN;i++)
	{
		getfac(i,v[i]);
		dfs(1,0,i);
	}
}

ll count(int u)
{
	ll res=0;
	for(int i=g[u].size()-1;i>=0;i--)
	{
		int k=g[u][i];
		if(v[k]&1)
			res+=f[k]-1;
		else
			res-=f[k]-1;
	}
	return res;
}

int main()
{
	int T,temp;
	init();
	read(T);
	while(T--)
	{
		read(n);
		ans=0;CLR(num,0);CLR(f,0);
		for(int i=0;i<n;i++)
		{
			read(temp);num[temp]++;
		}
		for(int i=2;i<MAXN;i++)
		{
			if(!num[i])
				continue;
			for(int j=g[i].size()-1;j>=0;j--)
				f[g[i][j]]+=num[i];
		}
		for(int i=2;i<MAXN;i++)
		{
			if(!num[i])
				continue;
			ll k=count(i);
			ans+=k*(n-1-k);
		}
		ans=n*(n-1)*(n-2)/6-ans/2;
		write(ans),putchar('\n');
	}
	return 0;
} 
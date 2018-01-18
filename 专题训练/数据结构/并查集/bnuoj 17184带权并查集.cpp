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

struct DisjointSet
{
	int fa[MAXN];
	ll sum[MAXN];
	void init(int n)
	{
		for(int i=0;i<=n;i++)
			fa[i]=i;
		CLR(sum,0);
	}
	int findfa(int x)
	{
		if(fa[x]==x)
			return x;
		int xx=findfa(fa[x]);
		sum[x]+=sum[fa[x]];
		return fa[x]=xx;
	}
	bool merge(int x,int y,int num)
	{
		int xx=findfa(x);
		int yy=findfa(y);
		if(xx==yy)
		{
			return sum[x]-sum[y]==num;
		}
		if(yy>xx)
		{
			fa[xx]=yy;
			sum[xx]=sum[y]+num-sum[x];	
		}
		else
		{
			fa[yy]=xx;
			sum[yy]=sum[x]-num-sum[y];
		}
		return true;
	}
}g;


int main()
{
	int n,m,a,b,c;
	scanf("%d %d",&n,&m);
	g.init(n);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		b++;
		if(g.merge(a,b,c))
			puts("Accepted!");
		else
			puts("Error!");
	}
	for(int i=1;i<=n;i++)
	{
		int xx=g.findfa(i),yy=g.findfa(i+1);
		if(xx==yy)
			write(g.sum[i]-g.sum[i+1]),putchar('\n');
		else
			puts("Unknown!");
	}
	return 0;
}

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

const int MAXN=1000;


bool v[MAXN],used[MAXN][MAXN];
double dis[MAXN],cost[MAXN][MAXN],g[MAXN][MAXN];
int x[MAXN],y[MAXN],b[MAXN],pre[MAXN];
int n,tot;

double Prim()
{
	CLR(v,0);
	CLR(used,0);
	CLR(cost,0);
	for(int i=1;i<=n;i++)
		dis[i]=g[1][i],pre[i]=1;
	dis[1]=0.0;
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		int mark=-1;
		for(int j=1;j<=n;j++) if(!v[j])
			if(mark==-1 || dis[j]<dis[mark])
				mark=j;
		if(mark==-1)
			break;
		v[mark]=1;
		used[mark][pre[mark]]=used[pre[mark]][mark]=true;
		ans+=dis[mark];
		for(int j=1;j<=n;j++)
		{
			if(v[j]&&j!=mark)
				cost[mark][j]=cost[j][mark]=max(cost[j][pre[mark]], dis[mark]);
			if(!v[j] && dis[j]>g[mark][j])
				dis[j]=g[mark][j],pre[j]=mark;

		}
	}
	return ans;
}

inline double getDist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	int T;
//	freopen("data.txt","r",stdin);
	read(T);
	while(T--)
	{
		read(n);
		for(int i=1;i<=n;i++)
			read(x[i]),read(y[i]),read(b[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				g[i][j]=getDist(x[i],y[i],x[j],y[j]);
		double temp=Prim();
		double ans=-1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) if(i!=j)
				if(used[i][j])
					ans=max(ans,(b[i]+b[j])/(temp-g[i][j]));
				else
					ans=max(ans,(b[i]+b[j])/(temp-cost[i][j]));
		printf("%.2f\n",ans);
	}
	return 0;
}

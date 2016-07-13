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

const int MAXN=222;

struct edge
{
    int t,next;
};

struct Point
{
	double x,y;
}a[MAXN/2][2];
int n;

struct TwoSAT
{
	int n;
	edge G[MAXN*MAXN];
	bool mark[MAXN*2];
	int S[MAXN*2],head[MAXN*2],c,tot;

	void add(int f,int t)
    {
        G[tot].t=t;
        G[tot].next=head[f];
        head[f]=tot++;
    }

	bool dfs(int x)
	{
		if(mark[x^1])
			return false;
		if(mark[x])
			return true;
		mark[x]=true;
		S[c++]=x;
		for(int i=head[x];~i;i=G[i].next)
            if(!dfs(G[i].t))
                return false;
		return true;
	}

	void init(int n)
	{
		this->n=n;tot=0;
		CLR(mark,0);CLR(head,-1);
	}

	void add_clause(int x,int xval,int y,int yval)
	{
		x=x*2+xval;
		y=y*2+yval;
		add(y,x^1);
		add(x,y^1);
	}

	bool solve()
	{
		for(int i=0;i<2*n;i+=2)
			if(!mark[i] && !mark[i+1])
			{
				c=0;
				if(!dfs(i))
				{
					while(c>0)
						mark[S[--c]]=false;
					if(!dfs(i+1))
						return false;
				}
			}
		return true;
	}
}g;

double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool build(double r)
{
	g.init(n);
	for(int i=0;i<n;i++)	for(int k=0;k<2;k++)
	for(int j=i+1;j<n;j++)	for(int q=0;q<2;q++)
		if(dist(a[i][k],a[j][q])<2*r)
			g.add_clause(i,k^1,j,q^1);
	return g.solve();
}

int main()
{
//    freopen("data.txt","r",stdin);
	while(read(n))
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<2;j++)
				scanf("%lf %lf",&a[i][j].x,&a[i][j].y);


		double l=0.0,h=40000.0;
		while(h-l>=eps)
		{
			double mid=(h+l)/2.0;
			if(build(mid))
				l=mid;
			else
				h=mid;
		}
		printf("%.2f\n",h);
	}
	return 0;
}

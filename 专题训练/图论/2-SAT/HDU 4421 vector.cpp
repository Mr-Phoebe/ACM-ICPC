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

const int MAXN=510;
int b[MAXN][MAXN];


struct TwoSAT
{
    int n;
    vector<int> G[MAXN*2];
    bool mark[MAXN*2];
    int S[MAXN*2],c;

    bool dfs(int x)
    {
        if(mark[x^1])
            return false;
        if(mark[x])
            return true;
        mark[x]=true;
        S[c++]=x;
        int sz=G[x].size();
        for(int i=sz-1;i>=0;i--)
        {
            if(!dfs(G[x][i]))
            {
                return false;
            }
        }
		return true;
    }

    void init(int n)
    {
        this->n=n;
        for(int i=0;i<2*n;i++)
            G[i].clear();
        CLR(mark,0);
    }

    void add_clause(int x,int xval,int y,int yval)
    {
        x=x*2+xval;
        y=y*2+yval;
        G[x^1].push_back(y);
        G[y^1].push_back(x);
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

bool build(int n)
{
	for(int k=0;k<32;k++)
	{
		g.init(n);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				int w=(b[i][j]>>k)&1;
				if(i%2==1 && j%2==1)
				{
					if(!w)
					{
						g.add_clause(i,1,j,1);
						g.add_clause(i,0,j,1);
						g.add_clause(i,1,j,0);
					}
					else
					{
						g.add_clause(i,0,j,0);
					}
				}
				else if(i%2==0 && j%2==0)
				{
					if(!w)
					{
						g.add_clause(i,1,j,1);
					}
					else
					{
						g.add_clause(i,0,j,1);
						g.add_clause(i,1,j,0);
						g.add_clause(i,0,j,0);
					}
				}
				else
				{
					if(!w)
					{
						g.add_clause(i,0,j,1);
						g.add_clause(i,1,j,0);
					}
					else
					{
						g.add_clause(i,0,j,0);
						g.add_clause(i,1,j,1);
					}
				}
			}
		if(!g.solve())
			return false;
	}
	return true;
}

bool ok(int n)
{
    for(int i=0;i<n;i++)
	{
        if(b[i][i]!=0)
			return false;
        for(int j=i+1;j<n;j++)
            if(b[i][j] != b[j][i])
                return false;
    }
    return true;
}

int main()
{
    freopen("data.txt","r",stdin);
    freopen("out1.txt","w",stdout);
	int n;
	while(read(n))
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				read(b[i][j]);
		if(!ok(n))
		{
			puts("NO");
			continue;
		}
		if(build(n))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}

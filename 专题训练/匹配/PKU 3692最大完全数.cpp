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

const int MAXN=210;

bool mapp[MAXN][MAXN];
int from[MAXN],G,B,m;
bool used[MAXN];

bool match(int x)
{
	for(int i=1;i<=B;i++)
		if(mapp[x][i] && !used[i])
		{
			used[i]=true;
			if(from[i]==-1 || match(from[i]))
			{
				from[i]=x;
				return true;
			}
		}
	return false;
}

int hungry()
{
	int tot=0;
	CLR(from,-1);
	for(int i=1;i<=G;i++)
	{
		CLR(used,0);
		if(match(i))
			tot++;
	}
	return tot;
}


int main()
{
    freopen("data.txt","r",stdin);
    int Cas=1;
	while(read(G)&&read(B)&&read(m)&&G&&B&&m)
	{
	    for(int i=1;i<=G;i++)
            for(int j=1;j<=B;j++)
                mapp[i][j]=true;
		int u,v;
		for(int i=0;i<m;i++)
		{
			read(u),read(v);
			mapp[u][v]=false;
		}
		printf("Case %d: %d\n",Cas++,B+G-hungry());
	}
	return 0;
}

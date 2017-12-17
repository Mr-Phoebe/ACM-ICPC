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

const int MAXN=1010;
const int MOD=1e6+3;

ll c[MAXN][MAXN],ans[MAXN],num[33]; 
int n;

void init()
{
	for(int i=0;i<MAXN;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	}
		
}

ll cal(int t,int d)
{
	ll sum=0;
	for(int i=1;i<=t && i<=d;i+=2)
		if(d-i<=n-t)
			sum=(sum+(c[t][i]*c[n-t][d-i])%MOD)%MOD;
	return sum%MOD;
}


int main()
{
	init();
	while(read(n))
	{
		CLR(num,0);
		ll u;
		for(int i=1;i<=n;i++)
		{
			read(u);
			for(int j=0;j<32;j++)
				if(u&(1<<j))
					num[j]++;	
		}

		for(int i=1;i<=n;i++)
		{
			ll temp=0;
			for(int j=0;j<32;j++)
				temp=(temp+(cal(num[j],i)*(1LL<<j))%MOD)%MOD;	
			ans[i]=temp%MOD; 
		}	
		for(int i=1;i<n;i++)
			write(ans[i]),putchar(' ');
		write(ans[n]),putchar('\n');
	}
	return 0;
}
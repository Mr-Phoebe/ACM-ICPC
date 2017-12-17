//      whn6325689
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
#define MID(x,y) (x+((y-x)>>1LL))
#define eps 1e-9
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

const int M=100000;

inline ll getsum(ll i,ll j)
{
	return i*i+M*i+j*j-M*j+i*j;
}

int main()
{
	ll T,n,m;
	read(T);
	while(T--)
	{
		read(n),read(m);
		ll l=-100000000000LL,r=100000000000LL;
		while(l<r)
		{
			ll mid=MID(l,r);
			ll num=0; 
			for(ll j=1;j<=n;j++)
			{
				ll low=1,high=n+1;
				while(low<high)
				{
					ll midd=MID(low,high);
					if(getsum(midd,j) <= mid)
						low=midd+1;
					else
						high=midd;
				}
				num+=high-1;
			}
			if(num<m)
				l=mid+1;
			else
				r=mid;
		}
		write(l),putchar('\n');
	}
	return 0;
}
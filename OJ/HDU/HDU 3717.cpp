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

const int MAXN=100010;

ll n,k;
ll m[MAXN],cnt[MAXN];

bool check(ll x)
{
    ll suma,sumb,ans,po,i,numa;
    ll j=n;
    suma=sumb=ans=numa=0;
    for(i=n;i>=1;i--)
	{
        if(j>i)
		{
	        while((j-i)*(j-i)>=x)
			{
	            suma-=cnt[j]*(j-i-1)*(j-i-1);
	            sumb-=cnt[j]*(j-i-1);
	            numa-=cnt[j];
	            j--;
	        }
        }
        suma+=2*sumb+numa;
        sumb+=numa;
        if(m[i]-numa*x+suma<0)
			cnt[i]=0;
        else cnt[i]=(m[i]-numa*x+suma)/x+1;
        numa+=cnt[i];
        ans+=cnt[i];
    }
    return ans<=k;
}
int main()
{
	int T;
	read(T);
	while(T--)
	{
		read(n),read(k);
		for(int i=1;i<=n;i++)
			read(m[i]);
		ll l=1,h=1LL<<62LL;
		while(l<=h)
		{
			ll mid=l+(h-l)/2;
			if(check(mid))
				h=mid-1;
			else
				l=mid+1;
		}
		write(l),putchar('\n');
	}
	return 0;
}

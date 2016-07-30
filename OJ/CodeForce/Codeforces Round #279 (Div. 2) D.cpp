//      whn6325689
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

int ans=0;
void change(ll f[],ll c[],int i)
{
    while(f[i]>c[i])
    {
        f[i]--;ans++;
        if(i==3)
        {
            f[2]++;
            if(f[0]%i==0)
            	f[0]*=2;
			else
				f[1]*=2;
       }
       if(f[0]%i==0)
      	   f[0]/=i;
	   else
		   f[1]/=i;
    }
}

ll x(ll f[],ll i)
{
    ll t=f[i];
    while(t%2==0){t/=2;f[2]++;}
    while(t%3==0){t/=3;f[3]++;}
    return t;
}

int main()
{
    ll a[4],b[4];
    read(a[0]),read(a[1]),read(b[0]),read(b[1]);
    a[2]=a[3]=b[2]=b[3]=0LL;
    if(x(a,0)*x(a,1)!=x(b,0)*x(b,1))
	{
		printf("-1");
		return 0;
	}
    change(a,b,3);change(b,a,3);
	change(a,b,2);change(b,a,2);
    write(ans),putchar('\n');
	write(a[0]),putchar(' '),write(a[1]),putchar('\n');
	write(b[0]),putchar(' '),write(b[1]),putchar('\n');
    return 0;
}
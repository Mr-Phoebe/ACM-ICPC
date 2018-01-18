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

const int MAXN=100010;
int h[MAXN],dp[MAXN];
int n,m,w;

bool check(int low)
{
	for(int i=1;i<=w;i++)
	{
		dp[i]=max(0,low-h[i]-dp[i-1])+dp[i-1];
		if(dp[i]>m)
			return false;
	}
	for(int i=w+1;i<=n;i++)
	{
		dp[i]=max(0,low-h[i]+dp[i-w]-dp[i-1])+dp[i-1];
		if(dp[i]>m)
			return false;
	}
	return true;
}

int main()
{
	read(n);read(m);read(w);
	for(int i=1;i<=n;i++)
		read(h[i]);
	int l=0,r=1000100000,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	write(l-1);
	putchar('\n');
}
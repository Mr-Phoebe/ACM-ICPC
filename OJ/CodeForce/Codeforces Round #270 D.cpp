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

const int MAXN=2010;

int n,a[MAXN][MAXN];

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			read(a[i][j]);
	for(int i=1;i<=n;i++)
		if(a[i][i])
			goto NO;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i][j]!=a[j][i] || a[i][j]==0&&i!=j)
				goto NO;
	for(int i=1;i<=n;i++)
	{
		int k=1;
		for(int j=1;j<=n;j++)
			if(i!=j && a[i][j]<a[i][k])
				k=j;
		for(int t=1;t<=n;t++)
			if(abs(a[i][t]-a[k][t])!=a[i][k])
				goto NO;
	}
	puts("YES");
	return 0;
NO:
	puts("NO");
	return 0;	
}
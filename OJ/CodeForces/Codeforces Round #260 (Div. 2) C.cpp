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

ll a[MAXN],dp[2][2];

int main()
{
	int n,temp,maxn=-INF;
	while(read(n))
	{
		for(int i=0;i<n;i++)
		{
			read(temp);a[temp]++;
			maxn=max(temp,maxn);
		}
		int k=1;
		for(int i=1;i<=maxn;i++,k^=1)
		{
			dp[k][0]=max(dp[!k][1],dp[!k][0]);
			dp[k][1]=dp[!k][0]+i*a[i];
		}
		dp[k][1]=max(dp[!k][1],dp[k][1]);
		dp[k][0]=max(dp[!k][0],dp[k][0]);
		printf("%I64d\n",max(dp[k][1],dp[k][0]));
		CLR(a,0);
		CLR(dp,0);
	}
	return 0;
}
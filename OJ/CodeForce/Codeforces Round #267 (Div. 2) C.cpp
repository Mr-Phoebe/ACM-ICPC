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

int n,m,k;
ll dp[5010][2];
ll a[5010],sum[5010];

int main()
{
    CLR(dp,0);
    CLR(sum,0);
    read(n),read(m),read(k);
    for(int i=1; i<=n; i++)
        read(a[i]);
    for(int i=1; i<=m; i++)             // 维护前缀长为 m 的前缀和
        sum[m]+=a[i];
    for(int i=m+1; i<=n; i++)
        sum[i]=sum[i-1]+a[i]-a[i-m];
    int v=0;
    dp[m][v]=sum[m];
    for(int i=m+1; i<=n; i++)
        dp[i][v]=max(dp[i-1][v],sum[i]);
    for(int i=2; i<=k; i++,v^=1)
        for(int j=m; j<=n; j++)
            dp[j][v^1]=max(dp[j-1][v^1],dp[j-m][v]+sum[j]);
    write(dp[n][v]),putchar('\n');
    return 0;
}

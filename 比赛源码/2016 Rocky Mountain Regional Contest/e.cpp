
//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
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
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<50
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define getidx(l,r) (l+r | l!=r)
#define ls getidx(l,mid)
#define rs getidx(mid+1,r)
#define lson l,mid
#define rson mid+1,r

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
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

double dp[11][240*100+5];
double a[11], b[11], c[11];

double func(int i, double x)
{
     return a[i]*x*x + b[i]*x + c[i];
}

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    t *= 100;
    for(int i = 0; i < n; i++)
    {
         scanf("%lf %lf %lf", &a[i], &b[i], &c[i]);
    }
    for(int i = 0; i < n;i ++)
        for(int j = 0; j <= t; j++)
        {
            double x = j/100.0;
            if(!i)
                dp[i][j] = func(i, x);
            else
            {
                 int l = 0, r = j;
                 while(r-l >= 3)
                 {
                     int midl = (2*l+r)/3;
                     int midr = (l+2*r)/3;
                     double x1 = midl/100.0;
                     double x2 = midr/100.0;
                     if(dp[i-1][j-midl]+func(i, x1) > dp[i-1][j-midr]+func(i, x2))
                         r = midr;
                     else
                        l = midl;
                }
                 for(;l<=r;l++)
                 {
                      double x1 = l/100.0;
                      dp[i][j] = max(dp[i][j], dp[i-1][j-l]+func(i, x1));
                 }
            }
        }
    printf("%.8lf\n", dp[n-1][t]/n);
    return 0;
}

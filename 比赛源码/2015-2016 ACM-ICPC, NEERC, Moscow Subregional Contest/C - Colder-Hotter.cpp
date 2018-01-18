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
#define LLINF 1LL<<62
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
#define getidx(l,r) (l+r|l!=r)
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
int ansx, ansy;

int main()
{
    double xl = 0, xr = 1e9, yl = 0, yr = 1e9;
    for (int t = 1; t <= 100; t++)
    {
        double mid1 = (xl+xr)/2, mid2 = (mid1+xr)/2;
        int flag1, flag2;
        printf("%.0lf 0\n", mid1);
        fflush(stdout);
        scanf("%d", &flag1);
        printf("%.0lf 0\n", mid2);
        fflush(stdout);
        scanf("%d", &flag2);
        if (flag2)
        {
            xl = mid1;
            ansx = xl;
        }
        else
        {
            xr = mid2;
            ansx = xr;
        }
    }
    int tmp = ansx;
    for (int i = max(0, tmp-10); i <= min(1000000000, tmp+10); i++)
    {
        int flag;
        printf("%d 0\n", i);
        fflush(stdout);
        scanf("%d", &flag);
        if (flag) ansx = i;
    }
    for (int t = 1; t <= 100; t++)
    {
        double mid1 = (yl+yr)/2, mid2 = (mid1+yr)/2;
        int flag1, flag2;
        printf("%d %.0lf\n", ansx, mid1);
        fflush(stdout);
        scanf("%d", &flag1);
        printf("%d %.0lf\n", ansx, mid2);
        fflush(stdout);
        scanf("%d", &flag2);
        if (flag2)
        {
            yl = mid1;
            ansy = yl;
        }
        else
        {
            yr = mid2;
            ansy = yr;
        }
    }
    tmp = ansy;
    for (int i = max(0, tmp-10); i <= min(1000000000, tmp+10); i++)
    {
        int flag;
        printf("%d %d\n", ansx, i);
        fflush(stdout);
        scanf("%d", &flag);
        if (flag) ansy = i;
    }
    printf("A %d %d\n", ansx, ansy);
    return 0;
}

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


int sgn(double x)
{
    return x < -eps ? -1 : x > eps;
}

long long sum[50010], sqr_sum[50010];
int a[50010];

int main()
{
    sum[0] = sqr_sum[0] = 0;
    int nn;
    scanf("%d", &nn);
    while(nn--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        for(int i = 1; i <= n; ++i)
            sum[i] = sum[i-1] + a[i], sqr_sum[i] = sqr_sum[i-1] + (long long)a[i]*a[i];
        k = n-k;
        if(k == 0 || k == 1)
        {
            puts("0");
        }
        else
        {
            double ans = 1e100;
            for(int i = 1; i + k - 1 <= n; ++i)
            {
                double mid = (double)(sum[i+k-1] - sum[i-1])/k;
                double tmp = sqr_sum[i+k-1] - sqr_sum[i-1];
                tmp -= 2*(sum[i+k-1] - sum[i-1])*mid;
                tmp += k*mid*mid;
                if(sgn(tmp-ans) == -1)
                    ans = tmp;
            }
            printf("%.11f\n", ans);
        }
    }
    return 0;
}

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

int n;
int a[15], st[5000];
bool c[15][15][15];
double ans, s[15][15][15], f[5000];

int main()
{
    while (scanf("%d", &n))
    {
        if (n == 0) break;
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        st[0] = 0;
        for (int i = 1; i < (1<<n); i++)
        if (__builtin_popcount(i)%3 == 0)
        {
            st[0]++;
            st[st[0]] = i;
        }
        sort(a, a+n);
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n-2; i++)
            for (int j = i+1; j < n-1; j++)
                for (int k = j+1; k < n; k++)
                if (a[k] < a[i] + a[j])
                {
                    c[i][j][k] = true;
                    double p = double(a[i]+a[j]+a[k])/2;
                    s[i][j][k] = sqrt(p*(p-a[i])*(p-a[j])*(p-a[k]));
                }
        memset(f, 0, sizeof(f)); ans = 0;
        for (int i = 1; i <= st[0]; i++)
        {
            int now = st[i];
            for (int j = 0; j < n-2; j++)
            if (now&(1<<j))
            {
                for (int k = j+1; k < n-1; k++)
                if (now&(1<<k))
                {
                    for (int l = k+1; l < n; l++)
                    if (now&(1<<l))
                    {
                        int to = now^(1<<j)^(1<<k)^(1<<l), s1 = now^(1<<j)^(1<<k), s2 = now^(1<<j)^(1<<l), s3 = now^(1<<k)^(1<<l);
                        if (c[j][k][l]) f[now] = max(f[now], max(f[to], max(f[s1], max(f[s2], f[s3])))+s[j][k][l]);
                        else f[now] = max(f[now], max(f[to], max(f[s1], max(f[s2], f[s3]))));
                        if (f[now] > ans) ans = f[now];
                    }
                }
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}


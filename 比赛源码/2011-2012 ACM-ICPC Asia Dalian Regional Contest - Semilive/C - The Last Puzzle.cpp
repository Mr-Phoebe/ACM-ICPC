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
int n;
int ti[205], d[205], ans[205];
int f[205][205][2], g[205][205][2];

int calc(int i, int j)
{
    return d[i] - d[j];
}

bool dp(int t)
{
    for (int i = 0; i < n; i++)
    for (int j = i; j <= n; j++) f[i][j][0] = f[i][j][1] = t + 1;
    f[1][n][0] = max(0, t - ti[1]);
    f[0][n - 1][1] = max(0, t - ti[n-1]);
    for (int l = n - 1; l > 1; l--)
    {
        for (int i = 0; i + l <= n; i++)
        {
            int j = i + l;
            if (f[i + 1][j][0] > f[i][j][0] + calc(i + 1, i))
            {
                f[i + 1][j][0] = f[i][j][0] + calc(i + 1, i);
                g[i + 1][j][0] = 0;
            }
            if (f[i][j - 1][1] > f[i][j][0] + calc(j - 1, i))
            {
                f[i][j - 1][1] = f[i][j][0] + calc(j - 1, i);
                g[i][j - 1][1] = 0;
            }
            if (f[i + 1][j][0] > f[i][j][1] + calc(j, i + 1))
            {
                f[i + 1][j][0] = f[i][j][1] + calc(j, i + 1);
                g[i + 1][j][0] = 1;
            }
            if (f[i][j - 1][1] > f[i][j][1] + calc(j, j - 1))
            {
                f[i][j - 1][1] = f[i][j][1] + calc(j, j - 1);
                g[i][j - 1][1] = 1;
            }
            f[i + 1][j][0] = max(f[i + 1][j][0], t - ti[i + 1]);
            f[i][j - 1][1] = max(f[i][j - 1][1], t - ti[j - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    if (f[i][i + 1][0] <= t || f[i][i + 1][1] <= t) return true;
    return false;
}

int main()
{
    int i;
    while (scanf("%d", &n) != EOF)
    {
        n++;
        for (i = 1; i < n; i++)
        {
            scanf("%d", &ti[i]);
            ti[i]--;
        }
        for (i = 1; i < n; i++) scanf("%d", &d[i]);
        d[n] = d[n-1];
        int tot = n*1000000;
        if (dp(tot))
        {
            int flag;
            for (i = 0; i < n; i++)
            if (f[i][i + 1][0] <= tot)
            {
                flag = 0;
                break;
            }
            else if (f[i][i+1][1] <= tot)
            {
                flag = 1;
                break;
            }
            int l = i, r = i+1;
            ans[0] = 0;
            while (ans[0] < n-1)
            {
                if (flag == 1)
                {
                    ans[0]++;
                    ans[ans[0]] = r;
                    flag = g[l][r][flag];
                    r++;
                }
                else
                {
                    ans[0]++;
                    ans[ans[0]] = l;
                    flag = g[l][r][flag];
                    l--;
                }
            }
            for (i = ans[0]; i > 1; i--) printf("%d ",ans[i]);
            printf("%d\n", ans[1]);
        }
        else printf("Mission Impossible\n");
    }
    return 0;
}
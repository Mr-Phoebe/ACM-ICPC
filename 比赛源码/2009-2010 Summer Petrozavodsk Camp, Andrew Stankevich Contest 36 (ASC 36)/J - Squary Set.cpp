
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
int n, m;
int a[450], b[450];
bool f[200005][35];
bool upd[200005][35];
int g[200005][35];
int ans[35];

int main()
{
    freopen("squary.in","r",stdin);
    freopen("squary.out","w",stdout);
    for (int i = 1; i*i <= 200000; i++) a[i] = i*i;
    scanf("%d%d", &n, &m);
    int cnt = int(sqrt(n));
    if (a[cnt] == n) cnt--;
    for (int i = 1; i <= cnt; i++) b[i] = n-a[i];
    memset(f,0,sizeof(f)); f[0][0] = true; g[0][0] = 0;
    for (int i = cnt; i >= 1; i--)
    {
        memset(upd, 0, sizeof(upd));
        for (int j = n; j >= b[i]; j--)
        for (int k = 1; k <= m; k++)
        if (f[j-b[i]][k-1] && !upd[j-b[i]][k-1])
        {
            f[j][k] = 1;
            upd[j][k] = 1;
            g[j][k] = j-b[i];
        }
    }
    if (!f[n][m]) printf("NO\n");
    else
    {
        printf("YES\n");
        int i = m, now = n;
        ans[0] = 0;
        while (now != 0)
        {
            ans[0]++;
            ans[ans[0]] = now-g[now][i];
            now = g[now][i]; i--;
        }
        sort(ans+1,ans+ans[0]+1);
        for (int i = 1; i <= ans[0]; i++) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}

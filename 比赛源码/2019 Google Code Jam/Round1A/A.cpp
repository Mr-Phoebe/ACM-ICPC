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
#include <list>
#include <ctime>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
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
    while((c < '0' || c > '9') && c != '-' && c != EOF)
        c = getchar();
    if(c == EOF)
        return false;
    if(c == '-')
        c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9')
        x *= 10, x += (c - '0'),c = getchar();
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
    if(!len)
        data[len++] = 0;
    while(len--)
        putchar(data[len]+48);
}
//-----------------------------------

const int MAXN = 20;

bool flag[MAXN][MAXN];
int avail[MAXN][MAXN];
vector<pair<int, int> > g[MAXN][MAXN];
int px[MAXN * MAXN], py[MAXN * MAXN];
pair<int, int> ans[MAXN * MAXN];

bool dfs(int depth, int x, int y, int n, int m)
{
    if(depth == n * m)
    {
        for(int i = 0; i < n * m; i++)
            ans[i] = make_pair(px[i] + 1, py[i] + 1);
        return true;
    }
    if(depth == 0)
    {
        for(int i = 0; i < 3 && i < n; i++)
            for(int j = 0; j < 3 && j < m; j++)
            {
                flag[i][j] = true;
                px[0] = i;
                py[0] = j;
                if(dfs(1, i, j, n, m))
                    return true;
                flag[i][j] = false;
            }
    }
    else
    {
        int total = 0;
        pii mov[MAXN * MAXN];
        for(int i = 0; i < g[x][y].size(); i++)
        {
            int u = g[x][y][i].first;
            int v = g[x][y][i].second;
            if (!flag[u][v])
                mov[total++] = make_pair(u, v);
        }
        for(int i = 0; i < total; i++)
        {
            int u = mov[i].first;
            int v = mov[i].second;
            flag[u][v] = true;
            px[depth] = u;
            py[depth] = v;
            if (dfs(depth + 1, u, v, n, m))
                return true;
            flag[u][v] = false;
        }
    }
    return false;
}

int main()
{
    int T;
    read(T);
    for(int test = 1; test <= T; test++)
    {
        int n, m;
        read(n), read(m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                g[i][j].clear();
                for(int x = 0; x < n; x++)
                    for(int y = 0; y < m; y++)
                        if(i != x && j != y && i + j != x + y && i - j != x - y)
                            g[i][j].push_back(make_pair(x, y));
            }
        memset(flag, 0, sizeof(flag));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                random_shuffle(g[i][j].begin(), g[i][j].end());
        printf("Case #%d: ", test);
        if (!dfs(0, -1, -1, n, m))
            printf("IMPOSSIBLE\n");
        else
        {
            printf("POSSIBLE\n");
            for (int i = 0; i < n * m; i++)
                printf("%d %d\n", ans[i].first, ans[i].second);
        }
    }
    return 0;
}

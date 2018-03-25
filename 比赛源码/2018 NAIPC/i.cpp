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

const ll MOD = 1000000007;

vector<vector<int> > g;
vector<int> red;
vector<int> reds;
vector<int> sz;
vector<vector<ll> > res;


int n,m;

void dfs(int x,int p)
{
    sz[x] = 0;
    reds[x] = 0;
    for(int i=0; i<g[x].size(); i++)
    {
        if(g[x][i] == p)
            continue;
        dfs(g[x][i],x);
        sz[x] += sz[g[x][i]];
        reds[x] += reds[g[x][i]];
    }
    if(red[x])
        reds[x] += 1;
    sz[x] = max(sz[x], 1);
    return;
}

void solve(int x, int p)
{
    res[x].resize(min(sz[x], reds[x])+1);
    for(int i=0; i<res[x].size(); i++)
        res[x][i] = 0;
    res[x][0] = 1;
    for(int i=0; i<g[x].size(); i++)
    {
        if(g[x][i] == p)
            continue;
        solve(g[x][i],x);
        int ss = res[g[x][i]].size();
        int sp = res[x].size();
        vector<ll> vv = res[x];
        vector<ll> temp(res[x].size(), 0);
        for(int j=0; j<ss; j++)
        {
            for(int k=j; k<sp; k++)
            {
                temp[k] += vv[k-j]*res[g[x][i]][j];
                temp[k] %= MOD;
            }
        }
        res[x] = temp;
    }
    if(red[x])
        res[x][1] += 1;
    else
        res[x][0] += 1;
    return;
}

signed main()
{
    read(n), read(m);
    g.resize(n);
    int x;
    for(int i=0; i<n-1; i++)
    {
        read(x);
        x--;
        g[x].push_back(i+1);
    }
    red.resize(n);
    reds.resize(n);
    res.resize(n);
    sz.resize(n);
    for(int i=0; i<m; i++)
    {
        read(x);
        red[x-1] = 1;
    }
    dfs(0,-1);
    solve(0,-1);
   for(int i = 0; i < res[0].size(); i++)
    {
        write(res[0][i]);
        puts("");
    }
    for(int i = res[0].size(); i <= m; i++)
        puts("0");
    return 0;
}

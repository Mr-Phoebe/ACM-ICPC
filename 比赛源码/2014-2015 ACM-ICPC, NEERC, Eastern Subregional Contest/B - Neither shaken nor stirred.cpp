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

const int MAXN=100005;
vector<int> g[MAXN];
int k[MAXN],dp[MAXN][2],vis[MAXN];

void dfs(int u,int fa)
{
    if(vis[u])
    {
        if(dp[u][0]!=dp[fa][1])
        {
            dp[u][0]=-1;
            if(!k[u])
            {
                dp[u][1]=-1;
                for(auto v:g[u])
                    dfs(v,u);
            }
        }
    }
    else
    {
        vis[u]=1;
        dp[u][0]=dp[fa][1];
        dp[u][1]=k[u] ? k[u] : dp[u][0];
        for(auto v:g[u])
            dfs(v,u);
    }
}
int main()
{
    int n,m;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        read(k[i]),read(m);
        for(int j=0,x; j < m; j++)
        {
            read(x);
            g[i].pb(x);
        }
    }

    vis[1]=1;
    dp[1][0]=0;
    dp[1][1]=k[1];
    for(auto u:g[1])
        dfs(u,1);

    for(int i=1; i<=n; i++)
    {
        if(dp[i][0]==-1) printf("unknown");
        else if(dp[i][0]==0) printf("sober");
        else
            printf("%d",dp[i][0]);

        printf(" ");

        if(dp[i][1]==-1) printf("unknown");
        else if(dp[i][1]==0) printf("sober");
        else
            printf("%d",dp[i][1]);

        printf("\n");
    }
    return 0;
}

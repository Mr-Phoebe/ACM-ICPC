#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<time.h>
#include<string>
#include<map>
#include <algorithm>
#include <climits>
#define cl(a,b)    memset(a,b,sizeof(a))
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define REP2(i,a,b) for(int i=a;i>=b;--i)
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define X first
#define Y second
#define MAXN 200050
#define MOD 60
#define lson i<<1
#define rson i<<1|1
#define eps 1e-8
using namespace std;
int nx[MAXN * 2], head[MAXN], to[MAXN * 2];
int ecnt;
int val[MAXN];
int a[MAXN];
int l[MAXN], r[MAXN];
void addedge(int x, int y)
{
    to[ecnt] = y, nx[ecnt] = head[x], head[x] = ecnt++;
    to[ecnt] = x, nx[ecnt] = head[y], head[y] = ecnt++;
}
int fa[MAXN][20];
int dep[MAXN];
int cid = 0;
void dfs(int cur, int faa, int depth)
{
    l[cur] = ++cid;
    dep[cur] = depth;
    for (int i = 1; i < 20; ++i)
        fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    for (int i = head[cur]; i != -1; i = nx[i])
    {
        int u = to[i];
        if (u == faa)
            continue;
        fa[u][0] = cur;
        val[u] = val[cur] + a[u];
        dfs(u, cur, depth + 1);
    }
    r[cur] = ++cid;
}
int getlca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 19; i >= 0; --i)
    {
        if (dep[fa[x][i]] >= dep[y])
            x = fa[x][i];
        if (x == y)
            return x;
    }
    for (int i = 19; i >= 0; --i)
        if (fa[x][i] != fa[y][i])
        {
            x = fa[x][i];
            y = fa[y][i];
        }
    return fa[x][0];
}
struct node
{
    int u, v, lca, val;
} p[MAXN];
bool cmp(node a, node b)
{
    return dep[a.lca] > dep[b.lca];
}
bool vis[MAXN];

int sum[MAXN];
int d[MAXN];
int n, m;
int cs[MAXN], cd[MAXN];
vector<int> e[MAXN];
int lowbit(int x)
{
    return x & (-x);
}
void add(int p, int va, int *c)
{
    while (p <= 2*n)
    {
        c[p] += va;
        p += lowbit(p);
    }
}
int getsum(int p, int *c)
{
    int res = 0;
    while (p)
    {
        res += c[p];
        p -= lowbit(p);
    }
    return res;
}

void solve(int cur, int fa)
{
    sum[cur] = d[cur] = 0;
    for (int i = head[cur]; i != -1; i = nx[i])
    {
        int u = to[i];
        if (fa == u)
            continue;
        solve(to[i], cur);
        sum[cur] += d[u];
    }
    d[cur] = sum[cur];
    for (int i = 0; i < e[cur].size(); ++i)
    {
        int u = p[e[cur][i]].u;
        int v = p[e[cur][i]].v;
        int tmp = getsum(l[u], cs) + getsum(l[v], cs) - getsum(l[u], cd)
                  - getsum(l[v], cd) + sum[cur];
        d[cur] = max(d[cur], tmp + p[e[cur][i]].val);
    }
    add(l[cur], d[cur], cd);
    add(r[cur], -d[cur], cd);
    add(l[cur], sum[cur], cs);
    add(r[cur], -sum[cur], cs);
}

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d%d", &n, &m);
        cid=0;
        for(int i=0; i<=2*n; ++i)cd[i]=cs[i]=0;
        for (int i = 0; i <= n; ++i)
        {

            vis[i] = false;
            head[i] = -1;
            e[i].clear();
        }
        ecnt = 0;
        for (int i = 1; i < n; ++i)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            addedge(x, y);
        }
        fa[1][0] = 1;
        val[1] = 0;
        dfs(1, -1, 0);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &p[i].u, &p[i].v,&p[i].val);
            p[i].lca = getlca(p[i].u, p[i].v);
            e[p[i].lca].push_back(i);
        }
        solve(1, -1);

        printf("%d\n", d[1]);
    }
    return 0;
}

/*

3 2
1 2
1 3
1 2 1
1 3 2

7 3
1 2
1 3
2 4
2 5
3 6
3 7
2 3 4
4 5 3
6 7 3
 */

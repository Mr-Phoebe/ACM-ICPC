#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e5;

int np, pri[maxn + 5], vis[maxn + 5];
int k, fac[maxn + 5];

int v[maxn + 5];
vector<int> g[maxn + 5];

void prime_table(int n)
{
    np = 0;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i])
            continue;
        pri[np++] = i;
        for (int j = i * 2; j <= n; j += i)
            vis[j] = 1;
    }
}

void div_fac(int n, int& cnt)
{
    cnt = 0;
    for (int i = 0; i < np && pri[i] * pri[i] <= n; i++)
    {
        if (n % pri[i] == 0)
        {
            fac[cnt++] = pri[i];
            while (n % pri[i] == 0)
                n /= pri[i];
        }
    }
    if (n != 1)
        fac[cnt++] = n;
}

void dfs (int u, int d, int idx)
{
    if (d >= v[idx])
    {
        if (u != 1)
            g[idx].push_back(u);
        return;
    }

    dfs(u, d + 1, idx);
    dfs(u * fac[d], d + 1, idx);
}

void init ()
{
    np = 0;
    memset(vis, 0, sizeof(vis));
    prime_table(maxn);

    for (int i = 2; i <= maxn; i++)
    {
        div_fac(i, v[i]);
        dfs(1, 0, i);
    }
}

int N, f[maxn + 5], c[maxn + 5];

void input ()
{
    int x;
    scanf("%d", &N);
    memset(c, 0, sizeof(c));
    memset(f, 0, sizeof(f));

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        c[x]++;
    }
    for (int i = 2; i <= maxn; i++)
    {
        if (c[i] == 0)
            continue;
        for (int j = 0; j < g[i].size(); j++)
            f[g[i][j]] += c[i];
    }
}

typedef long long ll;

int count (int n)
{
    int ret = 0;
    for (int i = 0; i < g[n].size(); i++)
    {
        int k = g[n][i];
        if (v[k]&1)
            ret += (f[k] - 1);
        else
            ret -= (f[k] - 1);
    }
    return ret;
}

ll solve ()
{
    ll ret = 0;
    for (int i = 2; i <= maxn; i++)
    {
        if (c[i] == 0)
            continue;
        ll k = count(i);
        ret += k * (N - 1 - k);
    }
    ll a = N;
    ll sum = 1LL * a * (a - 1) * (a - 2) / 6;
    return sum - ret / 2;
}

int main ()
{
    init();
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        input();
        printf("%I64d\n", solve());
    }
    return 0;
}

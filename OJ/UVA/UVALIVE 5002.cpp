#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

long long c[1010][1010];

void init()
{
    c[0][0] = 1;
    for(int i = 1; i <= 1000; ++i)
    {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; ++j)
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) %mod;
    }
}

int to[1010], pre[1010], tail[1010];
int e_tot;

inline void add(int _from, int _to)
{
    to[e_tot] = _to;
    pre[e_tot] = tail[_from];
    tail[_from] = e_tot++;
}

int cnt[1010];

long long dfs(int now)
{
    cnt[now] = 0;
    long long ret = 1;
    for(int i = tail[now]; i != -1; i = pre[i])
    {
        long long son_ans = dfs(to[i]);
        cnt[now] += cnt[to[i]];
        ret = ret * son_ans %mod * c[cnt[now]][cnt[to[i]]] %mod;
    }
    ++cnt[now];
    return ret;
}

int indeg[1010];


int main()
{
    init();
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++)
    {
        printf("Case %d: ", i);
        int n;
        scanf("%d", &n);
        memset(tail, -1, sizeof tail);
        memset(indeg, 0, sizeof indeg);
        e_tot = 0;
        for(int i = 1, u, v; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            add(u, v);
            ++indeg[v];
        }
        int root;
        for(root = 1; root <= n && indeg[root] != 0; root++);
        printf("%lld\n", dfs(root));
    }
    return 0;
}

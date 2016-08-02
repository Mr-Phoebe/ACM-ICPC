#include <bits/stdc++.h>

using namespace std;

int	tail[10010], to[10010<<1], pre[10010<<1], tot;

inline void add(int _from, int _to)
{
    pre[tot] = tail[_from];
    to[tot] = _to;
    tail[_from] = tot++;
}

int sum_down[10010], pCnt_down[10010];

void init_down(int now, int fa)
{
    sum_down[now] = 0, pCnt_down[now] = 1;
    for(int i = tail[now]; i != -1; i = pre[i])
    {
        int _to = to[i];
        if(_to == fa)
            continue;
        init_down(_to, now);
        sum_down[now] += sum_down[_to] + pCnt_down[_to];
        pCnt_down[now] += pCnt_down[_to];
    }
}

int sum_up[10010], pCnt_up[10100];
int n;

void init_up(int now, int fa)
{
    sum_up[now] = 0, pCnt_up[now] = n - pCnt_down[now];
    if(fa != -1)
        sum_up[now] = sum_up[fa] + pCnt_up[fa] + sum_down[fa] - sum_down[now] - (pCnt_down[fa] - 1)  + (pCnt_down[fa] - 1 - pCnt_down[now])*2 + 1;
    for(int i = tail[now]; i != -1; i = pre[i])
    {
        if(to[i] == fa)
            continue;
        init_up(to[i], now);
    }
}

int dp[10010][110], pre_best[10010][110];
int ans;
int m;

void dfs(int now, int fa)
{
    for(int i = 0; i <= m; i++)
        dp[now][i] = pre_best[now][i] = sum_down[now];
    dp[now][0] = pre_best[now][0] = sum_down[now];
    for(int i = tail[now]; i != -1; i = pre[i])
    {
        int _to = to[i];
        if(_to == fa)
            continue;
        dfs(_to, now);
        for(int len = 1; len <= m; len++)
        {
            dp[now][len] = min(dp[now][len], dp[_to][len-1] + sum_down[now] - sum_down[_to] - pCnt_down[_to]);
            if(len != m)
                ans = min(ans, pre_best[now][len] - sum_down[_to] - pCnt_down[_to] + dp[_to][m-1 - len] + sum_up[now]);
        }
        for(int len = 1; len <= m; len++)
            pre_best[now][len] = min(pre_best[now][len], dp[now][len]);
    }
    ans = min(ans, dp[now][m] + sum_up[now]);
}

int main()
{
    for(scanf("%d%d", &n, &m); n || m; scanf("%d%d", &n, &m))
    {
        tot = 0;
        memset(tail, -1, sizeof(int)*(n+5));
        for(int i = 1; i < n; i++)
        {
            int _u, _v;
            scanf("%d%d", &_u, &_v);
            add(_u, _v);
            add(_v, _u);
        }
        init_down(0, -1);
        init_up(0, -1);
        ans = 0x3f3f3f3f;
        dfs(0, -1);
        printf("%d\n", ans);
    }
    return 0;
}

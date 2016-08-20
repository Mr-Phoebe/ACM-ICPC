#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <climits>
#include <stack>
#include <cmath>
#include <bitset>
#include <numeric>
#include <functional>

using namespace std;

int n, m;
int dp[110][110];
int tail[110], pre[210], to[210], cost[110], val[110], tot;

inline void add(int _from, int _to)
{
    pre[tot] = tail[_from];
    to[tot] = _to;
    tail[_from] = tot++;
}

void dfs(int now, int fa)
{
    for(int i = cost[now]; i <= m; i++)
        dp[now][i] = val[now];
    for(int i = tail[now]; i != -1; i = pre[i])
    {
        int _to = to[i];
        if(_to == fa) continue;
        dfs(_to, now);
        for(int j = m; j >= cost[now]; j--)
            for(int k = 1; j+k <=m; k++)
                dp[now][j+k] = max(dp[now][j+k], dp[now][j] + dp[_to][k]);
    }
}

int main()
{
    while(scanf("%d%d", &n, &m) && n!= -1)
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d", &cost[i], &val[i]);
            cost[i] += 19;
            cost[i] /= 20;
        }
        tot = 0;
        memset(dp, 0, sizeof dp);
        memset(tail, -1, sizeof tail);
        for(int i = 0; i < n-1; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        if(!m)
            puts("0");
        else
        {
            dfs(1, -1);
            printf("%d\n", dp[1][m]);
        }
    }
    return 0;
}

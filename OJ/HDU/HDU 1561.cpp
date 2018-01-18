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

int dp[210][210];
int tail[210], pre[210], to[210], cost[210];
int tot;
int m;

inline void add(int _from, int _to)
{
    pre[tot] = tail[_from];
    to[tot] = _to;
    tail[_from] = tot++;
}

void dfs(int now)
{
    memset(dp[now], 0, sizeof dp[now]);
    dp[now][1] = cost[now];
    for(int i = tail[now]; i != -1; i = pre[i])
    {
        int _to = to[i];
        dfs(_to);
        for(int j = m; j >= 2; j--)
        {
            if(!now) break;
            for(int k = 1; k < j; k++)
                dp[now][j] = max(dp[now][j], dp[now][j-k] + dp[_to][k]);
        }
    }
}

int main()
{
    int n;
    while(scanf("%d%d", &n, &m) && n)
    {
        tot = 0;
        memset(tail, -1, sizeof tail);
        for(int i = 1; i <= n; i++)
        {
            int _from, _cost;
            scanf("%d%d", &_from, &_cost);
            add(_from, i);
            cost[i] = _cost;
        }
        dfs(0);
        for(int i = tail[0]; i != -1; i = pre[i])
        {
            int _to = to[i];
            for(int j = m; j >= 1; j--)
            {
                for(int k = 1; k <= j; k++)
                    dp[0][j] = max(dp[0][j], dp[0][j-k] + dp[_to][k]);
            }
        }
        printf("%d\n", dp[0][m]);
    }
    return 0;
}

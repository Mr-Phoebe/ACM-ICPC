#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x, y;
};

int cross(node a, node b, node c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

node pole;

bool cmp(node a, node b)
{
    int tmp = cross(pole, b, a);
    if(!tmp)
        return a.x < b.x;
    else
        return tmp < 0;
}

node p[310];

bool Graham(int n)
{
    int pole_idx = 0;
    for(int i = 1; i < n; i++)
        if(p[i].x < p[pole_idx].x || (p[i].x == p[pole_idx].x && p[i].y < p[pole_idx].y))
            pole_idx = i;
    swap(p[0], p[pole_idx]);
    pole.x = p[0].x, pole.y = p[0].y;
    sort(p+1, p+n, cmp);
    node tmp1 = p[0], tmp2 = p[1];
    for(int i = 2; i < n; i++)
    {
        if(cross(p[i], p[i-1], p[i-2]) >= 0)
            return false;
        tmp1 = tmp2, tmp2 = p[i];
    }
    return true;
}

int dp[310][310], cost[310][310];

int dfs(int l, int r)
{
    if(dp[l][r] != 0x3f3f3f3f)
        return dp[l][r];
    if(l == r-1)
        return dp[l][r] = 0;
    for(int i = l+1; i < r; i++)
    {
        dp[l][r] = min(dp[l][r], dfs(l, i) + dfs(i, r) + cost[l][i] + cost[i][r]);
    }
    return dp[l][r];
}

int main()
{
    int n, pp;
    while(scanf("%d%d", &n, &pp) > 0)
    {
        for(int i = 0; i < n; i++)
            scanf("%d%d", &p[i].x, &p[i].y);
        if(!Graham(n))
            puts("I can't cut.");
        else
        {
            memset(dp, 0x3f, sizeof dp);
            for(int i = 0; i < n-1; i++)
            {
                cost[i][i+1] = 0;
                for(int j = i+2; j < n; j++)
                    cost[i][j] = abs(p[i].x + p[j].x) * abs(p[i].y + p[j].y) %pp;
            }
            cost[0][n-1] = 0;
            for(int i = 1; i < n-1; i++)
            {
                dp[0][n-1] = min(dp[0][n-1], dfs(0, i) + dfs(i, n-1) + cost[0][i] + cost[i][n-1]);
            }
            printf("%d\n", dp[0][n-1]);
        }
    }
    return 0;
}

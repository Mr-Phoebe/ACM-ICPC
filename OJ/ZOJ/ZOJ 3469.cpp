#include <bits/stdc++.h>

using namespace std;

struct node
{
    int x, y, angry;
    friend bool operator < (node a, node b)
    {
        return a.x < b.x;
    }
};

node a[1010];
long long dp[1010][1010][2];
int angry_sum[1010];
int n, v, mid;

long long dfs(int l, int r, bool now)  //true for left, false for right
{
    if(l == r)
        return 0;
    long long &ret = dp[l][r][now];
    if(ret != -1)
        return ret;
    ret = 1LL << 33;
    int delay = angry_sum[n] - angry_sum[r] + angry_sum[l-1];
    if(now)
    {
        if(l < mid)
        {
            ret = min(ret, dfs(l+1, r, true) + v * (a[l+1].x - a[l].x) * (a[l].angry + delay));
            ret = min(ret, dfs(l+1, r, false) + v * (a[r].x - a[l].x) * (a[l].angry + delay));
        }
    }
    else
    {
        if(r > mid)
        {
            ret = min(ret, dfs(l, r-1, true) + v * (a[r].x - a[l].x) * (a[r].angry +delay));
            ret = min(ret, dfs(l, r-1, false) + v * (a[r].x - a[r-1].x) * (a[r].angry + delay));
        }
    }
    return ret;
}

int main()
{
    int x;
    while(scanf("%d%d", &n, &x) > 0)
    {
        v = 1;
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i].x);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i].y);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i].angry);
        a[n+1].x = x, a[n+1].y = 0, a[n+1].angry = 0;
        ++n;
        sort(a+1, a+n+1);
        angry_sum[0] = 0;
        int normal_sum = 0;
        for(int i = 1; i <= n; ++i)
        {
            normal_sum += a[i].y;
            angry_sum[i] = angry_sum[i-1] + a[i].angry;
            if(a[i].x == x)
                mid = i;
        }
        memset(dp, -1, sizeof dp);
        printf("%.3f\n", (normal_sum - min(dfs(1, n, true), dfs(1, n, false)))*1.0/1000);
    }
    return 0;
}

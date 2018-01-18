
/*
 * =====================================================================================
 *
 *       Filename:  4661.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2014/10/1 19:53:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
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

const int mod = 1e9+7;

long long exGcd(long long a, long long b, long long &x, long long &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    long long gcd;
    gcd = exGcd(b, a%b, y, x);
    y -= a/b*x;
    return gcd;
}

long long p[1000010], rev[1000010];

inline long long Rev(int a)
{
    long long x, y;
    exGcd(a, mod, x, y);
    x = (x %mod + mod) %mod;
    return x;
}

inline void init()
{
    p[0] = 1;
    for(int i = 1; i <= 1000000; i++)
        p[i] = p[i-1] * i %mod, rev[i] = Rev(p[i]);
}

int tail[1000010], pre[1000010<<1], to[1000010<<1], tot;

inline void add(int _from, int _to)
{
    pre[tot] = tail[_from];
    to[tot] = _to;
    tail[_from] = tot++;
}

long long dp[1000010];
int cnt[1000010];

void dfs1(int now, int fa)
{
    dp[now] = 1;
    cnt[now] = 0;
    for(int i = tail[now]; i != -1; i = pre[i])
    {
        int _to = to[i];
        if(_to == fa)
            continue;
        dfs1(_to, now);
        cnt[now] += cnt[_to];
        dp[now] = dp[now] * dp[_to] %mod * rev[cnt[_to]] %mod;
    }
    dp[now] = dp[now] * p[cnt[now]] %mod;
    cnt[now]++;
}

long long ans;
int n;

void dfs2(int now, int fa)
{
    ans = (ans + dp[now]*dp[now] %mod) %mod;
    for(int i = tail[now]; i != -1; i = pre[i])
    {
        int _to = to[i];
        if(_to == fa)
            continue;
        dp[_to] = dp[now] * cnt[_to] %mod * Rev(n - cnt[_to]) %mod;
        dfs2(_to, now);
    }
}

int main()
{
    int nn;
    init();
    for(scanf("%d", &nn); nn--; )
    {
        scanf("%d", &n);
        tot = 0;
        memset(tail, -1, sizeof(int) * (n+5));
        for(int i = 1; i < n; i++)
        {
            int _u, _v;
            scanf("%d%d", &_u, &_v);
            add(_u, _v);
            add(_v, _u);
        }
        dfs1(1, -1);
        ans = 0;
        dfs2(1, -1);
        printf("%I64d\n", ans);
    }
    return 0;
}

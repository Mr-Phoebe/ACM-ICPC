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

int to[10010<<1], pre[10010<<1], tail[10010<<1], tot;

inline void add(int _from, int _to)
{
    to[tot] = _to;
    pre[tot] = tail[_from];
    tail[_from] = tot++;
}

int bit[10000<<3], first[10010], second[10010], last[10010], len;

void update(int pos, int val)
{
    for(; pos <= len; pos += pos & (-pos))
        bit[pos] += val;
}

int query(int pos)
{
    int ret = 0;
    for(; pos > 0; pos -= pos & (-pos))
        ret += bit[pos];
    return ret;
}

int timestamp;

void dfs(int now, int fa)
{
    printf("%d__\n", now);
    first[now] = ++timestamp;
    for(int i = tail[now]; i != -1; i = pre[i])
    {
        if(to[i] == fa)
            continue;
        dfs(to[i], now);
        ++timestamp;
    }
    second[now] = timestamp;
}

int main()
{
    int nn;
    scanf("%d", &nn);
    for(int ii = 1; ii <= nn; ++ii)
    {
        int n;
        scanf("%d", &n);
        memset(tail, -1, sizeof tail);
        tot = 0;
        for(int i = 1, u, v; i < n; ++i)
        {
            scanf("%d%d", &u, &v);
            add(u, v), add(v, u);
        }
        timestamp = 0;
        dfs(1, -1);
        for(int i = 1; i <= n; ++i)
            last[i] = first[i] + timestamp - 1;
        for(int i = 1, val; i <= n; ++i)
        {
            scanf("%d", &val);
            update(first[i], val);
            update(last[i], val);
        }
        int m, x, y, head_id = 1;
        char str[8];
        printf("Case #%d:\n", ii);
        while(m--)
        {
            scanf("%s%d", str, &x);
            if(str[0] =='R')
                head_id = first[x];
            else if(str[0] == 'Q')
            {
                if(head_id == first[x])
                    printf("%d\n", query(last[x]-1) - query(first[x]-1));
                else if(head_id > first[x])
                    printf("%d\n", query(last[x]) - query(second[x]));
                else
                    printf("%d\n", query(second[x]) - query(first[x]-1));
            }
            else
            {
                scanf("%d", &y);
                update(first[x], y);
                update(last[x], y);
            }
        }
    }
    return 0;
}

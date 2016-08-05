#include <bits/stdc++.h>

using namespace std;

int to[20010<<1], pre[20010<<1], tail[20010];
int e_tot;

inline void add(int _from, int _to)
{
    to[e_tot] = _to;
    pre[e_tot] = tail[_from];
    tail[_from] = e_tot++;
}

vector<pair<int, int> > ee;
int in[20010], out[20010], d[20010];

void dfs(int now, int fa, int div)
{
    d[now] = div;
    for(int i = tail[now]; i != -1; i = pre[i])
    {
        if(fa == to[i])
            continue;
        dfs(to[i], now, div+1);
    }
}

int ans;

int get_ans(int now, int fa)
{
    int ret = in[now] - out[now];
    for(int i = tail[now]; i != -1; i = pre[i])
    {
        if(fa == to[i])
            continue;
        ret += get_ans(to[i], now);
    }
    if(ret == 1)
        ++ans;
    return ret;
}



int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(tail, -1, sizeof tail);
    ee.clear();
    for(int i = 0, u, v, k; i < m; ++i)
    {
        scanf("%d%d%d", &u, &v, &k);
        if(k == 1)
        {
            add(u, v);
            add(v, u);
        }
        else
        {
            ee.push_back(make_pair(u, v));
        }
    }
    dfs(1, -1, 0);
    int sz = ee.size();
    for(int i = 0; i < sz; ++i)
    {
        if(d[ee[i].first] > d[ee[i].second])
            swap(ee[i].first, ee[i].second);
        ++out[ee[i].first];
        ++in[ee[i].second];
    }
    ans = 0;
    get_ans(1, -1);
    printf("%d\n", ans);
    return 0;
}

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

vector<int> succ[50010], prod[50010], bucket[50010], dom_t[50010];
int semi[50010], anc[50010], idom[50010], best[50010], fa[50010];
int dfn[50010], redfn[50010];
int timestamp;

void dfs(int now)
{
    dfn[now] = ++timestamp;
    redfn[timestamp] = now;
    anc[timestamp] = idom[timestamp] = 0;
    semi[timestamp] = best[timestamp] = timestamp;
    int sz = succ[now].size();
    for(int i = 0; i < sz; ++i)
    {
        if(dfn[succ[now][i]] == -1)
        {
            dfs(succ[now][i]);
            fa[dfn[succ[now][i]]] = dfn[now];
        }
        prod[dfn[succ[now][i]]].push_back(dfn[now]);
    }
}

void compress(int now)
{
    if(anc[anc[now]] != 0)
    {
        compress(anc[now]);
        if(semi[best[now]] > semi[best[anc[now]]])
            best[now] = best[anc[now]];
        anc[now] = anc[anc[now]];
    }
}

int eval(int now)
{
    if(anc[now] == 0)
        return now;
    compress(now);
    return best[now];
}

void debug()
{
    for(int i=timestamp;i>1;i--)
        cout<<redfn[i]<<" "<<anc[i]<<endl;
    cout<<"---------------------"<<endl;
}

void lengauer_tarjan(int n)
{
    memset(dfn, -1, sizeof dfn);
    memset(fa, -1, sizeof fa);
//	memset(anc, 0, sizeof anc);
//	memset(idom, 0, sizeof idom);
//	for(int i = 0; i <= n; ++i)
//		best[i] = semi[i] = i;
    timestamp = 0;
    dfs(n);
    fa[1] = 0;
    for(int w = timestamp; w > 1; --w)
    {
        if(fa[w] == -1)
            continue;
        int sz = prod[w].size();
        for(int i = 0; i < sz; ++i)
        {
            int u = eval(prod[w][i]);
            if(semi[w] > semi[u])
                semi[w] = semi[u];
        }
        //debug();
        bucket[semi[w]].push_back(w);
        anc[w] = fa[w];
        if(fa[w] == 0)
            continue;
        sz = bucket[fa[w]].size();
        for(int i = 0; i < sz; ++i)
        {
            int u = eval(bucket[fa[w]][i]);
            if(semi[u] < fa[w])
                idom[bucket[fa[w]][i]] = u;
            else
                idom[bucket[fa[w]][i]] = fa[w];
        }
        bucket[fa[w]].clear();
    }
    for(int w = 2; w <= n; ++w)
    {
        if(fa[w] == -1)
            continue;
        if(idom[w] != semi[w])
            idom[w] = idom[idom[w]];
    }
    idom[1] = 0;
    for(int i = timestamp; i > 1; --i)
    {
        if(fa[i] == -1)
            continue;
        dom_t[idom[i]].push_back(i);
    }
}

long long ans[50010];

void get_ans(int now)
{
    ans[redfn[now]] += redfn[now];
    int sz = dom_t[now].size();
    for(int i = 0; i < sz; ++i)
    {
        ans[redfn[dom_t[now][i]]] += ans[redfn[now]];
        get_ans(dom_t[now][i]);
    }
}

void MAIN(int n, int m)
{
    for(int i = 0; i <= n; ++i)
        succ[i].clear(), prod[i].clear(), bucket[i].clear(), dom_t[i].clear();
    for(int i = 0, u, v; i < m; ++i)
    {
        scanf("%d%d", &u, &v);
        succ[u].push_back(v);
    }
    lengauer_tarjan(n);
    memset(ans, 0, sizeof ans);
    get_ans(1);
    for(int i = 1; i <= n; ++i)
        printf("%I64d%c", ans[i], i == n ? '\n' :' ');
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) > 0)
        MAIN(n, m);
    return 0;
}

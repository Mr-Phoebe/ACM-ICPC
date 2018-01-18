#include <bits/stdc++.h>

struct node
{
    node *ch[2];
    int cnt;
    void upd()
    {
        cnt = ch[0]->cnt + ch[1]->cnt;
    }
} Nnull, *null = &Nnull;

node mem[100010 * 20];
node *tot, *root[100010];
int fuckLen;

void build(node *&now, int l, int r)
{
    now->ch[0] = now->ch[1] = null;
    if(l == r)
        return ;
    int m = (l + r) >> 1;
    build(now->ch[0], l, m);
    build(now->ch[1], m + 1, r);
    now->upd();
}

void update(node *pre, node *&now, int pos, int l, int r)
{
    if(l == r)
    {
        now = tot ++;
        *now = *pre;
        ++ now->cnt;
    }
    else
    {
        now = tot ++;
        *now = *pre;
        int m = (l + r) >> 1;
        if(pos <= m)
            update(pre->ch[0], now->ch[0], pos, l, m);
        else
            update(pre->ch[1], now->ch[1], pos, m + 1, r);
        now->upd();
    }
}

int getCnt(node *left, node *right, int _l, int _r, int l, int r)   //get the number of hotel which is in the path between left and right and has star between [_l..r], right is ancestor of left
{
    int ret = 0;
    if(_l <= l && r <= _r)
    {
        ret = left->cnt - right->cnt;
    }
    else if(l <= _r && _l <= r)
    {
        int m = (l + r) >> 1;
        ret = getCnt(left->ch[0], right->ch[0], _l, _r, l, m) + getCnt(left->ch[1], right->ch[1], _l, _r, m + 1, r);
    }
    return ret;
}

int to[100010 << 1], pre[100010 << 1], tail[100010];
int e_tot;

inline void add(int _from, int _to)
{
    to[e_tot] = _to;
    pre[e_tot] = tail[_from];
    tail[_from] = e_tot ++;
}

int star[100010];
int p[100010][20], depth[100010];

void dfs(int now, int fa, int dep)
{
    update(root[fa], root[now], star[now], 1, fuckLen);
    for(int i = 1; i < 20; ++ i)
    {
        p[now][i] = p[p[now][i - 1]][i - 1];
    }
    depth[now] = dep;
    for(int i = tail[now]; i != -1; i = pre[i])
    {
        if(to[i] == fa)
            continue;
        p[to[i]][0] = now;
        dfs(to[i], now, dep + 1);
    }
}

int getLca(int u, int v)
{
    if(depth[u] > depth[v])
        std::swap(u, v);
    for(int delta = depth[v] - depth[u], i = 0; delta != 0; delta >>= 1, ++ i)
    {
        if(delta & 1)
        {
            v = p[v][i];
        }
    }
    if(u == v)
        return u;
    for(int i = 19; i >= 0; -- i)
    {
        if(p[u][i] == p[v][i])
            continue;
        u = p[u][i];
        v = p[v][i];
    }
    return p[u][0];
}

int getKthPosition(int u, int v, int k, int valL, int valR, int t)   // the kth node in the path of u->v, and v must be one ancestor of u, t is the parama of the recursion
{
    if(u == v)
        return u;
    if(v == p[u][0])
    {
        if(k == 1 && valL <= star[u] && star[u] <= valR)
            return u;
        else
            return v;
    }
    if(depth[p[u][t]] < depth[v])
    {
        return getKthPosition(u, v, k, valL, valR, t - 1);
    }
    int cnt = getCnt(root[u], root[p[u][t]], valL, valR, 1, fuckLen) + (valL <= star[p[u][t]] && star[p[u][t]] <= valR);
    if(cnt < k)
        return getKthPosition(p[p[u][t]][0], v, k - cnt, valL, valR, t - 1);
    else
        return getKthPosition(u, p[u][t], k, valL, valR, t - 1);
}

void MAIN(int n, int m)
{
    fuckLen = 1;
    for(int i = 1; i <= n; ++ i)
    {
        scanf("%d", &star[i]);
        fuckLen = std::max(fuckLen, star[i]);
    }
    memset(tail, -1, sizeof tail);
    e_tot = 0;
    for(int i = 1, u, v; i < n; ++ i)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    p[1][0] = 1;
    tot = mem;
    //build(root[0], 1, 100000);
    build(root[0], 1, fuckLen);
    dfs(1, 0, 0);
    for(int i = 0, s, t, a, b, k; i < m; ++ i)
    {
        scanf("%d%d%d%d%d", &s, &t, &a, &b, &k);
        int lca = getLca(s, t), fuck = (a <= star[lca] && star[lca] <= b);
        int cnt1 = getCnt(root[s], root[lca], a, b, 1, fuckLen) + fuck, cnt2 = getCnt(root[t], root[lca], a, b, 1, fuckLen) + fuck;
        if(cnt1 + cnt2 - fuck < k)
        {
            puts("-1");
        }
        else if(cnt1 >= k)
        {
            printf("%d\n", getKthPosition(s, lca, k, a, b, 19));
        }
        else
        {
            printf("%d\n", getKthPosition(t, lca, cnt1 + cnt2 - fuck - k + 1, a, b, 19));
        }
    }
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) == 2)
    {
        MAIN(n, m);
    }
    return 0;
}

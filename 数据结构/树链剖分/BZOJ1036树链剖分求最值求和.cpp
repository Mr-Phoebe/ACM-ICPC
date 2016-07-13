#include <cstdio>
#include <iostream>
#include <algorithm>

const int MAXN = 30001;
struct Edge
{
    int v;
    Edge *next;
};
struct Node
{
    int value, max, sum;
};
Edge g[MAXN*2], *header[MAXN];
Node s[MAXN*2];
int n, m;
void AddEdge(const int x, const int y)
{
    static int LinkSize;
    Edge* const node = g+(LinkSize++);
    node->v = y;
    node->next = header[x];
    header[x] = node;
}

int _st, _ed, _x;
int _query_max(const int p, const int lef, const int rig)
{
    if (_st <= lef && rig <= _ed) return s[p].max;
    const int mid = (lef+rig)/2;
    int res = static_cast<int>(0x80000000UL);
    if (_st <= mid) res = _query_max(p*2, lef, mid);
    if (mid+1 <= _ed) res = std::max(res, _query_max(p*2+1, mid+1, rig));
    return res;
}
int _query_sum(const int p, const int lef, const int rig)
{
    if (_st <= lef && rig <= _ed) return s[p].sum;
    const int mid = (lef+rig)/2;
    int res = 0;
    if (_st <= mid) res += _query_sum(p*2, lef, mid);
    if (mid+1 <= _ed) res += _query_sum(p*2+1, mid+1, rig);
    return res;
}
void _modify(const int p, const int lef, const int rig)
{
    if (lef == rig)
    {
        s[p].value = s[p].max = s[p].sum = _x;
        return;
    }
    const int mid = (lef+rig)/2;
    if (_st <= mid) _modify(p*2, lef, mid);
    if (mid+1 <= _ed) _modify(p*2+1, mid+1, rig);
    s[p].max = std::max(s[p*2].max, s[p*2+1].max);
    s[p].sum = s[p*2].sum + s[p*2+1].sum;
}
inline int QueryMax(const int lef, const int rig)
{
    _st = lef, _ed = rig;
    return _query_max(1, 1, n);
}
inline int QuerySum(const int lef, const int rig)
{
    _st = lef, _ed = rig;
    return _query_sum(1, 1, n);
}
inline void Modify(const int pos, const int x)
{
    _st = _ed = pos, _x = x;
    _modify(1, 1, n);
}

typedef int Array[MAXN];
Array size, top, hson, parent, number, depth;
void dfs(const int u)
{
    size[u] = 1;
    for (Edge *e = header[u]; e; e = e->next)
        if (e->v != parent[u])
        {
            parent[e->v] = u;
            depth[e->v] = depth[u]+1;
            dfs(e->v);
            size[u] += size[e->v];
            if (size[e->v] > size[hson[u]])
                hson[u] = e->v;
        }
}
void dfs2(const int u, const int tp)
{
    static int timestamp;
    number[u] = ++timestamp, top[u] = tp;
    if (hson[u])
        dfs2(hson[u], tp);
    for (Edge* e = header[u]; e; e = e->next)
        if (e->v != hson[u] && e->v != parent[u])
            dfs2(e->v, e->v);
}
int QMax(int a, int b)
{
    int ta = top[a], tb = top[b], res = QueryMax(number[a], number[a]);
    while (ta != tb)
    {
        if (depth[ta] < depth[tb])
            std::swap(ta, tb), std::swap(a, b);
        std::cout<<"a: "<<number[a]<<" father: "<<number[ta]<<std::endl;
        res = std::max(res, QueryMax(number[ta], number[a]));
        a = parent[ta], ta = top[a];
    }
    if (a == b) return res;
    if (depth[a] > depth[b]) std::swap(a, b);
    return std::max(res, QueryMax(number[a], number[b]));
}
int QSum(int a, int b)
{
    int ta = top[a], tb = top[b], res = 0;
    while (ta != tb)
    {
        if (depth[ta] < depth[tb])
            std::swap(ta, tb), std::swap(a, b);
        std::cout<<"a: "<<number[a]<<" father: "<<number[ta]<<std::endl;
        res += QuerySum(number[ta], number[a]);
        a = parent[ta], ta = top[a];
    }
    if (a == b) return res;
    if (depth[a] > depth[b]) std::swap(a, b);
    return res + QuerySum(number[a], number[b]);
}

int main()
{
    freopen("data.txt","r",stdin);
    scanf("%d", &n);
    for (int i = 1, x, y; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        AddEdge(x, y);
        AddEdge(y, x);
    }
    dfs(1);
    dfs2(1, 1);
    for (int i = 0, x; i < n; ++i)
    {
        scanf("%d", &x);
        Modify(number[i+1], x);
        std::cout<<top[i+1]<<" "<<number[i+1]<<"\n";
    }
    scanf("%d", &m);
    for (int i = 0, x, y; i < m; ++i)
    {
        static char buf[10];
        scanf("\n%s%d%d", buf, &x, &y);
        switch (buf[1])
        {
        case 'M':
            printf("%d\n", QMax(x, y));
            break;
        case 'S':
            printf("%d\n", QSum(x, y));
            break;
        case 'H':
            Modify(number[x], y);
            break;
        }
    }
}

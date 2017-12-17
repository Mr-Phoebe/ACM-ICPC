#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 10001;
int LinkSize;
struct Edge
{
    int v, w;
    Edge *next;
} g[MAXN*2], *header[MAXN];
int s[MAXN*4];
void add_edge(const int x, const int y, const int w)
{
    Edge *node = g+(LinkSize++);
    node->v = y;
    node->w = w;
    node->next = header[x];
    header[x] = node;
}
typedef int Matrix[MAXN+1];
int TestData, n, road[MAXN][3];
int _st, _ed, _x;
void _modify(const int p, const int lef, const int rig)
{
    if (lef == rig)
    {
        s[p] = _x;
        return;
    }
    const int mid = (lef+rig)/2;
    if (_st <= mid) _modify(p*2, lef, mid);
    if (mid+1 <= _ed) _modify(p*2+1, mid+1, rig);
    s[p] = max(s[p*2], s[p*2+1]);
}
int _query(const int p, const int lef, const int rig)
{
    if (_st <= lef && rig <= _ed)
        return s[p];
    const int mid = (lef+rig)/2;
    int res = 0;
    if (_st <= mid) res = max(res, _query(p*2, lef, mid));
    if (mid+1 <= _ed) res = max(res, _query(p*2+1, mid+1, rig));
    return res;
}
inline void Modify(const int pos, const int x)
{
    _st = _ed = pos, _x = x;
    _modify(1, 1, n);
}
inline int Query(const int lef, const int rig)
{
    _st = lef, _ed = rig;
    return _query(1, 1, n);
}
Matrix depth, size, top, parent, hson, number;
void dfs(const int u)
{
    size[u] = 1, hson[u] = 0;
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
int TreeSize;
void build_tree(const int u, const int tp)
{
    number[u] = ++TreeSize, top[u] = tp;
    if (hson[u])
        build_tree(hson[u], tp);
    for (Edge *e = header[u]; e; e = e->next)
        if (e->v != parent[u] && e->v != hson[u])
            build_tree(e->v, e->v);
}

inline int GetMax(int a, int b)
{
    int ta = top[a], tb = top[b], res = 0;
    while (ta != tb)
    {
        if (depth[ta] < depth[tb])
            swap(ta, tb), swap(a, b);
        res = max(res, Query(number[ta], number[a]));
        a = parent[ta], ta = top[a];
    }
    if (a == b) return res;
    if (depth[a] > depth[b]) swap(a, b);
    return max(res, Query(number[hson[a]], number[b]));
}
void Solve()
{
    scanf("\n%d", &n);
    LinkSize = TreeSize = 0;
    memset(s, 0, sizeof(*s)*4*n);
    memset(header+1, 0, sizeof(*header)*n);

    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d%d", &road[i][0], &road[i][1], &road[i][2]);
        add_edge(road[i][0], road[i][1], road[i][2]);
        add_edge(road[i][1], road[i][0], road[i][2]);
    }
    dfs(1);
    build_tree(1, 1);
    for (int i = 1; i < n; ++i)
    {
        if (depth[road[i][0]] > depth[road[i][1]])
            swap(road[i][0], road[i][1]);
        Modify(number[road[i][1]], road[i][2]);
    }
    for (int x, y; ; )
    {
        static char s[10];
        scanf("\n%s", s);
        if (s[0] == 'D') return;
        scanf("%d%d", &x, &y);
        if (s[0] == 'Q')
            printf("%d\n", GetMax(x, y));
        else
            Modify(number[road[x][1]], y);
    }
}
int main()
{
    scanf("%d", &TestData);
    while (TestData--)
    {
        Solve();
    }
}

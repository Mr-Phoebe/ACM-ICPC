#include <cstdio>
#include <algorithm>

const int MAXN = 80001, SQRTN = 283;
struct Edge
{
    int v;
    Edge *next;
};
Edge g[MAXN*2], *header[MAXN];
void AddEdge(const int x, const int y)
{
    static int LinkSize;
    Edge* const node = g+(LinkSize++);
    node->v = y;
    node->next = header[x];
    header[x] = node;
}

//-------Block Array:
int Blocks, Block[SQRTN][SQRTN], BSize[SQRTN], a[SQRTN*SQRTN];
int* lower_bound(int* const beg, int* const end, const int x)
{
    int* const pos = std::lower_bound(beg, end, x);
    return *pos != x ? pos-1 : std::upper_bound(beg, end, x)-1;
}
void BlockModify(const int index, const int value)
{
    const int block = index/SQRTN;
    const int offset = std::lower_bound(Block[block], Block[block]+BSize[block], a[index]) - Block[block];
    a[index] = Block[block][offset] = value;
    std::sort(Block[block], Block[block]+BSize[block]);
}
int BlockGetRank(const int st, const int ed, const int x)
{
    const int bs = st/SQRTN, be = ed/SQRTN;
    int rank = 0;
    if (bs == be)
    {
        for (int i = st; i <= ed; ++i) rank += a[i] <= x;
        return rank;
    }
    for (int i = st; i < (bs+1)*SQRTN; ++i) rank += a[i] <= x;
    for (int i = be*SQRTN; i <= ed; ++i) rank += a[i] <= x;
    for (int i = bs+1; i < be; ++i) rank += lower_bound(Block[i], Block[i]+BSize[i], x)-Block[i]+1;
    return rank;
}
int BlockGetMin()
{
    int res = 0x7FFFFFFF;
    for (int i = 0; i < Blocks; ++i)
        res = std::min(res, Block[i][0]);
    return res;
}
int BlockGetMax()
{
    int res = static_cast<int>(0x80000000);
    for (int i = 0; i < Blocks; ++i)
        res = std::max(res, Block[i][BSize[i]-1]);
    return res;
}
//-------Heavy-Light Decomposition:
typedef int Array[MAXN];
Array top, hson, parent, depth, size, number;
void HLDdfs(const int u)
{
    size[u] = 1, hson[u] = 0;
    for (Edge* e = header[u]; e; e = e->next)
        if (e->v != parent[u])
        {
            parent[e->v] = u;
            depth[e->v] = depth[u]+1;
            HLDdfs(e->v);
            size[u] += size[e->v];
            if (size[e->v] > size[hson[u]])
                hson[u] = e->v;
        }
}
void HLDdfs2(const int u, const int tp)
{
    static int timestamp;
    number[u] = timestamp++, top[u] = tp;
    if (hson[u])
        HLDdfs2(hson[u], tp);
    for (Edge *e = header[u]; e; e = e->next)
        if (e->v != hson[u] && e->v != parent[u])
            HLDdfs2(e->v, e->v);
}
int HLDGetRank(int a, int b, const int num, int& lca)
{
    int ta = top[a], tb = top[b], rank = 0;
    while (ta != tb)
    {
        if (depth[ta] < depth[tb])
            std::swap(ta, tb), std::swap(a, b);
        rank += BlockGetRank(number[ta], number[a], num);
        a = parent[ta], ta = top[a];
    }
    if (depth[a] > depth[b]) std::swap(a, b);
    lca = a;
    if (a == b) return rank + BlockGetRank(number[a], number[a], num);
    return rank + BlockGetRank(number[a], number[b], num);
}

int n, m, t[MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", t+i);
    for (int i = 1, x, y; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        AddEdge(x, y);
        AddEdge(y, x);
    }
    HLDdfs(1);
    HLDdfs2(1, 1);
    for (int i = 1; i <= n; ++i)
        a[number[i]] = Block[number[i]/SQRTN][BSize[number[i]/SQRTN]++] = t[i];
    Blocks = 1+(n-1)/SQRTN;
    for (int i = 0; i < Blocks; ++i)
        std::sort(Block[i], Block[i]+BSize[i]);
    for (int i = 0, k, x, y; i < m; ++i)
    {
        scanf("%d%d%d", &k, &x, &y);
        if (k == 0)
        {
            BlockModify(number[x], y);
            continue;
        }
        int lef = BlockGetMin()-1, rig = BlockGetMax(), lca;
        HLDGetRank(x, y, 0, lca);
        const int nodes = depth[x]+depth[y]-depth[lca]*2+1;
        k = nodes-k+1;
        if (nodes < k || k < 1)
        {
            printf("invalid request!\n");
            continue;
        }
        while (rig-lef > 1)
        {
            const int mid = (lef+rig)/2;
            if (HLDGetRank(x, y, mid, lca) >= k)
                rig = mid;
            else
                lef = mid;
        }
        printf("%d\n", rig);
    }
}

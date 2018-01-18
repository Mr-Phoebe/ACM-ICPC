#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <climits>
#include <map>
#include <queue>
#include <vector>

const int N = 100000;
const int D = 40;

int n, q, queue[N], parent[N], size[N], balance[N], depth[N], weight[N];
bool visited[N];
std::vector <int> tree[N];

struct Entry {
    Entry(int ancestor, int distance, int subtree) : ancestor(ancestor), distance(distance), subtree(subtree) {}

    int ancestor, distance, subtree;
};

std::vector <Entry> entries[N];

struct BinaryIndexedTree {
    void allocate(int size) {
        n = size;
        count = pool + pool_size;
        std::fill(count, count + n, 0);
        pool_size += size;
    }

    void add(int k, int v) {
        for (; k < n; k += ~k & k + 1) {
            count[k] += v;
        }
    }

    int query(int k) {
        k = std::min(k, n - 1);
        int result = 0;
        for (; k >= 0; k -= ~k & k + 1) {
            result += count[k];
        }
        return result;
    }

    int  n;
    int* count;

    static int pool_size;
    static int pool[N * D];
};

int BinaryIndexedTree::pool_size;
int BinaryIndexedTree::pool[N * D];

std::map <int, BinaryIndexedTree> bits[N];

void divide(int root)
{
    parent[root] = -1;
    size[root] = balance[root] = 0;
    int tail = 0;
    queue[tail ++] = root;
    for (int head = 0; head < tail; ++ head) {
        int u = queue[head];
        for (int _ = 0; _ < (int)tree[u].size(); ++ _) {
            int v = tree[u][_];
            if (v != parent[u] && !visited[v]) {
                parent[v] = u;
                size[v] = balance[v] = 0;
                queue[tail ++] = v;
            }
        }
    }
    for (int i = tail - 1; i >= 1; -- i) {
        int u = queue[i];
        size[u] ++;
        size[parent[u]] += size[u];
        balance[parent[u]] = std::max(balance[parent[u]], size[u]);
    }
    for (int i = 0; i < tail; ++ i) {
        int u = queue[i];
        balance[u] = std::max(balance[u], size[root] - size[u]);
    }
    for (int i = 0; i < tail; ++ i) {
        int u = queue[i];
        if (balance[u] < balance[root]) {
            root = u;
        }
    }
    bits[root][-1].allocate(tail);
    bits[root][-1].add(0, weight[root]);
    visited[root] = true;
    entries[root].push_back(Entry(root, 0, -1));
    for (int _ = 0; _ < (int)tree[root].size(); ++ _) {
        int vv = tree[root][_];
        if (!visited[vv]) {
            tail = 0;
            queue[tail ++] = vv;
            parent[vv] = root;
            depth[vv] = 1;
            for (int head = 0; head < tail; ++ head) {
                int u = queue[head];
                entries[u].push_back(Entry(root, depth[u], vv));
                for (int __ = 0; __ < (int)tree[u].size(); ++ __) {
                    int v = tree[u][__];
                    if (v != parent[u] && !visited[v]) {
                        parent[v] = u;
                        depth[v] = depth[u] + 1;
                        queue[tail ++] = v;
                    }
                }
            }
            bits[root][vv].allocate(tail + 1);
            for (int i = 0; i < tail; ++ i) {
                int u = queue[i];
                bits[root][-1].add(depth[u], weight[u]);
                bits[root][vv].add(depth[u], weight[u]);
            }
            divide(vv);
        }
    }
}

int main()
{
    while (scanf("%d%d", &n, &q) == 2) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", weight + i);
        }
        std::fill(tree, tree + n, std::vector <int>());
        for (int i = 0; i < n - 1; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        memset(visited, 0, sizeof(visited));
        std::fill(entries, entries + n, std::vector <Entry>());
        BinaryIndexedTree::pool_size = 0;
        std::fill(bits, bits + n, std::map <int, BinaryIndexedTree>());
        divide(0);
        while (q --) {
            int u, d;
            char buffer[2];
            scanf("%s%d%d", buffer, &u, &d);
            u --;
            if (*buffer == '!') {
                d -= weight[u];
                for (int _ = 0; _ < (int)entries[u].size(); ++ _) {
                    const Entry &entry = entries[u][_];
                    bits[entry.ancestor][-1].add(entry.distance, d);
                    if (~entry.subtree) {
                        bits[entry.ancestor][entry.subtree].add(entry.distance, d);
                    }
                }
                weight[u] += d;
            } else {
                int result = 0;
                for (int _ = 0; _ < (int)entries[u].size(); ++ _) {
                    const Entry &entry = entries[u][_];
                    if (entry.distance <= d) {
                        result += bits[entry.ancestor][-1].query(d - entry.distance);
                        if (~entry.subtree) {
                            result -= bits[entry.ancestor][entry.subtree].query(d - entry.distance);
                        }
                    }
                }
                printf("%d\n", result);
            }
        }
    }
    return 0;
}

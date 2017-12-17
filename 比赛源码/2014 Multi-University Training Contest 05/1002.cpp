#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 100000;
const int D = 20;

int n, m, a[N], b[N], depth[N], shortcut[D][N], parent[N];
std::vector <int> tree[N], queries[N];

int get_lca(int a, int b)
{
    if (depth[a] > depth[b]) {
        std::swap(a, b);
    }
    for (int i = D - 1; i >= 0; -- i) {
        if (depth[b] - depth[a] >> i & 1) {
            b = shortcut[i][b];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = D - 1; i >= 0; -- i) {
        if (shortcut[i][a] != shortcut[i][b]) {
            a = shortcut[i][a];
            b = shortcut[i][b];
        }
    }
    return shortcut[0][a];
}

int find(int u)
{
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

int main()
{
    while (scanf("%d%d", &n, &m) == 2) {
        std::fill(tree, tree + n, std::vector <int>());
        for (int i = 0; i < n - 1; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            a --;
            b --;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        std::vector <int> queue;
        {
            int* parent = shortcut[0];
            depth[0] = 0;
            parent[0] = -1;
            queue.push_back(0);
            for (int head = 0; head < (int)queue.size(); ++ head) {
                int u = queue[head];
                for (int _ = 0; _ < (int)tree[u].size(); ++ _) {
                    int v = tree[u][_];
                    if (v != parent[u]) {
                        depth[v] = depth[u] + 1;
                        parent[v] = u;
                        queue.push_back(v);
                    }
                }
            }
        }
        for (int i = 1; i < D; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int &result = shortcut[i][j];
                result = shortcut[i - 1][j];
                if (~result) {
                    result = shortcut[i - 1][result];
                }
            }
        }
        std::fill(queries, queries + n, std::vector <int>());
        for (int i = 0; i < m; ++ i) {
            scanf("%d%d", a + i, b + i);
            a[i] --;
            b[i] --;
            queries[get_lca(a[i], b[i])].push_back(i);
        }
        for (int i = 0; i < n; ++ i) {
            parent[i] = i;
        }
        int result = 0;
        for (int _ = n - 1; _ >= 0; -- _) {
            int u = queue[_];
            bool found = false;
            for (int __ = 0; __ < (int)queries[u].size() && !found; ++ __) {
                int i = queries[u][__];
                if (find(a[i]) == u && find(b[i]) == u) {
                    found = true;
                }
            }
            if (!found) {
                parent[u] = shortcut[0][u];
            } else {
                result ++;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}

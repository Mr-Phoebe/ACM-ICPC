#include <algorithm>
#include <cctype>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>

const int N = 1000000;

int n, q, head[N], to[N << 1], next[N << 1];
int queue[N], parent[N], depth[N], subtree[N], children[N][4], path[N], belong[N];

void add_edge(int i, int a, int b)
{
    to[i]   = b;
    next[i] = head[a];
    head[a] = i;
}

int query(int a, int b)
{
    if (a > b) {
        std::swap(a, b);
    }
    if (a != 0 && belong[a] == belong[b]) {
        return 0;
    }
    int i = 0;
    while (children[0][i] == belong[a] || children[0][i] == belong[b]) {
        i ++;
    }
    int result = a == 0 ? path[b] : std::min(path[a], path[b]);
    return std::min(result, children[0][i]);
}

int next_int()
{
    int result = 0;
    char c = getchar();
    while (!isdigit(c)) {
        c = getchar();
    }
    while (isdigit(c)) {
        result = result * 10 + c - '0';
        c = getchar();
    }
    return result;
}

int main()
{
    while (scanf("%d%d", &n, &q) == 2) {
        memset(head, -1, sizeof(head));
        for (int i = 0; i < n - 1; ++ i) {
            int a = next_int();
            int b = next_int();
            //scanf("%d%d", &a, &b);
            a --;
            b --;
            add_edge(i << 1,     a, b);
            add_edge(i << 1 | 1, b, a);
        }
        {
            int tail = 0;
            queue[tail ++] = 0;
            parent[0] = -1;
            for (int _head = 0; _head < tail; ++ _head) {
                int u = queue[_head];
                depth[u] = ~parent[u] ? depth[parent[u]] + 1 : 0;
                for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
                    int v = to[iterator];
                    if (v != parent[u]) {
                        parent[v] = u;
                        queue[tail ++] = v;
                    }
                }
            }
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < 4; ++ j) {
                    children[i][j] = INT_MAX;
                }
            }
            for (int i = n - 1; i >= 0; -- i) {
                int u = queue[i];
                subtree[u] = std::min(u, children[u][0]);
                int p = parent[u];
                if (~p) {
                    children[p][3] = subtree[u];
                    std::sort(children[p], children[p] + 4);
                }
            }
            tail = 0;
            for (int iterator = head[0]; ~iterator; iterator = next[iterator]) {
                int v = to[iterator];
                path[v] = INT_MAX;
                belong[v] = subtree[v];
                queue[tail ++] = v;
            }
            path[0] = INT_MAX;
            belong[0] = -1; // mark
            for (int _head = 0; _head < tail; ++ _head) {
                int u = queue[_head];
                for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
                    int v = to[iterator];
                    if (v != parent[u]) {
                        path[v] = std::min(path[u], children[u][subtree[v] == children[u][0]]);
                        belong[v] = belong[u];
                        queue[tail ++] = v;
                    }
                }
                path[u] = std::min(path[u], children[u][0]);
            }
        }
        int last = 0;
        while (q --) {
            int u = next_int();
            int v = next_int();
            u ^= last;
            v ^= last;
            assert(1 <= u && u <= n);
            assert(1 <= v && v <= n);
            last = query(u - 1, v - 1) + 1;
            printf("%d\n", last);
        }
    }
    return 0;
}


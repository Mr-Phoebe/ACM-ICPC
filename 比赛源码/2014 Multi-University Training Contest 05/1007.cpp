#include <cassert>
#include <cstdio>
#include <cstring>

const int M = 20;
const int N = M << 1;
const int MOD = (int)1e9 + 7;

int binom[N + 1][N + 1], n, m, a[M], b[M], parent[N], new_id[N], predecessor[N], ways[1 << M + 1];
bool visited[N];

int find(int i)
{
    if (parent[i] != i) {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void update(int &x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
    memset(binom, 0, sizeof(binom));
    for (int i = 0; i <= N; ++ i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++ j) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
        }
    }
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; ++ i) {
            parent[i] = i;
        }
        for (int i = 0; i < m; ++ i) {
            scanf("%d%d", a + i, b + i);
            a[i] --;
            b[i] --;
            if (find(a[i]) != find(b[i])) {
                parent[find(a[i])] = find(b[i]);
            }
        }
        int result = 1;
        int total = n;
        memset(visited, 0, sizeof(visited));
        for (int _ = 0; _ < n; ++ _) {
            if (!visited[_]) {
                memset(new_id, -1, sizeof(new_id));
                int nn = 0;
                for (int i = 0; i < n; ++ i) {
                    if (!visited[i] && find(i) == find(_)) {
                        visited[i] = true;
                        new_id[i] = nn ++;
                    }
                }
                memset(predecessor, 0, sizeof(predecessor));
                for (int i = 0; i < m; ++ i) {
                    if (~new_id[a[i]] && ~new_id[b[i]]) {
                        predecessor[new_id[b[i]]] |= 1 << new_id[a[i]];
                    }
                }
                for (int k = 0; k < nn; ++ k) {
                    for (int i = 0; i < nn; ++ i) {
                        for (int j = 0; j < nn; ++ j) {
                            if (predecessor[j] >> i & 1) {
                                predecessor[j] |= predecessor[i];
                            }
                        }
                    }
                }
                memset(ways, 0, sizeof(int) * (1 << nn));
                ways[0] = 1;
                for (int mask = 0; mask < 1 << nn; ++ mask) {
                    for (int i = 0; i < nn; ++ i) {
                        if ((~mask >> i & 1) && (mask & predecessor[i]) == predecessor[i]) {
                            update(ways[mask | 1 << i], ways[mask]);
                        }
                    }
                }
                result = (long long)result * ways[(1 << nn) - 1] % MOD * binom[total][nn] % MOD;
                total -= nn;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}

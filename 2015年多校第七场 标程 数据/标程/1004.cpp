#include <cstdio>
#include <algorithm>
#include <cstring>

const int MaxN = 200005;
const int MaxM = 400005;
int ax[MaxM], m;
int query[MaxN][3];
int addIdToQueryId[MaxN];
int bit[2][MaxM];

inline int getId(int x) {
    return std::lower_bound(ax, ax + m, x) - ax + 1;
}

void add(int* tr, int k, int v) {
    while (k <= m) {
        tr[k] += v;
        k += k & -k;
    }
}

int read(int* tr, int k) {
    int r = 0;
    while (k) {
        r += tr[k];
        k -= k & -k;
    }
    return r;
}

int main() {
    int n, id;
    int l, r;
    
    //freopen("data.in", "r", stdin);
    
    int kase = 1;
    while (scanf("%d", &n) == 1) {
        printf("Case #%d:\n",kase++);
        m = 0;
        for (int i = 1, j = 0; i <= n; i++) {
            scanf("%d%d", &query[i][0], &query[i][1]);
            if (query[i][0] == 0) {
                addIdToQueryId[++j] = i;
                query[i][2] = query[i][1] + j;
                ax[m++] = query[i][1];
                ax[m++] = query[i][2];
            }
        }
        std::sort(ax, ax + m);
        m = std::unique(ax, ax + m) - ax;
        for (int i = 0; i <= m; i++) {
            bit[0][i] = bit[1][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (query[i][0] == 0) {
                l = getId(query[i][1]);
                r = getId(query[i][2]);
                printf("%d\n", read(bit[1], r) - read(bit[0], l - 1));
                add(bit[0], l, 1);
                add(bit[1], r, 1);
            } else {
                id = addIdToQueryId[query[i][1]];
                l = getId(query[id][1]);
                r = getId(query[id][2]);
                add(bit[0], l, -1);
                add(bit[1], r, -1);
            }
        }
    }
    return 0;
}
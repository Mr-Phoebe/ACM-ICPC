#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5+5;

int n, a[N], b[N], p[N], v[N], r[5*N][2];

void init () {
    memset(v, 0, sizeof(v));

    for (int i = 2; i <= n; i++) {
        if (v[i])
            continue;

        for (int j = i * 2; j <= n; j += i)
            v[j] = 1;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
        p[a[i]] = i;
    }
    sort(b+1, b+n+1);
}

int solve () {
    int c = 0;

    for (int i = 1; i <= n; i++) {
        while (p[b[i]] != i) {
            for (int j = i; j < p[b[i]]; j++) {
                if (!v[p[b[i]] - j + 1]) {
                    r[c][1] = p[b[i]];
                    r[c++][0] = j;

                    int t = p[b[i]];
                    p[b[i]] = j;
                    p[a[j]] = t;
                    swap(a[j], a[t]);
                    break;
                }
            }
        }
    }
    return c;
}

int main () {
    scanf("%d", &n);
    init();
    int c = solve();

    printf("%d\n", c);
    for (int i = 0; i < c; i++)
        printf("%d %d\n", r[i][0], r[i][1]);
    return 0;
}
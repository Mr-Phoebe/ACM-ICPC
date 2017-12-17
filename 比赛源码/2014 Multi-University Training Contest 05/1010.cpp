#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstring>

const int N = 800;

int n, a[N][N], b[N][N];
std::bitset <N> rows[3][N], columns[3][N];

int main() {
    while (scanf("%d", &n) == 1) {
        assert(1 <= n && n <= N);
        for (int _ = 1; _ < 3; ++ _) {
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < n; ++ j) {
                    rows[_][i].reset(j);
                    columns[_][j].reset(i);
                }
            }
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                assert(scanf("%d", a[i] + j) == 1);
                assert(0 <= a[i][j] && a[i][j] <= 1000000000);
                a[i][j] %= 3;
                rows[a[i][j]][i].set(j);
            }
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                assert(scanf("%d", b[i] + j) == 1);
                assert(0 <= b[i][j] && b[i][j] <= 1000000000);
                b[i][j] %= 3;
                columns[b[i][j]][j].set(i);
            }
        }
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                int result = 0;
                result += (rows[1][i] & columns[1][j]).count();
                result += (rows[1][i] & columns[2][j]).count() * 2;
                result += (rows[2][i] & columns[1][j]).count() * 2;
                result += (rows[2][i] & columns[2][j]).count();
                printf("%d%c", result % 3, " \n"[j == n - 1]);
            }
        }
    }
    return 0;
}

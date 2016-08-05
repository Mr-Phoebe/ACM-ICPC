#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
const int MOD = 1000000007;

int T;
char a[N], b[N];
int n, m, jump[N];
int dp[N];

int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    scanf("%d", &T);
    int cas = 0;
    while (T--) {
        scanf("%s%s", a + 1, b + 1);
        n = strlen(a + 1); m = strlen(b + 1);
        int j = 0;
        for (int i = 2; i <= m; i++) {
            while (j && b[i] != b[j + 1]) j = jump[j];
            if (b[i] == b[j + 1]) j++;
            jump[i] = j;
        }
        j = 0;
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            while (j && a[i] != b[j + 1]) j = jump[j];
            if (a[i] == b[j + 1]) j++;
            dp[i] = dp[i - 1];
            if (j == m) {
                dp[i] = (dp[i] + dp[i - m]) % MOD;
                j = jump[j];
            }
        }
        printf("Case #%d: %d\n", ++cas, dp[n]);
    }
    return 0;
}

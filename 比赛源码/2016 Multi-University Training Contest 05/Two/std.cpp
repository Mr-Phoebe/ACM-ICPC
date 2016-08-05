#include <bits/stdc++.h>

using namespace std;

const int N = 1000+5;
const int MOD = 1e9+7;

int n, m, a[N], b[N];
int dp[N][N];

int solve() {
    for(int i = 1;i <= n; i++) {
        for(int j = 1;j <= m; j++) {
            dp[i][j] = (dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%MOD;
            if(dp[i][j] < 0) dp[i][j] += MOD;
            if(a[i] == b[j]) dp[i][j] = (dp[i][j]*2+1)%MOD;
        }
    }
    return dp[n][m];
}

int main() {
 //   freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);
    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1;i <= m; i++) scanf("%d", &b[i]);
        printf("%d\n", solve());
    }
    return 0;
}

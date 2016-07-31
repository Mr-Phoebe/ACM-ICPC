#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
typedef vector<int> VI;
typedef vector<pair<int, int> > VII;


int n, t, k, dp[510][510], tmp[510][510];
VII e[510];

int work(int t, int fa) {
    int sons = 1;
    dp[t][0] = 0;
    dp[t][1] = k;
    for (int i = 0; i < e[t].size(); i ++ ) {
        int v = e[t][i].first;
        int c = e[t][i].second;
        if (v == fa) continue;
        int gs = work(v, t);
        sons += gs;
        for (int j = 0; j <= sons + 2; j ++ )
            for (int l = 0; l <= gs + 2; l ++ )
                tmp[j][l] = INF;
        for (int l = sons; l >= 0; l -- ) {
            for (int j = gs; j >= 0; j -- ) {
                if (j > 0)
                    tmp[l][j] = dp[t][l] + dp[v][j] + j * c;
                if (tmp[l + 1][j + 1] < INF)
                    tmp[l][j] = min(tmp[l][j], tmp[l + 1][j + 1] - k);
            }
        }
        for (int l = sons; l >= 0; l -- ) {
            int ans = INF;
            for (int j = 0; j <= min(l, gs); j ++ )
                ans = min(ans, tmp[l - j][j]);
            dp[t][l] = ans;
        }
    }
    return sons;
}

int main() {
    scanf("%d", &t);
    int ca = 0;
    for (int ca = 1; ca <= t; ca ++ ) {
        scanf("%d%d", &n, &k);
        int sumc = 0;
        for (int i = 1; i <= n; i ++ )
            e[i].clear();
        for (int i = 1; i < n; i ++ ) {
            int s, ee, c;
            scanf("%d%d%d", &s, &ee, &c);
            s ++ ;
            ee ++ ;
            e[s].PB(MP(ee, c));
            e[ee].PB(MP(s, c));
            sumc += c;
        }
        memset(dp, 0x3f, sizeof(dp));
        work(1, 0);
        printf("Case #%d: %d\n", ca, dp[1][0]);
    }
    return 0;
}

#include <bits/stdc++.h>
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)

using namespace std;

const int N = 50+5;
const int MOD = 1e9+7;

int n, root;
vector<int> G[N], vt[N];
int son[N], cnt[N], fa[N];
int dp[N][N][N], sum[N][N][N];
int C[N][N];

int pow_mod(int x, int n) {
    int ret = 1;
    while(n) {
        if(n&1) ret = 1ll*ret*x%MOD;
        x = 1ll*x*x%MOD;
        n >>= 1;
    }
    return ret;
}

int inv(int x) {
    return pow_mod(x, MOD-2);
}

inline void Add(int &x, int y) {
    x += y;
    if(x >= MOD) x -= MOD;
}

void dfs(int u, int pre) {
    son[u] = 0;
    cnt[u] = 1;
    for(int i = 0;i < G[u].size(); i++) {
        int v = G[u][i];
        if(v == pre) continue;
        dfs(v, u);
        fa[v] = u;
        int tmp = 1ll*cnt[v]*C[son[u]+son[v]][son[v]]%MOD;
        cnt[u] = 1ll*cnt[u]*tmp%MOD;
        son[u] += son[v];

        for(int j = 0;j < vt[v].size(); j++) vt[u].push_back(vt[v][j]);
    }
    vt[u].push_back(u);
    son[u]++;
}

int pr[N];

void dfs2(int u, int pre) {
    pr[u] = 0;
    for(int i = 0;i < G[u].size(); i++) {
        int v = G[u][i];
        if(v == pre) continue;
        dfs2(v, u);
        int tmp = 1;
        int cur_cnt = 0;
        for(int j = 0;j < G[u].size(); j++) if(G[u][j]!=pre&&j!=i) {
            int vv = G[u][j];
            tmp = 1ll*tmp*C[cur_cnt+son[vv]][son[vv]]%MOD*cnt[vv]%MOD;
            cur_cnt += son[vv];
        }
        for(int j = 0;j < vt[v].size(); j++) {
            int vv = vt[v][j];
            for(int p1 = 1;p1 <= vt[v].size(); p1++) if(dp[v][vv][p1]) {
                for(int p2 = 0;p2 <= cur_cnt; p2++)
                    Add(dp[u][vv][p2+p1], dp[v][vv][p1]*1ll*tmp%MOD*C[p1-1+p2][p2]%MOD*C[vt[v].size()-p1+cur_cnt-p2][cur_cnt-p2]%MOD);
            }
        }
        Add(pr[u], 1ll*tmp*pr[v]%MOD*C[cur_cnt+son[v]][son[v]]%MOD);
    }
    for(int i = 0;i < vt[u].size(); i++) if(vt[u][i]>u)
        Add(pr[u], cnt[u]);
    for(int i = 0;i < G[u].size(); i++) {
        int v = G[u][i];
        if(v==pre) continue;
        for(int j = 0;j < G[u].size(); j++) {
            int vv = G[u][j];
            if(vv==pre||j==i) continue;
            int cur_cnt = 0, tmp = 1;
            for(int k = 0;k < G[u].size(); k++) if(k!=i&&k!=j) {
                int vvv=G[u][k];
                if(vvv==pre) continue;
                tmp = 1ll*tmp*C[cur_cnt+son[vvv]][son[vvv]]%MOD*cnt[vvv]%MOD;
                cur_cnt += son[vvv];
            }
            int tot = 0;
            for(int k = 0;k < vt[v].size(); k++) {
                for(int p1 = 1;p1 <= son[v]; p1++) {
                    for(int p2 = 1;p2 <= son[vv]; p2++) {
                        int mul = 1ll*dp[v][vt[v][k]][p1]*sum[vv][p2][vt[v][k]]%MOD;
                        for(int p3 = 1;p3 <= p2; p3++) {
                            Add(tot, 1ll*mul*C[p1-1+p3-1][p1-1]%MOD*C[son[v]-p1+son[vv]-p3+1][son[v]-p1]%MOD);
                        }
                    }
                }
            }
            Add(pr[u], 1ll*tmp*tot%MOD*C[son[u]-1][cur_cnt]%MOD);
        }
    }
    dp[u][u][son[u]] = cnt[u];
    for(int i = 1;i <= vt[u].size(); i++) {
        for(int j = 1;j <= n; j++) {
            sum[u][i][j] = (sum[u][i][j-1]+dp[u][j][i])%MOD;
        }
    }
    //printf("pr[%d] = %d\n", u, pr[u]);
}

int solve() {
    dfs(root, -1);
    fa[root] = -1;
    for(int i = 1;i <= n; i++)
        for(int j = 1;j <= n; j++)
            for(int k = 1;k <= n; k++)
                dp[i][j][k] = sum[i][j][k] = 0;
    dfs2(root, -1);
    /*
    for(int i = 1;i <= n; i++) {
        for(int j = 1;j <= n; j++) {
            for(int k = 1;k <= n; k++)
                printf("dp[%d][%d][%d] = %d\n", i,j,k,dp[i][j][k]);
        }
    }
    */
    return pr[root];
}

void init() {
    for(int i = 0;i < N; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1;j < i; j++)
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
    }
}

int main() {
    init();
 //   freopen("data2.in", "r", stdin);
  //  freopen("data2.out", "w", stdout);
    while(scanf("%d%d", &n, &root) == 2) {
        for(int i = 1;i <= n; i++) G[i].clear(), vt[i].clear();
        int u, v;
        for(int i = 0;i < n-1; i++) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        printf("%d\n", solve());
    }
 //   showtime;
    return 0;
}
